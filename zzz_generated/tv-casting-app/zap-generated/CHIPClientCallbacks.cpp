/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include <zap-generated/CHIPClientCallbacks.h>

#include <cinttypes>

#include <app-common/zap-generated/enums.h>
#include <app/util/CHIPDeviceCallbacksMgr.h>
#include <app/util/af-enums.h>
#include <app/util/af.h>
#include <app/util/basic-types.h>
#include <lib/core/CHIPEncoding.h>
#include <lib/support/SafeInt.h>
#include <lib/support/TypeTraits.h>
#include <lib/support/logging/CHIPLogging.h>

using namespace ::chip;
using namespace ::chip::app::DataModel;

namespace {
[[maybe_unused]] constexpr uint16_t kByteSpanSizeLengthInBytes = 2;
} // namespace

#define CHECK_STATUS_WITH_RETVAL(error, retval)                                                                                    \
    if (CHIP_NO_ERROR != error)                                                                                                    \
    {                                                                                                                              \
        ChipLogError(Zcl, "CHECK_STATUS %s", ErrorStr(error));                                                                     \
        if (onFailureCallback != nullptr)                                                                                          \
        {                                                                                                                          \
            Callback::Callback<DefaultFailureCallback> * cb =                                                                      \
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);                                     \
            cb->mCall(cb->mContext, static_cast<uint8_t>(EMBER_ZCL_STATUS_INVALID_VALUE));                                         \
        }                                                                                                                          \
        return retval;                                                                                                             \
    }

#define CHECK_STATUS(error) CHECK_STATUS_WITH_RETVAL(error, true)
#define CHECK_STATUS_VOID(error) CHECK_STATUS_WITH_RETVAL(error, )

#define CHECK_MESSAGE_LENGTH_WITH_RETVAL(value, retval)                                                                            \
    if (!CanCastTo<uint16_t>(value))                                                                                               \
    {                                                                                                                              \
        ChipLogError(Zcl, "CHECK_MESSAGE_LENGTH expects a uint16_t value, got: %d", value);                                        \
        if (onFailureCallback != nullptr)                                                                                          \
        {                                                                                                                          \
            Callback::Callback<DefaultFailureCallback> * cb =                                                                      \
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);                                     \
            cb->mCall(cb->mContext, static_cast<uint8_t>(EMBER_ZCL_STATUS_INVALID_VALUE));                                         \
        }                                                                                                                          \
        return retval;                                                                                                             \
    }                                                                                                                              \
                                                                                                                                   \
    if (messageLen < value)                                                                                                        \
    {                                                                                                                              \
        ChipLogError(Zcl, "Unexpected response length: %d", messageLen);                                                           \
        if (onFailureCallback != nullptr)                                                                                          \
        {                                                                                                                          \
            Callback::Callback<DefaultFailureCallback> * cb =                                                                      \
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);                                     \
            cb->mCall(cb->mContext, static_cast<uint8_t>(EMBER_ZCL_STATUS_INVALID_VALUE));                                         \
        }                                                                                                                          \
        return retval;                                                                                                             \
    }                                                                                                                              \
                                                                                                                                   \
    messageLen = static_cast<uint16_t>(messageLen - static_cast<uint16_t>(value));

#define CHECK_MESSAGE_LENGTH(value) CHECK_MESSAGE_LENGTH_WITH_RETVAL(value, true)
#define CHECK_MESSAGE_LENGTH_VOID(value) CHECK_MESSAGE_LENGTH_WITH_RETVAL(value, )

#define GET_RESPONSE_CALLBACKS(name)                                                                                               \
    Callback::Cancelable * onSuccessCallback = nullptr;                                                                            \
    Callback::Cancelable * onFailureCallback = nullptr;                                                                            \
    NodeId sourceId                          = emberAfCurrentCommand()->SourceNodeId();                                            \
    uint8_t sequenceNumber                   = emberAfCurrentCommand()->seqNum;                                                    \
    CHIP_ERROR err = gCallbacks.GetResponseCallback(sourceId, sequenceNumber, &onSuccessCallback, &onFailureCallback);             \
                                                                                                                                   \
    if (CHIP_NO_ERROR != err)                                                                                                      \
    {                                                                                                                              \
        if (onSuccessCallback == nullptr)                                                                                          \
        {                                                                                                                          \
            ChipLogDetail(Zcl, "%s: Missing success callback", name);                                                              \
        }                                                                                                                          \
                                                                                                                                   \
        if (onFailureCallback == nullptr)                                                                                          \
        {                                                                                                                          \
            ChipLogDetail(Zcl, "%s: Missing failure callback", name);                                                              \
        }                                                                                                                          \
                                                                                                                                   \
        return true;                                                                                                               \
    }

