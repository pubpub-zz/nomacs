/*******************************************************************************************************
 nomacs is a fast and small image viewer with the capability of synchronizing multiple instances
 
 Copyright (C) 2011-2016 Markus Diem <markus@nomacs.org>
 Copyright (C) 2011-2016 Stefan Fiel <stefan@nomacs.org>
 Copyright (C) 2011-2016 Florian Kleber <florian@nomacs.org>

 This file is part of nomacs.

 nomacs is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 nomacs is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 related links:
 [1] http://www.nomacs.org/
 [2] https://github.com/nomacs/
 [3] http://download.nomacs.org
 *******************************************************************************************************/

#pragma once

#include "DkBaseWidgets.h"
#include "DkImageContainer.h"

#pragma warning(push, 0)	// no warnings from includes

#pragma warning(pop)

#ifndef DllExport
#ifdef DK_DLL_EXPORT
#define DllExport Q_DECL_EXPORT
#elif DK_DLL_IMPORT
#define DllExport Q_DECL_IMPORT
#else
#define DllExport Q_DECL_IMPORT
#endif
#endif

// Qt defines

namespace nmc {

// nomacs defines

class DkManipulatorWidget : public DkWidget {
	Q_OBJECT

public:
	DkManipulatorWidget(QWidget* parent = 0);

	void setImage(QSharedPointer<DkImageContainerT> imgC);

public slots:
	void selectManipulator();

private:
	void createLayout();

	QSharedPointer<DkImageContainerT> mImgC;
	QWidget* mSettingsWidget = 0;
	QLabel* mPreview = 0;
};

class DkEditDock : public DkDockWidget {
	Q_OBJECT

public:
	DkEditDock(const QString& title, QWidget* parent = 0, Qt::WindowFlags flags = 0);

public slots:
	void setImage(QSharedPointer<DkImageContainerT> imgC);

protected:
	void createLayout();

	//void writeSettings();
	//void readSettings();

	DkManipulatorWidget* mMplWidget = 0;
};

}