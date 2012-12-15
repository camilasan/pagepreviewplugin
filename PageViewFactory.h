<<<<<<< HEAD

=======
>>>>>>> f17b96fa42f73da230075d8e776e924d96b950a5
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


#ifndef PAGEVIEWFACTORY_H
#define PAGEVIEWFACTORY_H

#include <QWidget>
#include <interfaces/iuicontroller.h>
#include "PagePreviewWebView.h"

using namespace KDevelop;

class PagePreviewPlugin;

class PageViewFactory: public KDevelop::IToolViewFactory{
  
  public:
    PageViewFactory(PagePreviewPlugin *plugin){}

    virtual QWidget* create(QWidget *parent = 0)
    {
      PagePreviewWebView *view = new PagePreviewWebView(parent);
      view->show();
      return view;
    }

    virtual QString id() const
    {
      return "org.kdevelop.PagePreviewPlugin";
    }

    virtual Qt::DockWidgetArea defaultPosition()
    {
      return Qt::LeftDockWidgetArea;
    }

};


#endif // PAGEVIEWFACTORY_H