#define GET_CLUSTER_RESPONSE_CALLBACKS(name)                                                                                       \
    Callback::Cancelable * onSuccessCallback = nullptr;                                                                            \
    Callback::Cancelable * onFailureCallback = nullptr;                                                                            \
    NodeId sourceIdentifier                  = reinterpret_cast<NodeId>(commandObj);                                               \
    /* #6559: Currently, we only have one commands for the IMInvokeCommands and to a device, so the seqNum is always set to 0. */  \
    CHIP_ERROR err = gCallbacks.GetResponseCallback(sourceIdentifier, 0, &onSuccessCallback, &onFailureCallback);                  \
                                                                                                                                   \
    if (CHIP_NO_ERROR != err)                                                                                                      \
    {                                                                                                                              \
        if (onSuccessCallback == nullptr)                                                                                          \
        {                                                                                                                          \
            ChipLogDetail(Zcl, "%s: Missing success callback", name);                                                              \
        }                                                                                                                          \
                                                                                                                                   \
        if (onFailureCallback == nullptr)                                                                                          \
        {                                                                                                                          \
            ChipLogDetail(Zcl, "%s: Missing failure callback", name);                                                              \
        }                                                                                                                          \
                                                                                                                                   \
        return true;                                                                                                               \
    }

// Singleton instance of the callbacks manager
app::CHIPDeviceCallbacksMgr & gCallbacks = app::CHIPDeviceCallbacksMgr::GetInstance();

void ApplicationLauncherClusterApplicationLauncherListListAttributeFilter(TLV::TLVReader * tlvData,
                                                                          Callback::Cancelable * onSuccessCallback,
                                                                          Callback::Cancelable * onFailureCallback)
{
    chip::app::DataModel::DecodableList<uint16_t> list;
    CHIP_ERROR err = Decode(*tlvData, list);
    if (err != CHIP_NO_ERROR)
    {
        if (onFailureCallback != nullptr)
        {
            Callback::Callback<DefaultFailureCallback> * cb =
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);
            cb->mCall(cb->mContext, EMBER_ZCL_STATUS_INVALID_VALUE);
        }
        return;
    }

    Callback::Callback<ApplicationLauncherApplicationLauncherListListAttributeCallback> * cb =
        Callback::Callback<ApplicationLauncherApplicationLauncherListListAttributeCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, list);
}

void AudioOutputClusterAudioOutputListListAttributeFilter(TLV::TLVReader * tlvData, Callback::Cancelable * onSuccessCallback,
                                                          Callback::Cancelable * onFailureCallback)
{
    chip::app::DataModel::DecodableList<chip::app::Clusters::AudioOutput::Structs::AudioOutputInfo::DecodableType> list;
    CHIP_ERROR err = Decode(*tlvData, list);
    if (err != CHIP_NO_ERROR)
    {
        if (onFailureCallback != nullptr)
        {
            Callback::Callback<DefaultFailureCallback> * cb =
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);
            cb->mCall(cb->mContext, EMBER_ZCL_STATUS_INVALID_VALUE);
        }
        return;
    }

    Callback::Callback<AudioOutputAudioOutputListListAttributeCallback> * cb =
        Callback::Callback<AudioOutputAudioOutputListListAttributeCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, list);
}

void ChannelClusterChannelListListAttributeFilter(TLV::TLVReader * tlvData, Callback::Cancelable * onSuccessCallback,
                                                  Callback::Cancelable * onFailureCallback)
{
    chip::app::DataModel::DecodableList<chip::app::Clusters::Channel::Structs::ChannelInfo::DecodableType> list;
    CHIP_ERROR err = Decode(*tlvData, list);
    if (err != CHIP_NO_ERROR)
    {
        if (onFailureCallback != nullptr)
        {
            Callback::Callback<DefaultFailureCallback> * cb =
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);
            cb->mCall(cb->mContext, EMBER_ZCL_STATUS_INVALID_VALUE);
        }
        return;
    }

    Callback::Callback<ChannelChannelListListAttributeCallback> * cb =
        Callback::Callback<ChannelChannelListListAttributeCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, list);
}

void ContentLauncherClusterAcceptHeaderListListAttributeFilter(TLV::TLVReader * tlvData, Callback::Cancelable * onSuccessCallback,
                                                               Callback::Cancelable * onFailureCallback)
{
    chip::app::DataModel::DecodableList<chip::CharSpan> list;
    CHIP_ERROR err = Decode(*tlvData, list);
    if (err != CHIP_NO_ERROR)
    {
        if (onFailureCallback != nullptr)
        {
            Callback::Callback<DefaultFailureCallback> * cb =
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);
            cb->mCall(cb->mContext, EMBER_ZCL_STATUS_INVALID_VALUE);
        }
        return;
    }

    Callback::Callback<ContentLauncherAcceptHeaderListListAttributeCallback> * cb =
        Callback::Callback<ContentLauncherAcceptHeaderListListAttributeCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, list);
}

