/******************************************************************************
 *  Copyright (c) 2016, The Linux Foundation. All rights reserved.
 *
 *  Not a contribution.
 ******************************************************************************/

/******************************************************************************
 *
 *  Copyright (C) 2009-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#ifndef BTIF_AV_CO_H
#define BTIF_AV_CO_H

#include "btif_media.h"

/*******************************************************************************
**  Constants & Macros
********************************************************************************/
/*******************************************************************************
**  Functions
********************************************************************************/

/*******************************************************************************
 **
 ** Function         bta_av_co_cp_is_active
 **
 ** Description      Get the current configuration of content protection
 **
 ** Returns          TRUE if the current streaming has CP, FALSE otherwise
 **
 *******************************************************************************/
BOOLEAN bta_av_co_cp_is_active(void);

/*******************************************************************************
 **
 ** Function         bta_av_co_cp_get_flag
 **
 ** Description      Get content protection flag
 **                  BTA_AV_CP_SCMS_COPY_NEVER
 **                  BTA_AV_CP_SCMS_COPY_ONCE
 **                  BTA_AV_CP_SCMS_COPY_FREE
 **
 ** Returns          The current flag value
 **
 *******************************************************************************/
UINT8 bta_av_co_cp_get_flag(void);

/*******************************************************************************
 **
 ** Function         bta_av_co_cp_set_flag
 **
 ** Description      Set content protection flag
 **                  BTA_AV_CP_SCMS_COPY_NEVER
 **                  BTA_AV_CP_SCMS_COPY_ONCE
 **                  BTA_AV_CP_SCMS_COPY_FREE
 **
 ** Returns          TRUE if setting the SCMS flag is supported else FALSE
 **
 *******************************************************************************/
BOOLEAN bta_av_co_cp_set_flag(UINT8 cp_flag);

/*******************************************************************************
 **
 ** Function         bta_av_co_audio_codec_reset
 **
 ** Description      Reset the current codec configuration
 **
 ** Returns          void
 **
 *******************************************************************************/
void bta_av_co_audio_codec_reset(void);

/*******************************************************************************
 **
 ** Function         bta_av_co_audio_codec_supported
 **
 ** Description      Check if all opened connections are compatible with a codec
 **                  configuration
 **
 ** Returns          TRUE if all opened devices support this codec, FALSE otherwise
 **
 *******************************************************************************/
BOOLEAN bta_av_co_audio_codec_supported(tBTIF_STATUS *p_status);

/*******************************************************************************
 **
 ** Function         bta_av_co_audio_set_codec
 **
 ** Description      Set the current codec configuration from the feeding type.
 **                  This function is starting to modify the configuration, it
 **                  should be protected.
 **
 ** Returns          TRUE if successful, FALSE otherwise
 **
 *******************************************************************************/
BOOLEAN bta_av_co_audio_set_codec(const tBTIF_AV_MEDIA_FEEDINGS *p_feeding, tBTIF_STATUS *p_status);

/*******************************************************************************
 **
 ** Function         bta_av_co_get_current_codec
 **
 ** Description      Get the current codec type.
 **
 ** Returns          Codec Type Value
 **
 *******************************************************************************/
UINT8 bta_av_co_get_current_codec();

/*******************************************************************************
 **
 ** Function         bta_av_co_get_current_codecInfo
 **
 ** Description      Get the current codec Info.
 **
 ** Returns          Returns  pointer to Info
 **
 *******************************************************************************/
UINT8* bta_av_co_get_current_codecInfo();

/*******************************************************************************
 **
 ** Function         bta_av_co_audio_get_codec_config
 **
 ** Description     Retrieves the current codec configuration.  On Failure return the default
 **                      codec configuration.
 **
 ** Returns          TRUE if codec is SBC, FALSE otherwise
 **
 *******************************************************************************/
BOOLEAN bta_av_co_audio_get_codec_config(UINT8 *p_sbc_config, UINT16 *p_minmtu, UINT8 type);
/*******************************************************************************
 **
 ** Function         bta_av_co_audio_get_sbc_config
 **
 ** Description      Retrieves the SBC codec configuration.  If the codec in use
 **                  is not SBC, return the default SBC codec configuration.
 **
 ** Returns          TRUE if codec is SBC, FALSE otherwise
 **
 *******************************************************************************/
BOOLEAN bta_av_co_audio_get_sbc_config(tA2D_SBC_CIE *p_sbc_config, UINT16 *p_minmtu);
#if defined(AAC_ENCODER_INCLUDED) && (AAC_ENCODER_INCLUDED == TRUE)
/*******************************************************************************
 **
 ** Function         bta_av_co_audio_get_aac_config
 **
 ** Description      Retrieves the AAC codec configuration.  If the codec in use
 **                  is not AAC, return the default SBC codec configuration.
 **
 ** Returns          TRUE if codec is AAC, FALSE otherwise
 **
 *******************************************************************************/
BOOLEAN bta_av_co_audio_get_aac_config(tA2D_AAC_CIE *p_aac_config, UINT16 *p_minmtu);
#endif


/*******************************************************************************
 **
 ** Function         bta_av_co_audio_discard_config
 **
 ** Description      Discard the codec configuration of a connection
 **
 ** Returns          Nothing
 **
 *******************************************************************************/
void bta_av_co_audio_discard_config(tBTA_AV_HNDL hndl);

/*******************************************************************************
 **
 ** Function         bta_av_co_init
 **
 ** Description      Initialization
 **
 ** Returns          Nothing
 **
 *******************************************************************************/
void bta_av_co_init(void);


/*******************************************************************************
 **
 ** Function         bta_av_co_peer_cp_supported
 **
 ** Description      Checks if the peer supports CP
 **
 ** Returns          TRUE if the peer supports CP
 **
 *******************************************************************************/
BOOLEAN bta_av_co_peer_cp_supported(tBTA_AV_HNDL hndl);

/*******************************************************************************
 **
 ** Function         bta_av_co_get_remote_bitpool_pref
 **
 ** Description      Check if remote side did a setconfig within the limits
 **                  of our exported bitpool range. If set we will set the
 **                  remote preference.
 **
 ** Returns          TRUE if config set, FALSE otherwize
 **
 *******************************************************************************/
BOOLEAN bta_av_co_get_remote_bitpool_pref(UINT8 *min, UINT8 *max);

/*******************************************************************************
 **
 ** Function         bta_av_select_codec
 **
 ** Description      Select the current codec for the remote device selected
 **                  for streaming.
 **
 ** Returns          Return current codec id
 **
 *******************************************************************************/
UINT8 bta_av_select_codec(tBTA_AV_HNDL hdl);

/*******************************************************************************
 **
 ** Function         bta_av_co_audio_is_aac_enabled
 **
 ** Description      Compares the given BD address family against the interop databse
 **                  and return if AAC can be selected as a codec for streaming or not
 **
 ** Returns          TRUE if AAC is allowed , FALSE otherwise
 **
 *******************************************************************************/
BOOLEAN bta_av_co_audio_is_aac_enabled(bt_bdaddr_t *remote_bdaddr);

#endif
