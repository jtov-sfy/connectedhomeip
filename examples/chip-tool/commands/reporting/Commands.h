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

#include "ReportingCommand.h"

typedef void (*UnsupportedAttributeCallback)(void * context);

class Listen : public ReportingCommand
{
public:
    Listen() : ReportingCommand("listen") {}

    ~Listen()
    {
        delete onReportColorControlCurrentHueCallback;
        delete onReportColorControlCurrentSaturationCallback;
        delete onReportColorControlCurrentXCallback;
        delete onReportColorControlCurrentYCallback;
        delete onReportColorControlColorTemperatureCallback;
        delete onReportDoorLockLockStateCallback;
        delete onReportLevelControlCurrentLevelCallback;
        delete onReportOnOffOnOffCallback;
        delete onReportTemperatureMeasurementMeasuredValueCallback;
        delete onReportThermostatLocalTemperatureCallback;
    }

    void AddReportCallbacks(uint8_t endpointId) override
    {
        chip::app::CHIPDeviceCallbacksMgr & callbacksMgr = chip::app::CHIPDeviceCallbacksMgr::GetInstance();
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0300, 0x0000,
                                       onReportColorControlCurrentHueCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0300, 0x0001,
                                       onReportColorControlCurrentSaturationCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0300, 0x0003,
                                       onReportColorControlCurrentXCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0300, 0x0004,
                                       onReportColorControlCurrentYCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0300, 0x0007,
                                       onReportColorControlColorTemperatureCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0101, 0x0000,
                                       onReportDoorLockLockStateCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0008, 0x0000,
                                       onReportLevelControlCurrentLevelCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0006, 0x0000, onReportOnOffOnOffCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0402, 0x0000,
                                       onReportTemperatureMeasurementMeasuredValueCallback->Cancel());
        callbacksMgr.AddReportCallback(chip::kTestDeviceNodeId, endpointId, 0x0201, 0x0000,
                                       onReportThermostatLocalTemperatureCallback->Cancel());
    }

    static void OnDefaultSuccessResponse(void * context) { ChipLogProgress(chipTool, "Default Success Response"); }

    static void OnDefaultFailureResponse(void * context, uint8_t status)
    {
        ChipLogProgress(chipTool, "Default Failure Response: 0x%02x", status);
    }

    static void OnUnsupportedAttributeResponse(void * context)
    {
        ChipLogError(chipTool, "Unsupported attribute Response. This should never happen !");
    }

    static void OnBooleanAttributeResponse(void * context, bool value)
    {
        ChipLogProgress(chipTool, "Boolean attribute Response: %d", value);
    }

    static void OnInt8uAttributeResponse(void * context, uint8_t value)
    {
        ChipLogProgress(chipTool, "Int8u attribute Response: %" PRIu8, value);
    }

    static void OnInt16uAttributeResponse(void * context, uint16_t value)
    {
        ChipLogProgress(chipTool, "Int16u attribute Response: %" PRIu16, value);
    }

    static void OnInt16sAttributeResponse(void * context, int16_t value)
    {
        ChipLogProgress(chipTool, "Int16s attribute Response: %" PRId16, value);
    }

private:
    chip::Callback::Callback<Int8uAttributeCallback> * onReportColorControlCurrentHueCallback =
        new chip::Callback::Callback<Int8uAttributeCallback>(OnInt8uAttributeResponse, this);
    chip::Callback::Callback<Int8uAttributeCallback> * onReportColorControlCurrentSaturationCallback =
        new chip::Callback::Callback<Int8uAttributeCallback>(OnInt8uAttributeResponse, this);
    chip::Callback::Callback<Int16uAttributeCallback> * onReportColorControlCurrentXCallback =
        new chip::Callback::Callback<Int16uAttributeCallback>(OnInt16uAttributeResponse, this);
    chip::Callback::Callback<Int16uAttributeCallback> * onReportColorControlCurrentYCallback =
        new chip::Callback::Callback<Int16uAttributeCallback>(OnInt16uAttributeResponse, this);
    chip::Callback::Callback<Int16uAttributeCallback> * onReportColorControlColorTemperatureCallback =
        new chip::Callback::Callback<Int16uAttributeCallback>(OnInt16uAttributeResponse, this);
    chip::Callback::Callback<Int8uAttributeCallback> * onReportDoorLockLockStateCallback =
        new chip::Callback::Callback<Int8uAttributeCallback>(OnInt8uAttributeResponse, this);
    chip::Callback::Callback<Int8uAttributeCallback> * onReportLevelControlCurrentLevelCallback =
        new chip::Callback::Callback<Int8uAttributeCallback>(OnInt8uAttributeResponse, this);
    chip::Callback::Callback<BooleanAttributeCallback> * onReportOnOffOnOffCallback =
        new chip::Callback::Callback<BooleanAttributeCallback>(OnBooleanAttributeResponse, this);
    chip::Callback::Callback<Int16sAttributeCallback> * onReportTemperatureMeasurementMeasuredValueCallback =
        new chip::Callback::Callback<Int16sAttributeCallback>(OnInt16sAttributeResponse, this);
    chip::Callback::Callback<Int16sAttributeCallback> * onReportThermostatLocalTemperatureCallback =
        new chip::Callback::Callback<Int16sAttributeCallback>(OnInt16sAttributeResponse, this);
};

void registerCommandsReporting(Commands & commands)
{
    const char * clusterName = "Reporting";

    commands_list clusterCommands = {
        make_unique<Listen>(),
    };

    commands.Register(clusterName, clusterCommands);
}
