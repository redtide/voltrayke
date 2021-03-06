/*
    VolTrayke - Volume tray widget.
    Copyright (C) 2021  Andrea Zanellato <redtid3@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

    SPDX-License-Identifier: GPL-2.0-only
*/
#pragma once

#include "settings.hpp"

#include <QApplication>
#include <QSystemTrayIcon>

class AudioDevice;
class AudioEngine;

class QAction;

namespace azd {

class DialogAbout;
class DialogPrefs;
class MenuVolume;

class VolTrayke : public QApplication {
    Q_OBJECT

public:
    VolTrayke(int&, char**);
    ~VolTrayke();

    Settings& settings() { return settings_; }

private:
    void runMixer();
    void updateTrayIcon();

    void onAboutToQuit();
    void onAudioEngineChanged(int);
    void onAudioDeviceChanged(int);
    void onAudioDeviceListChanged();
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason);

    QAction* actAutoStart_;
    QSystemTrayIcon* trayIcon_;
    DialogAbout* dlgAbout_;
    DialogPrefs* dlgPrefs_;
    MenuVolume* mnuVolume_;
    Settings settings_;
    AudioEngine* engine_;
    AudioDevice* channel_;
};
} // namespace azd
