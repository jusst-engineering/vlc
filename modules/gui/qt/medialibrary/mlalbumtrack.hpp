/*****************************************************************************
 * Copyright (C) 2019 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * ( at your option ) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#pragma once

#include <QObject>
#include <QString>
#include <memory>

#include "mlhelper.hpp"
#include "mlqmltypes.hpp"

class VLCTick;

extern "C" {
    struct vlc_medialibrary_t;
    typedef struct vlc_ml_media_t vlc_ml_media_t;
};

class MLAlbumTrack : public QObject, public MLItem
{
    Q_OBJECT

public:
    MLAlbumTrack(vlc_medialibrary_t *_ml, const vlc_ml_media_t *_data, QObject *_parent = nullptr);

    QString getTitle() const;
    QString getAlbumTitle() const;
    QString getArtist() const;
    QString getCover() const;
    unsigned int getTrackNumber() const;
    unsigned int getDiscNumber() const;
    VLCTick getDuration() const;
    QString getMRL() const;

private:
    QString m_title;
    QString m_albumTitle;
    QString m_artist;
    QString m_cover;
    unsigned int m_trackNumber;
    unsigned int m_discNumber;
    int64_t m_duration;
    QString m_mrl;

   ml_unique_ptr<vlc_ml_media_t> m_data;
};
