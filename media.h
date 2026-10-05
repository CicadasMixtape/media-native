#pragma once

#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Foundation.Collections.h>

#ifndef MEDIA_H
#define MEDIA_H

using namespace winrt::Windows::Media::Control;

namespace media {
    inline GlobalSystemMediaTransportControlsSessionManager get_session_manager() {
        return GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
    }

    inline GlobalSystemMediaTransportControlsSession get_current_session() {
        const auto session_manager = get_session_manager();

        if (session_manager == nullptr) {
            return nullptr;
        }

        return session_manager.GetCurrentSession();
    }

    inline GlobalSystemMediaTransportControlsSessionMediaProperties get_current_properties() {
        const auto current_session = get_current_session();

        if (current_session == nullptr) {
            return nullptr;
        }

        return current_session.TryGetMediaPropertiesAsync().get();
    }

    inline std::string get_format() {
        const auto properties = get_current_properties();

        if (properties == nullptr) {
            return "";
        }

        std::string author = to_string(properties.Artist());
        std::string track = to_string(properties.Title());

        return std::format("{} - {}", author, track);
    }
}

#endif