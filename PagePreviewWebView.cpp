// Integrated preview of HTML/CSS documents for Quanta
// Copyright (C) 2011 Camila Ayres
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 'g
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "PagePreviewWebView.h"

#include <ktrader.h>
#include <kaboutdata.h>
#include <interfaces/idocumentcontroller.h>
#include <interfaces/icore.h>
#include <interfaces/iuicontroller.h>
#include <ktexteditor/editor.h>

class PagePreviewPlugin;

PagePreviewWebView::PagePreviewWebView(QWidget* parent) 
  : QWebView(parent)
{
  
    /* combobox with the html files */
    m_combobox = new QComboBox(this);
     
    /* verify the type of the doc and update the combobox */
    connect(KDevelop::ICore::self()->documentController(), SIGNAL(documentActivated(KDevelop::IDocument*)), 
	    SLOT(setDocument(KDevelop::IDocument*)));        
   
    /* for every change in the combobox, update the combobox */
    connect(m_combobox, SIGNAL(currentIndexChanged(int)), SLOT(previewDocumentCombo(int)));
  
    //switch on timer
    m_timer = new QTimer();
    m_timer->setSingleShot(true);
    connect(KDevelop::ICore::self()->documentController(), SIGNAL(documentContentChanged(KDevelop::IDocument*)), SLOT(timerPreview()));
    
    //switch off timer
    connect(m_timer, SIGNAL(timeout()), SLOT(previewDocument()));    
    
    if(KDevelop::IDocument* doc = KDevelop::ICore::self()->documentController()->activeDocument()){
      setDocument(doc);    
    }  
    

  
}

void PagePreviewWebView::setDocument(KDevelop::IDocument *doc)
{
 
    /* if there is no doc, get out of here */
    if(!doc->textDocument() || (!doc->mimeType()->is("text/html") && !doc->mimeType()->is("text/css"))){ 
	return; 
    }
  
    /* if doc type is css */ 
    if(doc->mimeType()->is("text/css")){
	
	int numberOfHtmlDoc = 0;  
	m_combobox->clear();
	
	/* get all the doc type html opened */
	foreach(KDevelop::IDocument *tmp, KDevelop::ICore::self()->documentController()->openDocuments()){
	  if(tmp->mimeType()->is("text/html")){
	    m_combobox->addItem(tmp->url().fileName(), KDevelop::ICore::self()->documentController()->openDocuments().indexOf(tmp));
	    ++numberOfHtmlDoc;
	  }	
	}     
	
	
	/* if there is no html opened so there is no html in QWebView */
	if(numberOfHtmlDoc == 0){
	  
	  m_activedoc = 0;
	  
	}else{
	  
	  /* if there is html opened so reaload QWebView */
	  previewDocumentCombo(m_combobox->currentIndex());
	  
	}
	
	m_combobox->show();      
    
    /* if doc type is not css */ 
    }else{
	/* hide combobox */
	m_combobox->hide();  
	/* just show m_activedoc */
	m_activedoc = doc;
	previewDocument();
    }
   
 
}

void PagePreviewWebView::previewDocument()
{
    /* if exists doc actived so reload the QWebView */  
    if(m_activedoc){
      setHtml(m_activedoc->textDocument()->text(), m_activedoc->url());
    }
  
}


void PagePreviewWebView::previewDocumentCombo(int index)
{  
  
    m_activedoc = KDevelop::ICore::self()->documentController()->openDocuments().at(m_combobox->itemData(index).toInt());
    setHtml(m_activedoc->textDocument()->text(), m_activedoc->url());   
    reload();   
    
}

void PagePreviewWebView::timerPreview()
{
    if(!m_timer->isActive()){
      m_timer->start(1500);
    }
}





