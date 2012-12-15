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


#ifndef PAGEPPREVIEWPLUGIN_H
#define PAGEPPREVIEWPLUGIN_H

#include <QObject>
#include <kpluginfactory.h>
#include <kparts/mainwindow.h>
#include <ktextedit.h>
#include <ktexteditor/document.h>
#include <interfaces/idocument.h>
#include <interfaces/iplugin.h>

class PageViewFactory;

class PagePreviewPlugin : public KDevelop::IPlugin
{
      Q_OBJECT
      public:
	PagePreviewPlugin(QObject* parent, const QVariantList &args);
	virtual ~PagePreviewPlugin();	
	virtual void unload();
   
      private:
	PageViewFactory* m_factory;
	      
};

#endif // PAGEPPREVIEWPLUGIN_H
