/* Copyright (C) 2007-2025 Open Information Security Foundation
 *
 * You can copy, redistribute or modify this Program under the terms of
 * the GNU General Public License version 2 as published by the Free
 * Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include "suricata-common.h"
#include "suricata-plugin.h"

#include "decode.h"
#include "source-pcap-over-ip.h"
#include "runmode-pcap-over-ip.h"
#include "util-device.h"

void InitCapturePlugin(const char *args, int plugin_slot, int receive_slot, int decode_slot)
{
    LiveBuildDeviceList("plugin");
    RunModeIdsPcapOverIPRegister(plugin_slot);
    TmModuleReceivePcapOverIPRegister(receive_slot);
    TmModuleDecodePcapOverIPRegister(decode_slot);
}

void SCPluginInit(void)
{
    SCCapturePlugin *plugin = SCCalloc(1, sizeof(SCCapturePlugin));
    if (plugin == NULL) {
        FatalError("Failed to allocate memory for capture plugin");
    }
    plugin->name = "pcap-over-ip";
    plugin->Init = InitCapturePlugin;
    plugin->GetDefaultMode = RunModeIdsPcapOverIPGetDefaultMode;
    SCPluginRegisterCapture(plugin);
}

const SCPlugin PluginRegistration = {
    .version = SC_API_VERSION,
    .suricata_version = SC_PACKAGE_VERSION,
    .name = "pcap-over-ip",
    .plugin_version = "1.0.0",
    .author = "Open Information Security Foundation",
    .license = "GPLv2",
    .Init = SCPluginInit,
};

const SCPlugin *SCPluginRegister()
{
    return &PluginRegistration;
}
