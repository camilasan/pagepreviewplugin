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

#include "PagePreviewPlugin.h"
#include "PagePreviewWebView.h"
#include "PageViewFactory.h"

#include <ktrader.h>
#include <kaboutdata.h>
#include <interfaces/idocumentcontroller.h>
#include <interfaces/icore.h>
#include <interfaces/iuicontroller.h>
#include <ktexteditor/editor.h>

K_PLUGIN_FACTORY(PagePreviewFactory, registerPlugin<PagePreviewPlugin>();)
K_EXPORT_PLUGIN(PagePreviewFactory(
KAboutData("Web Page Preview", "Web Page Preview", ki18n("Web Page Preview"),
"0.1", ki18n("Integrated preview of HTML/CSS documents."),
KAboutData::License_GPL)
    .addAuthor(ki18n("Camila Ayres"), ki18n("Author"), "smayres@gmail.com",
"http://camilasan.com")
))


PagePreviewPlugin::PagePreviewPlugin(QObject* parent, const QVariantList& /*args*/)
  : IPlugin(PagePreviewFactory::componentData(), parent)
  , m_factory(new PageViewFactory(this))
{	 
    /* add toolview */
    core()->uiController()->addToolView(i18n("Web Page Preview"), m_factory);	
    qDebug() << "Web View Created.";
   
	
}

PagePreviewPlugin::~PagePreviewPlugin()
{
    /* destroy m_factory */
    delete m_factory;
}

void PagePreviewPlugin::unload()
{
    /* remove toolview */
    core()->uiController()->removeToolView(m_factory);
}


