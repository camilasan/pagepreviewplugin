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
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#ifndef PAGEPREVIEWWEBVIEW_H
#define PAGEPREVIEWWEBVIEW_H

#include <QObject>
#include <QComboBox>
#include <QVariantList>
#include <QWebView>
#include <kurl.h>
#include <kparts/mainwindow.h>
#include <ktextedit.h>
#include <ktexteditor/document.h>
#include <interfaces/idocument.h>
#include <QTimer>

class PagePreviewWebView : public QWebView
{
      Q_OBJECT
      public:
	PagePreviewWebView(QWidget* parent = 0);
	      
      private slots:		
	void previewDocument();
	void setDocument(KDevelop::IDocument* doc);
	void previewDocumentCombo(int index);
	void timerPreview();
	
      private:
	QComboBox *m_combobox;
	QString *m_qurl;
	KUrl *m_kurl; 
	KDevelop::IDocument *m_activedoc; 
	QTimer *m_timer;
	
};


#endif // PAGEPREVIEWWEBVIEW_h