void MediaInputClusterMediaInputListListAttributeFilter(TLV::TLVReader * tlvData, Callback::Cancelable * onSuccessCallback,
                                                        Callback::Cancelable * onFailureCallback)
{
    chip::app::DataModel::DecodableList<chip::app::Clusters::MediaInput::Structs::MediaInputInfo::DecodableType> list;
    CHIP_ERROR err = Decode(*tlvData, list);
    if (err != CHIP_NO_ERROR)
    {
        if (onFailureCallback != nullptr)
        {
            Callback::Callback<DefaultFailureCallback> * cb =
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);
            cb->mCall(cb->mContext, EMBER_ZCL_STATUS_INVALID_VALUE);
        }
        return;
    }

    Callback::Callback<MediaInputMediaInputListListAttributeCallback> * cb =
        Callback::Callback<MediaInputMediaInputListListAttributeCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, list);
}

void TargetNavigatorClusterTargetNavigatorListListAttributeFilter(TLV::TLVReader * tlvData,
                                                                  Callback::Cancelable * onSuccessCallback,
                                                                  Callback::Cancelable * onFailureCallback)
{
    chip::app::DataModel::DecodableList<chip::app::Clusters::TargetNavigator::Structs::NavigateTargetTargetInfo::DecodableType>
        list;
    CHIP_ERROR err = Decode(*tlvData, list);
    if (err != CHIP_NO_ERROR)
    {
        if (onFailureCallback != nullptr)
        {
            Callback::Callback<DefaultFailureCallback> * cb =
                Callback::Callback<DefaultFailureCallback>::FromCancelable(onFailureCallback);
            cb->mCall(cb->mContext, EMBER_ZCL_STATUS_INVALID_VALUE);
        }
        return;
    }

    Callback::Callback<TargetNavigatorTargetNavigatorListListAttributeCallback> * cb =
        Callback::Callback<TargetNavigatorTargetNavigatorListListAttributeCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, list);
}

bool emberAfAccountLoginClusterGetSetupPINResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                           chip::CharSpan setupPIN)
{
    ChipLogProgress(Zcl, "GetSetupPINResponse:");
    ChipLogProgress(Zcl, "  setupPIN: %.*s", static_cast<int>(setupPIN.size()), setupPIN.data());

    GET_CLUSTER_RESPONSE_CALLBACKS("AccountLoginClusterGetSetupPINResponseCallback");

    Callback::Callback<AccountLoginClusterGetSetupPINResponseCallback> * cb =
        Callback::Callback<AccountLoginClusterGetSetupPINResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, setupPIN);
    return true;
}

bool emberAfApplicationLauncherClusterLaunchAppResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                                uint8_t status, chip::CharSpan data)
{
    ChipLogProgress(Zcl, "LaunchAppResponse:");
    ChipLogProgress(Zcl, "  status: %" PRIu8 "", status);
    ChipLogProgress(Zcl, "  data: %.*s", static_cast<int>(data.size()), data.data());

    GET_CLUSTER_RESPONSE_CALLBACKS("ApplicationLauncherClusterLaunchAppResponseCallback");

    Callback::Callback<ApplicationLauncherClusterLaunchAppResponseCallback> * cb =
        Callback::Callback<ApplicationLauncherClusterLaunchAppResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, status, data);
    return true;
}

bool emberAfChannelClusterChangeChannelResponseCallback(
    EndpointId endpoint, app::CommandSender * commandObj,
    chip::app::Clusters::Channel::Structs::ChannelInfo::DecodableType channelMatch, uint8_t errorType)
{
    ChipLogProgress(Zcl, "ChangeChannelResponse:");
    ChipLogProgress(Zcl, "  channelMatch: Not sure how to log struct ChannelInfo");
    ChipLogProgress(Zcl, "  errorType: %" PRIu8 "", errorType);

    GET_CLUSTER_RESPONSE_CALLBACKS("ChannelClusterChangeChannelResponseCallback");

    Callback::Callback<ChannelClusterChangeChannelResponseCallback> * cb =
        Callback::Callback<ChannelClusterChangeChannelResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, ChannelInfo(), errorType);
    return true;
}

