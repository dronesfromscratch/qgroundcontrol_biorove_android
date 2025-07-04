/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 *   @brief Custom QGCCorePlugin Implementation
 *   @author Gus Grubba <gus@auterion.com>
 */

#include <QtQml>
#include <QQmlEngine>
#include <QDateTime>
#include "QGCSettings.h"
#include "MAVLinkLogManager.h"

#include "CustomPlugin.h"

#include "MultiVehicleManager.h"
#include "QGCApplication.h"
#include "SettingsManager.h"
#include "AppMessages.h"
#include "QmlComponentInfo.h"
#include "QGCPalette.h"
#include "TrajectoryPoints.h"


CustomPlugin::CustomPlugin(QGCApplication *app, QGCToolbox *toolbox) :
    QGCCorePlugin(app, toolbox)
{
    customGPSWaypointRecoder = new CustomGPSWaypointRecoder(toolbox, this);
}

CustomPlugin::~CustomPlugin()
{

}

// expose CustomGPSWaypointRecoder to QML
QQmlApplicationEngine* CustomPlugin::createQmlApplicationEngine(QObject* parent)
{
    QQmlApplicationEngine* qmlEngine = QGCCorePlugin::createQmlApplicationEngine(parent);
    qmlEngine->rootContext()->setContextProperty("CustomGPSWaypointRecoder", customGPSWaypointRecoder);
    return qmlEngine;
}
