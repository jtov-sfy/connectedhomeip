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

#pragma once

#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app/InteractionModelEngine.h>
#include <app/data-model/DecodableList.h>
#include <app/util/af-enums.h>
#include <app/util/attribute-filter.h>
#include <app/util/im-client-callbacks.h>
#include <inttypes.h>
#include <lib/support/FunctionTraits.h>
#include <lib/support/Span.h>

// Note: The IMDefaultResponseCallback is a bridge to the old CallbackMgr before IM is landed, so it still accepts EmberAfStatus
// instead of IM status code.
// #6308 should handle IM error code on the application side, either modify this function or remove this.

// Cluster Specific Response Callbacks
typedef void (*AccountLoginClusterGetSetupPINResponseCallback)(void * context, chip::CharSpan setupPIN);
typedef void (*ApplicationLauncherClusterLaunchAppResponseCallback)(void * context, uint8_t status, chip::CharSpan data);
typedef void (*ChannelClusterChangeChannelResponseCallback)(void * context, ChannelInfo channelMatch, uint8_t errorType);
typedef void (*ContentLauncherClusterLaunchContentResponseCallback)(void * context, uint8_t contentLaunchStatus,
                                                                    chip::CharSpan data);
typedef void (*ContentLauncherClusterLaunchURLResponseCallback)(void * context, uint8_t contentLaunchStatus, chip::CharSpan data);
typedef void (*KeypadInputClusterSendKeyResponseCallback)(void * context, uint8_t status);
typedef void (*MediaPlaybackClusterMediaFastForwardResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaNextResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaPauseResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaPlayResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaPreviousResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaRewindResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaSkipBackwardResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaSkipForwardResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaStartOverResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaStopResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*TargetNavigatorClusterNavigateTargetResponseCallback)(void * context, uint8_t status, chip::CharSpan data);

// List specific responses
void ApplicationLauncherClusterApplicationLauncherListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*ApplicationLauncherApplicationLauncherListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<uint16_t> & data);
void AudioOutputClusterAudioOutputListListAttributeFilter(chip::TLV::TLVReader * data,
                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*AudioOutputAudioOutputListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::AudioOutput::Structs::AudioOutputInfo::DecodableType> & data);
void ChannelClusterChannelListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                  chip::Callback::Cancelable * onFailureCallback);
typedef void (*ChannelChannelListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::Channel::Structs::ChannelInfo::DecodableType> & data);
void ContentLauncherClusterAcceptHeaderListListAttributeFilter(chip::TLV::TLVReader * data,
                                                               chip::Callback::Cancelable * onSuccessCallback,
                                                               chip::Callback::Cancelable * onFailureCallback);
typedef void (*ContentLauncherAcceptHeaderListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CharSpan> & data);
void MediaInputClusterMediaInputListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*MediaInputMediaInputListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::MediaInput::Structs::MediaInputInfo::DecodableType> & data);
void TargetNavigatorClusterTargetNavigatorListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                  chip::Callback::Cancelable * onSuccessCallback,
                                                                  chip::Callback::Cancelable * onFailureCallback);
typedef void (*TargetNavigatorTargetNavigatorListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::TargetNavigator::Structs::NavigateTargetTargetInfo::DecodableType> & data);