bool emberAfContentLauncherClusterLaunchContentResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                                uint8_t contentLaunchStatus, chip::CharSpan data)
{
    ChipLogProgress(Zcl, "LaunchContentResponse:");
    ChipLogProgress(Zcl, "  contentLaunchStatus: %" PRIu8 "", contentLaunchStatus);
    ChipLogProgress(Zcl, "  data: %.*s", static_cast<int>(data.size()), data.data());

    GET_CLUSTER_RESPONSE_CALLBACKS("ContentLauncherClusterLaunchContentResponseCallback");

    Callback::Callback<ContentLauncherClusterLaunchContentResponseCallback> * cb =
        Callback::Callback<ContentLauncherClusterLaunchContentResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, contentLaunchStatus, data);
    return true;
}

bool emberAfContentLauncherClusterLaunchURLResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                            uint8_t contentLaunchStatus, chip::CharSpan data)
{
    ChipLogProgress(Zcl, "LaunchURLResponse:");
    ChipLogProgress(Zcl, "  contentLaunchStatus: %" PRIu8 "", contentLaunchStatus);
    ChipLogProgress(Zcl, "  data: %.*s", static_cast<int>(data.size()), data.data());

    GET_CLUSTER_RESPONSE_CALLBACKS("ContentLauncherClusterLaunchURLResponseCallback");

    Callback::Callback<ContentLauncherClusterLaunchURLResponseCallback> * cb =
        Callback::Callback<ContentLauncherClusterLaunchURLResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, contentLaunchStatus, data);
    return true;
}

bool emberAfKeypadInputClusterSendKeyResponseCallback(EndpointId endpoint, app::CommandSender * commandObj, uint8_t status)
{
    ChipLogProgress(Zcl, "SendKeyResponse:");
    ChipLogProgress(Zcl, "  status: %" PRIu8 "", status);

    GET_CLUSTER_RESPONSE_CALLBACKS("KeypadInputClusterSendKeyResponseCallback");

    Callback::Callback<KeypadInputClusterSendKeyResponseCallback> * cb =
        Callback::Callback<KeypadInputClusterSendKeyResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, status);
    return true;
}

bool emberAfMediaPlaybackClusterMediaFastForwardResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                                 uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaFastForwardResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaFastForwardResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaFastForwardResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaFastForwardResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaNextResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                          uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaNextResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaNextResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaNextResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaNextResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaPauseResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                           uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaPauseResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaPauseResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaPauseResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaPauseResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaPlayResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                          uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaPlayResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaPlayResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaPlayResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaPlayResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaPreviousResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                              uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaPreviousResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaPreviousResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaPreviousResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaPreviousResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaRewindResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                            uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaRewindResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaRewindResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaRewindResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaRewindResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaSkipBackwardResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                                  uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaSkipBackwardResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaSkipBackwardResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaSkipBackwardResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaSkipBackwardResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaSkipForwardResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                                 uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaSkipForwardResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaSkipForwardResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaSkipForwardResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaSkipForwardResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaStartOverResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                               uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaStartOverResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaStartOverResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaStartOverResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaStartOverResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfMediaPlaybackClusterMediaStopResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                          uint8_t mediaPlaybackStatus)
{
    ChipLogProgress(Zcl, "MediaStopResponse:");
    ChipLogProgress(Zcl, "  mediaPlaybackStatus: %" PRIu8 "", mediaPlaybackStatus);

    GET_CLUSTER_RESPONSE_CALLBACKS("MediaPlaybackClusterMediaStopResponseCallback");

    Callback::Callback<MediaPlaybackClusterMediaStopResponseCallback> * cb =
        Callback::Callback<MediaPlaybackClusterMediaStopResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, mediaPlaybackStatus);
    return true;
}

bool emberAfTargetNavigatorClusterNavigateTargetResponseCallback(EndpointId endpoint, app::CommandSender * commandObj,
                                                                 uint8_t status, chip::CharSpan data)
{
    ChipLogProgress(Zcl, "NavigateTargetResponse:");
    ChipLogProgress(Zcl, "  status: %" PRIu8 "", status);
    ChipLogProgress(Zcl, "  data: %.*s", static_cast<int>(data.size()), data.data());

    GET_CLUSTER_RESPONSE_CALLBACKS("TargetNavigatorClusterNavigateTargetResponseCallback");

    Callback::Callback<TargetNavigatorClusterNavigateTargetResponseCallback> * cb =
        Callback::Callback<TargetNavigatorClusterNavigateTargetResponseCallback>::FromCancelable(onSuccessCallback);
    cb->mCall(cb->mContext, status, data);
    return true;
}
