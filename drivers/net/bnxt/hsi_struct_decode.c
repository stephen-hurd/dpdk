/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2014-2015 Broadcom Corporation.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Broadcom Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HSI_INFO
#include <inttypes.h>
#include <rte_common.h>
#include <rte_log.h>
#include "hsi_struct_def_dpdk.h"
#include "hsi_struct_decode.h"
#include "hsi_struct_decode.h"

void decode_bd_base(const char *string __rte_unused, struct bd_base *data) {
	RTE_LOG(INFO, PMD, "bd_base\n");
	RTE_LOG(INFO, PMD, "         type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		(data->type & BD_BASE_TYPE_MASK) == BD_BASE_TYPE_SFT ? "SFT" :
		(data->type & BD_BASE_TYPE_MASK) == BD_BASE_TYPE_TX_BD_SHORT ? "TX_BD_SHORT" :
		(data->type & BD_BASE_TYPE_MASK) == BD_BASE_TYPE_TX_BD_EMPTY ? "TX_BD_EMPTY" :
		(data->type & BD_BASE_TYPE_MASK) == BD_BASE_TYPE_RX_PROD_PKT ? "RX_PROD_PKT" :
		(data->type & BD_BASE_TYPE_MASK) == BD_BASE_TYPE_RX_PROD_BFR ? "RX_PROD_BFR" :
		(data->type & BD_BASE_TYPE_MASK) == BD_BASE_TYPE_RX_PROD_AGG ? "RX_PROD_AGG" :
		(data->type & BD_BASE_TYPE_MASK) == BD_BASE_TYPE_TX_BD_LONG ? "TX_BD_LONG" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_1[0] = 0x%02"PRIX8"\n", data->unused_1[0]);
	RTE_LOG(INFO, PMD, "  unused_1[1] = 0x%02"PRIX8"\n", data->unused_1[1]);
	RTE_LOG(INFO, PMD, "  unused_1[2] = 0x%02"PRIX8"\n", data->unused_1[2]);
	RTE_LOG(INFO, PMD, "  unused_1[3] = 0x%02"PRIX8"\n", data->unused_1[3]);
	RTE_LOG(INFO, PMD, "  unused_1[4] = 0x%02"PRIX8"\n", data->unused_1[4]);
	RTE_LOG(INFO, PMD, "  unused_1[5] = 0x%02"PRIX8"\n", data->unused_1[5]);
	RTE_LOG(INFO, PMD, "  unused_1[6] = 0x%02"PRIX8"\n", data->unused_1[6]);
}

void decode_tx_bd_short(const char *string __rte_unused, struct tx_bd_short *data) {
	RTE_LOG(INFO, PMD, "tx_bd_short\n");
	RTE_LOG(INFO, PMD, "  flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "               BD_CNT = %0*X\n", 12, ((data->flags_type & TX_BD_SHORT_FLAGS_BD_CNT_MASK) >> TX_BD_SHORT_FLAGS_BD_CNT_SFT));
	RTE_LOG(INFO, PMD, "               LHINT = %0*X\n", 11, ((data->flags_type & TX_BD_SHORT_FLAGS_LHINT_MASK) >> TX_BD_SHORT_FLAGS_LHINT_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_PACKET_END ? "PACKET_END" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_NO_CMPL ? "NO_CMPL" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_LHINT_LT512 ? "LHINT_LT512" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_LHINT_LT1K ? "LHINT_LT1K" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_LHINT_LT2K ? "LHINT_LT2K" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_LHINT_GTE2K ? "LHINT_GTE2K" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_LHINT_LAST ? "LHINT_LAST" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_COAL_NOW ? "COAL_NOW" :
		(data->flags_type & TX_BD_SHORT_FLAGS_MASK) == TX_BD_SHORT_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "      opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "        addr = 0x%016"PRIX64"\n", data->addr);
}

void decode_tx_bd_long(const char *string __rte_unused, struct tx_bd_long *data) {
	RTE_LOG(INFO, PMD, "tx_bd_long\n");
	RTE_LOG(INFO, PMD, "  flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "               BD_CNT = %0*X\n", 12, ((data->flags_type & TX_BD_LONG_FLAGS_BD_CNT_MASK) >> TX_BD_LONG_FLAGS_BD_CNT_SFT));
	RTE_LOG(INFO, PMD, "               LHINT = %0*X\n", 11, ((data->flags_type & TX_BD_LONG_FLAGS_LHINT_MASK) >> TX_BD_LONG_FLAGS_LHINT_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_PACKET_END ? "PACKET_END" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_NO_CMPL ? "NO_CMPL" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_LHINT_LT512 ? "LHINT_LT512" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_LHINT_LT1K ? "LHINT_LT1K" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_LHINT_LT2K ? "LHINT_LT2K" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_LHINT_GTE2K ? "LHINT_GTE2K" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_LHINT_LAST ? "LHINT_LAST" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_COAL_NOW ? "COAL_NOW" :
		(data->flags_type & TX_BD_LONG_FLAGS_MASK) == TX_BD_LONG_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "      opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "        addr = 0x%016"PRIX64"\n", data->addr);
}

void decode_tx_bd_long_hi(const char *string __rte_unused, struct tx_bd_long_hi *data) {
	RTE_LOG(INFO, PMD, "tx_bd_long_hi\n");
	RTE_LOG(INFO, PMD, "      lflags = 0x%04"PRIX16"\n", data->lflags);
	RTE_LOG(INFO, PMD, "               TCP_UDP_CHKSUM : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_TCP_UDP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               IP_CHKSUM : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_IP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               NOCRC : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_NOCRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               STAMP : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_STAMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               T_IP_CHKSUM : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_T_IP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               LSO : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_LSO)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               IPID_FMT : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_IPID_FMT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               T_IPID : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_T_IPID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               ROCE_CRC : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_ROCE_CRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               FCOE_CRC : %s\n", (data->lflags & TX_BD_LONG_LFLAGS_FCOE_CRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    hdr_size = 0x%04"PRIX16"\n", data->hdr_size);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->hdr_size & TX_BD_LONG_HDR_SIZE_MASK) == TX_BD_LONG_HDR_SIZE_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         mss = 0x%08"PRIX32"\n", data->mss);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->mss & TX_BD_LONG_MSS_MASK) == TX_BD_LONG_MSS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%04"PRIX16"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "  cfa_action = 0x%04"PRIX16"\n", data->cfa_action);
	RTE_LOG(INFO, PMD, "    cfa_meta = 0x%08"PRIX32"\n", data->cfa_meta);
	RTE_LOG(INFO, PMD, "               VLAN_VID = %0*X\n", 13, ((data->cfa_meta & TX_BD_LONG_CFA_META_VLAN_VID_MASK) >> TX_BD_LONG_CFA_META_VLAN_VID_SFT));
	RTE_LOG(INFO, PMD, "               VLAN_PRI = %0*X\n", 11, ((data->cfa_meta & TX_BD_LONG_CFA_META_VLAN_PRI_MASK) >> TX_BD_LONG_CFA_META_VLAN_PRI_SFT));
	RTE_LOG(INFO, PMD, "               VLAN_TPID = %0*X\n", 11, ((data->cfa_meta & TX_BD_LONG_CFA_META_VLAN_TPID_MASK) >> TX_BD_LONG_CFA_META_VLAN_TPID_SFT));
	RTE_LOG(INFO, PMD, "               VLAN_RESERVED = %0*X\n", 13, ((data->cfa_meta & TX_BD_LONG_CFA_META_VLAN_RESERVED_MASK) >> TX_BD_LONG_CFA_META_VLAN_RESERVED_SFT));
	RTE_LOG(INFO, PMD, "               KEY = %0*X\n", 11, ((data->cfa_meta & TX_BD_LONG_CFA_META_KEY_MASK) >> TX_BD_LONG_CFA_META_KEY_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_DE ? "VLAN_DE" :
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_TPID_TPID88A8 ? "VLAN_TPID_TPID88A8" :
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_TPID_TPID8100 ? "VLAN_TPID_TPID8100" :
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_TPID_TPID9100 ? "VLAN_TPID_TPID9100" :
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_TPID_TPID9200 ? "VLAN_TPID_TPID9200" :
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_TPID_TPID9300 ? "VLAN_TPID_TPID9300" :
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_TPID_TPIDCFG ? "VLAN_TPID_TPIDCFG" :
		data->cfa_meta == TX_BD_LONG_CFA_META_VLAN_TPID_LAST ? "VLAN_TPID_LAST" :
		data->cfa_meta == TX_BD_LONG_CFA_META_KEY_NONE ? "KEY_NONE" :
		data->cfa_meta == TX_BD_LONG_CFA_META_KEY_VLAN_TAG ? "KEY_VLAN_TAG" :
		data->cfa_meta == TX_BD_LONG_CFA_META_KEY_LAST ? "KEY_LAST" :
		"Unknown");
}

void decode_tx_bd_empty(const char *string __rte_unused, struct tx_bd_empty *data) {
	RTE_LOG(INFO, PMD, "tx_bd_empty\n");
	RTE_LOG(INFO, PMD, "         type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		(data->type & TX_BD_EMPTY_TYPE_MASK) == TX_BD_EMPTY_TYPE_SFT ? "SFT" :
		(data->type & TX_BD_EMPTY_TYPE_MASK) == TX_BD_EMPTY_TYPE_TX_BD_EMPTY ? "TX_BD_EMPTY" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_1[0] = 0x%02"PRIX8"\n", data->unused_1[0]);
	RTE_LOG(INFO, PMD, "  unused_1[1] = 0x%02"PRIX8"\n", data->unused_1[1]);
	RTE_LOG(INFO, PMD, "  unused_1[2] = 0x%02"PRIX8"\n", data->unused_1[2]);
	RTE_LOG(INFO, PMD, "     unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "  unused_3[0] = 0x%02"PRIX8"\n", data->unused_3[0]);
	RTE_LOG(INFO, PMD, "  unused_3[1] = 0x%02"PRIX8"\n", data->unused_3[1]);
	RTE_LOG(INFO, PMD, "  unused_3[2] = 0x%02"PRIX8"\n", data->unused_3[2]);
	RTE_LOG(INFO, PMD, "     unused_4 = 0x%016"PRIX64"\n", data->unused_4);
}

void decode_rx_prod_pkt_bd(const char *string __rte_unused, struct rx_prod_pkt_bd *data) {
	RTE_LOG(INFO, PMD, "rx_prod_pkt_bd\n");
	RTE_LOG(INFO, PMD, "  flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "               BUFFERS = %0*X\n", 11, ((data->flags_type & RX_PROD_PKT_BD_FLAGS_BUFFERS_MASK) >> RX_PROD_PKT_BD_FLAGS_BUFFERS_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->flags_type & RX_PROD_PKT_BD_FLAGS_MASK) == RX_PROD_PKT_BD_FLAGS_SOP_PAD ? "SOP_PAD" :
		(data->flags_type & RX_PROD_PKT_BD_FLAGS_MASK) == RX_PROD_PKT_BD_FLAGS_EOP_PAD ? "EOP_PAD" :
		(data->flags_type & RX_PROD_PKT_BD_FLAGS_MASK) == RX_PROD_PKT_BD_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "      opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "        addr = 0x%016"PRIX64"\n", data->addr);
}

void decode_rx_prod_bfr_bd(const char *string __rte_unused, struct rx_prod_bfr_bd *data) {
	RTE_LOG(INFO, PMD, "rx_prod_bfr_bd\n");
	RTE_LOG(INFO, PMD, "  flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->flags_type & RX_PROD_BFR_BD_FLAGS_MASK) == RX_PROD_BFR_BD_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "      opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "        addr = 0x%016"PRIX64"\n", data->addr);
}

void decode_rx_prod_agg_bd(const char *string __rte_unused, struct rx_prod_agg_bd *data) {
	RTE_LOG(INFO, PMD, "rx_prod_agg_bd\n");
	RTE_LOG(INFO, PMD, "  flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->flags_type & RX_PROD_AGG_BD_FLAGS_MASK) == RX_PROD_AGG_BD_FLAGS_EOP_PAD ? "EOP_PAD" :
		(data->flags_type & RX_PROD_AGG_BD_FLAGS_MASK) == RX_PROD_AGG_BD_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "      opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "        addr = 0x%016"PRIX64"\n", data->addr);
}

void decode_cmpl_base(const char *string __rte_unused, struct cmpl_base *data) {
	RTE_LOG(INFO, PMD, "cmpl_base\n");
	RTE_LOG(INFO, PMD, "     type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "            Value : %s\n",
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_SFT ? "SFT" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_TX_L2 ? "TX_L2" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_RX_L2 ? "RX_L2" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_RX_AGG ? "RX_AGG" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_RX_TPA_START ? "RX_TPA_START" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_RX_TPA_END ? "RX_TPA_END" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_STAT_EJECT ? "STAT_EJECT" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_HWRM_DONE ? "HWRM_DONE" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_HWRM_FWD_REQ ? "HWRM_FWD_REQ" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_HWRM_FWD_RESP ? "HWRM_FWD_RESP" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_CQ_NOTIFICATION ? "CQ_NOTIFICATION" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_SRQ_EVENT ? "SRQ_EVENT" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_DBQ_EVENT ? "DBQ_EVENT" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_QP_EVENT ? "QP_EVENT" :
		(data->type & CMPL_BASE_TYPE_MASK) == CMPL_BASE_TYPE_FUNC_EVENT ? "FUNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    info1 = 0x%04"PRIX16"\n", data->info1);
	RTE_LOG(INFO, PMD, "    info2 = 0x%08"PRIX32"\n", data->info2);
	RTE_LOG(INFO, PMD, "  info3_v = 0x%08"PRIX32"\n", data->info3_v);
	RTE_LOG(INFO, PMD, "    info4 = 0x%08"PRIX32"\n", data->info4);
}

void decode_tx_cmpl(const char *string __rte_unused, struct tx_cmpl *data) {
	RTE_LOG(INFO, PMD, "tx_cmpl\n");
	RTE_LOG(INFO, PMD, "  flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->flags_type & TX_CMPL_FLAGS_MASK) == TX_CMPL_FLAGS_ERROR ? "ERROR" :
		(data->flags_type & TX_CMPL_FLAGS_MASK) == TX_CMPL_FLAGS_PUSH ? "PUSH" :
		(data->flags_type & TX_CMPL_FLAGS_MASK) == TX_CMPL_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%04"PRIX16"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "    errors_v = 0x%04"PRIX16"\n", data->errors_v);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%08"PRIX32"\n", data->unused_2);
}

void decode_rx_pkt_cmpl(const char *string __rte_unused, struct rx_pkt_cmpl *data) {
	RTE_LOG(INFO, PMD, "rx_pkt_cmpl\n");
	RTE_LOG(INFO, PMD, "      flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "                   PLACEMENT = %0*X\n", 12, ((data->flags_type & RX_PKT_CMPL_FLAGS_PLACEMENT_MASK) >> RX_PKT_CMPL_FLAGS_PLACEMENT_SFT));
	RTE_LOG(INFO, PMD, "                   ITYPE = %0*X\n", 11, ((data->flags_type & RX_PKT_CMPL_FLAGS_ITYPE_MASK) >> RX_PKT_CMPL_FLAGS_ITYPE_SFT));
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ERROR ? "ERROR" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_PLACEMENT_NORMAL ? "PLACEMENT_NORMAL" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_PLACEMENT_JUMBO ? "PLACEMENT_JUMBO" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_PLACEMENT_HDS ? "PLACEMENT_HDS" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_PLACEMENT_LAST ? "PLACEMENT_LAST" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_RSS_VALID ? "RSS_VALID" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_UNUSED ? "UNUSED" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_NOT_KNOWN ? "ITYPE_NOT_KNOWN" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_IP ? "ITYPE_IP" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_TCP ? "ITYPE_TCP" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_UDP ? "ITYPE_UDP" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_FCOE ? "ITYPE_FCOE" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_ROCE ? "ITYPE_ROCE" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_ICMP ? "ITYPE_ICMP" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_PTP_WO_TIMESTAMP ? "ITYPE_PTP_WO_TIMESTAMP" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_PTP_W_TIMESTAMP ? "ITYPE_PTP_W_TIMESTAMP" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_ITYPE_LAST ? "ITYPE_LAST" :
		(data->flags_type & RX_PKT_CMPL_FLAGS_MASK) == RX_PKT_CMPL_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "          opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "     agg_bufs_v1 = 0x%02"PRIX8"\n", data->agg_bufs_v1);
	RTE_LOG(INFO, PMD, "   rss_hash_type = 0x%02"PRIX8"\n", data->rss_hash_type);
	RTE_LOG(INFO, PMD, "  payload_offset = 0x%02"PRIX8"\n", data->payload_offset);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        rss_hash = 0x%08"PRIX32"\n", data->rss_hash);
}

void decode_rx_pkt_cmpl_hi(const char *string __rte_unused, struct rx_pkt_cmpl_hi *data) {
	RTE_LOG(INFO, PMD, "rx_pkt_cmpl_hi\n");
	RTE_LOG(INFO, PMD, "     flags2 = 0x%08"PRIX32"\n", data->flags2);
	RTE_LOG(INFO, PMD, "              META_FORMAT = %0*X\n", 11, ((data->flags2 & RX_PKT_CMPL_FLAGS2_META_FORMAT_MASK) >> RX_PKT_CMPL_FLAGS2_META_FORMAT_SFT));
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->flags2 == RX_PKT_CMPL_FLAGS2_IP_CS_CALC ? "IP_CS_CALC" :
		data->flags2 == RX_PKT_CMPL_FLAGS2_L4_CS_CALC ? "L4_CS_CALC" :
		data->flags2 == RX_PKT_CMPL_FLAGS2_T_IP_CS_CALC ? "T_IP_CS_CALC" :
		data->flags2 == RX_PKT_CMPL_FLAGS2_T_L4_CS_CALC ? "T_L4_CS_CALC" :
		data->flags2 == RX_PKT_CMPL_FLAGS2_META_FORMAT_NONE ? "META_FORMAT_NONE" :
		data->flags2 == RX_PKT_CMPL_FLAGS2_META_FORMAT_VLAN ? "META_FORMAT_VLAN" :
		data->flags2 == RX_PKT_CMPL_FLAGS2_META_FORMAT_LAST ? "META_FORMAT_LAST" :
		data->flags2 == RX_PKT_CMPL_FLAGS2_IP_TYPE ? "IP_TYPE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   metadata = 0x%08"PRIX32"\n", data->metadata);
	RTE_LOG(INFO, PMD, "              VID = %0*X\n", 13, ((data->metadata & RX_PKT_CMPL_METADATA_VID_MASK) >> RX_PKT_CMPL_METADATA_VID_SFT));
	RTE_LOG(INFO, PMD, "              PRI = %0*X\n", 11, ((data->metadata & RX_PKT_CMPL_METADATA_PRI_MASK) >> RX_PKT_CMPL_METADATA_PRI_SFT));
	RTE_LOG(INFO, PMD, "              TPID = %0*X\n", 14, ((data->metadata & RX_PKT_CMPL_METADATA_TPID_MASK) >> RX_PKT_CMPL_METADATA_TPID_SFT));
	RTE_LOG(INFO, PMD, "              DE : %s\n", (data->metadata & RX_PKT_CMPL_METADATA_DE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  errors_v2 = 0x%04"PRIX16"\n", data->errors_v2);
	RTE_LOG(INFO, PMD, "   cfa_code = 0x%04"PRIX16"\n", data->cfa_code);
	RTE_LOG(INFO, PMD, "    reorder = 0x%08"PRIX32"\n", data->reorder);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		(data->reorder & RX_PKT_CMPL_REORDER_MASK) == RX_PKT_CMPL_REORDER_SFT ? "SFT" :
		"Unknown");
}

void decode_rx_tpa_start_cmpl(const char *string __rte_unused, struct rx_tpa_start_cmpl *data) {
	RTE_LOG(INFO, PMD, "rx_tpa_start_cmpl\n");
	RTE_LOG(INFO, PMD, "     flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "                  PLACEMENT = %0*X\n", 12, ((data->flags_type & RX_TPA_START_CMPL_FLAGS_PLACEMENT_MASK) >> RX_TPA_START_CMPL_FLAGS_PLACEMENT_SFT));
	RTE_LOG(INFO, PMD, "                  ITYPE = %0*X\n", 11, ((data->flags_type & RX_TPA_START_CMPL_FLAGS_ITYPE_MASK) >> RX_TPA_START_CMPL_FLAGS_ITYPE_SFT));
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_ERROR ? "ERROR" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_PLACEMENT_JUMBO ? "PLACEMENT_JUMBO" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_PLACEMENT_HDS ? "PLACEMENT_HDS" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_PLACEMENT_GRO_JUMBO ? "PLACEMENT_GRO_JUMBO" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_PLACEMENT_GRO_HDS ? "PLACEMENT_GRO_HDS" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_PLACEMENT_LAST ? "PLACEMENT_LAST" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_RSS_VALID ? "RSS_VALID" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_UNUSED ? "UNUSED" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_ITYPE_TCP ? "ITYPE_TCP" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_ITYPE_LAST ? "ITYPE_LAST" :
		(data->flags_type & RX_TPA_START_CMPL_FLAGS_MASK) == RX_TPA_START_CMPL_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "         opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "             v1 = 0x%02"PRIX8"\n", data->v1);
	RTE_LOG(INFO, PMD, "  rss_hash_type = 0x%02"PRIX8"\n", data->rss_hash_type);
	RTE_LOG(INFO, PMD, "         agg_id = 0x%04"PRIX16"\n", data->agg_id);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->agg_id & RX_TPA_START_CMPL_AGG_ID_MASK) == RX_TPA_START_CMPL_AGG_ID_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       rss_hash = 0x%08"PRIX32"\n", data->rss_hash);
}

void decode_rx_tpa_start_cmpl_hi(const char *string __rte_unused, struct rx_tpa_start_cmpl_hi *data) {
	RTE_LOG(INFO, PMD, "rx_tpa_start_cmpl_hi\n");
	RTE_LOG(INFO, PMD, "                                                         flags2 = 0x%08"PRIX32"\n", data->flags2);
	RTE_LOG(INFO, PMD, "                                                                  META_FORMAT = %0*X\n", 11, ((data->flags2 & RX_TPA_START_CMPL_FLAGS2_META_FORMAT_MASK) >> RX_TPA_START_CMPL_FLAGS2_META_FORMAT_SFT));
	RTE_LOG(INFO, PMD, "                                                                  Value : %s\n",
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_IP_CS_CALC ? "IP_CS_CALC" :
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_L4_CS_CALC ? "L4_CS_CALC" :
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_T_IP_CS_CALC ? "T_IP_CS_CALC" :
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_T_L4_CS_CALC ? "T_L4_CS_CALC" :
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_META_FORMAT_NONE ? "META_FORMAT_NONE" :
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_META_FORMAT_VLAN ? "META_FORMAT_VLAN" :
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_META_FORMAT_LAST ? "META_FORMAT_LAST" :
		data->flags2 == RX_TPA_START_CMPL_FLAGS2_IP_TYPE ? "IP_TYPE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                                                       metadata = 0x%08"PRIX32"\n", data->metadata);
	RTE_LOG(INFO, PMD, "                                                                  VID = %0*X\n", 13, ((data->metadata & RX_TPA_START_CMPL_METADATA_VID_MASK) >> RX_TPA_START_CMPL_METADATA_VID_SFT));
	RTE_LOG(INFO, PMD, "                                                                  PRI = %0*X\n", 11, ((data->metadata & RX_TPA_START_CMPL_METADATA_PRI_MASK) >> RX_TPA_START_CMPL_METADATA_PRI_SFT));
	RTE_LOG(INFO, PMD, "                                                                  TPID = %0*X\n", 14, ((data->metadata & RX_TPA_START_CMPL_METADATA_TPID_MASK) >> RX_TPA_START_CMPL_METADATA_TPID_SFT));
	RTE_LOG(INFO, PMD, "                                                                  DE : %s\n", (data->metadata & RX_TPA_START_CMPL_METADATA_DE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                                             v2 = 0x%04"PRIX16"\n", data->v2);
	RTE_LOG(INFO, PMD, "                                                       cfa_code = 0x%04"PRIX16"\n", data->cfa_code);
	RTE_LOG(INFO, PMD, "  inner_l4_size_inner_l3_offset_inner_l2_offset_outer_l3_offset = 0x%08"PRIX32"\n", data->inner_l4_size_inner_l3_offset_inner_l2_offset_outer_l3_offset);
}

void decode_rx_tpa_end_cmpl(const char *string __rte_unused, struct rx_tpa_end_cmpl *data) {
	RTE_LOG(INFO, PMD, "rx_tpa_end_cmpl\n");
	RTE_LOG(INFO, PMD, "      flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "                   PLACEMENT = %0*X\n", 12, ((data->flags_type & RX_TPA_END_CMPL_FLAGS_PLACEMENT_MASK) >> RX_TPA_END_CMPL_FLAGS_PLACEMENT_SFT));
	RTE_LOG(INFO, PMD, "                   UNUSED = %0*X\n", 11, ((data->flags_type & RX_TPA_END_CMPL_FLAGS_UNUSED_MASK) >> RX_TPA_END_CMPL_FLAGS_UNUSED_SFT));
	RTE_LOG(INFO, PMD, "                   ITYPE = %0*X\n", 11, ((data->flags_type & RX_TPA_END_CMPL_FLAGS_ITYPE_MASK) >> RX_TPA_END_CMPL_FLAGS_ITYPE_SFT));
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		(data->flags_type & RX_TPA_END_CMPL_FLAGS_MASK) == RX_TPA_END_CMPL_FLAGS_ERROR ? "ERROR" :
		(data->flags_type & RX_TPA_END_CMPL_FLAGS_MASK) == RX_TPA_END_CMPL_FLAGS_PLACEMENT_JUMBO ? "PLACEMENT_JUMBO" :
		(data->flags_type & RX_TPA_END_CMPL_FLAGS_MASK) == RX_TPA_END_CMPL_FLAGS_PLACEMENT_HDS ? "PLACEMENT_HDS" :
		(data->flags_type & RX_TPA_END_CMPL_FLAGS_MASK) == RX_TPA_END_CMPL_FLAGS_PLACEMENT_GRO_JUMBO ? "PLACEMENT_GRO_JUMBO" :
		(data->flags_type & RX_TPA_END_CMPL_FLAGS_MASK) == RX_TPA_END_CMPL_FLAGS_PLACEMENT_GRO_HDS ? "PLACEMENT_GRO_HDS" :
		(data->flags_type & RX_TPA_END_CMPL_FLAGS_MASK) == RX_TPA_END_CMPL_FLAGS_PLACEMENT_LAST ? "PLACEMENT_LAST" :
		(data->flags_type & RX_TPA_END_CMPL_FLAGS_MASK) == RX_TPA_END_CMPL_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "          opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "     agg_bufs_v1 = 0x%02"PRIX8"\n", data->agg_bufs_v1);
	RTE_LOG(INFO, PMD, "        tpa_segs = 0x%02"PRIX8"\n", data->tpa_segs);
	RTE_LOG(INFO, PMD, "  payload_offset = 0x%02"PRIX8"\n", data->payload_offset);
	RTE_LOG(INFO, PMD, "          agg_id = 0x%02"PRIX8"\n", data->agg_id);
	RTE_LOG(INFO, PMD, "                   SFT : %s\n", (data->agg_id & RX_TPA_END_CMPL_AGG_ID_SFT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         tsdelta = 0x%08"PRIX32"\n", data->tsdelta);
}

void decode_rx_tpa_end_cmpl_hi(const char *string __rte_unused, struct rx_tpa_end_cmpl_hi *data) {
	RTE_LOG(INFO, PMD, "rx_tpa_end_cmpl_hi\n");
	RTE_LOG(INFO, PMD, "  tpa_dup_acks = 0x%08"PRIX32"\n", data->tpa_dup_acks);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->tpa_dup_acks & RX_TPA_END_CMPL_TPA_DUP_ACKS_MASK) == RX_TPA_END_CMPL_TPA_DUP_ACKS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   tpa_seg_len = 0x%04"PRIX16"\n", data->tpa_seg_len);
	RTE_LOG(INFO, PMD, "      unused_3 = 0x%04"PRIX16"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "     errors_v2 = 0x%04"PRIX16"\n", data->errors_v2);
	RTE_LOG(INFO, PMD, "      unused_4 = 0x%04"PRIX16"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "  start_opaque = 0x%08"PRIX32"\n", data->start_opaque);
}

void decode_rx_abuf_cmpl(const char *string __rte_unused, struct rx_abuf_cmpl *data) {
	RTE_LOG(INFO, PMD, "rx_abuf_cmpl\n");
	RTE_LOG(INFO, PMD, "      type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "             Value : %s\n",
		(data->type & RX_ABUF_CMPL_TYPE_MASK) == RX_ABUF_CMPL_TYPE_SFT ? "SFT" :
		(data->type & RX_ABUF_CMPL_TYPE_MASK) == RX_ABUF_CMPL_TYPE_RX_AGG ? "RX_AGG" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "    opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "         v = 0x%08"PRIX32"\n", data->v);
	RTE_LOG(INFO, PMD, "  unused_2 = 0x%08"PRIX32"\n", data->unused_2);
}

void decode_eject_cmpl(const char *string __rte_unused, struct eject_cmpl *data) {
	RTE_LOG(INFO, PMD, "eject_cmpl\n");
	RTE_LOG(INFO, PMD, "      type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "             Value : %s\n",
		(data->type & EJECT_CMPL_TYPE_MASK) == EJECT_CMPL_TYPE_SFT ? "SFT" :
		(data->type & EJECT_CMPL_TYPE_MASK) == EJECT_CMPL_TYPE_STAT_EJECT ? "STAT_EJECT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "    opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "         v = 0x%08"PRIX32"\n", data->v);
	RTE_LOG(INFO, PMD, "  unused_2 = 0x%08"PRIX32"\n", data->unused_2);
}

void decode_hwrm_cmpl(const char *string __rte_unused, struct hwrm_cmpl *data) {
	RTE_LOG(INFO, PMD, "hwrm_cmpl\n");
	RTE_LOG(INFO, PMD, "         type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		(data->type & HWRM_CMPL_TYPE_MASK) == HWRM_CMPL_TYPE_SFT ? "SFT" :
		(data->type & HWRM_CMPL_TYPE_MASK) == HWRM_CMPL_TYPE_HWRM_DONE ? "HWRM_DONE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  sequence_id = 0x%04"PRIX16"\n", data->sequence_id);
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%08"PRIX32"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "            v = 0x%08"PRIX32"\n", data->v);
	RTE_LOG(INFO, PMD, "     unused_3 = 0x%08"PRIX32"\n", data->unused_3);
}

void decode_hwrm_fwd_req_cmpl(const char *string __rte_unused, struct hwrm_fwd_req_cmpl *data) {
	RTE_LOG(INFO, PMD, "hwrm_fwd_req_cmpl\n");
	RTE_LOG(INFO, PMD, "    req_len_type = 0x%04"PRIX16"\n", data->req_len_type);
	RTE_LOG(INFO, PMD, "       source_id = 0x%04"PRIX16"\n", data->source_id);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  req_buf_addr_v = 0x%016"PRIX64"\n", data->req_buf_addr_v);
}

void decode_hwrm_fwd_resp_cmpl(const char *string __rte_unused, struct hwrm_fwd_resp_cmpl *data) {
	RTE_LOG(INFO, PMD, "hwrm_fwd_resp_cmpl\n");
	RTE_LOG(INFO, PMD, "             type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		(data->type & HWRM_FWD_RESP_CMPL_TYPE_MASK) == HWRM_FWD_RESP_CMPL_TYPE_SFT ? "SFT" :
		(data->type & HWRM_FWD_RESP_CMPL_TYPE_MASK) == HWRM_FWD_RESP_CMPL_TYPE_HWRM_FWD_RESP ? "HWRM_FWD_RESP" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        source_id = 0x%04"PRIX16"\n", data->source_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "  resp_buf_addr_v = 0x%016"PRIX64"\n", data->resp_buf_addr_v);
}

void decode_hwrm_async_event_cmpl(const char *string __rte_unused, struct hwrm_async_event_cmpl *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_LINK_STATUS_CHANGE ? "LINK_STATUS_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_LINK_MTU_CHANGE ? "LINK_MTU_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_LINK_SPEED_CHANGE ? "LINK_SPEED_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_DCB_CONFIG_CHANGE ? "DCB_CONFIG_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_PORT_CONN_NOT_ALLOWED ? "PORT_CONN_NOT_ALLOWED" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_LINK_SPEED_CFG_NOT_ALLOWED ? "LINK_SPEED_CFG_NOT_ALLOWED" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_LINK_SPEED_CFG_CHANGE ? "LINK_SPEED_CFG_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_PORT_PHY_CFG_CHANGE ? "PORT_PHY_CFG_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_FUNC_DRVR_UNLOAD ? "FUNC_DRVR_UNLOAD" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_FUNC_DRVR_LOAD ? "FUNC_DRVR_LOAD" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_FUNC_FLR_PROC_CMPLT ? "FUNC_FLR_PROC_CMPLT" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_PF_DRVR_UNLOAD ? "PF_DRVR_UNLOAD" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_PF_DRVR_LOAD ? "PF_DRVR_LOAD" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_VF_FLR ? "VF_FLR" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_VF_MAC_ADDR_CHANGE ? "VF_MAC_ADDR_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_PF_VF_COMM_STATUS_CHANGE ? "PF_VF_COMM_STATUS_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_VF_CFG_CHANGE ? "VF_CFG_CHANGE" :
		data->event_id == HWRM_ASYNC_EVENT_CMPL_EVENT_ID_HWRM_ERROR ? "HWRM_ERROR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
}

void decode_hwrm_async_event_cmpl_link_status_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_status_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_link_status_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_ID_LINK_STATUS_CHANGE ? "LINK_STATUS_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 PORT = %0*X\n", 11, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_PORT_MASK) >> HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_PORT_SFT));
	RTE_LOG(INFO, PMD, "                 PORT_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_PORT_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_PORT_ID_SFT));
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_LINK_CHANGE ? "LINK_CHANGE" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_LINK_CHANGE_DOWN ? "LINK_CHANGE_DOWN" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_LINK_CHANGE_UP ? "LINK_CHANGE_UP" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_STATUS_CHANGE_EVENT_DATA1_LINK_CHANGE_LAST ? "LINK_CHANGE_LAST" :
		"Unknown");
}

void decode_hwrm_async_event_cmpl_link_mtu_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_mtu_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_link_mtu_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_MTU_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_MTU_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_MTU_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_MTU_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 LINK_MTU_CHANGE : %s\n", (data->event_id & HWRM_ASYNC_EVENT_CMPL_LINK_MTU_CHANGE_EVENT_ID_LINK_MTU_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 NEW_MTU = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_MTU_CHANGE_EVENT_DATA1_NEW_MTU_MASK) >> HWRM_ASYNC_EVENT_CMPL_LINK_MTU_CHANGE_EVENT_DATA1_NEW_MTU_SFT));
}

void decode_hwrm_async_event_cmpl_link_speed_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_speed_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_link_speed_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 LINK_SPEED_CHANGE : %s\n", (data->event_id & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_ID_LINK_SPEED_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 NEW_LINK_SPEED_100MBPS = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_MASK) >> HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_SFT));
	RTE_LOG(INFO, PMD, "                 PORT_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_PORT_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_PORT_ID_SFT));
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_FORCE ? "FORCE" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_100MB ? "NEW_LINK_SPEED_100MBPS_100MB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_1GB ? "NEW_LINK_SPEED_100MBPS_1GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_2GB ? "NEW_LINK_SPEED_100MBPS_2GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_2_5GB ? "NEW_LINK_SPEED_100MBPS_2_5GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_10GB ? "NEW_LINK_SPEED_100MBPS_10GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_20GB ? "NEW_LINK_SPEED_100MBPS_20GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_25GB ? "NEW_LINK_SPEED_100MBPS_25GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_40GB ? "NEW_LINK_SPEED_100MBPS_40GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_50GB ? "NEW_LINK_SPEED_100MBPS_50GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_100GB ? "NEW_LINK_SPEED_100MBPS_100GB" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CHANGE_EVENT_DATA1_NEW_LINK_SPEED_100MBPS_LAST ? "NEW_LINK_SPEED_100MBPS_LAST" :
		"Unknown");
}

void decode_hwrm_async_event_cmpl_dcb_config_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_dcb_config_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_dcb_config_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_ID_DCB_CONFIG_CHANGE ? "DCB_CONFIG_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "                 ETS : %s\n", (data->event_data2 & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA2_ETS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 PFC : %s\n", (data->event_data2 & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA2_PFC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 APP : %s\n", (data->event_data2 & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA2_APP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 PORT_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_PORT_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_PORT_ID_SFT));
	RTE_LOG(INFO, PMD, "                 RECOMMEND_ROCE_PRIORITY = %0*X\n", 12, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_ROCE_PRIORITY_MASK) >> HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_ROCE_PRIORITY_SFT));
	RTE_LOG(INFO, PMD, "                 RECOMMEND_L2_PRIORITY = %0*X\n", 12, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_L2_PRIORITY_MASK) >> HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_L2_PRIORITY_SFT));
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_ROCE_PRIORITY_NONE ? "RECOMMEND_ROCE_PRIORITY_NONE" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_ROCE_PRIORITY_LAST ? "RECOMMEND_ROCE_PRIORITY_LAST" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_L2_PRIORITY_NONE ? "RECOMMEND_L2_PRIORITY_NONE" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_DCB_CONFIG_CHANGE_EVENT_DATA1_RECOMMEND_L2_PRIORITY_LAST ? "RECOMMEND_L2_PRIORITY_LAST" :
		"Unknown");
}

void decode_hwrm_async_event_cmpl_port_conn_not_allowed(const char *string __rte_unused, struct hwrm_async_event_cmpl_port_conn_not_allowed *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_port_conn_not_allowed\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 PORT_CONN_NOT_ALLOWED : %s\n", (data->event_id & HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_ID_PORT_CONN_NOT_ALLOWED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 PORT_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_PORT_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_PORT_ID_SFT));
	RTE_LOG(INFO, PMD, "                 ENFORCEMENT_POLICY = %0*X\n", 12, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_ENFORCEMENT_POLICY_MASK) >> HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_ENFORCEMENT_POLICY_SFT));
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_ENFORCEMENT_POLICY_NONE ? "ENFORCEMENT_POLICY_NONE" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_ENFORCEMENT_POLICY_DISABLETX ? "ENFORCEMENT_POLICY_DISABLETX" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_ENFORCEMENT_POLICY_WARNINGMSG ? "ENFORCEMENT_POLICY_WARNINGMSG" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_ENFORCEMENT_POLICY_PWRDOWN ? "ENFORCEMENT_POLICY_PWRDOWN" :
		data->event_data1 == HWRM_ASYNC_EVENT_CMPL_PORT_CONN_NOT_ALLOWED_EVENT_DATA1_ENFORCEMENT_POLICY_LAST ? "ENFORCEMENT_POLICY_LAST" :
		"Unknown");
}

void decode_hwrm_async_event_cmpl_link_speed_cfg_not_allowed(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_speed_cfg_not_allowed *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_link_speed_cfg_not_allowed\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_NOT_ALLOWED_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_NOT_ALLOWED_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_NOT_ALLOWED_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_NOT_ALLOWED_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_NOT_ALLOWED_EVENT_ID_LINK_SPEED_CFG_NOT_ALLOWED ? "LINK_SPEED_CFG_NOT_ALLOWED" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 PORT_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_NOT_ALLOWED_EVENT_DATA1_PORT_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_NOT_ALLOWED_EVENT_DATA1_PORT_ID_SFT));
}

void decode_hwrm_async_event_cmpl_link_speed_cfg_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_speed_cfg_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_link_speed_cfg_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_EVENT_ID_LINK_SPEED_CFG_CHANGE ? "LINK_SPEED_CFG_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 PORT_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_EVENT_DATA1_PORT_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_EVENT_DATA1_PORT_ID_SFT));
	RTE_LOG(INFO, PMD, "                 SUPPORTED_LINK_SPEEDS_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_EVENT_DATA1_SUPPORTED_LINK_SPEEDS_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 ILLEGAL_LINK_SPEED_CFG : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_LINK_SPEED_CFG_CHANGE_EVENT_DATA1_ILLEGAL_LINK_SPEED_CFG)?"ON":"OFF");
}

void decode_hwrm_async_event_cmpl_port_phy_cfg_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_port_phy_cfg_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_port_phy_cfg_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_EVENT_ID_PORT_PHY_CFG_CHANGE ? "PORT_PHY_CFG_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 PORT_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_EVENT_DATA1_PORT_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_EVENT_DATA1_PORT_ID_SFT));
	RTE_LOG(INFO, PMD, "                 FEC_CFG_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_EVENT_DATA1_FEC_CFG_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 EEE_CFG_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_EVENT_DATA1_EEE_CFG_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 PAUSE_CFG_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PORT_PHY_CFG_CHANGE_EVENT_DATA1_PAUSE_CFG_CHANGE)?"ON":"OFF");
}

void decode_hwrm_async_event_cmpl_func_drvr_unload(const char *string __rte_unused, struct hwrm_async_event_cmpl_func_drvr_unload *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_func_drvr_unload\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_UNLOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_UNLOAD_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_UNLOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_UNLOAD_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 FUNC_DRVR_UNLOAD : %s\n", (data->event_id & HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_UNLOAD_EVENT_ID_FUNC_DRVR_UNLOAD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 FUNC_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_UNLOAD_EVENT_DATA1_FUNC_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_UNLOAD_EVENT_DATA1_FUNC_ID_SFT));
}

void decode_hwrm_async_event_cmpl_func_drvr_load(const char *string __rte_unused, struct hwrm_async_event_cmpl_func_drvr_load *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_func_drvr_load\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_LOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_LOAD_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_LOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_LOAD_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_LOAD_EVENT_ID_FUNC_DRVR_LOAD ? "FUNC_DRVR_LOAD" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 FUNC_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_LOAD_EVENT_DATA1_FUNC_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_FUNC_DRVR_LOAD_EVENT_DATA1_FUNC_ID_SFT));
}

void decode_hwrm_async_event_cmpl_func_flr_proc_cmplt(const char *string __rte_unused, struct hwrm_async_event_cmpl_func_flr_proc_cmplt *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_func_flr_proc_cmplt\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_FUNC_FLR_PROC_CMPLT_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_FUNC_FLR_PROC_CMPLT_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_FUNC_FLR_PROC_CMPLT_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_FUNC_FLR_PROC_CMPLT_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_FUNC_FLR_PROC_CMPLT_EVENT_ID_FUNC_FLR_PROC_CMPLT ? "FUNC_FLR_PROC_CMPLT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 FUNC_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_FUNC_FLR_PROC_CMPLT_EVENT_DATA1_FUNC_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_FUNC_FLR_PROC_CMPLT_EVENT_DATA1_FUNC_ID_SFT));
}

void decode_hwrm_async_event_cmpl_pf_drvr_unload(const char *string __rte_unused, struct hwrm_async_event_cmpl_pf_drvr_unload *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_pf_drvr_unload\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 PF_DRVR_UNLOAD : %s\n", (data->event_id & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_EVENT_ID_PF_DRVR_UNLOAD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 FUNC_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_EVENT_DATA1_FUNC_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_EVENT_DATA1_FUNC_ID_SFT));
	RTE_LOG(INFO, PMD, "                 PORT = %0*X\n", 11, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_EVENT_DATA1_PORT_MASK) >> HWRM_ASYNC_EVENT_CMPL_PF_DRVR_UNLOAD_EVENT_DATA1_PORT_SFT));
}

void decode_hwrm_async_event_cmpl_pf_drvr_load(const char *string __rte_unused, struct hwrm_async_event_cmpl_pf_drvr_load *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_pf_drvr_load\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_EVENT_ID_PF_DRVR_LOAD ? "PF_DRVR_LOAD" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 FUNC_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_EVENT_DATA1_FUNC_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_EVENT_DATA1_FUNC_ID_SFT));
	RTE_LOG(INFO, PMD, "                 PORT = %0*X\n", 11, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_EVENT_DATA1_PORT_MASK) >> HWRM_ASYNC_EVENT_CMPL_PF_DRVR_LOAD_EVENT_DATA1_PORT_SFT));
}

void decode_hwrm_async_event_cmpl_vf_flr(const char *string __rte_unused, struct hwrm_async_event_cmpl_vf_flr *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_vf_flr\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_VF_FLR_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_VF_FLR_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_VF_FLR_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_VF_FLR_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_VF_FLR_EVENT_ID_VF_FLR ? "VF_FLR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 VF_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_VF_FLR_EVENT_DATA1_VF_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_VF_FLR_EVENT_DATA1_VF_ID_SFT));
}

void decode_hwrm_async_event_cmpl_vf_mac_addr_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_vf_mac_addr_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_vf_mac_addr_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_VF_MAC_ADDR_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_VF_MAC_ADDR_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_VF_MAC_ADDR_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_VF_MAC_ADDR_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_VF_MAC_ADDR_CHANGE_EVENT_ID_VF_MAC_ADDR_CHANGE ? "VF_MAC_ADDR_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 VF_ID = %0*X\n", 14, ((data->event_data1 & HWRM_ASYNC_EVENT_CMPL_VF_MAC_ADDR_CHANGE_EVENT_DATA1_VF_ID_MASK) >> HWRM_ASYNC_EVENT_CMPL_VF_MAC_ADDR_CHANGE_EVENT_DATA1_VF_ID_SFT));
}

void decode_hwrm_async_event_cmpl_pf_vf_comm_status_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_pf_vf_comm_status_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_pf_vf_comm_status_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_PF_VF_COMM_STATUS_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PF_VF_COMM_STATUS_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_PF_VF_COMM_STATUS_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_PF_VF_COMM_STATUS_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_PF_VF_COMM_STATUS_CHANGE_EVENT_ID_PF_VF_COMM_STATUS_CHANGE ? "PF_VF_COMM_STATUS_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 COMM_ESTABLISHED : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_PF_VF_COMM_STATUS_CHANGE_EVENT_DATA1_COMM_ESTABLISHED)?"ON":"OFF");
}

void decode_hwrm_async_event_cmpl_vf_cfg_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_vf_cfg_change *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_vf_cfg_change\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_EVENT_ID_VF_CFG_CHANGE ? "VF_CFG_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 MTU_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_EVENT_DATA1_MTU_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 MRU_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_EVENT_DATA1_MRU_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 DFLT_MAC_ADDR_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_EVENT_DATA1_DFLT_MAC_ADDR_CHANGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 DFLT_VLAN_CHANGE : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_VF_CFG_CHANGE_EVENT_DATA1_DFLT_VLAN_CHANGE)?"ON":"OFF");
}

void decode_hwrm_async_event_cmpl_hwrm_error(const char *string __rte_unused, struct hwrm_async_event_cmpl_hwrm_error *data) {
	RTE_LOG(INFO, PMD, "hwrm_async_event_cmpl_hwrm_error\n");
	RTE_LOG(INFO, PMD, "          type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		(data->type & HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_TYPE_SFT ? "SFT" :
		(data->type & HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_TYPE_MASK) == HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_TYPE_HWRM_ASYNC_EVENT ? "HWRM_ASYNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      event_id = 0x%04"PRIX16"\n", data->event_id);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_id == HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_ID_HWRM_ERROR ? "HWRM_ERROR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "                 SEVERITY = %0*X\n", 12, ((data->event_data2 & HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_DATA2_SEVERITY_MASK) >> HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_DATA2_SEVERITY_SFT));
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->event_data2 == HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_DATA2_SEVERITY_WARNING ? "SEVERITY_WARNING" :
		data->event_data2 == HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_DATA2_SEVERITY_NONFATAL ? "SEVERITY_NONFATAL" :
		data->event_data2 == HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_DATA2_SEVERITY_FATAL ? "SEVERITY_FATAL" :
		data->event_data2 == HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_DATA2_SEVERITY_LAST ? "SEVERITY_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      opaque_v = 0x%02"PRIX8"\n", data->opaque_v);
	RTE_LOG(INFO, PMD, "  timestamp_lo = 0x%02"PRIX8"\n", data->timestamp_lo);
	RTE_LOG(INFO, PMD, "  timestamp_hi = 0x%04"PRIX16"\n", data->timestamp_hi);
	RTE_LOG(INFO, PMD, "   event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "                 TIMESTAMP : %s\n", (data->event_data1 & HWRM_ASYNC_EVENT_CMPL_HWRM_ERROR_EVENT_DATA1_TIMESTAMP)?"ON":"OFF");
}

void decode_tx_doorbell(const char *string __rte_unused, struct tx_doorbell *data) {
	RTE_LOG(INFO, PMD, "tx_doorbell\n");
	RTE_LOG(INFO, PMD, "  key_idx = 0x%08"PRIX32"\n", data->key_idx);
}

void decode_rx_doorbell(const char *string __rte_unused, struct rx_doorbell *data) {
	RTE_LOG(INFO, PMD, "rx_doorbell\n");
	RTE_LOG(INFO, PMD, "  key_idx = 0x%08"PRIX32"\n", data->key_idx);
}

void decode_cmpl_doorbell(const char *string __rte_unused, struct cmpl_doorbell *data) {
	RTE_LOG(INFO, PMD, "cmpl_doorbell\n");
	RTE_LOG(INFO, PMD, "  key_mask_valid_idx = 0x%08"PRIX32"\n", data->key_mask_valid_idx);
}

void decode_status_doorbell(const char *string __rte_unused, struct status_doorbell *data) {
	RTE_LOG(INFO, PMD, "status_doorbell\n");
	RTE_LOG(INFO, PMD, "  key_idx = 0x%08"PRIX32"\n", data->key_idx);
}

void decode_push32_doorbell(const char *string __rte_unused, struct push32_doorbell *data) {
	RTE_LOG(INFO, PMD, "push32_doorbell\n");
	RTE_LOG(INFO, PMD, "  key_sz_idx = 0x%08"PRIX32"\n", data->key_sz_idx);
	RTE_LOG(INFO, PMD, "  flags_type = 0x%04"PRIX16"\n", data->flags_type);
	RTE_LOG(INFO, PMD, "               BD_CNT = %0*X\n", 12, ((data->flags_type & PUSH32_DOORBELL_FLAGS_BD_CNT_MASK) >> PUSH32_DOORBELL_FLAGS_BD_CNT_SFT));
	RTE_LOG(INFO, PMD, "               LHINT = %0*X\n", 11, ((data->flags_type & PUSH32_DOORBELL_FLAGS_LHINT_MASK) >> PUSH32_DOORBELL_FLAGS_LHINT_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_PACKET_END ? "PACKET_END" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_NO_CMPL ? "NO_CMPL" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_LHINT_LT512 ? "LHINT_LT512" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_LHINT_LT1K ? "LHINT_LT1K" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_LHINT_LT2K ? "LHINT_LT2K" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_LHINT_GTE2K ? "LHINT_GTE2K" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_LHINT_LAST ? "LHINT_LAST" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_COAL_NOW ? "COAL_NOW" :
		(data->flags_type & PUSH32_DOORBELL_FLAGS_MASK) == PUSH32_DOORBELL_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "      opaque = 0x%08"PRIX32"\n", data->opaque);
	RTE_LOG(INFO, PMD, "      lflags = 0x%04"PRIX16"\n", data->lflags);
	RTE_LOG(INFO, PMD, "               TCP_UDP_CHKSUM : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_TCP_UDP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               IP_CHKSUM : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_IP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               NOCRC : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_NOCRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               STAMP : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_STAMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               T_IP_CHKSUM : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_T_IP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               LSO : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_LSO)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               IPID_FMT : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_IPID_FMT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               T_IPID : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_T_IPID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               ROCE_CRC : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_ROCE_CRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               FCOE_CRC : %s\n", (data->lflags & PUSH32_DOORBELL_LFLAGS_FCOE_CRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    hdr_size = 0x%04"PRIX16"\n", data->hdr_size);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->hdr_size & PUSH32_DOORBELL_HDR_SIZE_MASK) == PUSH32_DOORBELL_HDR_SIZE_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         mss = 0x%08"PRIX32"\n", data->mss);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->mss & PUSH32_DOORBELL_MSS_MASK) == PUSH32_DOORBELL_MSS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%04"PRIX16"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "  cfa_action = 0x%04"PRIX16"\n", data->cfa_action);
	RTE_LOG(INFO, PMD, "    cfa_meta = 0x%08"PRIX32"\n", data->cfa_meta);
	RTE_LOG(INFO, PMD, "               VLAN_VID = %0*X\n", 13, ((data->cfa_meta & PUSH32_DOORBELL_CFA_META_VLAN_VID_MASK) >> PUSH32_DOORBELL_CFA_META_VLAN_VID_SFT));
	RTE_LOG(INFO, PMD, "               VLAN_PRI = %0*X\n", 11, ((data->cfa_meta & PUSH32_DOORBELL_CFA_META_VLAN_PRI_MASK) >> PUSH32_DOORBELL_CFA_META_VLAN_PRI_SFT));
	RTE_LOG(INFO, PMD, "               VLAN_TPID = %0*X\n", 11, ((data->cfa_meta & PUSH32_DOORBELL_CFA_META_VLAN_TPID_MASK) >> PUSH32_DOORBELL_CFA_META_VLAN_TPID_SFT));
	RTE_LOG(INFO, PMD, "               VLAN_RESERVED = %0*X\n", 13, ((data->cfa_meta & PUSH32_DOORBELL_CFA_META_VLAN_RESERVED_MASK) >> PUSH32_DOORBELL_CFA_META_VLAN_RESERVED_SFT));
	RTE_LOG(INFO, PMD, "               KEY = %0*X\n", 11, ((data->cfa_meta & PUSH32_DOORBELL_CFA_META_KEY_MASK) >> PUSH32_DOORBELL_CFA_META_KEY_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_DE ? "VLAN_DE" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_TPID_TPID88A8 ? "VLAN_TPID_TPID88A8" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_TPID_TPID8100 ? "VLAN_TPID_TPID8100" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_TPID_TPID9100 ? "VLAN_TPID_TPID9100" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_TPID_TPID9200 ? "VLAN_TPID_TPID9200" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_TPID_TPID9300 ? "VLAN_TPID_TPID9300" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_TPID_TPIDCFG ? "VLAN_TPID_TPIDCFG" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_VLAN_TPID_LAST ? "VLAN_TPID_LAST" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_KEY_NONE ? "KEY_NONE" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_KEY_VLAN_TAG ? "KEY_VLAN_TAG" :
		data->cfa_meta == PUSH32_DOORBELL_CFA_META_KEY_LAST ? "KEY_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "     data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "     data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "     data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "     data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "     data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "     data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "     data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "     data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "     data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "    data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "    data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "    data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "    data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "    data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "    data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "    data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "    data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "    data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "    data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "    data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "    data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "    data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "    data[23] = 0x%08"PRIX32"\n", data->data[23]);
	RTE_LOG(INFO, PMD, "    data[24] = 0x%08"PRIX32"\n", data->data[24]);
}

void decode_dbr_dbr(const char *string __rte_unused, struct dbr_dbr *data) {
	RTE_LOG(INFO, PMD, "dbr_dbr\n");
	RTE_LOG(INFO, PMD, "     index = 0x%08"PRIX32"\n", data->index);
	RTE_LOG(INFO, PMD, "             Value : %s\n",
		(data->index & DBR_DBR_INDEX_MASK) == DBR_DBR_INDEX_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  type_xid = 0x%08"PRIX32"\n", data->type_xid);
}

void decode_dbr_dbr32(const char *string __rte_unused, struct dbr_dbr32 *data) {
	RTE_LOG(INFO, PMD, "dbr_dbr32\n");
	RTE_LOG(INFO, PMD, "  type_abs_incr_xid = 0x%08"PRIX32"\n", data->type_abs_incr_xid);
}

void decode_sq_base(const char *string __rte_unused, struct sq_base *data) {
	RTE_LOG(INFO, PMD, "sq_base\n");
	RTE_LOG(INFO, PMD, "     wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->wqe_type == SQ_BASE_WQE_TYPE_SEND ? "SEND" :
		data->wqe_type == SQ_BASE_WQE_TYPE_SEND_W_IMMEAD ? "SEND_W_IMMEAD" :
		data->wqe_type == SQ_BASE_WQE_TYPE_SEND_W_INVALID ? "SEND_W_INVALID" :
		data->wqe_type == SQ_BASE_WQE_TYPE_WRITE_WQE ? "WRITE_WQE" :
		data->wqe_type == SQ_BASE_WQE_TYPE_WRITE_W_IMMEAD ? "WRITE_W_IMMEAD" :
		data->wqe_type == SQ_BASE_WQE_TYPE_READ_WQE ? "READ_WQE" :
		data->wqe_type == SQ_BASE_WQE_TYPE_ATOMIC_CS ? "ATOMIC_CS" :
		data->wqe_type == SQ_BASE_WQE_TYPE_ATOMIC_FA ? "ATOMIC_FA" :
		data->wqe_type == SQ_BASE_WQE_TYPE_LOCAL_INVALID ? "LOCAL_INVALID" :
		data->wqe_type == SQ_BASE_WQE_TYPE_FR_PMR ? "FR_PMR" :
		data->wqe_type == SQ_BASE_WQE_TYPE_BIND ? "BIND" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "  unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "  unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "  unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "  unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_sq_sge(const char *string __rte_unused, struct sq_sge *data) {
	RTE_LOG(INFO, PMD, "sq_sge\n");
	RTE_LOG(INFO, PMD, "  va_or_pa = 0x%016"PRIX64"\n", data->va_or_pa);
	RTE_LOG(INFO, PMD, "     l_key = 0x%08"PRIX32"\n", data->l_key);
	RTE_LOG(INFO, PMD, "      size = 0x%08"PRIX32"\n", data->size);
}

void decode_sq_psn_search(const char *string __rte_unused, struct sq_psn_search *data) {
	RTE_LOG(INFO, PMD, "sq_psn_search\n");
	RTE_LOG(INFO, PMD, "  opcode_start_psn = 0x%08"PRIX32"\n", data->opcode_start_psn);
	RTE_LOG(INFO, PMD, "    flags_next_psn = 0x%08"PRIX32"\n", data->flags_next_psn);
}

void decode_sq_send(const char *string __rte_unused, struct sq_send *data) {
	RTE_LOG(INFO, PMD, "sq_send\n");
	RTE_LOG(INFO, PMD, "             wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->wqe_type == SQ_SEND_WQE_TYPE_SEND ? "SEND" :
		data->wqe_type == SQ_SEND_WQE_TYPE_SEND_W_IMMEAD ? "SEND_W_IMMEAD" :
		data->wqe_type == SQ_SEND_WQE_TYPE_SEND_W_INVALID ? "SEND_W_INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "                        SIGNAL_COMP : %s\n", (data->flags & SQ_SEND_FLAGS_SIGNAL_COMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        RD_OR_ATOMIC_FENCE : %s\n", (data->flags & SQ_SEND_FLAGS_RD_OR_ATOMIC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        UC_FENCE : %s\n", (data->flags & SQ_SEND_FLAGS_UC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        SE : %s\n", (data->flags & SQ_SEND_FLAGS_SE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        INLINE : %s\n", (data->flags & SQ_SEND_FLAGS_INLINE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             wqe_size = 0x%02"PRIX8"\n", data->wqe_size);
	RTE_LOG(INFO, PMD, "          reserved8_1 = 0x%02"PRIX8"\n", data->reserved8_1);
	RTE_LOG(INFO, PMD, "  inv_key_or_imm_data = 0x%08"PRIX32"\n", data->inv_key_or_imm_data);
	RTE_LOG(INFO, PMD, "               length = 0x%08"PRIX32"\n", data->length);
	RTE_LOG(INFO, PMD, "                q_key = 0x%08"PRIX32"\n", data->q_key);
	RTE_LOG(INFO, PMD, "               dst_qp = 0x%08"PRIX32"\n", data->dst_qp);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		(data->dst_qp & SQ_SEND_DST_QP_MASK) == SQ_SEND_DST_QP_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                 avid = 0x%08"PRIX32"\n", data->avid);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		(data->avid & SQ_SEND_AVID_MASK) == SQ_SEND_AVID_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           reserved64 = 0x%016"PRIX64"\n", data->reserved64);
	RTE_LOG(INFO, PMD, "              data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "              data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "              data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "              data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "              data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "              data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "              data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "              data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "              data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "              data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "             data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "             data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "             data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "             data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "             data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "             data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "             data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "             data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "             data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "             data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "             data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "             data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "             data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "             data[23] = 0x%08"PRIX32"\n", data->data[23]);
}

void decode_sq_send_raweth_qp1(const char *string __rte_unused, struct sq_send_raweth_qp1 *data) {
	RTE_LOG(INFO, PMD, "sq_send_raweth_qp1\n");
	RTE_LOG(INFO, PMD, "      wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->wqe_type == SQ_SEND_RAWETH_QP1_WQE_TYPE_SEND ? "SEND" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "                 SIGNAL_COMP : %s\n", (data->flags & SQ_SEND_RAWETH_QP1_FLAGS_SIGNAL_COMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 RD_OR_ATOMIC_FENCE : %s\n", (data->flags & SQ_SEND_RAWETH_QP1_FLAGS_RD_OR_ATOMIC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 UC_FENCE : %s\n", (data->flags & SQ_SEND_RAWETH_QP1_FLAGS_UC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 SE : %s\n", (data->flags & SQ_SEND_RAWETH_QP1_FLAGS_SE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 INLINE : %s\n", (data->flags & SQ_SEND_RAWETH_QP1_FLAGS_INLINE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      wqe_size = 0x%02"PRIX8"\n", data->wqe_size);
	RTE_LOG(INFO, PMD, "     reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "        lflags = 0x%04"PRIX16"\n", data->lflags);
	RTE_LOG(INFO, PMD, "                 TCP_UDP_CHKSUM : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_TCP_UDP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 IP_CHKSUM : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_IP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 NOCRC : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_NOCRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 STAMP : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_STAMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 T_IP_CHKSUM : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_T_IP_CHKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 RESERVED1_1 : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_RESERVED1_1)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 RESERVED1_2 : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_RESERVED1_2)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 RESERVED1_3 : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_RESERVED1_3)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 ROCE_CRC : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_ROCE_CRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 FCOE_CRC : %s\n", (data->lflags & SQ_SEND_RAWETH_QP1_LFLAGS_FCOE_CRC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    cfa_action = 0x%04"PRIX16"\n", data->cfa_action);
	RTE_LOG(INFO, PMD, "        length = 0x%08"PRIX32"\n", data->length);
	RTE_LOG(INFO, PMD, "  reserved32_1 = 0x%08"PRIX32"\n", data->reserved32_1);
	RTE_LOG(INFO, PMD, "      cfa_meta = 0x%08"PRIX32"\n", data->cfa_meta);
	RTE_LOG(INFO, PMD, "                 VLAN_VID = %0*X\n", 13, ((data->cfa_meta & SQ_SEND_RAWETH_QP1_CFA_META_VLAN_VID_MASK) >> SQ_SEND_RAWETH_QP1_CFA_META_VLAN_VID_SFT));
	RTE_LOG(INFO, PMD, "                 VLAN_PRI = %0*X\n", 11, ((data->cfa_meta & SQ_SEND_RAWETH_QP1_CFA_META_VLAN_PRI_MASK) >> SQ_SEND_RAWETH_QP1_CFA_META_VLAN_PRI_SFT));
	RTE_LOG(INFO, PMD, "                 VLAN_TPID = %0*X\n", 11, ((data->cfa_meta & SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_MASK) >> SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_SFT));
	RTE_LOG(INFO, PMD, "                 VLAN_RESERVED = %0*X\n", 13, ((data->cfa_meta & SQ_SEND_RAWETH_QP1_CFA_META_VLAN_RESERVED_MASK) >> SQ_SEND_RAWETH_QP1_CFA_META_VLAN_RESERVED_SFT));
	RTE_LOG(INFO, PMD, "                 KEY = %0*X\n", 11, ((data->cfa_meta & SQ_SEND_RAWETH_QP1_CFA_META_KEY_MASK) >> SQ_SEND_RAWETH_QP1_CFA_META_KEY_SFT));
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_DE ? "VLAN_DE" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_TPID88A8 ? "VLAN_TPID_TPID88A8" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_TPID8100 ? "VLAN_TPID_TPID8100" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_TPID9100 ? "VLAN_TPID_TPID9100" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_TPID9200 ? "VLAN_TPID_TPID9200" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_TPID9300 ? "VLAN_TPID_TPID9300" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_TPIDCFG ? "VLAN_TPID_TPIDCFG" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_VLAN_TPID_LAST ? "VLAN_TPID_LAST" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_KEY_NONE ? "KEY_NONE" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_KEY_VLAN_TAG ? "KEY_VLAN_TAG" :
		data->cfa_meta == SQ_SEND_RAWETH_QP1_CFA_META_KEY_LAST ? "KEY_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved32_2 = 0x%08"PRIX32"\n", data->reserved32_2);
	RTE_LOG(INFO, PMD, "    reserved64 = 0x%016"PRIX64"\n", data->reserved64);
	RTE_LOG(INFO, PMD, "       data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "       data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "       data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "       data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "       data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "       data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "       data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "       data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "       data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "       data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "      data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "      data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "      data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "      data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "      data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "      data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "      data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "      data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "      data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "      data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "      data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "      data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "      data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "      data[23] = 0x%08"PRIX32"\n", data->data[23]);
}

void decode_sq_rdma(const char *string __rte_unused, struct sq_rdma *data) {
	RTE_LOG(INFO, PMD, "sq_rdma\n");
	RTE_LOG(INFO, PMD, "      wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->wqe_type == SQ_RDMA_WQE_TYPE_WRITE_WQE ? "WRITE_WQE" :
		data->wqe_type == SQ_RDMA_WQE_TYPE_WRITE_W_IMMEAD ? "WRITE_W_IMMEAD" :
		data->wqe_type == SQ_RDMA_WQE_TYPE_READ_WQE ? "READ_WQE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "                 SIGNAL_COMP : %s\n", (data->flags & SQ_RDMA_FLAGS_SIGNAL_COMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 RD_OR_ATOMIC_FENCE : %s\n", (data->flags & SQ_RDMA_FLAGS_RD_OR_ATOMIC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 UC_FENCE : %s\n", (data->flags & SQ_RDMA_FLAGS_UC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 SE : %s\n", (data->flags & SQ_RDMA_FLAGS_SE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 INLINE : %s\n", (data->flags & SQ_RDMA_FLAGS_INLINE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      wqe_size = 0x%02"PRIX8"\n", data->wqe_size);
	RTE_LOG(INFO, PMD, "     reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "      imm_data = 0x%08"PRIX32"\n", data->imm_data);
	RTE_LOG(INFO, PMD, "        length = 0x%08"PRIX32"\n", data->length);
	RTE_LOG(INFO, PMD, "  reserved32_1 = 0x%08"PRIX32"\n", data->reserved32_1);
	RTE_LOG(INFO, PMD, "     remote_va = 0x%016"PRIX64"\n", data->remote_va);
	RTE_LOG(INFO, PMD, "    remote_key = 0x%08"PRIX32"\n", data->remote_key);
	RTE_LOG(INFO, PMD, "  reserved32_2 = 0x%08"PRIX32"\n", data->reserved32_2);
	RTE_LOG(INFO, PMD, "       data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "       data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "       data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "       data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "       data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "       data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "       data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "       data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "       data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "       data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "      data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "      data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "      data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "      data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "      data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "      data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "      data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "      data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "      data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "      data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "      data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "      data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "      data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "      data[23] = 0x%08"PRIX32"\n", data->data[23]);
}

void decode_sq_atomic(const char *string __rte_unused, struct sq_atomic *data) {
	RTE_LOG(INFO, PMD, "sq_atomic\n");
	RTE_LOG(INFO, PMD, "    wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->wqe_type == SQ_ATOMIC_WQE_TYPE_ATOMIC_CS ? "ATOMIC_CS" :
		data->wqe_type == SQ_ATOMIC_WQE_TYPE_ATOMIC_FA ? "ATOMIC_FA" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "               SIGNAL_COMP : %s\n", (data->flags & SQ_ATOMIC_FLAGS_SIGNAL_COMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               RD_OR_ATOMIC_FENCE : %s\n", (data->flags & SQ_ATOMIC_FLAGS_RD_OR_ATOMIC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               UC_FENCE : %s\n", (data->flags & SQ_ATOMIC_FLAGS_UC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               SE : %s\n", (data->flags & SQ_ATOMIC_FLAGS_SE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               INLINE : %s\n", (data->flags & SQ_ATOMIC_FLAGS_INLINE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "  remote_key = 0x%08"PRIX32"\n", data->remote_key);
	RTE_LOG(INFO, PMD, "   remote_va = 0x%016"PRIX64"\n", data->remote_va);
	RTE_LOG(INFO, PMD, "   swap_data = 0x%016"PRIX64"\n", data->swap_data);
	RTE_LOG(INFO, PMD, "    cmp_data = 0x%016"PRIX64"\n", data->cmp_data);
	RTE_LOG(INFO, PMD, "     data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "     data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "     data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "     data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "     data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "     data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "     data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "     data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "     data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "     data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "    data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "    data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "    data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "    data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "    data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "    data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "    data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "    data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "    data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "    data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "    data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "    data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "    data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "    data[23] = 0x%08"PRIX32"\n", data->data[23]);
}

void decode_sq_localinvalidate(const char *string __rte_unused, struct sq_localinvalidate *data) {
	RTE_LOG(INFO, PMD, "sq_localinvalidate\n");
	RTE_LOG(INFO, PMD, "        wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->wqe_type == SQ_LOCALINVALIDATE_WQE_TYPE_LOCAL_INVALID ? "LOCAL_INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "                   SIGNAL_COMP : %s\n", (data->flags & SQ_LOCALINVALIDATE_FLAGS_SIGNAL_COMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   RD_OR_ATOMIC_FENCE : %s\n", (data->flags & SQ_LOCALINVALIDATE_FLAGS_RD_OR_ATOMIC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   UC_FENCE : %s\n", (data->flags & SQ_LOCALINVALIDATE_FLAGS_UC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   SE : %s\n", (data->flags & SQ_LOCALINVALIDATE_FLAGS_SE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   INLINE : %s\n", (data->flags & SQ_LOCALINVALIDATE_FLAGS_INLINE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "       inv_l_key = 0x%08"PRIX32"\n", data->inv_l_key);
	RTE_LOG(INFO, PMD, "      reserved64 = 0x%016"PRIX64"\n", data->reserved64);
	RTE_LOG(INFO, PMD, "  reserved128[0] = 0x%08"PRIX32"\n", data->reserved128[0]);
	RTE_LOG(INFO, PMD, "  reserved128[1] = 0x%08"PRIX32"\n", data->reserved128[1]);
	RTE_LOG(INFO, PMD, "  reserved128[2] = 0x%08"PRIX32"\n", data->reserved128[2]);
	RTE_LOG(INFO, PMD, "  reserved128[3] = 0x%08"PRIX32"\n", data->reserved128[3]);
	RTE_LOG(INFO, PMD, "         data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "         data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "         data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "         data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "         data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "         data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "         data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "         data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "         data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "         data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "        data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "        data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "        data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "        data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "        data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "        data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "        data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "        data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "        data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "        data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "        data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "        data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "        data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "        data[23] = 0x%08"PRIX32"\n", data->data[23]);
}

void decode_sq_fr_pmr(const char *string __rte_unused, struct sq_fr_pmr *data) {
	RTE_LOG(INFO, PMD, "sq_fr_pmr\n");
	RTE_LOG(INFO, PMD, "                     wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                                Value : %s\n",
		data->wqe_type == SQ_FR_PMR_WQE_TYPE_FR_PMR ? "FR_PMR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                        flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "                                SIGNAL_COMP : %s\n", (data->flags & SQ_FR_PMR_FLAGS_SIGNAL_COMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                RD_OR_ATOMIC_FENCE : %s\n", (data->flags & SQ_FR_PMR_FLAGS_RD_OR_ATOMIC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                UC_FENCE : %s\n", (data->flags & SQ_FR_PMR_FLAGS_UC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                SE : %s\n", (data->flags & SQ_FR_PMR_FLAGS_SE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                INLINE : %s\n", (data->flags & SQ_FR_PMR_FLAGS_INLINE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  access_cntl = 0x%02"PRIX8"\n", data->access_cntl);
	RTE_LOG(INFO, PMD, "                                LOCAL_WRITE : %s\n", (data->access_cntl & SQ_FR_PMR_ACCESS_CNTL_LOCAL_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                REMOTE_READ : %s\n", (data->access_cntl & SQ_FR_PMR_ACCESS_CNTL_REMOTE_READ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                REMOTE_WRITE : %s\n", (data->access_cntl & SQ_FR_PMR_ACCESS_CNTL_REMOTE_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                REMOTE_ATOMIC : %s\n", (data->access_cntl & SQ_FR_PMR_ACCESS_CNTL_REMOTE_ATOMIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                WINDOW_BIND : %s\n", (data->access_cntl & SQ_FR_PMR_ACCESS_CNTL_WINDOW_BIND)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "     zero_based_page_size_log = 0x%02"PRIX8"\n", data->zero_based_page_size_log);
	RTE_LOG(INFO, PMD, "                        l_key = 0x%08"PRIX32"\n", data->l_key);
	RTE_LOG(INFO, PMD, "                    length[0] = 0x%02"PRIX8"\n", data->length[0]);
	RTE_LOG(INFO, PMD, "                    length[1] = 0x%02"PRIX8"\n", data->length[1]);
	RTE_LOG(INFO, PMD, "                    length[2] = 0x%02"PRIX8"\n", data->length[2]);
	RTE_LOG(INFO, PMD, "                    length[3] = 0x%02"PRIX8"\n", data->length[3]);
	RTE_LOG(INFO, PMD, "                    length[4] = 0x%02"PRIX8"\n", data->length[4]);
	RTE_LOG(INFO, PMD, "                  reserved8_1 = 0x%02"PRIX8"\n", data->reserved8_1);
	RTE_LOG(INFO, PMD, "                  reserved8_2 = 0x%02"PRIX8"\n", data->reserved8_2);
	RTE_LOG(INFO, PMD, "  numlevels_pbl_page_size_log = 0x%02"PRIX8"\n", data->numlevels_pbl_page_size_log);
	RTE_LOG(INFO, PMD, "                       pblptr = 0x%016"PRIX64"\n", data->pblptr);
	RTE_LOG(INFO, PMD, "                           va = 0x%016"PRIX64"\n", data->va);
	RTE_LOG(INFO, PMD, "                      data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "                      data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "                      data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "                      data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "                      data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "                      data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "                      data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "                      data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "                      data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "                      data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "                     data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "                     data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "                     data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "                     data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "                     data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "                     data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "                     data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "                     data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "                     data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "                     data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "                     data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "                     data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "                     data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "                     data[23] = 0x%08"PRIX32"\n", data->data[23]);
}

void decode_sq_bind(const char *string __rte_unused, struct sq_bind *data) {
	RTE_LOG(INFO, PMD, "sq_bind\n");
	RTE_LOG(INFO, PMD, "             wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->wqe_type == SQ_BIND_WQE_TYPE_BIND ? "BIND" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "                        SIGNAL_COMP : %s\n", (data->flags & SQ_BIND_FLAGS_SIGNAL_COMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        RD_OR_ATOMIC_FENCE : %s\n", (data->flags & SQ_BIND_FLAGS_RD_OR_ATOMIC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        UC_FENCE : %s\n", (data->flags & SQ_BIND_FLAGS_UC_FENCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        SE : %s\n", (data->flags & SQ_BIND_FLAGS_SE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        INLINE : %s\n", (data->flags & SQ_BIND_FLAGS_INLINE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "          access_cntl = 0x%02"PRIX8"\n", data->access_cntl);
	RTE_LOG(INFO, PMD, "                        LOCAL_WRITE : %s\n", (data->access_cntl & SQ_BIND_ACCESS_CNTL_LOCAL_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        REMOTE_READ : %s\n", (data->access_cntl & SQ_BIND_ACCESS_CNTL_REMOTE_READ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        REMOTE_WRITE : %s\n", (data->access_cntl & SQ_BIND_ACCESS_CNTL_REMOTE_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        REMOTE_ATOMIC : %s\n", (data->access_cntl & SQ_BIND_ACCESS_CNTL_REMOTE_ATOMIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        WINDOW_BIND : %s\n", (data->access_cntl & SQ_BIND_ACCESS_CNTL_WINDOW_BIND)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "          reserved8_1 = 0x%02"PRIX8"\n", data->reserved8_1);
	RTE_LOG(INFO, PMD, "   mw_type_zero_based = 0x%02"PRIX8"\n", data->mw_type_zero_based);
	RTE_LOG(INFO, PMD, "          reserved8_2 = 0x%02"PRIX8"\n", data->reserved8_2);
	RTE_LOG(INFO, PMD, "           reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "         parent_l_key = 0x%08"PRIX32"\n", data->parent_l_key);
	RTE_LOG(INFO, PMD, "                l_key = 0x%08"PRIX32"\n", data->l_key);
	RTE_LOG(INFO, PMD, "                   va = 0x%016"PRIX64"\n", data->va);
	RTE_LOG(INFO, PMD, "            length[0] = 0x%02"PRIX8"\n", data->length[0]);
	RTE_LOG(INFO, PMD, "            length[1] = 0x%02"PRIX8"\n", data->length[1]);
	RTE_LOG(INFO, PMD, "            length[2] = 0x%02"PRIX8"\n", data->length[2]);
	RTE_LOG(INFO, PMD, "            length[3] = 0x%02"PRIX8"\n", data->length[3]);
	RTE_LOG(INFO, PMD, "            length[4] = 0x%02"PRIX8"\n", data->length[4]);
	RTE_LOG(INFO, PMD, "   data_reserved24[0] = 0x%02"PRIX8"\n", data->data_reserved24[0]);
	RTE_LOG(INFO, PMD, "   data_reserved24[1] = 0x%02"PRIX8"\n", data->data_reserved24[1]);
	RTE_LOG(INFO, PMD, "   data_reserved24[2] = 0x%02"PRIX8"\n", data->data_reserved24[2]);
	RTE_LOG(INFO, PMD, "   data_reserved24[3] = 0x%02"PRIX8"\n", data->data_reserved24[3]);
	RTE_LOG(INFO, PMD, "   data_reserved24[4] = 0x%02"PRIX8"\n", data->data_reserved24[4]);
	RTE_LOG(INFO, PMD, "   data_reserved24[5] = 0x%02"PRIX8"\n", data->data_reserved24[5]);
	RTE_LOG(INFO, PMD, "   data_reserved24[6] = 0x%02"PRIX8"\n", data->data_reserved24[6]);
	RTE_LOG(INFO, PMD, "   data_reserved24[7] = 0x%02"PRIX8"\n", data->data_reserved24[7]);
	RTE_LOG(INFO, PMD, "   data_reserved24[8] = 0x%02"PRIX8"\n", data->data_reserved24[8]);
	RTE_LOG(INFO, PMD, "   data_reserved24[9] = 0x%02"PRIX8"\n", data->data_reserved24[9]);
	RTE_LOG(INFO, PMD, "  data_reserved24[10] = 0x%02"PRIX8"\n", data->data_reserved24[10]);
	RTE_LOG(INFO, PMD, "  data_reserved24[11] = 0x%02"PRIX8"\n", data->data_reserved24[11]);
	RTE_LOG(INFO, PMD, "  data_reserved24[12] = 0x%02"PRIX8"\n", data->data_reserved24[12]);
	RTE_LOG(INFO, PMD, "  data_reserved24[13] = 0x%02"PRIX8"\n", data->data_reserved24[13]);
	RTE_LOG(INFO, PMD, "  data_reserved24[14] = 0x%02"PRIX8"\n", data->data_reserved24[14]);
	RTE_LOG(INFO, PMD, "  data_reserved24[15] = 0x%02"PRIX8"\n", data->data_reserved24[15]);
	RTE_LOG(INFO, PMD, "  data_reserved24[16] = 0x%02"PRIX8"\n", data->data_reserved24[16]);
	RTE_LOG(INFO, PMD, "  data_reserved24[17] = 0x%02"PRIX8"\n", data->data_reserved24[17]);
	RTE_LOG(INFO, PMD, "  data_reserved24[18] = 0x%02"PRIX8"\n", data->data_reserved24[18]);
	RTE_LOG(INFO, PMD, "  data_reserved24[19] = 0x%02"PRIX8"\n", data->data_reserved24[19]);
	RTE_LOG(INFO, PMD, "  data_reserved24[20] = 0x%02"PRIX8"\n", data->data_reserved24[20]);
	RTE_LOG(INFO, PMD, "  data_reserved24[21] = 0x%02"PRIX8"\n", data->data_reserved24[21]);
	RTE_LOG(INFO, PMD, "  data_reserved24[22] = 0x%02"PRIX8"\n", data->data_reserved24[22]);
	RTE_LOG(INFO, PMD, "  data_reserved24[23] = 0x%02"PRIX8"\n", data->data_reserved24[23]);
	RTE_LOG(INFO, PMD, "  data_reserved24[24] = 0x%02"PRIX8"\n", data->data_reserved24[24]);
	RTE_LOG(INFO, PMD, "  data_reserved24[25] = 0x%02"PRIX8"\n", data->data_reserved24[25]);
	RTE_LOG(INFO, PMD, "  data_reserved24[26] = 0x%02"PRIX8"\n", data->data_reserved24[26]);
	RTE_LOG(INFO, PMD, "  data_reserved24[27] = 0x%02"PRIX8"\n", data->data_reserved24[27]);
	RTE_LOG(INFO, PMD, "  data_reserved24[28] = 0x%02"PRIX8"\n", data->data_reserved24[28]);
	RTE_LOG(INFO, PMD, "  data_reserved24[29] = 0x%02"PRIX8"\n", data->data_reserved24[29]);
	RTE_LOG(INFO, PMD, "  data_reserved24[30] = 0x%02"PRIX8"\n", data->data_reserved24[30]);
	RTE_LOG(INFO, PMD, "  data_reserved24[31] = 0x%02"PRIX8"\n", data->data_reserved24[31]);
	RTE_LOG(INFO, PMD, "  data_reserved24[32] = 0x%02"PRIX8"\n", data->data_reserved24[32]);
	RTE_LOG(INFO, PMD, "  data_reserved24[33] = 0x%02"PRIX8"\n", data->data_reserved24[33]);
	RTE_LOG(INFO, PMD, "  data_reserved24[34] = 0x%02"PRIX8"\n", data->data_reserved24[34]);
	RTE_LOG(INFO, PMD, "  data_reserved24[35] = 0x%02"PRIX8"\n", data->data_reserved24[35]);
	RTE_LOG(INFO, PMD, "  data_reserved24[36] = 0x%02"PRIX8"\n", data->data_reserved24[36]);
	RTE_LOG(INFO, PMD, "  data_reserved24[37] = 0x%02"PRIX8"\n", data->data_reserved24[37]);
	RTE_LOG(INFO, PMD, "  data_reserved24[38] = 0x%02"PRIX8"\n", data->data_reserved24[38]);
	RTE_LOG(INFO, PMD, "  data_reserved24[39] = 0x%02"PRIX8"\n", data->data_reserved24[39]);
	RTE_LOG(INFO, PMD, "  data_reserved24[40] = 0x%02"PRIX8"\n", data->data_reserved24[40]);
	RTE_LOG(INFO, PMD, "  data_reserved24[41] = 0x%02"PRIX8"\n", data->data_reserved24[41]);
	RTE_LOG(INFO, PMD, "  data_reserved24[42] = 0x%02"PRIX8"\n", data->data_reserved24[42]);
	RTE_LOG(INFO, PMD, "  data_reserved24[43] = 0x%02"PRIX8"\n", data->data_reserved24[43]);
	RTE_LOG(INFO, PMD, "  data_reserved24[44] = 0x%02"PRIX8"\n", data->data_reserved24[44]);
	RTE_LOG(INFO, PMD, "  data_reserved24[45] = 0x%02"PRIX8"\n", data->data_reserved24[45]);
	RTE_LOG(INFO, PMD, "  data_reserved24[46] = 0x%02"PRIX8"\n", data->data_reserved24[46]);
	RTE_LOG(INFO, PMD, "  data_reserved24[47] = 0x%02"PRIX8"\n", data->data_reserved24[47]);
	RTE_LOG(INFO, PMD, "  data_reserved24[48] = 0x%02"PRIX8"\n", data->data_reserved24[48]);
	RTE_LOG(INFO, PMD, "  data_reserved24[49] = 0x%02"PRIX8"\n", data->data_reserved24[49]);
	RTE_LOG(INFO, PMD, "  data_reserved24[50] = 0x%02"PRIX8"\n", data->data_reserved24[50]);
	RTE_LOG(INFO, PMD, "  data_reserved24[51] = 0x%02"PRIX8"\n", data->data_reserved24[51]);
	RTE_LOG(INFO, PMD, "  data_reserved24[52] = 0x%02"PRIX8"\n", data->data_reserved24[52]);
	RTE_LOG(INFO, PMD, "  data_reserved24[53] = 0x%02"PRIX8"\n", data->data_reserved24[53]);
	RTE_LOG(INFO, PMD, "  data_reserved24[54] = 0x%02"PRIX8"\n", data->data_reserved24[54]);
	RTE_LOG(INFO, PMD, "  data_reserved24[55] = 0x%02"PRIX8"\n", data->data_reserved24[55]);
	RTE_LOG(INFO, PMD, "  data_reserved24[56] = 0x%02"PRIX8"\n", data->data_reserved24[56]);
	RTE_LOG(INFO, PMD, "  data_reserved24[57] = 0x%02"PRIX8"\n", data->data_reserved24[57]);
	RTE_LOG(INFO, PMD, "  data_reserved24[58] = 0x%02"PRIX8"\n", data->data_reserved24[58]);
	RTE_LOG(INFO, PMD, "  data_reserved24[59] = 0x%02"PRIX8"\n", data->data_reserved24[59]);
	RTE_LOG(INFO, PMD, "  data_reserved24[60] = 0x%02"PRIX8"\n", data->data_reserved24[60]);
	RTE_LOG(INFO, PMD, "  data_reserved24[61] = 0x%02"PRIX8"\n", data->data_reserved24[61]);
	RTE_LOG(INFO, PMD, "  data_reserved24[62] = 0x%02"PRIX8"\n", data->data_reserved24[62]);
	RTE_LOG(INFO, PMD, "  data_reserved24[63] = 0x%02"PRIX8"\n", data->data_reserved24[63]);
	RTE_LOG(INFO, PMD, "  data_reserved24[64] = 0x%02"PRIX8"\n", data->data_reserved24[64]);
	RTE_LOG(INFO, PMD, "  data_reserved24[65] = 0x%02"PRIX8"\n", data->data_reserved24[65]);
	RTE_LOG(INFO, PMD, "  data_reserved24[66] = 0x%02"PRIX8"\n", data->data_reserved24[66]);
	RTE_LOG(INFO, PMD, "  data_reserved24[67] = 0x%02"PRIX8"\n", data->data_reserved24[67]);
	RTE_LOG(INFO, PMD, "  data_reserved24[68] = 0x%02"PRIX8"\n", data->data_reserved24[68]);
	RTE_LOG(INFO, PMD, "  data_reserved24[69] = 0x%02"PRIX8"\n", data->data_reserved24[69]);
	RTE_LOG(INFO, PMD, "  data_reserved24[70] = 0x%02"PRIX8"\n", data->data_reserved24[70]);
	RTE_LOG(INFO, PMD, "  data_reserved24[71] = 0x%02"PRIX8"\n", data->data_reserved24[71]);
	RTE_LOG(INFO, PMD, "  data_reserved24[72] = 0x%02"PRIX8"\n", data->data_reserved24[72]);
	RTE_LOG(INFO, PMD, "  data_reserved24[73] = 0x%02"PRIX8"\n", data->data_reserved24[73]);
	RTE_LOG(INFO, PMD, "  data_reserved24[74] = 0x%02"PRIX8"\n", data->data_reserved24[74]);
	RTE_LOG(INFO, PMD, "  data_reserved24[75] = 0x%02"PRIX8"\n", data->data_reserved24[75]);
	RTE_LOG(INFO, PMD, "  data_reserved24[76] = 0x%02"PRIX8"\n", data->data_reserved24[76]);
	RTE_LOG(INFO, PMD, "  data_reserved24[77] = 0x%02"PRIX8"\n", data->data_reserved24[77]);
	RTE_LOG(INFO, PMD, "  data_reserved24[78] = 0x%02"PRIX8"\n", data->data_reserved24[78]);
	RTE_LOG(INFO, PMD, "  data_reserved24[79] = 0x%02"PRIX8"\n", data->data_reserved24[79]);
	RTE_LOG(INFO, PMD, "  data_reserved24[80] = 0x%02"PRIX8"\n", data->data_reserved24[80]);
	RTE_LOG(INFO, PMD, "  data_reserved24[81] = 0x%02"PRIX8"\n", data->data_reserved24[81]);
	RTE_LOG(INFO, PMD, "  data_reserved24[82] = 0x%02"PRIX8"\n", data->data_reserved24[82]);
	RTE_LOG(INFO, PMD, "  data_reserved24[83] = 0x%02"PRIX8"\n", data->data_reserved24[83]);
	RTE_LOG(INFO, PMD, "  data_reserved24[84] = 0x%02"PRIX8"\n", data->data_reserved24[84]);
	RTE_LOG(INFO, PMD, "  data_reserved24[85] = 0x%02"PRIX8"\n", data->data_reserved24[85]);
	RTE_LOG(INFO, PMD, "  data_reserved24[86] = 0x%02"PRIX8"\n", data->data_reserved24[86]);
	RTE_LOG(INFO, PMD, "  data_reserved24[87] = 0x%02"PRIX8"\n", data->data_reserved24[87]);
	RTE_LOG(INFO, PMD, "  data_reserved24[88] = 0x%02"PRIX8"\n", data->data_reserved24[88]);
	RTE_LOG(INFO, PMD, "  data_reserved24[89] = 0x%02"PRIX8"\n", data->data_reserved24[89]);
	RTE_LOG(INFO, PMD, "  data_reserved24[90] = 0x%02"PRIX8"\n", data->data_reserved24[90]);
	RTE_LOG(INFO, PMD, "  data_reserved24[91] = 0x%02"PRIX8"\n", data->data_reserved24[91]);
	RTE_LOG(INFO, PMD, "  data_reserved24[92] = 0x%02"PRIX8"\n", data->data_reserved24[92]);
	RTE_LOG(INFO, PMD, "  data_reserved24[93] = 0x%02"PRIX8"\n", data->data_reserved24[93]);
	RTE_LOG(INFO, PMD, "  data_reserved24[94] = 0x%02"PRIX8"\n", data->data_reserved24[94]);
	RTE_LOG(INFO, PMD, "  data_reserved24[95] = 0x%02"PRIX8"\n", data->data_reserved24[95]);
	RTE_LOG(INFO, PMD, "  data_reserved24[96] = 0x%02"PRIX8"\n", data->data_reserved24[96]);
	RTE_LOG(INFO, PMD, "  data_reserved24[97] = 0x%02"PRIX8"\n", data->data_reserved24[97]);
	RTE_LOG(INFO, PMD, "  data_reserved24[98] = 0x%02"PRIX8"\n", data->data_reserved24[98]);
}

void decode_rq_wqe(const char *string __rte_unused, struct rq_wqe *data) {
	RTE_LOG(INFO, PMD, "rq_wqe\n");
	RTE_LOG(INFO, PMD, "        wqe_type = 0x%02"PRIX8"\n", data->wqe_type);
	RTE_LOG(INFO, PMD, "                   RCV : %s\n", (data->wqe_type & RQ_WQE_WQE_TYPE_RCV)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "           flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "        wqe_size = 0x%02"PRIX8"\n", data->wqe_size);
	RTE_LOG(INFO, PMD, "       reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "      reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "           wr_id = 0x%016"PRIX64"\n", data->wr_id);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		(data->wr_id & RQ_WQE_WR_ID_MASK) == RQ_WQE_WR_ID_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved128[0] = 0x%08"PRIX32"\n", data->reserved128[0]);
	RTE_LOG(INFO, PMD, "  reserved128[1] = 0x%08"PRIX32"\n", data->reserved128[1]);
	RTE_LOG(INFO, PMD, "  reserved128[2] = 0x%08"PRIX32"\n", data->reserved128[2]);
	RTE_LOG(INFO, PMD, "  reserved128[3] = 0x%08"PRIX32"\n", data->reserved128[3]);
	RTE_LOG(INFO, PMD, "         data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "         data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "         data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "         data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "         data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "         data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "         data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "         data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "         data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "         data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "        data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "        data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "        data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "        data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "        data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "        data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "        data[16] = 0x%08"PRIX32"\n", data->data[16]);
	RTE_LOG(INFO, PMD, "        data[17] = 0x%08"PRIX32"\n", data->data[17]);
	RTE_LOG(INFO, PMD, "        data[18] = 0x%08"PRIX32"\n", data->data[18]);
	RTE_LOG(INFO, PMD, "        data[19] = 0x%08"PRIX32"\n", data->data[19]);
	RTE_LOG(INFO, PMD, "        data[20] = 0x%08"PRIX32"\n", data->data[20]);
	RTE_LOG(INFO, PMD, "        data[21] = 0x%08"PRIX32"\n", data->data[21]);
	RTE_LOG(INFO, PMD, "        data[22] = 0x%08"PRIX32"\n", data->data[22]);
	RTE_LOG(INFO, PMD, "        data[23] = 0x%08"PRIX32"\n", data->data[23]);
}

void decode_cq_base(const char *string __rte_unused, struct cq_base *data) {
	RTE_LOG(INFO, PMD, "cq_base\n");
	RTE_LOG(INFO, PMD, "     reserved64_1 = 0x%016"PRIX64"\n", data->reserved64_1);
	RTE_LOG(INFO, PMD, "     reserved64_2 = 0x%016"PRIX64"\n", data->reserved64_2);
	RTE_LOG(INFO, PMD, "     reserved64_3 = 0x%016"PRIX64"\n", data->reserved64_3);
	RTE_LOG(INFO, PMD, "  cqe_type_toggle = 0x%02"PRIX8"\n", data->cqe_type_toggle);
	RTE_LOG(INFO, PMD, "           status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "       reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "       reserved32 = 0x%08"PRIX32"\n", data->reserved32);
}

void decode_cq_req(const char *string __rte_unused, struct cq_req *data) {
	RTE_LOG(INFO, PMD, "cq_req\n");
	RTE_LOG(INFO, PMD, "        qp_handle = 0x%016"PRIX64"\n", data->qp_handle);
	RTE_LOG(INFO, PMD, "      sq_cons_idx = 0x%04"PRIX16"\n", data->sq_cons_idx);
	RTE_LOG(INFO, PMD, "     reserved16_1 = 0x%04"PRIX16"\n", data->reserved16_1);
	RTE_LOG(INFO, PMD, "     reserved32_2 = 0x%08"PRIX32"\n", data->reserved32_2);
	RTE_LOG(INFO, PMD, "       reserved64 = 0x%016"PRIX64"\n", data->reserved64);
	RTE_LOG(INFO, PMD, "  cqe_type_toggle = 0x%02"PRIX8"\n", data->cqe_type_toggle);
	RTE_LOG(INFO, PMD, "           status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->status == CQ_REQ_STATUS_OK ? "OK" :
		data->status == CQ_REQ_STATUS_BAD_RESPONSE_ERR ? "BAD_RESPONSE_ERR" :
		data->status == CQ_REQ_STATUS_LOCAL_LENGTH_ERR ? "LOCAL_LENGTH_ERR" :
		data->status == CQ_REQ_STATUS_LOCAL_QP_OPERATION_ERR ? "LOCAL_QP_OPERATION_ERR" :
		data->status == CQ_REQ_STATUS_LOCAL_PROTECTION_ERR ? "LOCAL_PROTECTION_ERR" :
		data->status == CQ_REQ_STATUS_MEMORY_MGT_OPERATION_ERR ? "MEMORY_MGT_OPERATION_ERR" :
		data->status == CQ_REQ_STATUS_REMOTE_INVALID_REQUEST_ERR ? "REMOTE_INVALID_REQUEST_ERR" :
		data->status == CQ_REQ_STATUS_REMOTE_ACCESS_ERR ? "REMOTE_ACCESS_ERR" :
		data->status == CQ_REQ_STATUS_REMOTE_OPERATION_ERR ? "REMOTE_OPERATION_ERR" :
		data->status == CQ_REQ_STATUS_RNR_NAK_RETRY_CNT_ERR ? "RNR_NAK_RETRY_CNT_ERR" :
		data->status == CQ_REQ_STATUS_TRANSPORT_RETRY_CNT_ERR ? "TRANSPORT_RETRY_CNT_ERR" :
		data->status == CQ_REQ_STATUS_WORK_REQUEST_FLUSHED_ERR ? "WORK_REQUEST_FLUSHED_ERR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     reserved16_2 = 0x%04"PRIX16"\n", data->reserved16_2);
	RTE_LOG(INFO, PMD, "     reserved32_1 = 0x%08"PRIX32"\n", data->reserved32_1);
}

void decode_cq_res_rc(const char *string __rte_unused, struct cq_res_rc *data) {
	RTE_LOG(INFO, PMD, "cq_res_rc\n");
	RTE_LOG(INFO, PMD, "                 length = 0x%08"PRIX32"\n", data->length);
	RTE_LOG(INFO, PMD, "  imm_data_or_inv_r_key = 0x%08"PRIX32"\n", data->imm_data_or_inv_r_key);
	RTE_LOG(INFO, PMD, "              qp_handle = 0x%016"PRIX64"\n", data->qp_handle);
	RTE_LOG(INFO, PMD, "              mr_handle = 0x%016"PRIX64"\n", data->mr_handle);
	RTE_LOG(INFO, PMD, "        cqe_type_toggle = 0x%02"PRIX8"\n", data->cqe_type_toggle);
	RTE_LOG(INFO, PMD, "                 status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "                          Value : %s\n",
		data->status == CQ_RES_RC_STATUS_OK ? "OK" :
		data->status == CQ_RES_RC_STATUS_LOCAL_ACCESS_ERROR ? "LOCAL_ACCESS_ERROR" :
		data->status == CQ_RES_RC_STATUS_LOCAL_LENGTH_ERR ? "LOCAL_LENGTH_ERR" :
		data->status == CQ_RES_RC_STATUS_LOCAL_PROTECTION_ERR ? "LOCAL_PROTECTION_ERR" :
		data->status == CQ_RES_RC_STATUS_LOCAL_QP_OPERATION_ERR ? "LOCAL_QP_OPERATION_ERR" :
		data->status == CQ_RES_RC_STATUS_MEMORY_MGT_OPERATION_ERR ? "MEMORY_MGT_OPERATION_ERR" :
		data->status == CQ_RES_RC_STATUS_REMOTE_INVALID_REQUEST_ERR ? "REMOTE_INVALID_REQUEST_ERR" :
		data->status == CQ_RES_RC_STATUS_WORK_REQUEST_FLUSHED_ERR ? "WORK_REQUEST_FLUSHED_ERR" :
		data->status == CQ_RES_RC_STATUS_HW_FLUSH_ERR ? "HW_FLUSH_ERR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                  flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                          Value : %s\n",
		data->flags == CQ_RES_RC_FLAGS_SRQ ? "SRQ" :
		data->flags == CQ_RES_RC_FLAGS_SRQ_RQ ? "SRQ_RQ" :
		data->flags == CQ_RES_RC_FLAGS_SRQ_SRQ ? "SRQ_SRQ" :
		data->flags == CQ_RES_RC_FLAGS_SRQ_LAST ? "SRQ_LAST" :
		data->flags == CQ_RES_RC_FLAGS_IMM ? "IMM" :
		data->flags == CQ_RES_RC_FLAGS_INV ? "INV" :
		data->flags == CQ_RES_RC_FLAGS_RDMA ? "RDMA" :
		data->flags == CQ_RES_RC_FLAGS_RDMA_SEND ? "RDMA_SEND" :
		data->flags == CQ_RES_RC_FLAGS_RDMA_RDMA_WRITE ? "RDMA_RDMA_WRITE" :
		data->flags == CQ_RES_RC_FLAGS_RDMA_LAST ? "RDMA_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        srq_or_rq_wr_id = 0x%08"PRIX32"\n", data->srq_or_rq_wr_id);
	RTE_LOG(INFO, PMD, "                          Value : %s\n",
		(data->srq_or_rq_wr_id & CQ_RES_RC_SRQ_OR_RQ_WR_ID_MASK) == CQ_RES_RC_SRQ_OR_RQ_WR_ID_SFT ? "SFT" :
		"Unknown");
}

void decode_cq_res_ud(const char *string __rte_unused, struct cq_res_ud *data) {
	RTE_LOG(INFO, PMD, "cq_res_ud\n");
	RTE_LOG(INFO, PMD, "                       length = 0x%08"PRIX32"\n", data->length);
	RTE_LOG(INFO, PMD, "                                Value : %s\n",
		(data->length & CQ_RES_UD_LENGTH_MASK) == CQ_RES_UD_LENGTH_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                     imm_data = 0x%08"PRIX32"\n", data->imm_data);
	RTE_LOG(INFO, PMD, "                    qp_handle = 0x%016"PRIX64"\n", data->qp_handle);
	RTE_LOG(INFO, PMD, "                   src_mac[0] = 0x%04"PRIX16"\n", data->src_mac[0]);
	RTE_LOG(INFO, PMD, "                   src_mac[1] = 0x%04"PRIX16"\n", data->src_mac[1]);
	RTE_LOG(INFO, PMD, "                   src_mac[2] = 0x%04"PRIX16"\n", data->src_mac[2]);
	RTE_LOG(INFO, PMD, "                   src_qp_low = 0x%04"PRIX16"\n", data->src_qp_low);
	RTE_LOG(INFO, PMD, "              cqe_type_toggle = 0x%02"PRIX8"\n", data->cqe_type_toggle);
	RTE_LOG(INFO, PMD, "                       status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "                                Value : %s\n",
		data->status == CQ_RES_UD_STATUS_OK ? "OK" :
		data->status == CQ_RES_UD_STATUS_LOCAL_ACCESS_ERROR ? "LOCAL_ACCESS_ERROR" :
		data->status == CQ_RES_UD_STATUS_HW_LOCAL_LENGTH_ERR ? "HW_LOCAL_LENGTH_ERR" :
		data->status == CQ_RES_UD_STATUS_LOCAL_PROTECTION_ERR ? "LOCAL_PROTECTION_ERR" :
		data->status == CQ_RES_UD_STATUS_LOCAL_QP_OPERATION_ERR ? "LOCAL_QP_OPERATION_ERR" :
		data->status == CQ_RES_UD_STATUS_MEMORY_MGT_OPERATION_ERR ? "MEMORY_MGT_OPERATION_ERR" :
		data->status == CQ_RES_UD_STATUS_WORK_REQUEST_FLUSHED_ERR ? "WORK_REQUEST_FLUSHED_ERR" :
		data->status == CQ_RES_UD_STATUS_HW_FLUSH_ERR ? "HW_FLUSH_ERR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                        flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                                ROCE_IP_VER = %0*X\n", 11, ((data->flags & CQ_RES_UD_FLAGS_ROCE_IP_VER_MASK) >> CQ_RES_UD_FLAGS_ROCE_IP_VER_SFT));
	RTE_LOG(INFO, PMD, "                                Value : %s\n",
		data->flags == CQ_RES_UD_FLAGS_SRQ ? "SRQ" :
		data->flags == CQ_RES_UD_FLAGS_SRQ_RQ ? "SRQ_RQ" :
		data->flags == CQ_RES_UD_FLAGS_SRQ_SRQ ? "SRQ_SRQ" :
		data->flags == CQ_RES_UD_FLAGS_SRQ_LAST ? "SRQ_LAST" :
		data->flags == CQ_RES_UD_FLAGS_IMM ? "IMM" :
		data->flags == CQ_RES_UD_FLAGS_ROCE_IP_VER_V1 ? "ROCE_IP_VER_V1" :
		data->flags == CQ_RES_UD_FLAGS_ROCE_IP_VER_V2IPV4 ? "ROCE_IP_VER_V2IPV4" :
		data->flags == CQ_RES_UD_FLAGS_ROCE_IP_VER_V2IPV6 ? "ROCE_IP_VER_V2IPV6" :
		data->flags == CQ_RES_UD_FLAGS_ROCE_IP_VER_LAST ? "ROCE_IP_VER_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  src_qp_high_srq_or_rq_wr_id = 0x%08"PRIX32"\n", data->src_qp_high_srq_or_rq_wr_id);
}

void decode_cq_res_raweth_qp1(const char *string __rte_unused, struct cq_res_raweth_qp1 *data) {
	RTE_LOG(INFO, PMD, "cq_res_raweth_qp1\n");
	RTE_LOG(INFO, PMD, "                                     length = 0x%04"PRIX16"\n", data->length);
	RTE_LOG(INFO, PMD, "                                              Value : %s\n",
		(data->length & CQ_RES_RAWETH_QP1_LENGTH_MASK) == CQ_RES_RAWETH_QP1_LENGTH_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                           raweth_qp1_flags = 0x%04"PRIX16"\n", data->raweth_qp1_flags);
	RTE_LOG(INFO, PMD, "                                              RESERVED5_1 = %0*X\n", 12, ((data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_RESERVED5_1_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_RESERVED5_1_SFT));
	RTE_LOG(INFO, PMD, "                                              ITYPE = %0*X\n", 12, ((data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_SFT));
	RTE_LOG(INFO, PMD, "                                              Value : %s\n",
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ERROR ? "ERROR" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_NOT_KNOWN ? "ITYPE_NOT_KNOWN" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_IP ? "ITYPE_IP" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_TCP ? "ITYPE_TCP" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_UDP ? "ITYPE_UDP" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_FCOE ? "ITYPE_FCOE" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_ROCE ? "ITYPE_ROCE" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_ICMP ? "ITYPE_ICMP" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_PTP_WO_TIMESTAMP ? "ITYPE_PTP_WO_TIMESTAMP" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_PTP_W_TIMESTAMP ? "ITYPE_PTP_W_TIMESTAMP" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_ITYPE_LAST ? "ITYPE_LAST" :
		(data->raweth_qp1_flags & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_MASK) == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                          raweth_qp1_errors = 0x%04"PRIX16"\n", data->raweth_qp1_errors);
	RTE_LOG(INFO, PMD, "                                              RESERVED4 = %0*X\n", 11, ((data->raweth_qp1_errors & CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_RESERVED4_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_RESERVED4_SFT));
	RTE_LOG(INFO, PMD, "                                              T_PKT_ERROR = %0*X\n", 11, ((data->raweth_qp1_errors & CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_SFT));
	RTE_LOG(INFO, PMD, "                                              PKT_ERROR = %0*X\n", 11, ((data->raweth_qp1_errors & CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_SFT));
	RTE_LOG(INFO, PMD, "                                              Value : %s\n",
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_IP_CS_ERROR ? "IP_CS_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_L4_CS_ERROR ? "L4_CS_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_IP_CS_ERROR ? "T_IP_CS_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_L4_CS_ERROR ? "T_L4_CS_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_CRC_ERROR ? "CRC_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_NO_ERROR ? "T_PKT_ERROR_NO_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_T_L3_BAD_VERSION ? "T_PKT_ERROR_T_L3_BAD_VERSION" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_T_L3_BAD_HDR_LEN ? "T_PKT_ERROR_T_L3_BAD_HDR_LEN" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_TUNNEL_TOTAL_ERROR ? "T_PKT_ERROR_TUNNEL_TOTAL_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_T_IP_TOTAL_ERROR ? "T_PKT_ERROR_T_IP_TOTAL_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_T_UDP_TOTAL_ERROR ? "T_PKT_ERROR_T_UDP_TOTAL_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_T_L3_BAD_TTL ? "T_PKT_ERROR_T_L3_BAD_TTL" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_T_PKT_ERROR_LAST ? "T_PKT_ERROR_LAST" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_NO_ERROR ? "PKT_ERROR_NO_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_L3_BAD_VERSION ? "PKT_ERROR_L3_BAD_VERSION" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_L3_BAD_HDR_LEN ? "PKT_ERROR_L3_BAD_HDR_LEN" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_L3_BAD_TTL ? "PKT_ERROR_L3_BAD_TTL" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_IP_TOTAL_ERROR ? "PKT_ERROR_IP_TOTAL_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_UDP_TOTAL_ERROR ? "PKT_ERROR_UDP_TOTAL_ERROR" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_L4_BAD_HDR_LEN ? "PKT_ERROR_L4_BAD_HDR_LEN" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_L4_BAD_HDR_LEN_TOO_SMALL ? "PKT_ERROR_L4_BAD_HDR_LEN_TOO_SMALL" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_L4_BAD_OPT_LEN ? "PKT_ERROR_L4_BAD_OPT_LEN" :
		data->raweth_qp1_errors == CQ_RES_RAWETH_QP1_RAWETH_QP1_ERRORS_PKT_ERROR_LAST ? "PKT_ERROR_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                        raweth_qp1_cfa_code = 0x%04"PRIX16"\n", data->raweth_qp1_cfa_code);
	RTE_LOG(INFO, PMD, "                                  qp_handle = 0x%016"PRIX64"\n", data->qp_handle);
	RTE_LOG(INFO, PMD, "                          raweth_qp1_flags2 = 0x%08"PRIX32"\n", data->raweth_qp1_flags2);
	RTE_LOG(INFO, PMD, "                                              META_FORMAT = %0*X\n", 11, ((data->raweth_qp1_flags2 & CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_META_FORMAT_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_META_FORMAT_SFT));
	RTE_LOG(INFO, PMD, "                                              Value : %s\n",
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_IP_CS_CALC ? "IP_CS_CALC" :
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_L4_CS_CALC ? "L4_CS_CALC" :
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_T_IP_CS_CALC ? "T_IP_CS_CALC" :
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_T_L4_CS_CALC ? "T_L4_CS_CALC" :
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_META_FORMAT_NONE ? "META_FORMAT_NONE" :
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_META_FORMAT_VLAN ? "META_FORMAT_VLAN" :
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_META_FORMAT_LAST ? "META_FORMAT_LAST" :
		data->raweth_qp1_flags2 == CQ_RES_RAWETH_QP1_RAWETH_QP1_FLAGS2_IP_TYPE ? "IP_TYPE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                        raweth_qp1_metadata = 0x%08"PRIX32"\n", data->raweth_qp1_metadata);
	RTE_LOG(INFO, PMD, "                                              VID = %0*X\n", 13, ((data->raweth_qp1_metadata & CQ_RES_RAWETH_QP1_RAWETH_QP1_METADATA_VID_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_METADATA_VID_SFT));
	RTE_LOG(INFO, PMD, "                                              PRI = %0*X\n", 11, ((data->raweth_qp1_metadata & CQ_RES_RAWETH_QP1_RAWETH_QP1_METADATA_PRI_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_METADATA_PRI_SFT));
	RTE_LOG(INFO, PMD, "                                              TPID = %0*X\n", 14, ((data->raweth_qp1_metadata & CQ_RES_RAWETH_QP1_RAWETH_QP1_METADATA_TPID_MASK) >> CQ_RES_RAWETH_QP1_RAWETH_QP1_METADATA_TPID_SFT));
	RTE_LOG(INFO, PMD, "                                              DE : %s\n", (data->raweth_qp1_metadata & CQ_RES_RAWETH_QP1_RAWETH_QP1_METADATA_DE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                            cqe_type_toggle = 0x%02"PRIX8"\n", data->cqe_type_toggle);
	RTE_LOG(INFO, PMD, "                                     status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "                                              Value : %s\n",
		data->status == CQ_RES_RAWETH_QP1_STATUS_OK ? "OK" :
		data->status == CQ_RES_RAWETH_QP1_STATUS_LOCAL_ACCESS_ERROR ? "LOCAL_ACCESS_ERROR" :
		data->status == CQ_RES_RAWETH_QP1_STATUS_HW_LOCAL_LENGTH_ERR ? "HW_LOCAL_LENGTH_ERR" :
		data->status == CQ_RES_RAWETH_QP1_STATUS_LOCAL_PROTECTION_ERR ? "LOCAL_PROTECTION_ERR" :
		data->status == CQ_RES_RAWETH_QP1_STATUS_LOCAL_QP_OPERATION_ERR ? "LOCAL_QP_OPERATION_ERR" :
		data->status == CQ_RES_RAWETH_QP1_STATUS_MEMORY_MGT_OPERATION_ERR ? "MEMORY_MGT_OPERATION_ERR" :
		data->status == CQ_RES_RAWETH_QP1_STATUS_WORK_REQUEST_FLUSHED_ERR ? "WORK_REQUEST_FLUSHED_ERR" :
		data->status == CQ_RES_RAWETH_QP1_STATUS_HW_FLUSH_ERR ? "HW_FLUSH_ERR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                                      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                                              Value : %s\n",
		data->flags == CQ_RES_RAWETH_QP1_FLAGS_SRQ ? "SRQ" :
		data->flags == CQ_RES_RAWETH_QP1_FLAGS_SRQ_RQ ? "SRQ_RQ" :
		data->flags == CQ_RES_RAWETH_QP1_FLAGS_SRQ_SRQ ? "SRQ_SRQ" :
		data->flags == CQ_RES_RAWETH_QP1_FLAGS_SRQ_LAST ? "SRQ_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  raweth_qp1_payload_offset_srq_or_rq_wr_id = 0x%08"PRIX32"\n", data->raweth_qp1_payload_offset_srq_or_rq_wr_id);
}

void decode_cq_terminal(const char *string __rte_unused, struct cq_terminal *data) {
	RTE_LOG(INFO, PMD, "cq_terminal\n");
	RTE_LOG(INFO, PMD, "        qp_handle = 0x%016"PRIX64"\n", data->qp_handle);
	RTE_LOG(INFO, PMD, "      sq_cons_idx = 0x%04"PRIX16"\n", data->sq_cons_idx);
	RTE_LOG(INFO, PMD, "      rq_cons_idx = 0x%04"PRIX16"\n", data->rq_cons_idx);
	RTE_LOG(INFO, PMD, "     reserved32_1 = 0x%08"PRIX32"\n", data->reserved32_1);
	RTE_LOG(INFO, PMD, "     reserved64_3 = 0x%016"PRIX64"\n", data->reserved64_3);
	RTE_LOG(INFO, PMD, "  cqe_type_toggle = 0x%02"PRIX8"\n", data->cqe_type_toggle);
	RTE_LOG(INFO, PMD, "           status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->status == CQ_TERMINAL_STATUS_OK ? "OK" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "     reserved32_2 = 0x%08"PRIX32"\n", data->reserved32_2);
}

void decode_cq_cutoff(const char *string __rte_unused, struct cq_cutoff *data) {
	RTE_LOG(INFO, PMD, "cq_cutoff\n");
	RTE_LOG(INFO, PMD, "     reserved64_1 = 0x%016"PRIX64"\n", data->reserved64_1);
	RTE_LOG(INFO, PMD, "     reserved64_2 = 0x%016"PRIX64"\n", data->reserved64_2);
	RTE_LOG(INFO, PMD, "     reserved64_3 = 0x%016"PRIX64"\n", data->reserved64_3);
	RTE_LOG(INFO, PMD, "  cqe_type_toggle = 0x%02"PRIX8"\n", data->cqe_type_toggle);
	RTE_LOG(INFO, PMD, "           status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->status == CQ_CUTOFF_STATUS_OK ? "OK" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "       reserved32 = 0x%08"PRIX32"\n", data->reserved32);
}

void decode_nq_base(const char *string __rte_unused, struct nq_base *data) {
	RTE_LOG(INFO, PMD, "nq_base\n");
	RTE_LOG(INFO, PMD, "  info10_type = 0x%04"PRIX16"\n", data->info10_type);
	RTE_LOG(INFO, PMD, "       info16 = 0x%04"PRIX16"\n", data->info16);
	RTE_LOG(INFO, PMD, "       info32 = 0x%08"PRIX32"\n", data->info32);
	RTE_LOG(INFO, PMD, "     info63_v = 0x%016"PRIX64"\n", data->info63_v);
}

void decode_nq_cn(const char *string __rte_unused, struct nq_cn *data) {
	RTE_LOG(INFO, PMD, "nq_cn\n");
	RTE_LOG(INFO, PMD, "            type = 0x%04"PRIX16"\n", data->type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		(data->type & NQ_CN_TYPE_MASK) == NQ_CN_TYPE_SFT ? "SFT" :
		(data->type & NQ_CN_TYPE_MASK) == NQ_CN_TYPE_CQ_NOTIFICATION ? "CQ_NOTIFICATION" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "   cq_handle_low = 0x%08"PRIX32"\n", data->cq_handle_low);
	RTE_LOG(INFO, PMD, "               v = 0x%08"PRIX32"\n", data->v);
	RTE_LOG(INFO, PMD, "  cq_handle_high = 0x%08"PRIX32"\n", data->cq_handle_high);
}

void decode_nq_srq_event(const char *string __rte_unused, struct nq_srq_event *data) {
	RTE_LOG(INFO, PMD, "nq_srq_event\n");
	RTE_LOG(INFO, PMD, "             type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		(data->type & NQ_SRQ_EVENT_TYPE_MASK) == NQ_SRQ_EVENT_TYPE_SFT ? "SFT" :
		(data->type & NQ_SRQ_EVENT_TYPE_MASK) == NQ_SRQ_EVENT_TYPE_SRQ_EVENT ? "SRQ_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                    SRQ_THRESHOLD_EVENT : %s\n", (data->event & NQ_SRQ_EVENT_EVENT_SRQ_THRESHOLD_EVENT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "       reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "   srq_handle_low = 0x%08"PRIX32"\n", data->srq_handle_low);
	RTE_LOG(INFO, PMD, "                v = 0x%08"PRIX32"\n", data->v);
	RTE_LOG(INFO, PMD, "  srq_handle_high = 0x%08"PRIX32"\n", data->srq_handle_high);
}

void decode_nq_dbq_event(const char *string __rte_unused, struct nq_dbq_event *data) {
	RTE_LOG(INFO, PMD, "nq_dbq_event\n");
	RTE_LOG(INFO, PMD, "            type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		(data->type & NQ_DBQ_EVENT_TYPE_MASK) == NQ_DBQ_EVENT_TYPE_SFT ? "SFT" :
		(data->type & NQ_DBQ_EVENT_TYPE_MASK) == NQ_DBQ_EVENT_TYPE_DBQ_EVENT ? "DBQ_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                   DBQ_THRESHOLD_EVENT : %s\n", (data->event & NQ_DBQ_EVENT_EVENT_DBQ_THRESHOLD_EVENT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         db_pfid = 0x%04"PRIX16"\n", data->db_pfid);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		(data->db_pfid & NQ_DBQ_EVENT_DB_PFID_MASK) == NQ_DBQ_EVENT_DB_PFID_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          db_dpi = 0x%08"PRIX32"\n", data->db_dpi);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		(data->db_dpi & NQ_DBQ_EVENT_DB_DPI_MASK) == NQ_DBQ_EVENT_DB_DPI_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "               v = 0x%08"PRIX32"\n", data->v);
	RTE_LOG(INFO, PMD, "  db_type_db_xid = 0x%08"PRIX32"\n", data->db_type_db_xid);
}

void decode_xrrq_irrq(const char *string __rte_unused, struct xrrq_irrq *data) {
	RTE_LOG(INFO, PMD, "xrrq_irrq\n");
	RTE_LOG(INFO, PMD, "         credits_type = 0x%04"PRIX16"\n", data->credits_type);
	RTE_LOG(INFO, PMD, "           reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "           reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "                  psn = 0x%08"PRIX32"\n", data->psn);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		(data->psn & XRRQ_IRRQ_PSN_MASK) == XRRQ_IRRQ_PSN_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                  msn = 0x%08"PRIX32"\n", data->msn);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		(data->msn & XRRQ_IRRQ_MSN_MASK) == XRRQ_IRRQ_MSN_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  va_or_atomic_result = 0x%016"PRIX64"\n", data->va_or_atomic_result);
	RTE_LOG(INFO, PMD, "           rdma_r_key = 0x%08"PRIX32"\n", data->rdma_r_key);
	RTE_LOG(INFO, PMD, "               length = 0x%08"PRIX32"\n", data->length);
}

void decode_xrrq_orrq(const char *string __rte_unused, struct xrrq_orrq *data) {
	RTE_LOG(INFO, PMD, "xrrq_orrq\n");
	RTE_LOG(INFO, PMD, "                 num_sges_type = 0x%04"PRIX16"\n", data->num_sges_type);
	RTE_LOG(INFO, PMD, "                    reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "                        length = 0x%08"PRIX32"\n", data->length);
	RTE_LOG(INFO, PMD, "                           psn = 0x%08"PRIX32"\n", data->psn);
	RTE_LOG(INFO, PMD, "                                 Value : %s\n",
		(data->psn & XRRQ_ORRQ_PSN_MASK) == XRRQ_ORRQ_PSN_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                       end_psn = 0x%08"PRIX32"\n", data->end_psn);
	RTE_LOG(INFO, PMD, "                                 Value : %s\n",
		(data->end_psn & XRRQ_ORRQ_END_PSN_MASK) == XRRQ_ORRQ_END_PSN_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  first_sge_phy_or_sing_sge_va = 0x%016"PRIX64"\n", data->first_sge_phy_or_sing_sge_va);
	RTE_LOG(INFO, PMD, "              single_sge_l_key = 0x%08"PRIX32"\n", data->single_sge_l_key);
	RTE_LOG(INFO, PMD, "               single_sge_size = 0x%08"PRIX32"\n", data->single_sge_size);
}

void decode_ptu_pte(const char *string __rte_unused, struct ptu_pte *data) {
	RTE_LOG(INFO, PMD, "ptu_pte\n");
	RTE_LOG(INFO, PMD, "  page_next_to_last_last_valid = 0x%016"PRIX64"\n", data->page_next_to_last_last_valid);
}

void decode_ptu_pde(const char *string __rte_unused, struct ptu_pde *data) {
	RTE_LOG(INFO, PMD, "ptu_pde\n");
	RTE_LOG(INFO, PMD, "  page_valid = 0x%016"PRIX64"\n", data->page_valid);
}

void decode_hwrm_ver_get_input(const char *string __rte_unused, struct hwrm_ver_get_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ver_get_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  hwrm_intf_maj = 0x%02"PRIX8"\n", data->hwrm_intf_maj);
	RTE_LOG(INFO, PMD, "  hwrm_intf_min = 0x%02"PRIX8"\n", data->hwrm_intf_min);
	RTE_LOG(INFO, PMD, "  hwrm_intf_upd = 0x%02"PRIX8"\n", data->hwrm_intf_upd);
	RTE_LOG(INFO, PMD, "    unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "    unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "    unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "    unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "    unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
}

void decode_hwrm_ver_get_output(const char *string __rte_unused, struct hwrm_ver_get_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ver_get_output\n");
	RTE_LOG(INFO, PMD, "           error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "             req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "               seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "        hwrm_intf_maj = 0x%02"PRIX8"\n", data->hwrm_intf_maj);
	RTE_LOG(INFO, PMD, "        hwrm_intf_min = 0x%02"PRIX8"\n", data->hwrm_intf_min);
	RTE_LOG(INFO, PMD, "        hwrm_intf_upd = 0x%02"PRIX8"\n", data->hwrm_intf_upd);
	RTE_LOG(INFO, PMD, "       hwrm_intf_rsvd = 0x%02"PRIX8"\n", data->hwrm_intf_rsvd);
	RTE_LOG(INFO, PMD, "          hwrm_fw_maj = 0x%02"PRIX8"\n", data->hwrm_fw_maj);
	RTE_LOG(INFO, PMD, "          hwrm_fw_min = 0x%02"PRIX8"\n", data->hwrm_fw_min);
	RTE_LOG(INFO, PMD, "          hwrm_fw_bld = 0x%02"PRIX8"\n", data->hwrm_fw_bld);
	RTE_LOG(INFO, PMD, "         hwrm_fw_rsvd = 0x%02"PRIX8"\n", data->hwrm_fw_rsvd);
	RTE_LOG(INFO, PMD, "          mgmt_fw_maj = 0x%02"PRIX8"\n", data->mgmt_fw_maj);
	RTE_LOG(INFO, PMD, "          mgmt_fw_min = 0x%02"PRIX8"\n", data->mgmt_fw_min);
	RTE_LOG(INFO, PMD, "          mgmt_fw_bld = 0x%02"PRIX8"\n", data->mgmt_fw_bld);
	RTE_LOG(INFO, PMD, "         mgmt_fw_rsvd = 0x%02"PRIX8"\n", data->mgmt_fw_rsvd);
	RTE_LOG(INFO, PMD, "       netctrl_fw_maj = 0x%02"PRIX8"\n", data->netctrl_fw_maj);
	RTE_LOG(INFO, PMD, "       netctrl_fw_min = 0x%02"PRIX8"\n", data->netctrl_fw_min);
	RTE_LOG(INFO, PMD, "       netctrl_fw_bld = 0x%02"PRIX8"\n", data->netctrl_fw_bld);
	RTE_LOG(INFO, PMD, "      netctrl_fw_rsvd = 0x%02"PRIX8"\n", data->netctrl_fw_rsvd);
	RTE_LOG(INFO, PMD, "         dev_caps_cfg = 0x%08"PRIX32"\n", data->dev_caps_cfg);
	RTE_LOG(INFO, PMD, "                        SECURE_FW_UPD_SUPPORTED : %s\n", (data->dev_caps_cfg & HWRM_VER_GET_OUTPUT_DEV_CAPS_CFG_SECURE_FW_UPD_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        FW_DCBX_AGENT_SUPPORTED : %s\n", (data->dev_caps_cfg & HWRM_VER_GET_OUTPUT_DEV_CAPS_CFG_FW_DCBX_AGENT_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        SHORT_CMD_SUPPORTED : %s\n", (data->dev_caps_cfg & HWRM_VER_GET_OUTPUT_DEV_CAPS_CFG_SHORT_CMD_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        SHORT_CMD_REQUIRED : %s\n", (data->dev_caps_cfg & HWRM_VER_GET_OUTPUT_DEV_CAPS_CFG_SHORT_CMD_REQUIRED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "          roce_fw_maj = 0x%02"PRIX8"\n", data->roce_fw_maj);
	RTE_LOG(INFO, PMD, "          roce_fw_min = 0x%02"PRIX8"\n", data->roce_fw_min);
	RTE_LOG(INFO, PMD, "          roce_fw_bld = 0x%02"PRIX8"\n", data->roce_fw_bld);
	RTE_LOG(INFO, PMD, "         roce_fw_rsvd = 0x%02"PRIX8"\n", data->roce_fw_rsvd);
	RTE_LOG(INFO, PMD, "         hwrm_fw_name = \"%.16s\"\n", data->hwrm_fw_name);
	RTE_LOG(INFO, PMD, "         mgmt_fw_name = \"%.16s\"\n", data->mgmt_fw_name);
	RTE_LOG(INFO, PMD, "      netctrl_fw_name = \"%.16s\"\n", data->netctrl_fw_name);
	RTE_LOG(INFO, PMD, "         reserved2[0] = 0x%08"PRIX32"\n", data->reserved2[0]);
	RTE_LOG(INFO, PMD, "         reserved2[1] = 0x%08"PRIX32"\n", data->reserved2[1]);
	RTE_LOG(INFO, PMD, "         reserved2[2] = 0x%08"PRIX32"\n", data->reserved2[2]);
	RTE_LOG(INFO, PMD, "         reserved2[3] = 0x%08"PRIX32"\n", data->reserved2[3]);
	RTE_LOG(INFO, PMD, "         roce_fw_name = \"%.16s\"\n", data->roce_fw_name);
	RTE_LOG(INFO, PMD, "             chip_num = 0x%04"PRIX16"\n", data->chip_num);
	RTE_LOG(INFO, PMD, "             chip_rev = 0x%02"PRIX8"\n", data->chip_rev);
	RTE_LOG(INFO, PMD, "           chip_metal = 0x%02"PRIX8"\n", data->chip_metal);
	RTE_LOG(INFO, PMD, "         chip_bond_id = 0x%02"PRIX8"\n", data->chip_bond_id);
	RTE_LOG(INFO, PMD, "   chip_platform_type = 0x%02"PRIX8"\n", data->chip_platform_type);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->chip_platform_type == HWRM_VER_GET_OUTPUT_CHIP_PLATFORM_TYPE_ASIC ? "ASIC" :
		data->chip_platform_type == HWRM_VER_GET_OUTPUT_CHIP_PLATFORM_TYPE_FPGA ? "FPGA" :
		data->chip_platform_type == HWRM_VER_GET_OUTPUT_CHIP_PLATFORM_TYPE_PALLADIUM ? "PALLADIUM" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      max_req_win_len = 0x%04"PRIX16"\n", data->max_req_win_len);
	RTE_LOG(INFO, PMD, "         max_resp_len = 0x%04"PRIX16"\n", data->max_resp_len);
	RTE_LOG(INFO, PMD, "      def_req_timeout = 0x%04"PRIX16"\n", data->def_req_timeout);
	RTE_LOG(INFO, PMD, "             unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "             unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "             unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "                valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_reset_input(const char *string __rte_unused, struct hwrm_func_reset_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_reset_input\n");
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "           enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                     VF_ID_VALID : %s\n", (data->enables & HWRM_FUNC_RESET_INPUT_ENABLES_VF_ID_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "  func_reset_level = 0x%02"PRIX8"\n", data->func_reset_level);
	RTE_LOG(INFO, PMD, "                     Value : %s\n",
		data->func_reset_level == HWRM_FUNC_RESET_INPUT_FUNC_RESET_LEVEL_RESETALL ? "RESETALL" :
		data->func_reset_level == HWRM_FUNC_RESET_INPUT_FUNC_RESET_LEVEL_RESETME ? "RESETME" :
		data->func_reset_level == HWRM_FUNC_RESET_INPUT_FUNC_RESET_LEVEL_RESETCHILDREN ? "RESETCHILDREN" :
		data->func_reset_level == HWRM_FUNC_RESET_INPUT_FUNC_RESET_LEVEL_RESETVF ? "RESETVF" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          unused_0 = 0x%02"PRIX8"\n", data->unused_0);
}

void decode_hwrm_func_reset_output(const char *string __rte_unused, struct hwrm_func_reset_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_reset_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_getfid_input(const char *string __rte_unused, struct hwrm_func_getfid_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_getfid_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "              PCI_ID : %s\n", (data->enables & HWRM_FUNC_GETFID_INPUT_ENABLES_PCI_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "     pci_id = 0x%04"PRIX16"\n", data->pci_id);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_func_getfid_output(const char *string __rte_unused, struct hwrm_func_getfid_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_getfid_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "         fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "    unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_vf_alloc_input(const char *string __rte_unused, struct hwrm_func_vf_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_alloc_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                FIRST_VF_ID : %s\n", (data->enables & HWRM_FUNC_VF_ALLOC_INPUT_ENABLES_FIRST_VF_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  first_vf_id = 0x%04"PRIX16"\n", data->first_vf_id);
	RTE_LOG(INFO, PMD, "      num_vfs = 0x%04"PRIX16"\n", data->num_vfs);
}

void decode_hwrm_func_vf_alloc_output(const char *string __rte_unused, struct hwrm_func_vf_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_alloc_output\n");
	RTE_LOG(INFO, PMD, "   error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  first_vf_id = 0x%04"PRIX16"\n", data->first_vf_id);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "     unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "     unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "     unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "        valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_vf_free_input(const char *string __rte_unused, struct hwrm_func_vf_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_free_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                FIRST_VF_ID : %s\n", (data->enables & HWRM_FUNC_VF_FREE_INPUT_ENABLES_FIRST_VF_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  first_vf_id = 0x%04"PRIX16"\n", data->first_vf_id);
	RTE_LOG(INFO, PMD, "      num_vfs = 0x%04"PRIX16"\n", data->num_vfs);
}

void decode_hwrm_func_vf_free_output(const char *string __rte_unused, struct hwrm_func_vf_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_vf_cfg_input(const char *string __rte_unused, struct hwrm_func_vf_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_cfg_input\n");
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "           enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                     MTU : %s\n", (data->enables & HWRM_FUNC_VF_CFG_INPUT_ENABLES_MTU)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     GUEST_VLAN : %s\n", (data->enables & HWRM_FUNC_VF_CFG_INPUT_ENABLES_GUEST_VLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     ASYNC_EVENT_CR : %s\n", (data->enables & HWRM_FUNC_VF_CFG_INPUT_ENABLES_ASYNC_EVENT_CR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     DFLT_MAC_ADDR : %s\n", (data->enables & HWRM_FUNC_VF_CFG_INPUT_ENABLES_DFLT_MAC_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               mtu = 0x%04"PRIX16"\n", data->mtu);
	RTE_LOG(INFO, PMD, "        guest_vlan = 0x%04"PRIX16"\n", data->guest_vlan);
	RTE_LOG(INFO, PMD, "    async_event_cr = 0x%04"PRIX16"\n", data->async_event_cr);
	RTE_LOG(INFO, PMD, "  dflt_mac_addr[0] = 0x%02"PRIX8"\n", data->dflt_mac_addr[0]);
	RTE_LOG(INFO, PMD, "  dflt_mac_addr[1] = 0x%02"PRIX8"\n", data->dflt_mac_addr[1]);
	RTE_LOG(INFO, PMD, "  dflt_mac_addr[2] = 0x%02"PRIX8"\n", data->dflt_mac_addr[2]);
	RTE_LOG(INFO, PMD, "  dflt_mac_addr[3] = 0x%02"PRIX8"\n", data->dflt_mac_addr[3]);
	RTE_LOG(INFO, PMD, "  dflt_mac_addr[4] = 0x%02"PRIX8"\n", data->dflt_mac_addr[4]);
	RTE_LOG(INFO, PMD, "  dflt_mac_addr[5] = 0x%02"PRIX8"\n", data->dflt_mac_addr[5]);
}

void decode_hwrm_func_vf_cfg_output(const char *string __rte_unused, struct hwrm_func_vf_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_qcaps_input(const char *string __rte_unused, struct hwrm_func_qcaps_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_qcaps_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_func_qcaps_output(const char *string __rte_unused, struct hwrm_func_qcaps_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_qcaps_output\n");
	RTE_LOG(INFO, PMD, "         error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "                fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "            port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "              flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                      PUSH_MODE_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_PUSH_MODE_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      GLOBAL_MSIX_AUTOMASKING : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_GLOBAL_MSIX_AUTOMASKING)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PTP_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_PTP_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      ROCE_V1_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_ROCE_V1_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      ROCE_V2_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_ROCE_V2_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      WOL_MAGICPKT_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_WOL_MAGICPKT_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      WOL_BMP_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_WOL_BMP_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      TX_RING_RL_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_TX_RING_RL_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      TX_BW_CFG_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_TX_BW_CFG_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      VF_TX_RING_RL_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_VF_TX_RING_RL_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      VF_BW_CFG_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_VF_BW_CFG_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      STD_TX_RING_MODE_SUPPORTED : %s\n", (data->flags & HWRM_FUNC_QCAPS_OUTPUT_FLAGS_STD_TX_RING_MODE_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "     mac_address[0] = 0x%02"PRIX8"\n", data->mac_address[0]);
	RTE_LOG(INFO, PMD, "     mac_address[1] = 0x%02"PRIX8"\n", data->mac_address[1]);
	RTE_LOG(INFO, PMD, "     mac_address[2] = 0x%02"PRIX8"\n", data->mac_address[2]);
	RTE_LOG(INFO, PMD, "     mac_address[3] = 0x%02"PRIX8"\n", data->mac_address[3]);
	RTE_LOG(INFO, PMD, "     mac_address[4] = 0x%02"PRIX8"\n", data->mac_address[4]);
	RTE_LOG(INFO, PMD, "     mac_address[5] = 0x%02"PRIX8"\n", data->mac_address[5]);
	RTE_LOG(INFO, PMD, "     max_rsscos_ctx = 0x%04"PRIX16"\n", data->max_rsscos_ctx);
	RTE_LOG(INFO, PMD, "     max_cmpl_rings = 0x%04"PRIX16"\n", data->max_cmpl_rings);
	RTE_LOG(INFO, PMD, "       max_tx_rings = 0x%04"PRIX16"\n", data->max_tx_rings);
	RTE_LOG(INFO, PMD, "       max_rx_rings = 0x%04"PRIX16"\n", data->max_rx_rings);
	RTE_LOG(INFO, PMD, "        max_l2_ctxs = 0x%04"PRIX16"\n", data->max_l2_ctxs);
	RTE_LOG(INFO, PMD, "          max_vnics = 0x%04"PRIX16"\n", data->max_vnics);
	RTE_LOG(INFO, PMD, "        first_vf_id = 0x%04"PRIX16"\n", data->first_vf_id);
	RTE_LOG(INFO, PMD, "            max_vfs = 0x%04"PRIX16"\n", data->max_vfs);
	RTE_LOG(INFO, PMD, "       max_stat_ctx = 0x%04"PRIX16"\n", data->max_stat_ctx);
	RTE_LOG(INFO, PMD, "  max_encap_records = 0x%08"PRIX32"\n", data->max_encap_records);
	RTE_LOG(INFO, PMD, "  max_decap_records = 0x%08"PRIX32"\n", data->max_decap_records);
	RTE_LOG(INFO, PMD, "    max_tx_em_flows = 0x%08"PRIX32"\n", data->max_tx_em_flows);
	RTE_LOG(INFO, PMD, "    max_tx_wm_flows = 0x%08"PRIX32"\n", data->max_tx_wm_flows);
	RTE_LOG(INFO, PMD, "    max_rx_em_flows = 0x%08"PRIX32"\n", data->max_rx_em_flows);
	RTE_LOG(INFO, PMD, "    max_rx_wm_flows = 0x%08"PRIX32"\n", data->max_rx_wm_flows);
	RTE_LOG(INFO, PMD, "  max_mcast_filters = 0x%08"PRIX32"\n", data->max_mcast_filters);
	RTE_LOG(INFO, PMD, "        max_flow_id = 0x%08"PRIX32"\n", data->max_flow_id);
	RTE_LOG(INFO, PMD, "   max_hw_ring_grps = 0x%08"PRIX32"\n", data->max_hw_ring_grps);
	RTE_LOG(INFO, PMD, "    max_sp_tx_rings = 0x%04"PRIX16"\n", data->max_sp_tx_rings);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "              valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_qcfg_input(const char *string __rte_unused, struct hwrm_func_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_func_qcfg_output(const char *string __rte_unused, struct hwrm_func_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_qcfg_output\n");
	RTE_LOG(INFO, PMD, "           error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "             req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "               seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "                  fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "              port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "                 vlan = 0x%04"PRIX16"\n", data->vlan);
	RTE_LOG(INFO, PMD, "                flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                        OOB_WOL_MAGICPKT_ENABLED : %s\n", (data->flags & HWRM_FUNC_QCFG_OUTPUT_FLAGS_OOB_WOL_MAGICPKT_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        OOB_WOL_BMP_ENABLED : %s\n", (data->flags & HWRM_FUNC_QCFG_OUTPUT_FLAGS_OOB_WOL_BMP_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        FW_DCBX_AGENT_ENABLED : %s\n", (data->flags & HWRM_FUNC_QCFG_OUTPUT_FLAGS_FW_DCBX_AGENT_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        STD_TX_RING_MODE_ENABLED : %s\n", (data->flags & HWRM_FUNC_QCFG_OUTPUT_FLAGS_STD_TX_RING_MODE_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "       mac_address[0] = 0x%02"PRIX8"\n", data->mac_address[0]);
	RTE_LOG(INFO, PMD, "       mac_address[1] = 0x%02"PRIX8"\n", data->mac_address[1]);
	RTE_LOG(INFO, PMD, "       mac_address[2] = 0x%02"PRIX8"\n", data->mac_address[2]);
	RTE_LOG(INFO, PMD, "       mac_address[3] = 0x%02"PRIX8"\n", data->mac_address[3]);
	RTE_LOG(INFO, PMD, "       mac_address[4] = 0x%02"PRIX8"\n", data->mac_address[4]);
	RTE_LOG(INFO, PMD, "       mac_address[5] = 0x%02"PRIX8"\n", data->mac_address[5]);
	RTE_LOG(INFO, PMD, "               pci_id = 0x%04"PRIX16"\n", data->pci_id);
	RTE_LOG(INFO, PMD, "     alloc_rsscos_ctx = 0x%04"PRIX16"\n", data->alloc_rsscos_ctx);
	RTE_LOG(INFO, PMD, "     alloc_cmpl_rings = 0x%04"PRIX16"\n", data->alloc_cmpl_rings);
	RTE_LOG(INFO, PMD, "       alloc_tx_rings = 0x%04"PRIX16"\n", data->alloc_tx_rings);
	RTE_LOG(INFO, PMD, "       alloc_rx_rings = 0x%04"PRIX16"\n", data->alloc_rx_rings);
	RTE_LOG(INFO, PMD, "         alloc_l2_ctx = 0x%04"PRIX16"\n", data->alloc_l2_ctx);
	RTE_LOG(INFO, PMD, "          alloc_vnics = 0x%04"PRIX16"\n", data->alloc_vnics);
	RTE_LOG(INFO, PMD, "                  mtu = 0x%04"PRIX16"\n", data->mtu);
	RTE_LOG(INFO, PMD, "                  mru = 0x%04"PRIX16"\n", data->mru);
	RTE_LOG(INFO, PMD, "          stat_ctx_id = 0x%04"PRIX16"\n", data->stat_ctx_id);
	RTE_LOG(INFO, PMD, "  port_partition_type = 0x%02"PRIX8"\n", data->port_partition_type);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->port_partition_type == HWRM_FUNC_QCFG_OUTPUT_PORT_PARTITION_TYPE_SPF ? "SPF" :
		data->port_partition_type == HWRM_FUNC_QCFG_OUTPUT_PORT_PARTITION_TYPE_MPFS ? "MPFS" :
		data->port_partition_type == HWRM_FUNC_QCFG_OUTPUT_PORT_PARTITION_TYPE_NPAR1_0 ? "NPAR1_0" :
		data->port_partition_type == HWRM_FUNC_QCFG_OUTPUT_PORT_PARTITION_TYPE_NPAR1_5 ? "NPAR1_5" :
		data->port_partition_type == HWRM_FUNC_QCFG_OUTPUT_PORT_PARTITION_TYPE_NPAR2_0 ? "NPAR2_0" :
		data->port_partition_type == HWRM_FUNC_QCFG_OUTPUT_PORT_PARTITION_TYPE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "         dflt_vnic_id = 0x%04"PRIX16"\n", data->dflt_vnic_id);
	RTE_LOG(INFO, PMD, "             unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "             unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "               min_bw = 0x%08"PRIX32"\n", data->min_bw);
	RTE_LOG(INFO, PMD, "                        BW_VALUE = %0*X\n", 17, ((data->min_bw & HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_MASK) >> HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                        BW_VALUE_UNIT = %0*X\n", 11, ((data->min_bw & HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->min_bw == HWRM_FUNC_QCFG_OUTPUT_MIN_BW_RSVD ? "RSVD" :
		data->min_bw == HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->min_bw == HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->min_bw == HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->min_bw == HWRM_FUNC_QCFG_OUTPUT_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "               max_bw = 0x%08"PRIX32"\n", data->max_bw);
	RTE_LOG(INFO, PMD, "                        BW_VALUE = %0*X\n", 17, ((data->max_bw & HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_MASK) >> HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                        BW_VALUE_UNIT = %0*X\n", 11, ((data->max_bw & HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->max_bw == HWRM_FUNC_QCFG_OUTPUT_MAX_BW_RSVD ? "RSVD" :
		data->max_bw == HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->max_bw == HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->max_bw == HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->max_bw == HWRM_FUNC_QCFG_OUTPUT_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             evb_mode = 0x%02"PRIX8"\n", data->evb_mode);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->evb_mode == HWRM_FUNC_QCFG_OUTPUT_EVB_MODE_NO_EVB ? "NO_EVB" :
		data->evb_mode == HWRM_FUNC_QCFG_OUTPUT_EVB_MODE_VEB ? "VEB" :
		data->evb_mode == HWRM_FUNC_QCFG_OUTPUT_EVB_MODE_VEPA ? "VEPA" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "            alloc_vfs = 0x%04"PRIX16"\n", data->alloc_vfs);
	RTE_LOG(INFO, PMD, "  alloc_mcast_filters = 0x%08"PRIX32"\n", data->alloc_mcast_filters);
	RTE_LOG(INFO, PMD, "   alloc_hw_ring_grps = 0x%08"PRIX32"\n", data->alloc_hw_ring_grps);
	RTE_LOG(INFO, PMD, "    alloc_sp_tx_rings = 0x%04"PRIX16"\n", data->alloc_sp_tx_rings);
	RTE_LOG(INFO, PMD, "             unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "                valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_cfg_input(const char *string __rte_unused, struct hwrm_func_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_cfg_input\n");
	RTE_LOG(INFO, PMD, "             req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "            cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "               seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "            target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "            resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                  fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "             unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "             unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "                flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                        PROM_MODE : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_PROM_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        SRC_MAC_ADDR_CHECK : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_SRC_MAC_ADDR_CHECK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        SRC_IP_ADDR_CHECK : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_SRC_IP_ADDR_CHECK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        VLAN_PRI_MATCH : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_VLAN_PRI_MATCH)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DFLT_PRI_NOMATCH : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_DFLT_PRI_NOMATCH)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DISABLE_PAUSE : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_DISABLE_PAUSE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DISABLE_STP : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_DISABLE_STP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DISABLE_LLDP : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_DISABLE_LLDP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DISABLE_PTPV2 : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_DISABLE_PTPV2)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        STD_TX_RING_MODE : %s\n", (data->flags & HWRM_FUNC_CFG_INPUT_FLAGS_STD_TX_RING_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                        MTU : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_MTU)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        MRU : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_MRU)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_RSSCOS_CTXS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_RSSCOS_CTXS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_CMPL_RINGS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_CMPL_RINGS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_TX_RINGS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_TX_RINGS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_RX_RINGS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_RX_RINGS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_L2_CTXS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_L2_CTXS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_VNICS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_VNICS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_STAT_CTXS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_STAT_CTXS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DFLT_MAC_ADDR : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_DFLT_MAC_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DFLT_VLAN : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_DFLT_VLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        DFLT_IP_ADDR : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_DFLT_IP_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        MIN_BW : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_MIN_BW)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        MAX_BW : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_MAX_BW)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        ASYNC_EVENT_CR : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_ASYNC_EVENT_CR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        VLAN_ANTISPOOF_MODE : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_VLAN_ANTISPOOF_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        ALLOWED_VLAN_PRIS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_ALLOWED_VLAN_PRIS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        EVB_MODE : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_EVB_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_MCAST_FILTERS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_MCAST_FILTERS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        NUM_HW_RING_GRPS : %s\n", (data->enables & HWRM_FUNC_CFG_INPUT_ENABLES_NUM_HW_RING_GRPS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  mtu = 0x%04"PRIX16"\n", data->mtu);
	RTE_LOG(INFO, PMD, "                  mru = 0x%04"PRIX16"\n", data->mru);
	RTE_LOG(INFO, PMD, "      num_rsscos_ctxs = 0x%04"PRIX16"\n", data->num_rsscos_ctxs);
	RTE_LOG(INFO, PMD, "       num_cmpl_rings = 0x%04"PRIX16"\n", data->num_cmpl_rings);
	RTE_LOG(INFO, PMD, "         num_tx_rings = 0x%04"PRIX16"\n", data->num_tx_rings);
	RTE_LOG(INFO, PMD, "         num_rx_rings = 0x%04"PRIX16"\n", data->num_rx_rings);
	RTE_LOG(INFO, PMD, "          num_l2_ctxs = 0x%04"PRIX16"\n", data->num_l2_ctxs);
	RTE_LOG(INFO, PMD, "            num_vnics = 0x%04"PRIX16"\n", data->num_vnics);
	RTE_LOG(INFO, PMD, "        num_stat_ctxs = 0x%04"PRIX16"\n", data->num_stat_ctxs);
	RTE_LOG(INFO, PMD, "     num_hw_ring_grps = 0x%04"PRIX16"\n", data->num_hw_ring_grps);
	RTE_LOG(INFO, PMD, "     dflt_mac_addr[0] = 0x%02"PRIX8"\n", data->dflt_mac_addr[0]);
	RTE_LOG(INFO, PMD, "     dflt_mac_addr[1] = 0x%02"PRIX8"\n", data->dflt_mac_addr[1]);
	RTE_LOG(INFO, PMD, "     dflt_mac_addr[2] = 0x%02"PRIX8"\n", data->dflt_mac_addr[2]);
	RTE_LOG(INFO, PMD, "     dflt_mac_addr[3] = 0x%02"PRIX8"\n", data->dflt_mac_addr[3]);
	RTE_LOG(INFO, PMD, "     dflt_mac_addr[4] = 0x%02"PRIX8"\n", data->dflt_mac_addr[4]);
	RTE_LOG(INFO, PMD, "     dflt_mac_addr[5] = 0x%02"PRIX8"\n", data->dflt_mac_addr[5]);
	RTE_LOG(INFO, PMD, "            dflt_vlan = 0x%04"PRIX16"\n", data->dflt_vlan);
	RTE_LOG(INFO, PMD, "      dflt_ip_addr[0] = 0x%08"PRIX32"\n", data->dflt_ip_addr[0]);
	RTE_LOG(INFO, PMD, "      dflt_ip_addr[1] = 0x%08"PRIX32"\n", data->dflt_ip_addr[1]);
	RTE_LOG(INFO, PMD, "      dflt_ip_addr[2] = 0x%08"PRIX32"\n", data->dflt_ip_addr[2]);
	RTE_LOG(INFO, PMD, "      dflt_ip_addr[3] = 0x%08"PRIX32"\n", data->dflt_ip_addr[3]);
	RTE_LOG(INFO, PMD, "               min_bw = 0x%08"PRIX32"\n", data->min_bw);
	RTE_LOG(INFO, PMD, "                        BW_VALUE = %0*X\n", 17, ((data->min_bw & HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_MASK) >> HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                        BW_VALUE_UNIT = %0*X\n", 11, ((data->min_bw & HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->min_bw == HWRM_FUNC_CFG_INPUT_MIN_BW_RSVD ? "RSVD" :
		data->min_bw == HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->min_bw == HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->min_bw == HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->min_bw == HWRM_FUNC_CFG_INPUT_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "               max_bw = 0x%08"PRIX32"\n", data->max_bw);
	RTE_LOG(INFO, PMD, "                        BW_VALUE = %0*X\n", 17, ((data->max_bw & HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_MASK) >> HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                        BW_VALUE_UNIT = %0*X\n", 11, ((data->max_bw & HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->max_bw == HWRM_FUNC_CFG_INPUT_MAX_BW_RSVD ? "RSVD" :
		data->max_bw == HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->max_bw == HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->max_bw == HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->max_bw == HWRM_FUNC_CFG_INPUT_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       async_event_cr = 0x%04"PRIX16"\n", data->async_event_cr);
	RTE_LOG(INFO, PMD, "  vlan_antispoof_mode = 0x%02"PRIX8"\n", data->vlan_antispoof_mode);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->vlan_antispoof_mode == HWRM_FUNC_CFG_INPUT_VLAN_ANTISPOOF_MODE_NOCHECK ? "NOCHECK" :
		data->vlan_antispoof_mode == HWRM_FUNC_CFG_INPUT_VLAN_ANTISPOOF_MODE_VALIDATE_VLAN ? "VALIDATE_VLAN" :
		data->vlan_antispoof_mode == HWRM_FUNC_CFG_INPUT_VLAN_ANTISPOOF_MODE_INSERT_IF_VLANDNE ? "INSERT_IF_VLANDNE" :
		data->vlan_antispoof_mode == HWRM_FUNC_CFG_INPUT_VLAN_ANTISPOOF_MODE_INSERT_OR_OVERRIDE_VLAN ? "INSERT_OR_OVERRIDE_VLAN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    allowed_vlan_pris = 0x%02"PRIX8"\n", data->allowed_vlan_pris);
	RTE_LOG(INFO, PMD, "             evb_mode = 0x%02"PRIX8"\n", data->evb_mode);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->evb_mode == HWRM_FUNC_CFG_INPUT_EVB_MODE_NO_EVB ? "NO_EVB" :
		data->evb_mode == HWRM_FUNC_CFG_INPUT_EVB_MODE_VEB ? "VEB" :
		data->evb_mode == HWRM_FUNC_CFG_INPUT_EVB_MODE_VEPA ? "VEPA" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    num_mcast_filters = 0x%04"PRIX16"\n", data->num_mcast_filters);
}

void decode_hwrm_func_cfg_output(const char *string __rte_unused, struct hwrm_func_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_qstats_input(const char *string __rte_unused, struct hwrm_func_qstats_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_qstats_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_func_qstats_output(const char *string __rte_unused, struct hwrm_func_qstats_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_qstats_output\n");
	RTE_LOG(INFO, PMD, "      error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "   tx_ucast_pkts = 0x%016"PRIX64"\n", data->tx_ucast_pkts);
	RTE_LOG(INFO, PMD, "   tx_mcast_pkts = 0x%016"PRIX64"\n", data->tx_mcast_pkts);
	RTE_LOG(INFO, PMD, "   tx_bcast_pkts = 0x%016"PRIX64"\n", data->tx_bcast_pkts);
	RTE_LOG(INFO, PMD, "     tx_err_pkts = 0x%016"PRIX64"\n", data->tx_err_pkts);
	RTE_LOG(INFO, PMD, "    tx_drop_pkts = 0x%016"PRIX64"\n", data->tx_drop_pkts);
	RTE_LOG(INFO, PMD, "  tx_ucast_bytes = 0x%016"PRIX64"\n", data->tx_ucast_bytes);
	RTE_LOG(INFO, PMD, "  tx_mcast_bytes = 0x%016"PRIX64"\n", data->tx_mcast_bytes);
	RTE_LOG(INFO, PMD, "  tx_bcast_bytes = 0x%016"PRIX64"\n", data->tx_bcast_bytes);
	RTE_LOG(INFO, PMD, "   rx_ucast_pkts = 0x%016"PRIX64"\n", data->rx_ucast_pkts);
	RTE_LOG(INFO, PMD, "   rx_mcast_pkts = 0x%016"PRIX64"\n", data->rx_mcast_pkts);
	RTE_LOG(INFO, PMD, "   rx_bcast_pkts = 0x%016"PRIX64"\n", data->rx_bcast_pkts);
	RTE_LOG(INFO, PMD, "     rx_err_pkts = 0x%016"PRIX64"\n", data->rx_err_pkts);
	RTE_LOG(INFO, PMD, "    rx_drop_pkts = 0x%016"PRIX64"\n", data->rx_drop_pkts);
	RTE_LOG(INFO, PMD, "  rx_ucast_bytes = 0x%016"PRIX64"\n", data->rx_ucast_bytes);
	RTE_LOG(INFO, PMD, "  rx_mcast_bytes = 0x%016"PRIX64"\n", data->rx_mcast_bytes);
	RTE_LOG(INFO, PMD, "  rx_bcast_bytes = 0x%016"PRIX64"\n", data->rx_bcast_bytes);
	RTE_LOG(INFO, PMD, "     rx_agg_pkts = 0x%016"PRIX64"\n", data->rx_agg_pkts);
	RTE_LOG(INFO, PMD, "    rx_agg_bytes = 0x%016"PRIX64"\n", data->rx_agg_bytes);
	RTE_LOG(INFO, PMD, "   rx_agg_events = 0x%016"PRIX64"\n", data->rx_agg_events);
	RTE_LOG(INFO, PMD, "   rx_agg_aborts = 0x%016"PRIX64"\n", data->rx_agg_aborts);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "           valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_clr_stats_input(const char *string __rte_unused, struct hwrm_func_clr_stats_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_clr_stats_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_func_clr_stats_output(const char *string __rte_unused, struct hwrm_func_clr_stats_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_clr_stats_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_vf_resc_free_input(const char *string __rte_unused, struct hwrm_func_vf_resc_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_resc_free_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "        vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_func_vf_resc_free_output(const char *string __rte_unused, struct hwrm_func_vf_resc_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_resc_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_vf_vnic_ids_query_input(const char *string __rte_unused, struct hwrm_func_vf_vnic_ids_query_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_vnic_ids_query_input\n");
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "             vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "          unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "          unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "   max_vnic_id_cnt = 0x%08"PRIX32"\n", data->max_vnic_id_cnt);
	RTE_LOG(INFO, PMD, "  vnic_id_tbl_addr = 0x%016"PRIX64"\n", data->vnic_id_tbl_addr);
}

void decode_hwrm_func_vf_vnic_ids_query_output(const char *string __rte_unused, struct hwrm_func_vf_vnic_ids_query_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_vf_vnic_ids_query_output\n");
	RTE_LOG(INFO, PMD, "   error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  vnic_id_cnt = 0x%08"PRIX32"\n", data->vnic_id_cnt);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "     unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_drv_rgtr_input(const char *string __rte_unused, struct hwrm_func_drv_rgtr_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_drv_rgtr_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "               flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                       FWD_ALL_MODE : %s\n", (data->flags & HWRM_FUNC_DRV_RGTR_INPUT_FLAGS_FWD_ALL_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       FWD_NONE_MODE : %s\n", (data->flags & HWRM_FUNC_DRV_RGTR_INPUT_FLAGS_FWD_NONE_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                       OS_TYPE : %s\n", (data->enables & HWRM_FUNC_DRV_RGTR_INPUT_ENABLES_OS_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       VER : %s\n", (data->enables & HWRM_FUNC_DRV_RGTR_INPUT_ENABLES_VER)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       TIMESTAMP : %s\n", (data->enables & HWRM_FUNC_DRV_RGTR_INPUT_ENABLES_TIMESTAMP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       VF_REQ_FWD : %s\n", (data->enables & HWRM_FUNC_DRV_RGTR_INPUT_ENABLES_VF_REQ_FWD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       ASYNC_EVENT_FWD : %s\n", (data->enables & HWRM_FUNC_DRV_RGTR_INPUT_ENABLES_ASYNC_EVENT_FWD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             os_type = 0x%04"PRIX16"\n", data->os_type);
	RTE_LOG(INFO, PMD, "                       Value : %s\n",
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_UNKNOWN ? "UNKNOWN" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_OTHER ? "OTHER" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_MSDOS ? "MSDOS" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_WINDOWS ? "WINDOWS" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_SOLARIS ? "SOLARIS" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_LINUX ? "LINUX" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_FREEBSD ? "FREEBSD" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_ESXI ? "ESXI" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_WIN864 ? "WIN864" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_WIN2012R2 ? "WIN2012R2" :
		data->os_type == HWRM_FUNC_DRV_RGTR_INPUT_OS_TYPE_UEFI ? "UEFI" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             ver_maj = 0x%02"PRIX8"\n", data->ver_maj);
	RTE_LOG(INFO, PMD, "             ver_min = 0x%02"PRIX8"\n", data->ver_min);
	RTE_LOG(INFO, PMD, "             ver_upd = 0x%02"PRIX8"\n", data->ver_upd);
	RTE_LOG(INFO, PMD, "            unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "            unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           timestamp = 0x%08"PRIX32"\n", data->timestamp);
	RTE_LOG(INFO, PMD, "            unused_2 = 0x%08"PRIX32"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[0] = 0x%08"PRIX32"\n", data->vf_req_fwd[0]);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[1] = 0x%08"PRIX32"\n", data->vf_req_fwd[1]);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[2] = 0x%08"PRIX32"\n", data->vf_req_fwd[2]);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[3] = 0x%08"PRIX32"\n", data->vf_req_fwd[3]);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[4] = 0x%08"PRIX32"\n", data->vf_req_fwd[4]);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[5] = 0x%08"PRIX32"\n", data->vf_req_fwd[5]);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[6] = 0x%08"PRIX32"\n", data->vf_req_fwd[6]);
	RTE_LOG(INFO, PMD, "       vf_req_fwd[7] = 0x%08"PRIX32"\n", data->vf_req_fwd[7]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[0] = 0x%08"PRIX32"\n", data->async_event_fwd[0]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[1] = 0x%08"PRIX32"\n", data->async_event_fwd[1]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[2] = 0x%08"PRIX32"\n", data->async_event_fwd[2]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[3] = 0x%08"PRIX32"\n", data->async_event_fwd[3]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[4] = 0x%08"PRIX32"\n", data->async_event_fwd[4]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[5] = 0x%08"PRIX32"\n", data->async_event_fwd[5]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[6] = 0x%08"PRIX32"\n", data->async_event_fwd[6]);
	RTE_LOG(INFO, PMD, "  async_event_fwd[7] = 0x%08"PRIX32"\n", data->async_event_fwd[7]);
}

void decode_hwrm_func_drv_rgtr_output(const char *string __rte_unused, struct hwrm_func_drv_rgtr_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_drv_rgtr_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_drv_unrgtr_input(const char *string __rte_unused, struct hwrm_func_drv_unrgtr_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_drv_unrgtr_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "              PREPARE_FOR_SHUTDOWN : %s\n", (data->flags & HWRM_FUNC_DRV_UNRGTR_INPUT_FLAGS_PREPARE_FOR_SHUTDOWN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_func_drv_unrgtr_output(const char *string __rte_unused, struct hwrm_func_drv_unrgtr_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_drv_unrgtr_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_buf_rgtr_input(const char *string __rte_unused, struct hwrm_func_buf_rgtr_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_buf_rgtr_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "             enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                       VF_ID : %s\n", (data->enables & HWRM_FUNC_BUF_RGTR_INPUT_ENABLES_VF_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       ERR_BUF_ADDR : %s\n", (data->enables & HWRM_FUNC_BUF_RGTR_INPUT_ENABLES_ERR_BUF_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "   req_buf_num_pages = 0x%04"PRIX16"\n", data->req_buf_num_pages);
	RTE_LOG(INFO, PMD, "   req_buf_page_size = 0x%04"PRIX16"\n", data->req_buf_page_size);
	RTE_LOG(INFO, PMD, "                       Value : %s\n",
		data->req_buf_page_size == HWRM_FUNC_BUF_RGTR_INPUT_REQ_BUF_PAGE_SIZE_16B ? "16B" :
		data->req_buf_page_size == HWRM_FUNC_BUF_RGTR_INPUT_REQ_BUF_PAGE_SIZE_4K ? "4K" :
		data->req_buf_page_size == HWRM_FUNC_BUF_RGTR_INPUT_REQ_BUF_PAGE_SIZE_8K ? "8K" :
		data->req_buf_page_size == HWRM_FUNC_BUF_RGTR_INPUT_REQ_BUF_PAGE_SIZE_64K ? "64K" :
		data->req_buf_page_size == HWRM_FUNC_BUF_RGTR_INPUT_REQ_BUF_PAGE_SIZE_2M ? "2M" :
		data->req_buf_page_size == HWRM_FUNC_BUF_RGTR_INPUT_REQ_BUF_PAGE_SIZE_4M ? "4M" :
		data->req_buf_page_size == HWRM_FUNC_BUF_RGTR_INPUT_REQ_BUF_PAGE_SIZE_1G ? "1G" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         req_buf_len = 0x%04"PRIX16"\n", data->req_buf_len);
	RTE_LOG(INFO, PMD, "        resp_buf_len = 0x%04"PRIX16"\n", data->resp_buf_len);
	RTE_LOG(INFO, PMD, "            unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "            unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr0 = 0x%016"PRIX64"\n", data->req_buf_page_addr[0]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr1 = 0x%016"PRIX64"\n", data->req_buf_page_addr[1]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr2 = 0x%016"PRIX64"\n", data->req_buf_page_addr[2]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr3 = 0x%016"PRIX64"\n", data->req_buf_page_addr[3]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr4 = 0x%016"PRIX64"\n", data->req_buf_page_addr[4]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr5 = 0x%016"PRIX64"\n", data->req_buf_page_addr[5]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr6 = 0x%016"PRIX64"\n", data->req_buf_page_addr[6]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr7 = 0x%016"PRIX64"\n", data->req_buf_page_addr[7]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr8 = 0x%016"PRIX64"\n", data->req_buf_page_addr[8]);
	RTE_LOG(INFO, PMD, "  req_buf_page_addr9 = 0x%016"PRIX64"\n", data->req_buf_page_addr[9]);
	RTE_LOG(INFO, PMD, "      error_buf_addr = 0x%016"PRIX64"\n", data->error_buf_addr);
	RTE_LOG(INFO, PMD, "       resp_buf_addr = 0x%016"PRIX64"\n", data->resp_buf_addr);
}

void decode_hwrm_func_buf_rgtr_output(const char *string __rte_unused, struct hwrm_func_buf_rgtr_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_buf_rgtr_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_buf_unrgtr_input(const char *string __rte_unused, struct hwrm_func_buf_unrgtr_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_buf_unrgtr_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "              VF_ID : %s\n", (data->enables & HWRM_FUNC_BUF_UNRGTR_INPUT_ENABLES_VF_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_func_buf_unrgtr_output(const char *string __rte_unused, struct hwrm_func_buf_unrgtr_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_buf_unrgtr_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_func_drv_qver_input(const char *string __rte_unused, struct hwrm_func_drv_qver_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_drv_qver_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "   reserved = 0x%08"PRIX32"\n", data->reserved);
	RTE_LOG(INFO, PMD, "        fid = 0x%04"PRIX16"\n", data->fid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_func_drv_qver_output(const char *string __rte_unused, struct hwrm_func_drv_qver_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_func_drv_qver_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "     os_type = 0x%04"PRIX16"\n", data->os_type);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_UNKNOWN ? "UNKNOWN" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_OTHER ? "OTHER" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_MSDOS ? "MSDOS" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_WINDOWS ? "WINDOWS" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_SOLARIS ? "SOLARIS" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_LINUX ? "LINUX" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_FREEBSD ? "FREEBSD" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_ESXI ? "ESXI" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_WIN864 ? "WIN864" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_WIN2012R2 ? "WIN2012R2" :
		data->os_type == HWRM_FUNC_DRV_QVER_OUTPUT_OS_TYPE_UEFI ? "UEFI" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     ver_maj = 0x%02"PRIX8"\n", data->ver_maj);
	RTE_LOG(INFO, PMD, "     ver_min = 0x%02"PRIX8"\n", data->ver_min);
	RTE_LOG(INFO, PMD, "     ver_upd = 0x%02"PRIX8"\n", data->ver_upd);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_phy_cfg_input(const char *string __rte_unused, struct hwrm_port_phy_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_cfg_input\n");
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "             resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                 flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                         RESET_PHY : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_RESET_PHY)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         DEPRECATED : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_DEPRECATED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FORCE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FORCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         RESTART_AUTONEG : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_RESTART_AUTONEG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         EEE_ENABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_EEE_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         EEE_DISABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_EEE_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         EEE_TX_LPI_ENABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_EEE_TX_LPI_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         EEE_TX_LPI_DISABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_EEE_TX_LPI_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FEC_AUTONEG_ENABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FEC_AUTONEG_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FEC_AUTONEG_DISABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FEC_AUTONEG_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FEC_CLAUSE74_ENABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FEC_CLAUSE74_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FEC_CLAUSE74_DISABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FEC_CLAUSE74_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FEC_CLAUSE91_ENABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FEC_CLAUSE91_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FEC_CLAUSE91_DISABLE : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FEC_CLAUSE91_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FORCE_LINK_DWN : %s\n", (data->flags & HWRM_PORT_PHY_CFG_INPUT_FLAGS_FORCE_LINK_DWN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                         AUTO_LINK_SPEED = %0*X\n", 11, (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_AUTO_LINK_SPEED_MASK));
	RTE_LOG(INFO, PMD, "                         EEE_LINK_SPEED = %0*X\n", 11, (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_EEE_LINK_SPEED_MASK));
	RTE_LOG(INFO, PMD, "                         AUTO_MODE : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_AUTO_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         AUTO_DUPLEX : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_AUTO_DUPLEX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         AUTO_PAUSE : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_AUTO_PAUSE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         AUTO_LINK_SPEED : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_AUTO_LINK_SPEED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         WIRESPEED : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_WIRESPEED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         LPBK : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_LPBK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         PREEMPHASIS : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_PREEMPHASIS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         FORCE_PAUSE : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_FORCE_PAUSE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         TX_LPI_TIMER : %s\n", (data->enables & HWRM_PORT_PHY_CFG_INPUT_ENABLES_TX_LPI_TIMER)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "      force_link_speed = 0x%04"PRIX16"\n", data->force_link_speed);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_100MB ? "100MB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_1GB ? "1GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_2GB ? "2GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_2_5GB ? "2_5GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_10GB ? "10GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_20GB ? "20GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_25GB ? "25GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_40GB ? "40GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_50GB ? "50GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_100GB ? "100GB" :
		data->force_link_speed == HWRM_PORT_PHY_CFG_INPUT_FORCE_LINK_SPEED_10MB ? "10MB" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             auto_mode = 0x%02"PRIX8"\n", data->auto_mode);
	RTE_LOG(INFO, PMD, "                         SPEED = %0*X\n", 11, (data->auto_mode & HWRM_PORT_PHY_CFG_INPUT_AUTO_MODE_SPEED_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->auto_mode == HWRM_PORT_PHY_CFG_INPUT_AUTO_MODE_NONE ? "NONE" :
		data->auto_mode == HWRM_PORT_PHY_CFG_INPUT_AUTO_MODE_ALL_SPEEDS ? "ALL_SPEEDS" :
		data->auto_mode == HWRM_PORT_PHY_CFG_INPUT_AUTO_MODE_ONE_SPEED ? "ONE_SPEED" :
		data->auto_mode == HWRM_PORT_PHY_CFG_INPUT_AUTO_MODE_ONE_OR_BELOW ? "ONE_OR_BELOW" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           auto_duplex = 0x%02"PRIX8"\n", data->auto_duplex);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->auto_duplex == HWRM_PORT_PHY_CFG_INPUT_AUTO_DUPLEX_HALF ? "HALF" :
		data->auto_duplex == HWRM_PORT_PHY_CFG_INPUT_AUTO_DUPLEX_FULL ? "FULL" :
		data->auto_duplex == HWRM_PORT_PHY_CFG_INPUT_AUTO_DUPLEX_BOTH ? "BOTH" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            auto_pause = 0x%02"PRIX8"\n", data->auto_pause);
	RTE_LOG(INFO, PMD, "                         TX : %s\n", (data->auto_pause & HWRM_PORT_PHY_CFG_INPUT_AUTO_PAUSE_TX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         RX : %s\n", (data->auto_pause & HWRM_PORT_PHY_CFG_INPUT_AUTO_PAUSE_RX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         AUTONEG_PAUSE : %s\n", (data->auto_pause & HWRM_PORT_PHY_CFG_INPUT_AUTO_PAUSE_AUTONEG_PAUSE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       auto_link_speed = 0x%04"PRIX16"\n", data->auto_link_speed);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_100MB ? "100MB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_1GB ? "1GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_2GB ? "2GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_2_5GB ? "2_5GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_10GB ? "10GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_20GB ? "20GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_25GB ? "25GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_40GB ? "40GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_50GB ? "50GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_100GB ? "100GB" :
		data->auto_link_speed == HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_10MB ? "10MB" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  auto_link_speed_mask = 0x%04"PRIX16"\n", data->auto_link_speed_mask);
	RTE_LOG(INFO, PMD, "                         100MBHD : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_100MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         100MB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         1GBHD : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_1GBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         1GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         2GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_2GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         2_5GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_2_5GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         10GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         20GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_20GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         25GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_25GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         40GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_40GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         50GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_50GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         100GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_100GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         10MBHD : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_10MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         10MB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_AUTO_LINK_SPEED_MASK_10MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             wirespeed = 0x%02"PRIX8"\n", data->wirespeed);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->wirespeed == HWRM_PORT_PHY_CFG_INPUT_WIRESPEED_OFF ? "OFF" :
		data->wirespeed == HWRM_PORT_PHY_CFG_INPUT_WIRESPEED_ON ? "ON" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                  lpbk = 0x%02"PRIX8"\n", data->lpbk);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->lpbk == HWRM_PORT_PHY_CFG_INPUT_LPBK_NONE ? "NONE" :
		data->lpbk == HWRM_PORT_PHY_CFG_INPUT_LPBK_LOCAL ? "LOCAL" :
		data->lpbk == HWRM_PORT_PHY_CFG_INPUT_LPBK_REMOTE ? "REMOTE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           force_pause = 0x%02"PRIX8"\n", data->force_pause);
	RTE_LOG(INFO, PMD, "                         TX : %s\n", (data->force_pause & HWRM_PORT_PHY_CFG_INPUT_FORCE_PAUSE_TX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         RX : %s\n", (data->force_pause & HWRM_PORT_PHY_CFG_INPUT_FORCE_PAUSE_RX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           preemphasis = 0x%08"PRIX32"\n", data->preemphasis);
	RTE_LOG(INFO, PMD, "   eee_link_speed_mask = 0x%04"PRIX16"\n", data->eee_link_speed_mask);
	RTE_LOG(INFO, PMD, "                         RSVD1 : %s\n", (data->eee_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_EEE_LINK_SPEED_MASK_RSVD1)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         100MB : %s\n", (data->eee_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_EEE_LINK_SPEED_MASK_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         RSVD2 : %s\n", (data->eee_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_EEE_LINK_SPEED_MASK_RSVD2)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         1GB : %s\n", (data->eee_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_EEE_LINK_SPEED_MASK_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         RSVD3 : %s\n", (data->eee_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_EEE_LINK_SPEED_MASK_RSVD3)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         RSVD4 : %s\n", (data->eee_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_EEE_LINK_SPEED_MASK_RSVD4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         10GB : %s\n", (data->eee_link_speed_mask & HWRM_PORT_PHY_CFG_INPUT_EEE_LINK_SPEED_MASK_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "              unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "          tx_lpi_timer = 0x%08"PRIX32"\n", data->tx_lpi_timer);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		(data->tx_lpi_timer & HWRM_PORT_PHY_CFG_INPUT_TX_LPI_TIMER_MASK) == HWRM_PORT_PHY_CFG_INPUT_TX_LPI_TIMER_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "              unused_4 = 0x%08"PRIX32"\n", data->unused_4);
}

void decode_hwrm_port_phy_cfg_output(const char *string __rte_unused, struct hwrm_port_phy_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_phy_qcfg_input(const char *string __rte_unused, struct hwrm_port_phy_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_port_phy_qcfg_output(const char *string __rte_unused, struct hwrm_port_phy_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_qcfg_output\n");
	RTE_LOG(INFO, PMD, "                            error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "                              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                              resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "                                  link = 0x%02"PRIX8"\n", data->link);
	RTE_LOG(INFO, PMD, "                                         PARTNER_ADV_AUTO_MODE_SPEED = %0*X\n", 11, (data->link & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_AUTO_MODE_SPEED_MASK));
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->link == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_NO_LINK ? "NO_LINK" :
		data->link == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SIGNAL ? "SIGNAL" :
		data->link == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_LINK ? "LINK" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                              unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "                            link_speed = 0x%04"PRIX16"\n", data->link_speed);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_100MB ? "100MB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_1GB ? "1GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_2GB ? "2GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_2_5GB ? "2_5GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_10GB ? "10GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_20GB ? "20GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_25GB ? "25GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_40GB ? "40GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_50GB ? "50GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_100GB ? "100GB" :
		data->link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_SPEED_10MB ? "10MB" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                                duplex = 0x%02"PRIX8"\n", data->duplex);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->duplex == HWRM_PORT_PHY_QCFG_OUTPUT_DUPLEX_HALF ? "HALF" :
		data->duplex == HWRM_PORT_PHY_QCFG_OUTPUT_DUPLEX_FULL ? "FULL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                                 pause = 0x%02"PRIX8"\n", data->pause);
	RTE_LOG(INFO, PMD, "                                         TX : %s\n", (data->pause & HWRM_PORT_PHY_QCFG_OUTPUT_PAUSE_TX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RX : %s\n", (data->pause & HWRM_PORT_PHY_QCFG_OUTPUT_PAUSE_RX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                        support_speeds = 0x%04"PRIX16"\n", data->support_speeds);
	RTE_LOG(INFO, PMD, "                                         100MBHD : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_100MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100MB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GBHD : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_1GBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         2GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_2GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         2_5GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_2_5GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         20GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_20GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         25GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_25GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         40GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_40GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         50GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_50GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100GB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_100GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10MBHD : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_10MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10MB : %s\n", (data->support_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_SUPPORT_SPEEDS_10MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      force_link_speed = 0x%04"PRIX16"\n", data->force_link_speed);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_100MB ? "100MB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_1GB ? "1GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_2GB ? "2GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_2_5GB ? "2_5GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_10GB ? "10GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_20GB ? "20GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_25GB ? "25GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_40GB ? "40GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_50GB ? "50GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_100GB ? "100GB" :
		data->force_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_LINK_SPEED_10MB ? "10MB" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                             auto_mode = 0x%02"PRIX8"\n", data->auto_mode);
	RTE_LOG(INFO, PMD, "                                         SPEED = %0*X\n", 11, (data->auto_mode & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_MODE_SPEED_MASK));
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_MODE_NONE ? "NONE" :
		data->auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_MODE_ALL_SPEEDS ? "ALL_SPEEDS" :
		data->auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_MODE_ONE_SPEED ? "ONE_SPEED" :
		data->auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_MODE_ONE_OR_BELOW ? "ONE_OR_BELOW" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                            auto_pause = 0x%02"PRIX8"\n", data->auto_pause);
	RTE_LOG(INFO, PMD, "                                         TX : %s\n", (data->auto_pause & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_PAUSE_TX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RX : %s\n", (data->auto_pause & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_PAUSE_RX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         AUTONEG_PAUSE : %s\n", (data->auto_pause & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_PAUSE_AUTONEG_PAUSE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       auto_link_speed = 0x%04"PRIX16"\n", data->auto_link_speed);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_100MB ? "100MB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_1GB ? "1GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_2GB ? "2GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_2_5GB ? "2_5GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_10GB ? "10GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_20GB ? "20GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_25GB ? "25GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_40GB ? "40GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_50GB ? "50GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_100GB ? "100GB" :
		data->auto_link_speed == HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_10MB ? "10MB" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                  auto_link_speed_mask = 0x%04"PRIX16"\n", data->auto_link_speed_mask);
	RTE_LOG(INFO, PMD, "                                         100MBHD : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_100MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100MB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GBHD : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_1GBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         2GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_2GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         2_5GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_2_5GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         20GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_20GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         25GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_25GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         40GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_40GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         50GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_50GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100GB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_100GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10MBHD : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_10MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10MB : %s\n", (data->auto_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_AUTO_LINK_SPEED_MASK_10MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                             wirespeed = 0x%02"PRIX8"\n", data->wirespeed);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->wirespeed == HWRM_PORT_PHY_QCFG_OUTPUT_WIRESPEED_OFF ? "OFF" :
		data->wirespeed == HWRM_PORT_PHY_QCFG_OUTPUT_WIRESPEED_ON ? "ON" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                                  lpbk = 0x%02"PRIX8"\n", data->lpbk);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->lpbk == HWRM_PORT_PHY_QCFG_OUTPUT_LPBK_NONE ? "NONE" :
		data->lpbk == HWRM_PORT_PHY_QCFG_OUTPUT_LPBK_LOCAL ? "LOCAL" :
		data->lpbk == HWRM_PORT_PHY_QCFG_OUTPUT_LPBK_REMOTE ? "REMOTE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                           force_pause = 0x%02"PRIX8"\n", data->force_pause);
	RTE_LOG(INFO, PMD, "                                         TX : %s\n", (data->force_pause & HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_PAUSE_TX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RX : %s\n", (data->force_pause & HWRM_PORT_PHY_QCFG_OUTPUT_FORCE_PAUSE_RX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         module_status = 0x%02"PRIX8"\n", data->module_status);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->module_status == HWRM_PORT_PHY_QCFG_OUTPUT_MODULE_STATUS_NONE ? "NONE" :
		data->module_status == HWRM_PORT_PHY_QCFG_OUTPUT_MODULE_STATUS_DISABLETX ? "DISABLETX" :
		data->module_status == HWRM_PORT_PHY_QCFG_OUTPUT_MODULE_STATUS_WARNINGMSG ? "WARNINGMSG" :
		data->module_status == HWRM_PORT_PHY_QCFG_OUTPUT_MODULE_STATUS_PWRDOWN ? "PWRDOWN" :
		data->module_status == HWRM_PORT_PHY_QCFG_OUTPUT_MODULE_STATUS_NOTINSERTED ? "NOTINSERTED" :
		data->module_status == HWRM_PORT_PHY_QCFG_OUTPUT_MODULE_STATUS_NOTAPPLICABLE ? "NOTAPPLICABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                           preemphasis = 0x%08"PRIX32"\n", data->preemphasis);
	RTE_LOG(INFO, PMD, "                               phy_maj = 0x%02"PRIX8"\n", data->phy_maj);
	RTE_LOG(INFO, PMD, "                               phy_min = 0x%02"PRIX8"\n", data->phy_min);
	RTE_LOG(INFO, PMD, "                               phy_bld = 0x%02"PRIX8"\n", data->phy_bld);
	RTE_LOG(INFO, PMD, "                              phy_type = 0x%02"PRIX8"\n", data->phy_type);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_UNKNOWN ? "UNKNOWN" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASECR ? "BASECR" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASEKR4 ? "BASEKR4" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASELR ? "BASELR" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASESR ? "BASESR" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASEKR2 ? "BASEKR2" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASEKX ? "BASEKX" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASEKR ? "BASEKR" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASET ? "BASET" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_BASETE ? "BASETE" :
		data->phy_type == HWRM_PORT_PHY_QCFG_OUTPUT_PHY_TYPE_SGMIIEXTPHY ? "SGMIIEXTPHY" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                            media_type = 0x%02"PRIX8"\n", data->media_type);
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->media_type == HWRM_PORT_PHY_QCFG_OUTPUT_MEDIA_TYPE_UNKNOWN ? "UNKNOWN" :
		data->media_type == HWRM_PORT_PHY_QCFG_OUTPUT_MEDIA_TYPE_TP ? "TP" :
		data->media_type == HWRM_PORT_PHY_QCFG_OUTPUT_MEDIA_TYPE_DAC ? "DAC" :
		data->media_type == HWRM_PORT_PHY_QCFG_OUTPUT_MEDIA_TYPE_FIBRE ? "FIBRE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         xcvr_pkg_type = 0x%02"PRIX8"\n", data->xcvr_pkg_type);
	RTE_LOG(INFO, PMD, "                                         XCVR_INTERNAL : %s\n", (data->xcvr_pkg_type & HWRM_PORT_PHY_QCFG_OUTPUT_XCVR_PKG_TYPE_XCVR_INTERNAL)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         XCVR_EXTERNAL : %s\n", (data->xcvr_pkg_type & HWRM_PORT_PHY_QCFG_OUTPUT_XCVR_PKG_TYPE_XCVR_EXTERNAL)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   eee_config_phy_addr = 0x%02"PRIX8"\n", data->eee_config_phy_addr);
	RTE_LOG(INFO, PMD, "                       parallel_detect = 0x%02"PRIX8"\n", data->parallel_detect);
	RTE_LOG(INFO, PMD, "               link_partner_adv_speeds = 0x%04"PRIX16"\n", data->link_partner_adv_speeds);
	RTE_LOG(INFO, PMD, "                                         100MBHD : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_100MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100MB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GBHD : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_1GBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         2GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_2GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         2_5GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_2_5GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         20GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_20GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         25GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_25GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         40GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_40GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         50GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_50GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100GB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_100GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10MBHD : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_10MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10MB : %s\n", (data->link_partner_adv_speeds & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_SPEEDS_10MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "            link_partner_adv_auto_mode = 0x%02"PRIX8"\n", data->link_partner_adv_auto_mode);
	RTE_LOG(INFO, PMD, "                                         SPEED = %0*X\n", 0, (data->link_partner_adv_auto_mode & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_AUTO_MODE_SPEED_MASK));
	RTE_LOG(INFO, PMD, "                                         Value : %s\n",
		data->link_partner_adv_auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_AUTO_MODE_NONE ? "NONE" :
		data->link_partner_adv_auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_AUTO_MODE_ALL_SPEEDS ? "ALL_SPEEDS" :
		data->link_partner_adv_auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_AUTO_MODE_ONE_SPEED ? "ONE_SPEED" :
		data->link_partner_adv_auto_mode == HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_AUTO_MODE_ONE_OR_BELOW ? "ONE_OR_BELOW" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                link_partner_adv_pause = 0x%02"PRIX8"\n", data->link_partner_adv_pause);
	RTE_LOG(INFO, PMD, "                                         TX : %s\n", (data->link_partner_adv_pause & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_PAUSE_TX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RX : %s\n", (data->link_partner_adv_pause & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_PAUSE_RX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               adv_eee_link_speed_mask = 0x%04"PRIX16"\n", data->adv_eee_link_speed_mask);
	RTE_LOG(INFO, PMD, "                                         RSVD1 : %s\n", (data->adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_ADV_EEE_LINK_SPEED_MASK_RSVD1)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100MB : %s\n", (data->adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_ADV_EEE_LINK_SPEED_MASK_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RSVD2 : %s\n", (data->adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_ADV_EEE_LINK_SPEED_MASK_RSVD2)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GB : %s\n", (data->adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_ADV_EEE_LINK_SPEED_MASK_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RSVD3 : %s\n", (data->adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_ADV_EEE_LINK_SPEED_MASK_RSVD3)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RSVD4 : %s\n", (data->adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_ADV_EEE_LINK_SPEED_MASK_RSVD4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10GB : %s\n", (data->adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_ADV_EEE_LINK_SPEED_MASK_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  link_partner_adv_eee_link_speed_mask = 0x%04"PRIX16"\n", data->link_partner_adv_eee_link_speed_mask);
	RTE_LOG(INFO, PMD, "                                         RSVD1 : %s\n", (data->link_partner_adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_EEE_LINK_SPEED_MASK_RSVD1)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         100MB : %s\n", (data->link_partner_adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_EEE_LINK_SPEED_MASK_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RSVD2 : %s\n", (data->link_partner_adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_EEE_LINK_SPEED_MASK_RSVD2)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         1GB : %s\n", (data->link_partner_adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_EEE_LINK_SPEED_MASK_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RSVD3 : %s\n", (data->link_partner_adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_EEE_LINK_SPEED_MASK_RSVD3)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         RSVD4 : %s\n", (data->link_partner_adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_EEE_LINK_SPEED_MASK_RSVD4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         10GB : %s\n", (data->link_partner_adv_eee_link_speed_mask & HWRM_PORT_PHY_QCFG_OUTPUT_LINK_PARTNER_ADV_EEE_LINK_SPEED_MASK_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "     xcvr_identifier_type_tx_lpi_timer = 0x%08"PRIX32"\n", data->xcvr_identifier_type_tx_lpi_timer);
	RTE_LOG(INFO, PMD, "                               fec_cfg = 0x%04"PRIX16"\n", data->fec_cfg);
	RTE_LOG(INFO, PMD, "                                         FEC_NONE_SUPPORTED : %s\n", (data->fec_cfg & HWRM_PORT_PHY_QCFG_OUTPUT_FEC_CFG_FEC_NONE_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         FEC_AUTONEG_SUPPORTED : %s\n", (data->fec_cfg & HWRM_PORT_PHY_QCFG_OUTPUT_FEC_CFG_FEC_AUTONEG_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         FEC_AUTONEG_ENABLED : %s\n", (data->fec_cfg & HWRM_PORT_PHY_QCFG_OUTPUT_FEC_CFG_FEC_AUTONEG_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         FEC_CLAUSE74_SUPPORTED : %s\n", (data->fec_cfg & HWRM_PORT_PHY_QCFG_OUTPUT_FEC_CFG_FEC_CLAUSE74_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         FEC_CLAUSE74_ENABLED : %s\n", (data->fec_cfg & HWRM_PORT_PHY_QCFG_OUTPUT_FEC_CFG_FEC_CLAUSE74_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         FEC_CLAUSE91_SUPPORTED : %s\n", (data->fec_cfg & HWRM_PORT_PHY_QCFG_OUTPUT_FEC_CFG_FEC_CLAUSE91_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                         FEC_CLAUSE91_ENABLED : %s\n", (data->fec_cfg & HWRM_PORT_PHY_QCFG_OUTPUT_FEC_CFG_FEC_CLAUSE91_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                              unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "                              unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "                       phy_vendor_name = \"%.16s\"\n", data->phy_vendor_name);
	RTE_LOG(INFO, PMD, "                 phy_vendor_partnumber = \"%.16s\"\n", data->phy_vendor_partnumber);
	RTE_LOG(INFO, PMD, "                              unused_3 = 0x%08"PRIX32"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "                              unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "                              unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "                              unused_6 = 0x%02"PRIX8"\n", data->unused_6);
	RTE_LOG(INFO, PMD, "                                 valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_mac_cfg_input(const char *string __rte_unused, struct hwrm_port_mac_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_mac_cfg_input\n");
	RTE_LOG(INFO, PMD, "                    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                   cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                   target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "                   resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                       flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                               MATCH_LINK : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_MATCH_LINK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               VLAN_PRI2COS_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_VLAN_PRI2COS_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               TUNNEL_PRI2COS_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_TUNNEL_PRI2COS_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               IP_DSCP2COS_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_IP_DSCP2COS_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               PTP_RX_TS_CAPTURE_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_PTP_RX_TS_CAPTURE_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               PTP_RX_TS_CAPTURE_DISABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_PTP_RX_TS_CAPTURE_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               PTP_TX_TS_CAPTURE_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_PTP_TX_TS_CAPTURE_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               PTP_TX_TS_CAPTURE_DISABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_PTP_TX_TS_CAPTURE_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               OOB_WOL_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_OOB_WOL_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               OOB_WOL_DISABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_OOB_WOL_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               VLAN_PRI2COS_DISABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_VLAN_PRI2COS_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               TUNNEL_PRI2COS_DISABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_TUNNEL_PRI2COS_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               IP_DSCP2COS_DISABLE : %s\n", (data->flags & HWRM_PORT_MAC_CFG_INPUT_FLAGS_IP_DSCP2COS_DISABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                               IPG : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_IPG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               LPBK : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_LPBK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               VLAN_PRI2COS_MAP_PRI : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_VLAN_PRI2COS_MAP_PRI)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               RESERVED1 : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_RESERVED1)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               TUNNEL_PRI2COS_MAP_PRI : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_TUNNEL_PRI2COS_MAP_PRI)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               DSCP2COS_MAP_PRI : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_DSCP2COS_MAP_PRI)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               RX_TS_CAPTURE_PTP_MSG_TYPE : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_RX_TS_CAPTURE_PTP_MSG_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               TX_TS_CAPTURE_PTP_MSG_TYPE : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_TX_TS_CAPTURE_PTP_MSG_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               COS_FIELD_CFG : %s\n", (data->enables & HWRM_PORT_MAC_CFG_INPUT_ENABLES_COS_FIELD_CFG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "                         ipg = 0x%02"PRIX8"\n", data->ipg);
	RTE_LOG(INFO, PMD, "                        lpbk = 0x%02"PRIX8"\n", data->lpbk);
	RTE_LOG(INFO, PMD, "                               Value : %s\n",
		data->lpbk == HWRM_PORT_MAC_CFG_INPUT_LPBK_NONE ? "NONE" :
		data->lpbk == HWRM_PORT_MAC_CFG_INPUT_LPBK_LOCAL ? "LOCAL" :
		data->lpbk == HWRM_PORT_MAC_CFG_INPUT_LPBK_REMOTE ? "REMOTE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        vlan_pri2cos_map_pri = 0x%02"PRIX8"\n", data->vlan_pri2cos_map_pri);
	RTE_LOG(INFO, PMD, "                   reserved1 = 0x%02"PRIX8"\n", data->reserved1);
	RTE_LOG(INFO, PMD, "      tunnel_pri2cos_map_pri = 0x%02"PRIX8"\n", data->tunnel_pri2cos_map_pri);
	RTE_LOG(INFO, PMD, "            dscp2pri_map_pri = 0x%02"PRIX8"\n", data->dscp2pri_map_pri);
	RTE_LOG(INFO, PMD, "  rx_ts_capture_ptp_msg_type = 0x%04"PRIX16"\n", data->rx_ts_capture_ptp_msg_type);
	RTE_LOG(INFO, PMD, "  tx_ts_capture_ptp_msg_type = 0x%04"PRIX16"\n", data->tx_ts_capture_ptp_msg_type);
	RTE_LOG(INFO, PMD, "               cos_field_cfg = 0x%02"PRIX8"\n", data->cos_field_cfg);
	RTE_LOG(INFO, PMD, "                               VLAN_PRI_SEL = %0*X\n", 11, ((data->cos_field_cfg & HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_VLAN_PRI_SEL_MASK) >> HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_VLAN_PRI_SEL_SFT));
	RTE_LOG(INFO, PMD, "                               T_VLAN_PRI_SEL = %0*X\n", 12, ((data->cos_field_cfg & HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_MASK) >> HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_SFT));
	RTE_LOG(INFO, PMD, "                               DEFAULT_COS = %0*X\n", 11, ((data->cos_field_cfg & HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_DEFAULT_COS_MASK) >> HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_DEFAULT_COS_SFT));
	RTE_LOG(INFO, PMD, "                               Value : %s\n",
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_RSVD1 ? "RSVD1" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_VLAN_PRI_SEL_INNERMOST ? "VLAN_PRI_SEL_INNERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_VLAN_PRI_SEL_OUTER ? "VLAN_PRI_SEL_OUTER" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_VLAN_PRI_SEL_OUTERMOST ? "VLAN_PRI_SEL_OUTERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_VLAN_PRI_SEL_UNSPECIFIED ? "VLAN_PRI_SEL_UNSPECIFIED" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_VLAN_PRI_SEL_LAST ? "VLAN_PRI_SEL_LAST" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_INNERMOST ? "T_VLAN_PRI_SEL_INNERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_OUTER ? "T_VLAN_PRI_SEL_OUTER" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_OUTERMOST ? "T_VLAN_PRI_SEL_OUTERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_UNSPECIFIED ? "T_VLAN_PRI_SEL_UNSPECIFIED" :
		data->cos_field_cfg == HWRM_PORT_MAC_CFG_INPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_LAST ? "T_VLAN_PRI_SEL_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                 unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "                 unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "                 unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
}

void decode_hwrm_port_mac_cfg_output(const char *string __rte_unused, struct hwrm_port_mac_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_mac_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "         mru = 0x%04"PRIX16"\n", data->mru);
	RTE_LOG(INFO, PMD, "         mtu = 0x%04"PRIX16"\n", data->mtu);
	RTE_LOG(INFO, PMD, "         ipg = 0x%02"PRIX8"\n", data->ipg);
	RTE_LOG(INFO, PMD, "        lpbk = 0x%02"PRIX8"\n", data->lpbk);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->lpbk == HWRM_PORT_MAC_CFG_OUTPUT_LPBK_NONE ? "NONE" :
		data->lpbk == HWRM_PORT_MAC_CFG_OUTPUT_LPBK_LOCAL ? "LOCAL" :
		data->lpbk == HWRM_PORT_MAC_CFG_OUTPUT_LPBK_REMOTE ? "REMOTE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_mac_qcfg_input(const char *string __rte_unused, struct hwrm_port_mac_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_mac_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_port_mac_qcfg_output(const char *string __rte_unused, struct hwrm_port_mac_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_mac_qcfg_output\n");
	RTE_LOG(INFO, PMD, "                  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "                    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "                         mru = 0x%04"PRIX16"\n", data->mru);
	RTE_LOG(INFO, PMD, "                         mtu = 0x%04"PRIX16"\n", data->mtu);
	RTE_LOG(INFO, PMD, "                         ipg = 0x%02"PRIX8"\n", data->ipg);
	RTE_LOG(INFO, PMD, "                        lpbk = 0x%02"PRIX8"\n", data->lpbk);
	RTE_LOG(INFO, PMD, "                               Value : %s\n",
		data->lpbk == HWRM_PORT_MAC_QCFG_OUTPUT_LPBK_NONE ? "NONE" :
		data->lpbk == HWRM_PORT_MAC_QCFG_OUTPUT_LPBK_LOCAL ? "LOCAL" :
		data->lpbk == HWRM_PORT_MAC_QCFG_OUTPUT_LPBK_REMOTE ? "REMOTE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        vlan_pri2cos_map_pri = 0x%02"PRIX8"\n", data->vlan_pri2cos_map_pri);
	RTE_LOG(INFO, PMD, "                       flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "                               VLAN_PRI2COS_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_QCFG_OUTPUT_FLAGS_VLAN_PRI2COS_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               TUNNEL_PRI2COS_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_QCFG_OUTPUT_FLAGS_TUNNEL_PRI2COS_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               IP_DSCP2COS_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_QCFG_OUTPUT_FLAGS_IP_DSCP2COS_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                               OOB_WOL_ENABLE : %s\n", (data->flags & HWRM_PORT_MAC_QCFG_OUTPUT_FLAGS_OOB_WOL_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      tunnel_pri2cos_map_pri = 0x%02"PRIX8"\n", data->tunnel_pri2cos_map_pri);
	RTE_LOG(INFO, PMD, "            dscp2pri_map_pri = 0x%02"PRIX8"\n", data->dscp2pri_map_pri);
	RTE_LOG(INFO, PMD, "  rx_ts_capture_ptp_msg_type = 0x%04"PRIX16"\n", data->rx_ts_capture_ptp_msg_type);
	RTE_LOG(INFO, PMD, "  tx_ts_capture_ptp_msg_type = 0x%04"PRIX16"\n", data->tx_ts_capture_ptp_msg_type);
	RTE_LOG(INFO, PMD, "               cos_field_cfg = 0x%02"PRIX8"\n", data->cos_field_cfg);
	RTE_LOG(INFO, PMD, "                               VLAN_PRI_SEL = %0*X\n", 11, ((data->cos_field_cfg & HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_VLAN_PRI_SEL_MASK) >> HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_VLAN_PRI_SEL_SFT));
	RTE_LOG(INFO, PMD, "                               T_VLAN_PRI_SEL = %0*X\n", 12, ((data->cos_field_cfg & HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_MASK) >> HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_SFT));
	RTE_LOG(INFO, PMD, "                               DEFAULT_COS = %0*X\n", 11, ((data->cos_field_cfg & HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_DEFAULT_COS_MASK) >> HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_DEFAULT_COS_SFT));
	RTE_LOG(INFO, PMD, "                               Value : %s\n",
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_RSVD ? "RSVD" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_VLAN_PRI_SEL_INNERMOST ? "VLAN_PRI_SEL_INNERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_VLAN_PRI_SEL_OUTER ? "VLAN_PRI_SEL_OUTER" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_VLAN_PRI_SEL_OUTERMOST ? "VLAN_PRI_SEL_OUTERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_VLAN_PRI_SEL_UNSPECIFIED ? "VLAN_PRI_SEL_UNSPECIFIED" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_VLAN_PRI_SEL_LAST ? "VLAN_PRI_SEL_LAST" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_INNERMOST ? "T_VLAN_PRI_SEL_INNERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_OUTER ? "T_VLAN_PRI_SEL_OUTER" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_OUTERMOST ? "T_VLAN_PRI_SEL_OUTERMOST" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_UNSPECIFIED ? "T_VLAN_PRI_SEL_UNSPECIFIED" :
		data->cos_field_cfg == HWRM_PORT_MAC_QCFG_OUTPUT_COS_FIELD_CFG_T_VLAN_PRI_SEL_LAST ? "T_VLAN_PRI_SEL_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_qstats_input(const char *string __rte_unused, struct hwrm_port_qstats_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_qstats_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "            port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        unused_2[0] = 0x%02"PRIX8"\n", data->unused_2[0]);
	RTE_LOG(INFO, PMD, "        unused_2[1] = 0x%02"PRIX8"\n", data->unused_2[1]);
	RTE_LOG(INFO, PMD, "        unused_2[2] = 0x%02"PRIX8"\n", data->unused_2[2]);
	RTE_LOG(INFO, PMD, "           unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "  tx_stat_host_addr = 0x%016"PRIX64"\n", data->tx_stat_host_addr);
	RTE_LOG(INFO, PMD, "  rx_stat_host_addr = 0x%016"PRIX64"\n", data->rx_stat_host_addr);
}

void decode_hwrm_port_qstats_output(const char *string __rte_unused, struct hwrm_port_qstats_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_qstats_output\n");
	RTE_LOG(INFO, PMD, "    error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  tx_stat_size = 0x%04"PRIX16"\n", data->tx_stat_size);
	RTE_LOG(INFO, PMD, "  rx_stat_size = 0x%04"PRIX16"\n", data->rx_stat_size);
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "      unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "         valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_lpbk_qstats_input(const char *string __rte_unused, struct hwrm_port_lpbk_qstats_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_lpbk_qstats_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_hwrm_port_lpbk_qstats_output(const char *string __rte_unused, struct hwrm_port_lpbk_qstats_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_lpbk_qstats_output\n");
	RTE_LOG(INFO, PMD, "         error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  lpbk_ucast_frames = 0x%016"PRIX64"\n", data->lpbk_ucast_frames);
	RTE_LOG(INFO, PMD, "  lpbk_mcast_frames = 0x%016"PRIX64"\n", data->lpbk_mcast_frames);
	RTE_LOG(INFO, PMD, "  lpbk_bcast_frames = 0x%016"PRIX64"\n", data->lpbk_bcast_frames);
	RTE_LOG(INFO, PMD, "   lpbk_ucast_bytes = 0x%016"PRIX64"\n", data->lpbk_ucast_bytes);
	RTE_LOG(INFO, PMD, "   lpbk_mcast_bytes = 0x%016"PRIX64"\n", data->lpbk_mcast_bytes);
	RTE_LOG(INFO, PMD, "   lpbk_bcast_bytes = 0x%016"PRIX64"\n", data->lpbk_bcast_bytes);
	RTE_LOG(INFO, PMD, "    tx_stat_discard = 0x%016"PRIX64"\n", data->tx_stat_discard);
	RTE_LOG(INFO, PMD, "      tx_stat_error = 0x%016"PRIX64"\n", data->tx_stat_error);
	RTE_LOG(INFO, PMD, "    rx_stat_discard = 0x%016"PRIX64"\n", data->rx_stat_discard);
	RTE_LOG(INFO, PMD, "      rx_stat_error = 0x%016"PRIX64"\n", data->rx_stat_error);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "           unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "              valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_clr_stats_input(const char *string __rte_unused, struct hwrm_port_clr_stats_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_clr_stats_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_port_clr_stats_output(const char *string __rte_unused, struct hwrm_port_clr_stats_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_clr_stats_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_lpbk_clr_stats_input(const char *string __rte_unused, struct hwrm_port_lpbk_clr_stats_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_lpbk_clr_stats_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_hwrm_port_lpbk_clr_stats_output(const char *string __rte_unused, struct hwrm_port_lpbk_clr_stats_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_lpbk_clr_stats_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_ts_query_input(const char *string __rte_unused, struct hwrm_port_ts_query_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_ts_query_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->flags == HWRM_PORT_TS_QUERY_INPUT_FLAGS_PATH ? "PATH" :
		data->flags == HWRM_PORT_TS_QUERY_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_PORT_TS_QUERY_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_PORT_TS_QUERY_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_port_ts_query_output(const char *string __rte_unused, struct hwrm_port_ts_query_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_ts_query_output\n");
	RTE_LOG(INFO, PMD, "     error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "     ptp_msg_ts = 0x%016"PRIX64"\n", data->ptp_msg_ts);
	RTE_LOG(INFO, PMD, "  ptp_msg_seqid = 0x%04"PRIX16"\n", data->ptp_msg_seqid);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "          valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_phy_qcaps_input(const char *string __rte_unused, struct hwrm_port_phy_qcaps_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_qcaps_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_port_phy_qcaps_output(const char *string __rte_unused, struct hwrm_port_phy_qcaps_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_qcaps_output\n");
	RTE_LOG(INFO, PMD, "                   error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "                     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                     resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "                eee_supported = 0x%02"PRIX8"\n", data->eee_supported);
	RTE_LOG(INFO, PMD, "                     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  supported_speeds_force_mode = 0x%04"PRIX16"\n", data->supported_speeds_force_mode);
	RTE_LOG(INFO, PMD, "                                100MBHD : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_100MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                100MB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                1GBHD : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_1GBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                1GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                2GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_2GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                2_5GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_2_5GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                10GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                20GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_20GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                25GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_25GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                40GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_40GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                50GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_50GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                100GB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_100GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                10MBHD : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_10MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                10MB : %s\n", (data->supported_speeds_force_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_FORCE_MODE_10MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   supported_speeds_auto_mode = 0x%04"PRIX16"\n", data->supported_speeds_auto_mode);
	RTE_LOG(INFO, PMD, "                                100MBHD : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_100MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                100MB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                1GBHD : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_1GBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                1GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                2GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_2GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                2_5GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_2_5GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                10GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                20GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_20GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                25GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_25GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                40GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_40GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                50GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_50GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                100GB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_100GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                10MBHD : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_10MBHD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                10MB : %s\n", (data->supported_speeds_auto_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_AUTO_MODE_10MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    supported_speeds_eee_mode = 0x%04"PRIX16"\n", data->supported_speeds_eee_mode);
	RTE_LOG(INFO, PMD, "                                RSVD1 : %s\n", (data->supported_speeds_eee_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_EEE_MODE_RSVD1)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                100MB : %s\n", (data->supported_speeds_eee_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_EEE_MODE_100MB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                RSVD2 : %s\n", (data->supported_speeds_eee_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_EEE_MODE_RSVD2)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                1GB : %s\n", (data->supported_speeds_eee_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_EEE_MODE_1GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                RSVD3 : %s\n", (data->supported_speeds_eee_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_EEE_MODE_RSVD3)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                RSVD4 : %s\n", (data->supported_speeds_eee_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_EEE_MODE_RSVD4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                10GB : %s\n", (data->supported_speeds_eee_mode & HWRM_PORT_PHY_QCAPS_OUTPUT_SUPPORTED_SPEEDS_EEE_MODE_10GB)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             tx_lpi_timer_low = 0x%08"PRIX32"\n", data->tx_lpi_timer_low);
	RTE_LOG(INFO, PMD, "                                Value : %s\n",
		(data->tx_lpi_timer_low & HWRM_PORT_PHY_QCAPS_OUTPUT_TX_LPI_TIMER_LOW_MASK) == HWRM_PORT_PHY_QCAPS_OUTPUT_TX_LPI_TIMER_LOW_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      valid_tx_lpi_timer_high = 0x%08"PRIX32"\n", data->valid_tx_lpi_timer_high);
}

void decode_hwrm_port_phy_i2c_write_input(const char *string __rte_unused, struct hwrm_port_phy_i2c_write_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_i2c_write_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "           flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "         enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                   PAGE_OFFSET : %s\n", (data->enables & HWRM_PORT_PHY_I2C_WRITE_INPUT_ENABLES_PAGE_OFFSET)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  i2c_slave_addr = 0x%02"PRIX8"\n", data->i2c_slave_addr);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     page_number = 0x%04"PRIX16"\n", data->page_number);
	RTE_LOG(INFO, PMD, "     page_offset = 0x%04"PRIX16"\n", data->page_offset);
	RTE_LOG(INFO, PMD, "     data_length = 0x%02"PRIX8"\n", data->data_length);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%04"PRIX16"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%04"PRIX16"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "        unused_4 = 0x%04"PRIX16"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "         data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "         data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "         data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "         data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "         data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "         data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "         data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "         data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "         data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "         data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "        data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "        data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "        data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "        data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "        data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "        data[15] = 0x%08"PRIX32"\n", data->data[15]);
}

void decode_hwrm_port_phy_i2c_write_output(const char *string __rte_unused, struct hwrm_port_phy_i2c_write_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_i2c_write_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_phy_i2c_read_input(const char *string __rte_unused, struct hwrm_port_phy_i2c_read_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_i2c_read_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "           flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "         enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                   PAGE_OFFSET : %s\n", (data->enables & HWRM_PORT_PHY_I2C_READ_INPUT_ENABLES_PAGE_OFFSET)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  i2c_slave_addr = 0x%02"PRIX8"\n", data->i2c_slave_addr);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     page_number = 0x%04"PRIX16"\n", data->page_number);
	RTE_LOG(INFO, PMD, "     page_offset = 0x%04"PRIX16"\n", data->page_offset);
	RTE_LOG(INFO, PMD, "     data_length = 0x%02"PRIX8"\n", data->data_length);
	RTE_LOG(INFO, PMD, "     unused_1[0] = 0x%02"PRIX8"\n", data->unused_1[0]);
	RTE_LOG(INFO, PMD, "     unused_1[1] = 0x%02"PRIX8"\n", data->unused_1[1]);
	RTE_LOG(INFO, PMD, "     unused_1[2] = 0x%02"PRIX8"\n", data->unused_1[2]);
	RTE_LOG(INFO, PMD, "     unused_1[3] = 0x%02"PRIX8"\n", data->unused_1[3]);
	RTE_LOG(INFO, PMD, "     unused_1[4] = 0x%02"PRIX8"\n", data->unused_1[4]);
	RTE_LOG(INFO, PMD, "     unused_1[5] = 0x%02"PRIX8"\n", data->unused_1[5]);
	RTE_LOG(INFO, PMD, "     unused_1[6] = 0x%02"PRIX8"\n", data->unused_1[6]);
}

void decode_hwrm_port_phy_i2c_read_output(const char *string __rte_unused, struct hwrm_port_phy_i2c_read_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_phy_i2c_read_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "     data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "     data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "     data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "     data[3] = 0x%08"PRIX32"\n", data->data[3]);
	RTE_LOG(INFO, PMD, "     data[4] = 0x%08"PRIX32"\n", data->data[4]);
	RTE_LOG(INFO, PMD, "     data[5] = 0x%08"PRIX32"\n", data->data[5]);
	RTE_LOG(INFO, PMD, "     data[6] = 0x%08"PRIX32"\n", data->data[6]);
	RTE_LOG(INFO, PMD, "     data[7] = 0x%08"PRIX32"\n", data->data[7]);
	RTE_LOG(INFO, PMD, "     data[8] = 0x%08"PRIX32"\n", data->data[8]);
	RTE_LOG(INFO, PMD, "     data[9] = 0x%08"PRIX32"\n", data->data[9]);
	RTE_LOG(INFO, PMD, "    data[10] = 0x%08"PRIX32"\n", data->data[10]);
	RTE_LOG(INFO, PMD, "    data[11] = 0x%08"PRIX32"\n", data->data[11]);
	RTE_LOG(INFO, PMD, "    data[12] = 0x%08"PRIX32"\n", data->data[12]);
	RTE_LOG(INFO, PMD, "    data[13] = 0x%08"PRIX32"\n", data->data[13]);
	RTE_LOG(INFO, PMD, "    data[14] = 0x%08"PRIX32"\n", data->data[14]);
	RTE_LOG(INFO, PMD, "    data[15] = 0x%08"PRIX32"\n", data->data[15]);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_led_cfg_input(const char *string __rte_unused, struct hwrm_port_led_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_led_cfg_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "         enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                   LED0_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED0_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED0_STATE : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED0_STATE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED0_COLOR : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED0_COLOR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED0_BLINK_ON : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED0_BLINK_ON)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED0_BLINK_OFF : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED0_BLINK_OFF)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED0_GROUP_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED0_GROUP_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED1_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED1_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED1_STATE : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED1_STATE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED1_COLOR : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED1_COLOR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED1_BLINK_ON : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED1_BLINK_ON)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED1_BLINK_OFF : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED1_BLINK_OFF)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED1_GROUP_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED1_GROUP_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED2_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED2_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED2_STATE : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED2_STATE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED2_COLOR : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED2_COLOR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED2_BLINK_ON : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED2_BLINK_ON)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED2_BLINK_OFF : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED2_BLINK_OFF)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED2_GROUP_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED2_GROUP_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED3_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED3_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED3_STATE : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED3_STATE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED3_COLOR : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED3_COLOR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED3_BLINK_ON : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED3_BLINK_ON)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED3_BLINK_OFF : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED3_BLINK_OFF)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   LED3_GROUP_ID : %s\n", (data->enables & HWRM_PORT_LED_CFG_INPUT_ENABLES_LED3_GROUP_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "        num_leds = 0x%02"PRIX8"\n", data->num_leds);
	RTE_LOG(INFO, PMD, "            rsvd = 0x%02"PRIX8"\n", data->rsvd);
	RTE_LOG(INFO, PMD, "         led0_id = 0x%02"PRIX8"\n", data->led0_id);
	RTE_LOG(INFO, PMD, "      led0_state = 0x%02"PRIX8"\n", data->led0_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led0_state == HWRM_PORT_LED_CFG_INPUT_LED0_STATE_DEFAULT ? "DEFAULT" :
		data->led0_state == HWRM_PORT_LED_CFG_INPUT_LED0_STATE_OFF ? "OFF" :
		data->led0_state == HWRM_PORT_LED_CFG_INPUT_LED0_STATE_ON ? "ON" :
		data->led0_state == HWRM_PORT_LED_CFG_INPUT_LED0_STATE_BLINK ? "BLINK" :
		data->led0_state == HWRM_PORT_LED_CFG_INPUT_LED0_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led0_color = 0x%02"PRIX8"\n", data->led0_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led0_color == HWRM_PORT_LED_CFG_INPUT_LED0_COLOR_DEFAULT ? "DEFAULT" :
		data->led0_color == HWRM_PORT_LED_CFG_INPUT_LED0_COLOR_AMBER ? "AMBER" :
		data->led0_color == HWRM_PORT_LED_CFG_INPUT_LED0_COLOR_GREEN ? "GREEN" :
		data->led0_color == HWRM_PORT_LED_CFG_INPUT_LED0_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "   led0_blink_on = 0x%04"PRIX16"\n", data->led0_blink_on);
	RTE_LOG(INFO, PMD, "  led0_blink_off = 0x%04"PRIX16"\n", data->led0_blink_off);
	RTE_LOG(INFO, PMD, "   led0_group_id = 0x%02"PRIX8"\n", data->led0_group_id);
	RTE_LOG(INFO, PMD, "           rsvd0 = 0x%02"PRIX8"\n", data->rsvd0);
	RTE_LOG(INFO, PMD, "         led1_id = 0x%02"PRIX8"\n", data->led1_id);
	RTE_LOG(INFO, PMD, "      led1_state = 0x%02"PRIX8"\n", data->led1_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led1_state == HWRM_PORT_LED_CFG_INPUT_LED1_STATE_DEFAULT ? "DEFAULT" :
		data->led1_state == HWRM_PORT_LED_CFG_INPUT_LED1_STATE_OFF ? "OFF" :
		data->led1_state == HWRM_PORT_LED_CFG_INPUT_LED1_STATE_ON ? "ON" :
		data->led1_state == HWRM_PORT_LED_CFG_INPUT_LED1_STATE_BLINK ? "BLINK" :
		data->led1_state == HWRM_PORT_LED_CFG_INPUT_LED1_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led1_color = 0x%02"PRIX8"\n", data->led1_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led1_color == HWRM_PORT_LED_CFG_INPUT_LED1_COLOR_DEFAULT ? "DEFAULT" :
		data->led1_color == HWRM_PORT_LED_CFG_INPUT_LED1_COLOR_AMBER ? "AMBER" :
		data->led1_color == HWRM_PORT_LED_CFG_INPUT_LED1_COLOR_GREEN ? "GREEN" :
		data->led1_color == HWRM_PORT_LED_CFG_INPUT_LED1_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "   led1_blink_on = 0x%04"PRIX16"\n", data->led1_blink_on);
	RTE_LOG(INFO, PMD, "  led1_blink_off = 0x%04"PRIX16"\n", data->led1_blink_off);
	RTE_LOG(INFO, PMD, "   led1_group_id = 0x%02"PRIX8"\n", data->led1_group_id);
	RTE_LOG(INFO, PMD, "           rsvd1 = 0x%02"PRIX8"\n", data->rsvd1);
	RTE_LOG(INFO, PMD, "         led2_id = 0x%02"PRIX8"\n", data->led2_id);
	RTE_LOG(INFO, PMD, "      led2_state = 0x%02"PRIX8"\n", data->led2_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led2_state == HWRM_PORT_LED_CFG_INPUT_LED2_STATE_DEFAULT ? "DEFAULT" :
		data->led2_state == HWRM_PORT_LED_CFG_INPUT_LED2_STATE_OFF ? "OFF" :
		data->led2_state == HWRM_PORT_LED_CFG_INPUT_LED2_STATE_ON ? "ON" :
		data->led2_state == HWRM_PORT_LED_CFG_INPUT_LED2_STATE_BLINK ? "BLINK" :
		data->led2_state == HWRM_PORT_LED_CFG_INPUT_LED2_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led2_color = 0x%02"PRIX8"\n", data->led2_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led2_color == HWRM_PORT_LED_CFG_INPUT_LED2_COLOR_DEFAULT ? "DEFAULT" :
		data->led2_color == HWRM_PORT_LED_CFG_INPUT_LED2_COLOR_AMBER ? "AMBER" :
		data->led2_color == HWRM_PORT_LED_CFG_INPUT_LED2_COLOR_GREEN ? "GREEN" :
		data->led2_color == HWRM_PORT_LED_CFG_INPUT_LED2_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "   led2_blink_on = 0x%04"PRIX16"\n", data->led2_blink_on);
	RTE_LOG(INFO, PMD, "  led2_blink_off = 0x%04"PRIX16"\n", data->led2_blink_off);
	RTE_LOG(INFO, PMD, "   led2_group_id = 0x%02"PRIX8"\n", data->led2_group_id);
	RTE_LOG(INFO, PMD, "           rsvd2 = 0x%02"PRIX8"\n", data->rsvd2);
	RTE_LOG(INFO, PMD, "         led3_id = 0x%02"PRIX8"\n", data->led3_id);
	RTE_LOG(INFO, PMD, "      led3_state = 0x%02"PRIX8"\n", data->led3_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led3_state == HWRM_PORT_LED_CFG_INPUT_LED3_STATE_DEFAULT ? "DEFAULT" :
		data->led3_state == HWRM_PORT_LED_CFG_INPUT_LED3_STATE_OFF ? "OFF" :
		data->led3_state == HWRM_PORT_LED_CFG_INPUT_LED3_STATE_ON ? "ON" :
		data->led3_state == HWRM_PORT_LED_CFG_INPUT_LED3_STATE_BLINK ? "BLINK" :
		data->led3_state == HWRM_PORT_LED_CFG_INPUT_LED3_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led3_color = 0x%02"PRIX8"\n", data->led3_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led3_color == HWRM_PORT_LED_CFG_INPUT_LED3_COLOR_DEFAULT ? "DEFAULT" :
		data->led3_color == HWRM_PORT_LED_CFG_INPUT_LED3_COLOR_AMBER ? "AMBER" :
		data->led3_color == HWRM_PORT_LED_CFG_INPUT_LED3_COLOR_GREEN ? "GREEN" :
		data->led3_color == HWRM_PORT_LED_CFG_INPUT_LED3_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "   led3_blink_on = 0x%04"PRIX16"\n", data->led3_blink_on);
	RTE_LOG(INFO, PMD, "  led3_blink_off = 0x%04"PRIX16"\n", data->led3_blink_off);
	RTE_LOG(INFO, PMD, "   led3_group_id = 0x%02"PRIX8"\n", data->led3_group_id);
	RTE_LOG(INFO, PMD, "           rsvd3 = 0x%02"PRIX8"\n", data->rsvd3);
}

void decode_hwrm_port_led_cfg_output(const char *string __rte_unused, struct hwrm_port_led_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_led_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_led_qcfg_input(const char *string __rte_unused, struct hwrm_port_led_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_led_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_port_led_qcfg_output(const char *string __rte_unused, struct hwrm_port_led_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_led_qcfg_output\n");
	RTE_LOG(INFO, PMD, "      error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "        num_leds = 0x%02"PRIX8"\n", data->num_leds);
	RTE_LOG(INFO, PMD, "         led0_id = 0x%02"PRIX8"\n", data->led0_id);
	RTE_LOG(INFO, PMD, "       led0_type = 0x%02"PRIX8"\n", data->led0_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led0_type == HWRM_PORT_LED_QCFG_OUTPUT_LED0_TYPE_SPEED ? "SPEED" :
		data->led0_type == HWRM_PORT_LED_QCFG_OUTPUT_LED0_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led0_type == HWRM_PORT_LED_QCFG_OUTPUT_LED0_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led0_state = 0x%02"PRIX8"\n", data->led0_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led0_state == HWRM_PORT_LED_QCFG_OUTPUT_LED0_STATE_DEFAULT ? "DEFAULT" :
		data->led0_state == HWRM_PORT_LED_QCFG_OUTPUT_LED0_STATE_OFF ? "OFF" :
		data->led0_state == HWRM_PORT_LED_QCFG_OUTPUT_LED0_STATE_ON ? "ON" :
		data->led0_state == HWRM_PORT_LED_QCFG_OUTPUT_LED0_STATE_BLINK ? "BLINK" :
		data->led0_state == HWRM_PORT_LED_QCFG_OUTPUT_LED0_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led0_color = 0x%02"PRIX8"\n", data->led0_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led0_color == HWRM_PORT_LED_QCFG_OUTPUT_LED0_COLOR_DEFAULT ? "DEFAULT" :
		data->led0_color == HWRM_PORT_LED_QCFG_OUTPUT_LED0_COLOR_AMBER ? "AMBER" :
		data->led0_color == HWRM_PORT_LED_QCFG_OUTPUT_LED0_COLOR_GREEN ? "GREEN" :
		data->led0_color == HWRM_PORT_LED_QCFG_OUTPUT_LED0_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "   led0_blink_on = 0x%04"PRIX16"\n", data->led0_blink_on);
	RTE_LOG(INFO, PMD, "  led0_blink_off = 0x%04"PRIX16"\n", data->led0_blink_off);
	RTE_LOG(INFO, PMD, "   led0_group_id = 0x%02"PRIX8"\n", data->led0_group_id);
	RTE_LOG(INFO, PMD, "         led1_id = 0x%02"PRIX8"\n", data->led1_id);
	RTE_LOG(INFO, PMD, "       led1_type = 0x%02"PRIX8"\n", data->led1_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led1_type == HWRM_PORT_LED_QCFG_OUTPUT_LED1_TYPE_SPEED ? "SPEED" :
		data->led1_type == HWRM_PORT_LED_QCFG_OUTPUT_LED1_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led1_type == HWRM_PORT_LED_QCFG_OUTPUT_LED1_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led1_state = 0x%02"PRIX8"\n", data->led1_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led1_state == HWRM_PORT_LED_QCFG_OUTPUT_LED1_STATE_DEFAULT ? "DEFAULT" :
		data->led1_state == HWRM_PORT_LED_QCFG_OUTPUT_LED1_STATE_OFF ? "OFF" :
		data->led1_state == HWRM_PORT_LED_QCFG_OUTPUT_LED1_STATE_ON ? "ON" :
		data->led1_state == HWRM_PORT_LED_QCFG_OUTPUT_LED1_STATE_BLINK ? "BLINK" :
		data->led1_state == HWRM_PORT_LED_QCFG_OUTPUT_LED1_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led1_color = 0x%02"PRIX8"\n", data->led1_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led1_color == HWRM_PORT_LED_QCFG_OUTPUT_LED1_COLOR_DEFAULT ? "DEFAULT" :
		data->led1_color == HWRM_PORT_LED_QCFG_OUTPUT_LED1_COLOR_AMBER ? "AMBER" :
		data->led1_color == HWRM_PORT_LED_QCFG_OUTPUT_LED1_COLOR_GREEN ? "GREEN" :
		data->led1_color == HWRM_PORT_LED_QCFG_OUTPUT_LED1_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "   led1_blink_on = 0x%04"PRIX16"\n", data->led1_blink_on);
	RTE_LOG(INFO, PMD, "  led1_blink_off = 0x%04"PRIX16"\n", data->led1_blink_off);
	RTE_LOG(INFO, PMD, "   led1_group_id = 0x%02"PRIX8"\n", data->led1_group_id);
	RTE_LOG(INFO, PMD, "         led2_id = 0x%02"PRIX8"\n", data->led2_id);
	RTE_LOG(INFO, PMD, "       led2_type = 0x%02"PRIX8"\n", data->led2_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led2_type == HWRM_PORT_LED_QCFG_OUTPUT_LED2_TYPE_SPEED ? "SPEED" :
		data->led2_type == HWRM_PORT_LED_QCFG_OUTPUT_LED2_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led2_type == HWRM_PORT_LED_QCFG_OUTPUT_LED2_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led2_state = 0x%02"PRIX8"\n", data->led2_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led2_state == HWRM_PORT_LED_QCFG_OUTPUT_LED2_STATE_DEFAULT ? "DEFAULT" :
		data->led2_state == HWRM_PORT_LED_QCFG_OUTPUT_LED2_STATE_OFF ? "OFF" :
		data->led2_state == HWRM_PORT_LED_QCFG_OUTPUT_LED2_STATE_ON ? "ON" :
		data->led2_state == HWRM_PORT_LED_QCFG_OUTPUT_LED2_STATE_BLINK ? "BLINK" :
		data->led2_state == HWRM_PORT_LED_QCFG_OUTPUT_LED2_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led2_color = 0x%02"PRIX8"\n", data->led2_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led2_color == HWRM_PORT_LED_QCFG_OUTPUT_LED2_COLOR_DEFAULT ? "DEFAULT" :
		data->led2_color == HWRM_PORT_LED_QCFG_OUTPUT_LED2_COLOR_AMBER ? "AMBER" :
		data->led2_color == HWRM_PORT_LED_QCFG_OUTPUT_LED2_COLOR_GREEN ? "GREEN" :
		data->led2_color == HWRM_PORT_LED_QCFG_OUTPUT_LED2_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "   led2_blink_on = 0x%04"PRIX16"\n", data->led2_blink_on);
	RTE_LOG(INFO, PMD, "  led2_blink_off = 0x%04"PRIX16"\n", data->led2_blink_off);
	RTE_LOG(INFO, PMD, "   led2_group_id = 0x%02"PRIX8"\n", data->led2_group_id);
	RTE_LOG(INFO, PMD, "         led3_id = 0x%02"PRIX8"\n", data->led3_id);
	RTE_LOG(INFO, PMD, "       led3_type = 0x%02"PRIX8"\n", data->led3_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led3_type == HWRM_PORT_LED_QCFG_OUTPUT_LED3_TYPE_SPEED ? "SPEED" :
		data->led3_type == HWRM_PORT_LED_QCFG_OUTPUT_LED3_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led3_type == HWRM_PORT_LED_QCFG_OUTPUT_LED3_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led3_state = 0x%02"PRIX8"\n", data->led3_state);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led3_state == HWRM_PORT_LED_QCFG_OUTPUT_LED3_STATE_DEFAULT ? "DEFAULT" :
		data->led3_state == HWRM_PORT_LED_QCFG_OUTPUT_LED3_STATE_OFF ? "OFF" :
		data->led3_state == HWRM_PORT_LED_QCFG_OUTPUT_LED3_STATE_ON ? "ON" :
		data->led3_state == HWRM_PORT_LED_QCFG_OUTPUT_LED3_STATE_BLINK ? "BLINK" :
		data->led3_state == HWRM_PORT_LED_QCFG_OUTPUT_LED3_STATE_BLINKALT ? "BLINKALT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      led3_color = 0x%02"PRIX8"\n", data->led3_color);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->led3_color == HWRM_PORT_LED_QCFG_OUTPUT_LED3_COLOR_DEFAULT ? "DEFAULT" :
		data->led3_color == HWRM_PORT_LED_QCFG_OUTPUT_LED3_COLOR_AMBER ? "AMBER" :
		data->led3_color == HWRM_PORT_LED_QCFG_OUTPUT_LED3_COLOR_GREEN ? "GREEN" :
		data->led3_color == HWRM_PORT_LED_QCFG_OUTPUT_LED3_COLOR_GREENAMBER ? "GREENAMBER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "   led3_blink_on = 0x%04"PRIX16"\n", data->led3_blink_on);
	RTE_LOG(INFO, PMD, "  led3_blink_off = 0x%04"PRIX16"\n", data->led3_blink_off);
	RTE_LOG(INFO, PMD, "   led3_group_id = 0x%02"PRIX8"\n", data->led3_group_id);
	RTE_LOG(INFO, PMD, "        unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "        unused_5 = 0x%04"PRIX16"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "        unused_6 = 0x%02"PRIX8"\n", data->unused_6);
	RTE_LOG(INFO, PMD, "        unused_7 = 0x%02"PRIX8"\n", data->unused_7);
	RTE_LOG(INFO, PMD, "        unused_8 = 0x%02"PRIX8"\n", data->unused_8);
	RTE_LOG(INFO, PMD, "           valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_port_led_qcaps_input(const char *string __rte_unused, struct hwrm_port_led_qcaps_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_led_qcaps_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_port_led_qcaps_output(const char *string __rte_unused, struct hwrm_port_led_qcaps_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_port_led_qcaps_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "         num_leds = 0x%02"PRIX8"\n", data->num_leds);
	RTE_LOG(INFO, PMD, "      unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "      unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "      unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "          led0_id = 0x%02"PRIX8"\n", data->led0_id);
	RTE_LOG(INFO, PMD, "        led0_type = 0x%02"PRIX8"\n", data->led0_type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->led0_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED0_TYPE_SPEED ? "SPEED" :
		data->led0_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED0_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led0_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED0_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    led0_group_id = 0x%02"PRIX8"\n", data->led0_group_id);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "  led0_state_caps = 0x%04"PRIX16"\n", data->led0_state_caps);
	RTE_LOG(INFO, PMD, "                    ENABLED : %s\n", (data->led0_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_STATE_CAPS_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    OFF_SUPPORTED : %s\n", (data->led0_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_STATE_CAPS_OFF_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    ON_SUPPORTED : %s\n", (data->led0_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_STATE_CAPS_ON_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_SUPPORTED : %s\n", (data->led0_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_STATE_CAPS_BLINK_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_ALT_SUPPORTED : %s\n", (data->led0_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_STATE_CAPS_BLINK_ALT_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  led0_color_caps = 0x%04"PRIX16"\n", data->led0_color_caps);
	RTE_LOG(INFO, PMD, "                    RSVD : %s\n", (data->led0_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_COLOR_CAPS_RSVD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    AMBER_SUPPORTED : %s\n", (data->led0_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_COLOR_CAPS_AMBER_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    GREEN_SUPPORTED : %s\n", (data->led0_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED0_COLOR_CAPS_GREEN_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "          led1_id = 0x%02"PRIX8"\n", data->led1_id);
	RTE_LOG(INFO, PMD, "        led1_type = 0x%02"PRIX8"\n", data->led1_type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->led1_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED1_TYPE_SPEED ? "SPEED" :
		data->led1_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED1_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led1_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED1_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    led1_group_id = 0x%02"PRIX8"\n", data->led1_group_id);
	RTE_LOG(INFO, PMD, "         unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "  led1_state_caps = 0x%04"PRIX16"\n", data->led1_state_caps);
	RTE_LOG(INFO, PMD, "                    ENABLED : %s\n", (data->led1_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_STATE_CAPS_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    OFF_SUPPORTED : %s\n", (data->led1_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_STATE_CAPS_OFF_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    ON_SUPPORTED : %s\n", (data->led1_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_STATE_CAPS_ON_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_SUPPORTED : %s\n", (data->led1_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_STATE_CAPS_BLINK_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_ALT_SUPPORTED : %s\n", (data->led1_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_STATE_CAPS_BLINK_ALT_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  led1_color_caps = 0x%04"PRIX16"\n", data->led1_color_caps);
	RTE_LOG(INFO, PMD, "                    RSVD : %s\n", (data->led1_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_COLOR_CAPS_RSVD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    AMBER_SUPPORTED : %s\n", (data->led1_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_COLOR_CAPS_AMBER_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    GREEN_SUPPORTED : %s\n", (data->led1_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED1_COLOR_CAPS_GREEN_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "          led2_id = 0x%02"PRIX8"\n", data->led2_id);
	RTE_LOG(INFO, PMD, "        led2_type = 0x%02"PRIX8"\n", data->led2_type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->led2_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED2_TYPE_SPEED ? "SPEED" :
		data->led2_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED2_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led2_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED2_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    led2_group_id = 0x%02"PRIX8"\n", data->led2_group_id);
	RTE_LOG(INFO, PMD, "         unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "  led2_state_caps = 0x%04"PRIX16"\n", data->led2_state_caps);
	RTE_LOG(INFO, PMD, "                    ENABLED : %s\n", (data->led2_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_STATE_CAPS_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    OFF_SUPPORTED : %s\n", (data->led2_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_STATE_CAPS_OFF_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    ON_SUPPORTED : %s\n", (data->led2_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_STATE_CAPS_ON_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_SUPPORTED : %s\n", (data->led2_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_STATE_CAPS_BLINK_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_ALT_SUPPORTED : %s\n", (data->led2_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_STATE_CAPS_BLINK_ALT_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  led2_color_caps = 0x%04"PRIX16"\n", data->led2_color_caps);
	RTE_LOG(INFO, PMD, "                    RSVD : %s\n", (data->led2_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_COLOR_CAPS_RSVD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    AMBER_SUPPORTED : %s\n", (data->led2_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_COLOR_CAPS_AMBER_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    GREEN_SUPPORTED : %s\n", (data->led2_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED2_COLOR_CAPS_GREEN_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "          led3_id = 0x%02"PRIX8"\n", data->led3_id);
	RTE_LOG(INFO, PMD, "        led3_type = 0x%02"PRIX8"\n", data->led3_type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->led3_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED3_TYPE_SPEED ? "SPEED" :
		data->led3_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED3_TYPE_ACTIVITY ? "ACTIVITY" :
		data->led3_type == HWRM_PORT_LED_QCAPS_OUTPUT_LED3_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    led3_group_id = 0x%02"PRIX8"\n", data->led3_group_id);
	RTE_LOG(INFO, PMD, "         unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "  led3_state_caps = 0x%04"PRIX16"\n", data->led3_state_caps);
	RTE_LOG(INFO, PMD, "                    ENABLED : %s\n", (data->led3_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_STATE_CAPS_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    OFF_SUPPORTED : %s\n", (data->led3_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_STATE_CAPS_OFF_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    ON_SUPPORTED : %s\n", (data->led3_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_STATE_CAPS_ON_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_SUPPORTED : %s\n", (data->led3_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_STATE_CAPS_BLINK_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    BLINK_ALT_SUPPORTED : %s\n", (data->led3_state_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_STATE_CAPS_BLINK_ALT_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  led3_color_caps = 0x%04"PRIX16"\n", data->led3_color_caps);
	RTE_LOG(INFO, PMD, "                    RSVD : %s\n", (data->led3_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_COLOR_CAPS_RSVD)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    AMBER_SUPPORTED : %s\n", (data->led3_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_COLOR_CAPS_AMBER_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    GREEN_SUPPORTED : %s\n", (data->led3_color_caps & HWRM_PORT_LED_QCAPS_OUTPUT_LED3_COLOR_CAPS_GREEN_SUPPORTED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "         unused_6 = 0x%02"PRIX8"\n", data->unused_6);
	RTE_LOG(INFO, PMD, "         unused_7 = 0x%02"PRIX8"\n", data->unused_7);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_qportcfg_input(const char *string __rte_unused, struct hwrm_queue_qportcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_qportcfg_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->flags == HWRM_QUEUE_QPORTCFG_INPUT_FLAGS_PATH ? "PATH" :
		data->flags == HWRM_QUEUE_QPORTCFG_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_QUEUE_QPORTCFG_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_QUEUE_QPORTCFG_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_queue_qportcfg_output(const char *string __rte_unused, struct hwrm_queue_qportcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_qportcfg_output\n");
	RTE_LOG(INFO, PMD, "                        error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "                          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                          resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "           max_configurable_queues = 0x%02"PRIX8"\n", data->max_configurable_queues);
	RTE_LOG(INFO, PMD, "  max_configurable_lossless_queues = 0x%02"PRIX8"\n", data->max_configurable_lossless_queues);
	RTE_LOG(INFO, PMD, "                 queue_cfg_allowed = 0x%02"PRIX8"\n", data->queue_cfg_allowed);
	RTE_LOG(INFO, PMD, "                    queue_cfg_info = 0x%02"PRIX8"\n", data->queue_cfg_info);
	RTE_LOG(INFO, PMD, "                                     ASYM_CFG : %s\n", (data->queue_cfg_info & HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_CFG_INFO_ASYM_CFG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "       queue_pfcenable_cfg_allowed = 0x%02"PRIX8"\n", data->queue_pfcenable_cfg_allowed);
	RTE_LOG(INFO, PMD, "         queue_pri2cos_cfg_allowed = 0x%02"PRIX8"\n", data->queue_pri2cos_cfg_allowed);
	RTE_LOG(INFO, PMD, "          queue_cos2bw_cfg_allowed = 0x%02"PRIX8"\n", data->queue_cos2bw_cfg_allowed);
	RTE_LOG(INFO, PMD, "                         queue_id0 = 0x%02"PRIX8"\n", data->queue_id0);
	RTE_LOG(INFO, PMD, "         queue_id0_service_profile = 0x%02"PRIX8"\n", data->queue_id0_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id0_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID0_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id0_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID0_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id0_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID0_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         queue_id1 = 0x%02"PRIX8"\n", data->queue_id1);
	RTE_LOG(INFO, PMD, "         queue_id1_service_profile = 0x%02"PRIX8"\n", data->queue_id1_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id1_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID1_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id1_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID1_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id1_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID1_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         queue_id2 = 0x%02"PRIX8"\n", data->queue_id2);
	RTE_LOG(INFO, PMD, "         queue_id2_service_profile = 0x%02"PRIX8"\n", data->queue_id2_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id2_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID2_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id2_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID2_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id2_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID2_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         queue_id3 = 0x%02"PRIX8"\n", data->queue_id3);
	RTE_LOG(INFO, PMD, "         queue_id3_service_profile = 0x%02"PRIX8"\n", data->queue_id3_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id3_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID3_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id3_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID3_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id3_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID3_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         queue_id4 = 0x%02"PRIX8"\n", data->queue_id4);
	RTE_LOG(INFO, PMD, "         queue_id4_service_profile = 0x%02"PRIX8"\n", data->queue_id4_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id4_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID4_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id4_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID4_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id4_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID4_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         queue_id5 = 0x%02"PRIX8"\n", data->queue_id5);
	RTE_LOG(INFO, PMD, "         queue_id5_service_profile = 0x%02"PRIX8"\n", data->queue_id5_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id5_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID5_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id5_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID5_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id5_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID5_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         queue_id6 = 0x%02"PRIX8"\n", data->queue_id6);
	RTE_LOG(INFO, PMD, "         queue_id6_service_profile = 0x%02"PRIX8"\n", data->queue_id6_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id6_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID6_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id6_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID6_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id6_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID6_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                         queue_id7 = 0x%02"PRIX8"\n", data->queue_id7);
	RTE_LOG(INFO, PMD, "         queue_id7_service_profile = 0x%02"PRIX8"\n", data->queue_id7_service_profile);
	RTE_LOG(INFO, PMD, "                                     Value : %s\n",
		data->queue_id7_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID7_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->queue_id7_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID7_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->queue_id7_service_profile == HWRM_QUEUE_QPORTCFG_OUTPUT_QUEUE_ID7_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                             valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_qcfg_input(const char *string __rte_unused, struct hwrm_queue_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_qcfg_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->flags == HWRM_QUEUE_QCFG_INPUT_FLAGS_PATH ? "PATH" :
		data->flags == HWRM_QUEUE_QCFG_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_QUEUE_QCFG_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_QUEUE_QCFG_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   queue_id = 0x%08"PRIX32"\n", data->queue_id);
}

void decode_hwrm_queue_qcfg_output(const char *string __rte_unused, struct hwrm_queue_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_qcfg_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "        queue_len = 0x%08"PRIX32"\n", data->queue_len);
	RTE_LOG(INFO, PMD, "  service_profile = 0x%02"PRIX8"\n", data->service_profile);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->service_profile == HWRM_QUEUE_QCFG_OUTPUT_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->service_profile == HWRM_QUEUE_QCFG_OUTPUT_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->service_profile == HWRM_QUEUE_QCFG_OUTPUT_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   queue_cfg_info = 0x%02"PRIX8"\n", data->queue_cfg_info);
	RTE_LOG(INFO, PMD, "                    ASYM_CFG : %s\n", (data->queue_cfg_info & HWRM_QUEUE_QCFG_OUTPUT_QUEUE_CFG_INFO_ASYM_CFG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_cfg_input(const char *string __rte_unused, struct hwrm_queue_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_cfg_input\n");
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "        resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "            flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                    PATH = %0*X\n", 11, ((data->flags & HWRM_QUEUE_CFG_INPUT_FLAGS_PATH_MASK) >> HWRM_QUEUE_CFG_INPUT_FLAGS_PATH_SFT));
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->flags == HWRM_QUEUE_CFG_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_QUEUE_CFG_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_QUEUE_CFG_INPUT_FLAGS_PATH_BIDIR ? "PATH_BIDIR" :
		data->flags == HWRM_QUEUE_CFG_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                    DFLT_LEN : %s\n", (data->enables & HWRM_QUEUE_CFG_INPUT_ENABLES_DFLT_LEN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    SERVICE_PROFILE : %s\n", (data->enables & HWRM_QUEUE_CFG_INPUT_ENABLES_SERVICE_PROFILE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         queue_id = 0x%08"PRIX32"\n", data->queue_id);
	RTE_LOG(INFO, PMD, "         dflt_len = 0x%08"PRIX32"\n", data->dflt_len);
	RTE_LOG(INFO, PMD, "  service_profile = 0x%02"PRIX8"\n", data->service_profile);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->service_profile == HWRM_QUEUE_CFG_INPUT_SERVICE_PROFILE_LOSSY ? "LOSSY" :
		data->service_profile == HWRM_QUEUE_CFG_INPUT_SERVICE_PROFILE_LOSSLESS ? "LOSSLESS" :
		data->service_profile == HWRM_QUEUE_CFG_INPUT_SERVICE_PROFILE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "      unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "      unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "      unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "      unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "      unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "      unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_hwrm_queue_cfg_output(const char *string __rte_unused, struct hwrm_queue_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_pfcenable_qcfg_input(const char *string __rte_unused, struct hwrm_queue_pfcenable_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pfcenable_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_queue_pfcenable_qcfg_output(const char *string __rte_unused, struct hwrm_queue_pfcenable_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pfcenable_qcfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "       flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "               PRI0_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI0_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               PRI1_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI1_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               PRI2_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI2_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               PRI3_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI3_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               PRI4_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI4_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               PRI5_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI5_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               PRI6_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI6_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               PRI7_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_QCFG_OUTPUT_FLAGS_PRI7_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_pfcenable_cfg_input(const char *string __rte_unused, struct hwrm_queue_pfcenable_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pfcenable_cfg_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "              PRI0_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI0_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              PRI1_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI1_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              PRI2_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI2_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              PRI3_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI3_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              PRI4_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI4_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              PRI5_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI5_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              PRI6_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI6_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "              PRI7_PFC_ENABLED : %s\n", (data->flags & HWRM_QUEUE_PFCENABLE_CFG_INPUT_FLAGS_PRI7_PFC_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_queue_pfcenable_cfg_output(const char *string __rte_unused, struct hwrm_queue_pfcenable_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pfcenable_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_pri2cos_qcfg_input(const char *string __rte_unused, struct hwrm_queue_pri2cos_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pri2cos_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "        flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->flags == HWRM_QUEUE_PRI2COS_QCFG_INPUT_FLAGS_PATH ? "PATH" :
		data->flags == HWRM_QUEUE_PRI2COS_QCFG_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_QUEUE_PRI2COS_QCFG_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_QUEUE_PRI2COS_QCFG_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		data->flags == HWRM_QUEUE_PRI2COS_QCFG_INPUT_FLAGS_IVLAN ? "IVLAN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      port_id = 0x%02"PRIX8"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
}

void decode_hwrm_queue_pri2cos_qcfg_output(const char *string __rte_unused, struct hwrm_queue_pri2cos_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pri2cos_qcfg_output\n");
	RTE_LOG(INFO, PMD, "         error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  pri0_cos_queue_id = 0x%02"PRIX8"\n", data->pri0_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri1_cos_queue_id = 0x%02"PRIX8"\n", data->pri1_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri2_cos_queue_id = 0x%02"PRIX8"\n", data->pri2_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri3_cos_queue_id = 0x%02"PRIX8"\n", data->pri3_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri4_cos_queue_id = 0x%02"PRIX8"\n", data->pri4_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri5_cos_queue_id = 0x%02"PRIX8"\n", data->pri5_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri6_cos_queue_id = 0x%02"PRIX8"\n", data->pri6_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri7_cos_queue_id = 0x%02"PRIX8"\n", data->pri7_cos_queue_id);
	RTE_LOG(INFO, PMD, "     queue_cfg_info = 0x%02"PRIX8"\n", data->queue_cfg_info);
	RTE_LOG(INFO, PMD, "                      ASYM_CFG : %s\n", (data->queue_cfg_info & HWRM_QUEUE_PRI2COS_QCFG_OUTPUT_QUEUE_CFG_INFO_ASYM_CFG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "           unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "           unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "              valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_pri2cos_cfg_input(const char *string __rte_unused, struct hwrm_queue_pri2cos_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pri2cos_cfg_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "              flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                      PATH = %0*X\n", 11, ((data->flags & HWRM_QUEUE_PRI2COS_CFG_INPUT_FLAGS_PATH_MASK) >> HWRM_QUEUE_PRI2COS_CFG_INPUT_FLAGS_PATH_SFT));
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->flags == HWRM_QUEUE_PRI2COS_CFG_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_QUEUE_PRI2COS_CFG_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_QUEUE_PRI2COS_CFG_INPUT_FLAGS_PATH_BIDIR ? "PATH_BIDIR" :
		data->flags == HWRM_QUEUE_PRI2COS_CFG_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		data->flags == HWRM_QUEUE_PRI2COS_CFG_INPUT_FLAGS_IVLAN ? "IVLAN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                      PRI0_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI0_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PRI1_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI1_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PRI2_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI2_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PRI3_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI3_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PRI4_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI4_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PRI5_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI5_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PRI6_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI6_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PRI7_COS_QUEUE_ID : %s\n", (data->enables & HWRM_QUEUE_PRI2COS_CFG_INPUT_ENABLES_PRI7_COS_QUEUE_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "            port_id = 0x%02"PRIX8"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  pri0_cos_queue_id = 0x%02"PRIX8"\n", data->pri0_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri1_cos_queue_id = 0x%02"PRIX8"\n", data->pri1_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri2_cos_queue_id = 0x%02"PRIX8"\n", data->pri2_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri3_cos_queue_id = 0x%02"PRIX8"\n", data->pri3_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri4_cos_queue_id = 0x%02"PRIX8"\n", data->pri4_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri5_cos_queue_id = 0x%02"PRIX8"\n", data->pri5_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri6_cos_queue_id = 0x%02"PRIX8"\n", data->pri6_cos_queue_id);
	RTE_LOG(INFO, PMD, "  pri7_cos_queue_id = 0x%02"PRIX8"\n", data->pri7_cos_queue_id);
	RTE_LOG(INFO, PMD, "        unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "        unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "        unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "        unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "        unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "        unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "        unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_hwrm_queue_pri2cos_cfg_output(const char *string __rte_unused, struct hwrm_queue_pri2cos_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_pri2cos_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_cos2bw_qcfg_input(const char *string __rte_unused, struct hwrm_queue_cos2bw_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_cos2bw_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_queue_cos2bw_qcfg_output(const char *string __rte_unused, struct hwrm_queue_cos2bw_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_cos2bw_qcfg_output\n");
	RTE_LOG(INFO, PMD, "            error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "              resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "             queue_id0 = 0x%02"PRIX8"\n", data->queue_id0);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id0 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id0 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id0 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id0 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "              unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "              unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "      queue_id0_min_bw = 0x%08"PRIX32"\n", data->queue_id0_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id0_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id0_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_RSVD ? "RSVD" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id0_max_bw = 0x%08"PRIX32"\n", data->queue_id0_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id0_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id0_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_RSVD ? "RSVD" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id0_tsa_assign = 0x%02"PRIX8"\n", data->queue_id0_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_TSA_ASSIGN_SP ? "SP" :
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID0_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id0_pri_lvl = 0x%02"PRIX8"\n", data->queue_id0_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id0_bw_weight = 0x%02"PRIX8"\n", data->queue_id0_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id1 = 0x%02"PRIX8"\n", data->queue_id1);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id1 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id1 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id1 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id1 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id1_min_bw = 0x%08"PRIX32"\n", data->queue_id1_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id1_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id1_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_RSVD ? "RSVD" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id1_max_bw = 0x%08"PRIX32"\n", data->queue_id1_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id1_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id1_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_RSVD ? "RSVD" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id1_tsa_assign = 0x%02"PRIX8"\n", data->queue_id1_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_TSA_ASSIGN_SP ? "SP" :
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID1_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id1_pri_lvl = 0x%02"PRIX8"\n", data->queue_id1_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id1_bw_weight = 0x%02"PRIX8"\n", data->queue_id1_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id2 = 0x%02"PRIX8"\n", data->queue_id2);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id2 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id2 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id2 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id2 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id2_min_bw = 0x%08"PRIX32"\n", data->queue_id2_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id2_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id2_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_RSVD ? "RSVD" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id2_max_bw = 0x%08"PRIX32"\n", data->queue_id2_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id2_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id2_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_RSVD ? "RSVD" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id2_tsa_assign = 0x%02"PRIX8"\n", data->queue_id2_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_TSA_ASSIGN_SP ? "SP" :
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID2_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id2_pri_lvl = 0x%02"PRIX8"\n", data->queue_id2_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id2_bw_weight = 0x%02"PRIX8"\n", data->queue_id2_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id3 = 0x%02"PRIX8"\n", data->queue_id3);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id3 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id3 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id3 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id3 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id3_min_bw = 0x%08"PRIX32"\n", data->queue_id3_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id3_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id3_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_RSVD ? "RSVD" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id3_max_bw = 0x%08"PRIX32"\n", data->queue_id3_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id3_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id3_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_RSVD ? "RSVD" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id3_tsa_assign = 0x%02"PRIX8"\n", data->queue_id3_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_TSA_ASSIGN_SP ? "SP" :
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID3_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id3_pri_lvl = 0x%02"PRIX8"\n", data->queue_id3_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id3_bw_weight = 0x%02"PRIX8"\n", data->queue_id3_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id4 = 0x%02"PRIX8"\n", data->queue_id4);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id4 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id4 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id4 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id4 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id4_min_bw = 0x%08"PRIX32"\n", data->queue_id4_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id4_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id4_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_RSVD ? "RSVD" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id4_max_bw = 0x%08"PRIX32"\n", data->queue_id4_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id4_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id4_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_RSVD ? "RSVD" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id4_tsa_assign = 0x%02"PRIX8"\n", data->queue_id4_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_TSA_ASSIGN_SP ? "SP" :
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID4_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id4_pri_lvl = 0x%02"PRIX8"\n", data->queue_id4_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id4_bw_weight = 0x%02"PRIX8"\n", data->queue_id4_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id5 = 0x%02"PRIX8"\n", data->queue_id5);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id5 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id5 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id5 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id5 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id5_min_bw = 0x%08"PRIX32"\n", data->queue_id5_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id5_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id5_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_RSVD ? "RSVD" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id5_max_bw = 0x%08"PRIX32"\n", data->queue_id5_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id5_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id5_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_RSVD ? "RSVD" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id5_tsa_assign = 0x%02"PRIX8"\n", data->queue_id5_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_TSA_ASSIGN_SP ? "SP" :
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID5_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id5_pri_lvl = 0x%02"PRIX8"\n", data->queue_id5_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id5_bw_weight = 0x%02"PRIX8"\n", data->queue_id5_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id6 = 0x%02"PRIX8"\n", data->queue_id6);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id6 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id6 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id6 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id6 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id6_min_bw = 0x%08"PRIX32"\n", data->queue_id6_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id6_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id6_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_RSVD ? "RSVD" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id6_max_bw = 0x%08"PRIX32"\n", data->queue_id6_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id6_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id6_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_RSVD ? "RSVD" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id6_tsa_assign = 0x%02"PRIX8"\n", data->queue_id6_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_TSA_ASSIGN_SP ? "SP" :
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID6_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id6_pri_lvl = 0x%02"PRIX8"\n", data->queue_id6_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id6_bw_weight = 0x%02"PRIX8"\n", data->queue_id6_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id7 = 0x%02"PRIX8"\n", data->queue_id7);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id7 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id7 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id7 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id7 & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id7_min_bw = 0x%08"PRIX32"\n", data->queue_id7_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id7_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id7_min_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_RSVD ? "RSVD" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id7_max_bw = 0x%08"PRIX32"\n", data->queue_id7_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id7_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id7_max_bw & HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_RSVD ? "RSVD" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id7_tsa_assign = 0x%02"PRIX8"\n", data->queue_id7_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_TSA_ASSIGN_SP ? "SP" :
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_QCFG_OUTPUT_QUEUE_ID7_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id7_pri_lvl = 0x%02"PRIX8"\n", data->queue_id7_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id7_bw_weight = 0x%02"PRIX8"\n", data->queue_id7_bw_weight);
	RTE_LOG(INFO, PMD, "              unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "              unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "              unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "              unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "                 valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_queue_cos2bw_cfg_input(const char *string __rte_unused, struct hwrm_queue_cos2bw_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_cos2bw_cfg_input\n");
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "             resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                 flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "               enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID0_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID0_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID1_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID1_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID2_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID2_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID3_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID3_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID4_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID4_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID5_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID5_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID6_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID6_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                         COS_QUEUE_ID7_VALID : %s\n", (data->enables & HWRM_QUEUE_COS2BW_CFG_INPUT_ENABLES_COS_QUEUE_ID7_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "             queue_id0 = 0x%02"PRIX8"\n", data->queue_id0);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id0 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id0 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id0 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id0 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "              unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      queue_id0_min_bw = 0x%08"PRIX32"\n", data->queue_id0_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id0_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id0_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_RSVD ? "RSVD" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id0_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id0_max_bw = 0x%08"PRIX32"\n", data->queue_id0_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id0_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id0_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_RSVD ? "RSVD" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id0_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id0_tsa_assign = 0x%02"PRIX8"\n", data->queue_id0_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_TSA_ASSIGN_SP ? "SP" :
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id0_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID0_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id0_pri_lvl = 0x%02"PRIX8"\n", data->queue_id0_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id0_bw_weight = 0x%02"PRIX8"\n", data->queue_id0_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id1 = 0x%02"PRIX8"\n", data->queue_id1);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id1 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id1 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id1 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id1 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id1_min_bw = 0x%08"PRIX32"\n", data->queue_id1_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id1_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id1_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_RSVD ? "RSVD" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id1_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id1_max_bw = 0x%08"PRIX32"\n", data->queue_id1_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id1_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id1_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_RSVD ? "RSVD" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id1_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id1_tsa_assign = 0x%02"PRIX8"\n", data->queue_id1_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_TSA_ASSIGN_SP ? "SP" :
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id1_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID1_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id1_pri_lvl = 0x%02"PRIX8"\n", data->queue_id1_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id1_bw_weight = 0x%02"PRIX8"\n", data->queue_id1_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id2 = 0x%02"PRIX8"\n", data->queue_id2);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id2 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id2 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id2 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id2 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id2_min_bw = 0x%08"PRIX32"\n", data->queue_id2_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id2_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id2_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_RSVD ? "RSVD" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id2_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id2_max_bw = 0x%08"PRIX32"\n", data->queue_id2_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id2_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id2_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_RSVD ? "RSVD" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id2_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id2_tsa_assign = 0x%02"PRIX8"\n", data->queue_id2_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_TSA_ASSIGN_SP ? "SP" :
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id2_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID2_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id2_pri_lvl = 0x%02"PRIX8"\n", data->queue_id2_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id2_bw_weight = 0x%02"PRIX8"\n", data->queue_id2_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id3 = 0x%02"PRIX8"\n", data->queue_id3);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id3 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id3 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id3 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id3 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id3_min_bw = 0x%08"PRIX32"\n", data->queue_id3_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id3_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id3_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_RSVD ? "RSVD" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id3_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id3_max_bw = 0x%08"PRIX32"\n", data->queue_id3_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id3_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id3_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_RSVD ? "RSVD" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id3_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id3_tsa_assign = 0x%02"PRIX8"\n", data->queue_id3_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_TSA_ASSIGN_SP ? "SP" :
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id3_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID3_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id3_pri_lvl = 0x%02"PRIX8"\n", data->queue_id3_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id3_bw_weight = 0x%02"PRIX8"\n", data->queue_id3_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id4 = 0x%02"PRIX8"\n", data->queue_id4);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id4 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id4 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id4 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id4 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id4_min_bw = 0x%08"PRIX32"\n", data->queue_id4_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id4_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id4_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_RSVD ? "RSVD" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id4_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id4_max_bw = 0x%08"PRIX32"\n", data->queue_id4_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id4_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id4_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_RSVD ? "RSVD" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id4_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id4_tsa_assign = 0x%02"PRIX8"\n", data->queue_id4_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_TSA_ASSIGN_SP ? "SP" :
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id4_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID4_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id4_pri_lvl = 0x%02"PRIX8"\n", data->queue_id4_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id4_bw_weight = 0x%02"PRIX8"\n", data->queue_id4_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id5 = 0x%02"PRIX8"\n", data->queue_id5);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id5 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id5 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id5 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id5 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id5_min_bw = 0x%08"PRIX32"\n", data->queue_id5_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id5_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id5_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_RSVD ? "RSVD" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id5_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id5_max_bw = 0x%08"PRIX32"\n", data->queue_id5_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id5_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id5_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_RSVD ? "RSVD" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id5_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id5_tsa_assign = 0x%02"PRIX8"\n", data->queue_id5_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_TSA_ASSIGN_SP ? "SP" :
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id5_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID5_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id5_pri_lvl = 0x%02"PRIX8"\n", data->queue_id5_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id5_bw_weight = 0x%02"PRIX8"\n", data->queue_id5_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id6 = 0x%02"PRIX8"\n", data->queue_id6);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id6 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id6 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id6 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id6 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id6_min_bw = 0x%08"PRIX32"\n", data->queue_id6_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id6_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id6_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_RSVD ? "RSVD" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id6_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id6_max_bw = 0x%08"PRIX32"\n", data->queue_id6_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id6_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id6_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_RSVD ? "RSVD" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id6_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id6_tsa_assign = 0x%02"PRIX8"\n", data->queue_id6_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_TSA_ASSIGN_SP ? "SP" :
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id6_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID6_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id6_pri_lvl = 0x%02"PRIX8"\n", data->queue_id6_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id6_bw_weight = 0x%02"PRIX8"\n", data->queue_id6_bw_weight);
	RTE_LOG(INFO, PMD, "             queue_id7 = 0x%02"PRIX8"\n", data->queue_id7);
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id7 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MIN_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id7 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE = %0*X\n", 17, ((data->queue_id7 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                         MAX_BW_BW_VALUE_UNIT = %0*X\n", 11, ((data->queue_id7 & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "      queue_id7_min_bw = 0x%08"PRIX32"\n", data->queue_id7_min_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id7_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id7_min_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_RSVD ? "RSVD" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id7_min_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MIN_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      queue_id7_max_bw = 0x%08"PRIX32"\n", data->queue_id7_max_bw);
	RTE_LOG(INFO, PMD, "                         BW_VALUE = %0*X\n", 0, (data->queue_id7_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_MASK));
	RTE_LOG(INFO, PMD, "                         BW_VALUE_UNIT = %0*X\n", 0, (data->queue_id7_max_bw & HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_MASK));
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_RSVD ? "RSVD" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->queue_id7_max_bw == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  queue_id7_tsa_assign = 0x%02"PRIX8"\n", data->queue_id7_tsa_assign);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_TSA_ASSIGN_SP ? "SP" :
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_TSA_ASSIGN_ETS ? "ETS" :
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_TSA_ASSIGN_RESERVED_FIRST ? "RESERVED_FIRST" :
		data->queue_id7_tsa_assign == HWRM_QUEUE_COS2BW_CFG_INPUT_QUEUE_ID7_TSA_ASSIGN_RESERVED_LAST ? "RESERVED_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     queue_id7_pri_lvl = 0x%02"PRIX8"\n", data->queue_id7_pri_lvl);
	RTE_LOG(INFO, PMD, "   queue_id7_bw_weight = 0x%02"PRIX8"\n", data->queue_id7_bw_weight);
	RTE_LOG(INFO, PMD, "           unused_1[0] = 0x%02"PRIX8"\n", data->unused_1[0]);
	RTE_LOG(INFO, PMD, "           unused_1[1] = 0x%02"PRIX8"\n", data->unused_1[1]);
	RTE_LOG(INFO, PMD, "           unused_1[2] = 0x%02"PRIX8"\n", data->unused_1[2]);
	RTE_LOG(INFO, PMD, "           unused_1[3] = 0x%02"PRIX8"\n", data->unused_1[3]);
	RTE_LOG(INFO, PMD, "           unused_1[4] = 0x%02"PRIX8"\n", data->unused_1[4]);
}

void decode_hwrm_queue_cos2bw_cfg_output(const char *string __rte_unused, struct hwrm_queue_cos2bw_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_queue_cos2bw_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_alloc_input(const char *string __rte_unused, struct hwrm_vnic_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_alloc_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "              DEFAULT : %s\n", (data->flags & HWRM_VNIC_ALLOC_INPUT_FLAGS_DEFAULT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_vnic_alloc_output(const char *string __rte_unused, struct hwrm_vnic_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_alloc_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "     vnic_id = 0x%08"PRIX32"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_free_input(const char *string __rte_unused, struct hwrm_vnic_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_free_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    vnic_id = 0x%08"PRIX32"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_vnic_free_output(const char *string __rte_unused, struct hwrm_vnic_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_cfg_input(const char *string __rte_unused, struct hwrm_vnic_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_cfg_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  DEFAULT : %s\n", (data->flags & HWRM_VNIC_CFG_INPUT_FLAGS_DEFAULT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  VLAN_STRIP_MODE : %s\n", (data->flags & HWRM_VNIC_CFG_INPUT_FLAGS_VLAN_STRIP_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  BD_STALL_MODE : %s\n", (data->flags & HWRM_VNIC_CFG_INPUT_FLAGS_BD_STALL_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  ROCE_DUAL_VNIC_MODE : %s\n", (data->flags & HWRM_VNIC_CFG_INPUT_FLAGS_ROCE_DUAL_VNIC_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  ROCE_ONLY_VNIC_MODE : %s\n", (data->flags & HWRM_VNIC_CFG_INPUT_FLAGS_ROCE_ONLY_VNIC_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  RSS_DFLT_CR_MODE : %s\n", (data->flags & HWRM_VNIC_CFG_INPUT_FLAGS_RSS_DFLT_CR_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                  DFLT_RING_GRP : %s\n", (data->enables & HWRM_VNIC_CFG_INPUT_ENABLES_DFLT_RING_GRP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  RSS_RULE : %s\n", (data->enables & HWRM_VNIC_CFG_INPUT_ENABLES_RSS_RULE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  COS_RULE : %s\n", (data->enables & HWRM_VNIC_CFG_INPUT_ENABLES_COS_RULE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  LB_RULE : %s\n", (data->enables & HWRM_VNIC_CFG_INPUT_ENABLES_LB_RULE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  MRU : %s\n", (data->enables & HWRM_VNIC_CFG_INPUT_ENABLES_MRU)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        vnic_id = 0x%04"PRIX16"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "  dflt_ring_grp = 0x%04"PRIX16"\n", data->dflt_ring_grp);
	RTE_LOG(INFO, PMD, "       rss_rule = 0x%04"PRIX16"\n", data->rss_rule);
	RTE_LOG(INFO, PMD, "       cos_rule = 0x%04"PRIX16"\n", data->cos_rule);
	RTE_LOG(INFO, PMD, "        lb_rule = 0x%04"PRIX16"\n", data->lb_rule);
	RTE_LOG(INFO, PMD, "            mru = 0x%04"PRIX16"\n", data->mru);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_vnic_cfg_output(const char *string __rte_unused, struct hwrm_vnic_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                VF_ID_VALID : %s\n", (data->enables & HWRM_VNIC_QCFG_INPUT_ENABLES_VF_ID_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      vnic_id = 0x%08"PRIX32"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "        vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_vnic_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_qcfg_output\n");
	RTE_LOG(INFO, PMD, "     error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  dflt_ring_grp = 0x%04"PRIX16"\n", data->dflt_ring_grp);
	RTE_LOG(INFO, PMD, "       rss_rule = 0x%04"PRIX16"\n", data->rss_rule);
	RTE_LOG(INFO, PMD, "       cos_rule = 0x%04"PRIX16"\n", data->cos_rule);
	RTE_LOG(INFO, PMD, "        lb_rule = 0x%04"PRIX16"\n", data->lb_rule);
	RTE_LOG(INFO, PMD, "            mru = 0x%04"PRIX16"\n", data->mru);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "          flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  DEFAULT : %s\n", (data->flags & HWRM_VNIC_QCFG_OUTPUT_FLAGS_DEFAULT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  VLAN_STRIP_MODE : %s\n", (data->flags & HWRM_VNIC_QCFG_OUTPUT_FLAGS_VLAN_STRIP_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  BD_STALL_MODE : %s\n", (data->flags & HWRM_VNIC_QCFG_OUTPUT_FLAGS_BD_STALL_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  ROCE_DUAL_VNIC_MODE : %s\n", (data->flags & HWRM_VNIC_QCFG_OUTPUT_FLAGS_ROCE_DUAL_VNIC_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  ROCE_ONLY_VNIC_MODE : %s\n", (data->flags & HWRM_VNIC_QCFG_OUTPUT_FLAGS_ROCE_ONLY_VNIC_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  RSS_DFLT_CR_MODE : %s\n", (data->flags & HWRM_VNIC_QCFG_OUTPUT_FLAGS_RSS_DFLT_CR_MODE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%08"PRIX32"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "       unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "          valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_qcaps_input(const char *string __rte_unused, struct hwrm_vnic_qcaps_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_qcaps_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_vnic_qcaps_output(const char *string __rte_unused, struct hwrm_vnic_qcaps_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_qcaps_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "         mru = 0x%04"PRIX16"\n", data->mru);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "               UNUSED : %s\n", (data->flags & HWRM_VNIC_QCAPS_OUTPUT_FLAGS_UNUSED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               VLAN_STRIP_CAP : %s\n", (data->flags & HWRM_VNIC_QCAPS_OUTPUT_FLAGS_VLAN_STRIP_CAP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               BD_STALL_CAP : %s\n", (data->flags & HWRM_VNIC_QCAPS_OUTPUT_FLAGS_BD_STALL_CAP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               ROCE_DUAL_VNIC_CAP : %s\n", (data->flags & HWRM_VNIC_QCAPS_OUTPUT_FLAGS_ROCE_DUAL_VNIC_CAP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               ROCE_ONLY_VNIC_CAP : %s\n", (data->flags & HWRM_VNIC_QCAPS_OUTPUT_FLAGS_ROCE_ONLY_VNIC_CAP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               RSS_DFLT_CR_CAP : %s\n", (data->flags & HWRM_VNIC_QCAPS_OUTPUT_FLAGS_RSS_DFLT_CR_CAP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%08"PRIX32"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "    unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "    unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_tpa_cfg_input(const char *string __rte_unused, struct hwrm_vnic_tpa_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_tpa_cfg_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  TPA : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_TPA)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  ENCAP_TPA : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_ENCAP_TPA)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  RSC_WND_UPDATE : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_RSC_WND_UPDATE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  GRO : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_GRO)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  AGG_WITH_ECN : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_AGG_WITH_ECN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  AGG_WITH_SAME_GRE_SEQ : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_AGG_WITH_SAME_GRE_SEQ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  GRO_IPID_CHECK : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_GRO_IPID_CHECK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  GRO_TTL_CHECK : %s\n", (data->flags & HWRM_VNIC_TPA_CFG_INPUT_FLAGS_GRO_TTL_CHECK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                  MAX_AGG_SEGS : %s\n", (data->enables & HWRM_VNIC_TPA_CFG_INPUT_ENABLES_MAX_AGG_SEGS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  MAX_AGGS : %s\n", (data->enables & HWRM_VNIC_TPA_CFG_INPUT_ENABLES_MAX_AGGS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  MAX_AGG_TIMER : %s\n", (data->enables & HWRM_VNIC_TPA_CFG_INPUT_ENABLES_MAX_AGG_TIMER)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  MIN_AGG_LEN : %s\n", (data->enables & HWRM_VNIC_TPA_CFG_INPUT_ENABLES_MIN_AGG_LEN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        vnic_id = 0x%04"PRIX16"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "   max_agg_segs = 0x%04"PRIX16"\n", data->max_agg_segs);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->max_agg_segs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGG_SEGS_1 ? "1" :
		data->max_agg_segs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGG_SEGS_2 ? "2" :
		data->max_agg_segs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGG_SEGS_4 ? "4" :
		data->max_agg_segs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGG_SEGS_8 ? "8" :
		data->max_agg_segs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGG_SEGS_MAX ? "MAX" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       max_aggs = 0x%04"PRIX16"\n", data->max_aggs);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->max_aggs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGGS_1 ? "1" :
		data->max_aggs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGGS_2 ? "2" :
		data->max_aggs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGGS_4 ? "4" :
		data->max_aggs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGGS_8 ? "8" :
		data->max_aggs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGGS_16 ? "16" :
		data->max_aggs == HWRM_VNIC_TPA_CFG_INPUT_MAX_AGGS_MAX ? "MAX" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "  max_agg_timer = 0x%08"PRIX32"\n", data->max_agg_timer);
	RTE_LOG(INFO, PMD, "    min_agg_len = 0x%08"PRIX32"\n", data->min_agg_len);
}

void decode_hwrm_vnic_tpa_cfg_output(const char *string __rte_unused, struct hwrm_vnic_tpa_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_tpa_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_tpa_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_tpa_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_tpa_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      vnic_id = 0x%04"PRIX16"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_vnic_tpa_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_tpa_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_tpa_qcfg_output\n");
	RTE_LOG(INFO, PMD, "     error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "          flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  TPA : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_TPA)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  ENCAP_TPA : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_ENCAP_TPA)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  RSC_WND_UPDATE : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_RSC_WND_UPDATE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  GRO : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_GRO)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  AGG_WITH_ECN : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_AGG_WITH_ECN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  AGG_WITH_SAME_GRE_SEQ : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_AGG_WITH_SAME_GRE_SEQ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  GRO_IPID_CHECK : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_GRO_IPID_CHECK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  GRO_TTL_CHECK : %s\n", (data->flags & HWRM_VNIC_TPA_QCFG_OUTPUT_FLAGS_GRO_TTL_CHECK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   max_agg_segs = 0x%04"PRIX16"\n", data->max_agg_segs);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->max_agg_segs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGG_SEGS_1 ? "1" :
		data->max_agg_segs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGG_SEGS_2 ? "2" :
		data->max_agg_segs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGG_SEGS_4 ? "4" :
		data->max_agg_segs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGG_SEGS_8 ? "8" :
		data->max_agg_segs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGG_SEGS_MAX ? "MAX" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       max_aggs = 0x%04"PRIX16"\n", data->max_aggs);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->max_aggs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGGS_1 ? "1" :
		data->max_aggs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGGS_2 ? "2" :
		data->max_aggs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGGS_4 ? "4" :
		data->max_aggs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGGS_8 ? "8" :
		data->max_aggs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGGS_16 ? "16" :
		data->max_aggs == HWRM_VNIC_TPA_QCFG_OUTPUT_MAX_AGGS_MAX ? "MAX" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  max_agg_timer = 0x%08"PRIX32"\n", data->max_agg_timer);
	RTE_LOG(INFO, PMD, "    min_agg_len = 0x%08"PRIX32"\n", data->min_agg_len);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "          valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_rss_cfg_input(const char *string __rte_unused, struct hwrm_vnic_rss_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_cfg_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          hash_type = 0x%08"PRIX32"\n", data->hash_type);
	RTE_LOG(INFO, PMD, "                      IPV4 : %s\n", (data->hash_type & HWRM_VNIC_RSS_CFG_INPUT_HASH_TYPE_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      TCP_IPV4 : %s\n", (data->hash_type & HWRM_VNIC_RSS_CFG_INPUT_HASH_TYPE_TCP_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      UDP_IPV4 : %s\n", (data->hash_type & HWRM_VNIC_RSS_CFG_INPUT_HASH_TYPE_UDP_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      IPV6 : %s\n", (data->hash_type & HWRM_VNIC_RSS_CFG_INPUT_HASH_TYPE_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      TCP_IPV6 : %s\n", (data->hash_type & HWRM_VNIC_RSS_CFG_INPUT_HASH_TYPE_TCP_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      UDP_IPV6 : %s\n", (data->hash_type & HWRM_VNIC_RSS_CFG_INPUT_HASH_TYPE_UDP_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  ring_grp_tbl_addr = 0x%016"PRIX64"\n", data->ring_grp_tbl_addr);
	RTE_LOG(INFO, PMD, "  hash_key_tbl_addr = 0x%016"PRIX64"\n", data->hash_key_tbl_addr);
	RTE_LOG(INFO, PMD, "        rss_ctx_idx = 0x%04"PRIX16"\n", data->rss_ctx_idx);
	RTE_LOG(INFO, PMD, "        unused_1[0] = 0x%04"PRIX16"\n", data->unused_1[0]);
	RTE_LOG(INFO, PMD, "        unused_1[1] = 0x%04"PRIX16"\n", data->unused_1[1]);
	RTE_LOG(INFO, PMD, "        unused_1[2] = 0x%04"PRIX16"\n", data->unused_1[2]);
}

void decode_hwrm_vnic_rss_cfg_output(const char *string __rte_unused, struct hwrm_vnic_rss_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_rss_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_rss_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_qcfg_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  rss_ctx_idx = 0x%04"PRIX16"\n", data->rss_ctx_idx);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_vnic_rss_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_rss_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_qcfg_output\n");
	RTE_LOG(INFO, PMD, "    error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "     hash_type = 0x%08"PRIX32"\n", data->hash_type);
	RTE_LOG(INFO, PMD, "                 IPV4 : %s\n", (data->hash_type & HWRM_VNIC_RSS_QCFG_OUTPUT_HASH_TYPE_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 TCP_IPV4 : %s\n", (data->hash_type & HWRM_VNIC_RSS_QCFG_OUTPUT_HASH_TYPE_TCP_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 UDP_IPV4 : %s\n", (data->hash_type & HWRM_VNIC_RSS_QCFG_OUTPUT_HASH_TYPE_UDP_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 IPV6 : %s\n", (data->hash_type & HWRM_VNIC_RSS_QCFG_OUTPUT_HASH_TYPE_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 TCP_IPV6 : %s\n", (data->hash_type & HWRM_VNIC_RSS_QCFG_OUTPUT_HASH_TYPE_TCP_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 UDP_IPV6 : %s\n", (data->hash_type & HWRM_VNIC_RSS_QCFG_OUTPUT_HASH_TYPE_UDP_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "   hash_key[0] = 0x%08"PRIX32"\n", data->hash_key[0]);
	RTE_LOG(INFO, PMD, "   hash_key[1] = 0x%08"PRIX32"\n", data->hash_key[1]);
	RTE_LOG(INFO, PMD, "   hash_key[2] = 0x%08"PRIX32"\n", data->hash_key[2]);
	RTE_LOG(INFO, PMD, "   hash_key[3] = 0x%08"PRIX32"\n", data->hash_key[3]);
	RTE_LOG(INFO, PMD, "   hash_key[4] = 0x%08"PRIX32"\n", data->hash_key[4]);
	RTE_LOG(INFO, PMD, "   hash_key[5] = 0x%08"PRIX32"\n", data->hash_key[5]);
	RTE_LOG(INFO, PMD, "   hash_key[6] = 0x%08"PRIX32"\n", data->hash_key[6]);
	RTE_LOG(INFO, PMD, "   hash_key[7] = 0x%08"PRIX32"\n", data->hash_key[7]);
	RTE_LOG(INFO, PMD, "   hash_key[8] = 0x%08"PRIX32"\n", data->hash_key[8]);
	RTE_LOG(INFO, PMD, "   hash_key[9] = 0x%08"PRIX32"\n", data->hash_key[9]);
	RTE_LOG(INFO, PMD, "      unused_1 = 0x%08"PRIX32"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "      unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "      unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "      unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "         valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_plcmodes_cfg_input(const char *string __rte_unused, struct hwrm_vnic_plcmodes_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_plcmodes_cfg_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  REGULAR_PLACEMENT : %s\n", (data->flags & HWRM_VNIC_PLCMODES_CFG_INPUT_FLAGS_REGULAR_PLACEMENT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  JUMBO_PLACEMENT : %s\n", (data->flags & HWRM_VNIC_PLCMODES_CFG_INPUT_FLAGS_JUMBO_PLACEMENT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_IPV4 : %s\n", (data->flags & HWRM_VNIC_PLCMODES_CFG_INPUT_FLAGS_HDS_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_IPV6 : %s\n", (data->flags & HWRM_VNIC_PLCMODES_CFG_INPUT_FLAGS_HDS_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_FCOE : %s\n", (data->flags & HWRM_VNIC_PLCMODES_CFG_INPUT_FLAGS_HDS_FCOE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_ROCE : %s\n", (data->flags & HWRM_VNIC_PLCMODES_CFG_INPUT_FLAGS_HDS_ROCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                  JUMBO_THRESH_VALID : %s\n", (data->enables & HWRM_VNIC_PLCMODES_CFG_INPUT_ENABLES_JUMBO_THRESH_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_OFFSET_VALID : %s\n", (data->enables & HWRM_VNIC_PLCMODES_CFG_INPUT_ENABLES_HDS_OFFSET_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_THRESHOLD_VALID : %s\n", (data->enables & HWRM_VNIC_PLCMODES_CFG_INPUT_ENABLES_HDS_THRESHOLD_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        vnic_id = 0x%08"PRIX32"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "   jumbo_thresh = 0x%04"PRIX16"\n", data->jumbo_thresh);
	RTE_LOG(INFO, PMD, "     hds_offset = 0x%04"PRIX16"\n", data->hds_offset);
	RTE_LOG(INFO, PMD, "  hds_threshold = 0x%04"PRIX16"\n", data->hds_threshold);
	RTE_LOG(INFO, PMD, "    unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "    unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "    unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_vnic_plcmodes_cfg_output(const char *string __rte_unused, struct hwrm_vnic_plcmodes_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_plcmodes_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_plcmodes_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_plcmodes_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_plcmodes_qcfg_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    vnic_id = 0x%08"PRIX32"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_vnic_plcmodes_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_plcmodes_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_plcmodes_qcfg_output\n");
	RTE_LOG(INFO, PMD, "     error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "          flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  REGULAR_PLACEMENT : %s\n", (data->flags & HWRM_VNIC_PLCMODES_QCFG_OUTPUT_FLAGS_REGULAR_PLACEMENT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  JUMBO_PLACEMENT : %s\n", (data->flags & HWRM_VNIC_PLCMODES_QCFG_OUTPUT_FLAGS_JUMBO_PLACEMENT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_IPV4 : %s\n", (data->flags & HWRM_VNIC_PLCMODES_QCFG_OUTPUT_FLAGS_HDS_IPV4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_IPV6 : %s\n", (data->flags & HWRM_VNIC_PLCMODES_QCFG_OUTPUT_FLAGS_HDS_IPV6)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_FCOE : %s\n", (data->flags & HWRM_VNIC_PLCMODES_QCFG_OUTPUT_FLAGS_HDS_FCOE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  HDS_ROCE : %s\n", (data->flags & HWRM_VNIC_PLCMODES_QCFG_OUTPUT_FLAGS_HDS_ROCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                  DFLT_VNIC : %s\n", (data->flags & HWRM_VNIC_PLCMODES_QCFG_OUTPUT_FLAGS_DFLT_VNIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   jumbo_thresh = 0x%04"PRIX16"\n", data->jumbo_thresh);
	RTE_LOG(INFO, PMD, "     hds_offset = 0x%04"PRIX16"\n", data->hds_offset);
	RTE_LOG(INFO, PMD, "  hds_threshold = 0x%04"PRIX16"\n", data->hds_threshold);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "          valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_rss_cos_lb_ctx_alloc_input(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_cos_lb_ctx_alloc_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_hwrm_vnic_rss_cos_lb_ctx_alloc_output(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_cos_lb_ctx_alloc_output\n");
	RTE_LOG(INFO, PMD, "         error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  rss_cos_lb_ctx_id = 0x%04"PRIX16"\n", data->rss_cos_lb_ctx_id);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "           unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "           unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "              valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_vnic_rss_cos_lb_ctx_free_input(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_cos_lb_ctx_free_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  rss_cos_lb_ctx_id = 0x%04"PRIX16"\n", data->rss_cos_lb_ctx_id);
	RTE_LOG(INFO, PMD, "        unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "        unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "        unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_vnic_rss_cos_lb_ctx_free_output(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_vnic_rss_cos_lb_ctx_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_ring_alloc_input(const char *string __rte_unused, struct hwrm_ring_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_alloc_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "         enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                   RESERVED1 : %s\n", (data->enables & HWRM_RING_ALLOC_INPUT_ENABLES_RESERVED1)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   RING_ARB_CFG : %s\n", (data->enables & HWRM_RING_ALLOC_INPUT_ENABLES_RING_ARB_CFG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   RESERVED3 : %s\n", (data->enables & HWRM_RING_ALLOC_INPUT_ENABLES_RESERVED3)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   STAT_CTX_ID_VALID : %s\n", (data->enables & HWRM_RING_ALLOC_INPUT_ENABLES_STAT_CTX_ID_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   RESERVED4 : %s\n", (data->enables & HWRM_RING_ALLOC_INPUT_ENABLES_RESERVED4)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   MAX_BW_VALID : %s\n", (data->enables & HWRM_RING_ALLOC_INPUT_ENABLES_MAX_BW_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "       ring_type = 0x%02"PRIX8"\n", data->ring_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->ring_type == HWRM_RING_ALLOC_INPUT_RING_TYPE_CMPL ? "CMPL" :
		data->ring_type == HWRM_RING_ALLOC_INPUT_RING_TYPE_TX ? "TX" :
		data->ring_type == HWRM_RING_ALLOC_INPUT_RING_TYPE_RX ? "RX" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "   page_tbl_addr = 0x%016"PRIX64"\n", data->page_tbl_addr);
	RTE_LOG(INFO, PMD, "             fbo = 0x%08"PRIX32"\n", data->fbo);
	RTE_LOG(INFO, PMD, "       page_size = 0x%02"PRIX8"\n", data->page_size);
	RTE_LOG(INFO, PMD, "  page_tbl_depth = 0x%02"PRIX8"\n", data->page_tbl_depth);
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "          length = 0x%08"PRIX32"\n", data->length);
	RTE_LOG(INFO, PMD, "      logical_id = 0x%04"PRIX16"\n", data->logical_id);
	RTE_LOG(INFO, PMD, "    cmpl_ring_id = 0x%04"PRIX16"\n", data->cmpl_ring_id);
	RTE_LOG(INFO, PMD, "        queue_id = 0x%04"PRIX16"\n", data->queue_id);
	RTE_LOG(INFO, PMD, "        unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "        unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "       reserved1 = 0x%08"PRIX32"\n", data->reserved1);
	RTE_LOG(INFO, PMD, "    ring_arb_cfg = 0x%04"PRIX16"\n", data->ring_arb_cfg);
	RTE_LOG(INFO, PMD, "                   ARB_POLICY = %0*X\n", 11, ((data->ring_arb_cfg & HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_ARB_POLICY_MASK) >> HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_ARB_POLICY_SFT));
	RTE_LOG(INFO, PMD, "                   RSVD = %0*X\n", 11, ((data->ring_arb_cfg & HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_RSVD_MASK) >> HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_RSVD_SFT));
	RTE_LOG(INFO, PMD, "                   ARB_POLICY_PARAM = %0*X\n", 12, ((data->ring_arb_cfg & HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_ARB_POLICY_PARAM_MASK) >> HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_ARB_POLICY_PARAM_SFT));
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->ring_arb_cfg == HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_ARB_POLICY_SP ? "ARB_POLICY_SP" :
		data->ring_arb_cfg == HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_ARB_POLICY_WFQ ? "ARB_POLICY_WFQ" :
		data->ring_arb_cfg == HWRM_RING_ALLOC_INPUT_RING_ARB_CFG_ARB_POLICY_LAST ? "ARB_POLICY_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_6 = 0x%02"PRIX8"\n", data->unused_6);
	RTE_LOG(INFO, PMD, "        unused_7 = 0x%02"PRIX8"\n", data->unused_7);
	RTE_LOG(INFO, PMD, "       reserved3 = 0x%08"PRIX32"\n", data->reserved3);
	RTE_LOG(INFO, PMD, "     stat_ctx_id = 0x%08"PRIX32"\n", data->stat_ctx_id);
	RTE_LOG(INFO, PMD, "       reserved4 = 0x%08"PRIX32"\n", data->reserved4);
	RTE_LOG(INFO, PMD, "          max_bw = 0x%08"PRIX32"\n", data->max_bw);
	RTE_LOG(INFO, PMD, "                   BW_VALUE = %0*X\n", 17, ((data->max_bw & HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_MASK) >> HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_SFT));
	RTE_LOG(INFO, PMD, "                   BW_VALUE_UNIT = %0*X\n", 11, ((data->max_bw & HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_UNIT_MASK) >> HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_UNIT_SFT));
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->max_bw == HWRM_RING_ALLOC_INPUT_MAX_BW_RSVD ? "RSVD" :
		data->max_bw == HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_UNIT_MBPS ? "BW_VALUE_UNIT_MBPS" :
		data->max_bw == HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_UNIT_PERCENT1_100 ? "BW_VALUE_UNIT_PERCENT1_100" :
		data->max_bw == HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_UNIT_INVALID ? "BW_VALUE_UNIT_INVALID" :
		data->max_bw == HWRM_RING_ALLOC_INPUT_MAX_BW_BW_VALUE_UNIT_LAST ? "BW_VALUE_UNIT_LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        int_mode = 0x%02"PRIX8"\n", data->int_mode);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->int_mode == HWRM_RING_ALLOC_INPUT_INT_MODE_LEGACY ? "LEGACY" :
		data->int_mode == HWRM_RING_ALLOC_INPUT_INT_MODE_RSVD ? "RSVD" :
		data->int_mode == HWRM_RING_ALLOC_INPUT_INT_MODE_MSIX ? "MSIX" :
		data->int_mode == HWRM_RING_ALLOC_INPUT_INT_MODE_POLL ? "POLL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     unused_8[0] = 0x%02"PRIX8"\n", data->unused_8[0]);
	RTE_LOG(INFO, PMD, "     unused_8[1] = 0x%02"PRIX8"\n", data->unused_8[1]);
	RTE_LOG(INFO, PMD, "     unused_8[2] = 0x%02"PRIX8"\n", data->unused_8[2]);
}

void decode_hwrm_ring_alloc_output(const char *string __rte_unused, struct hwrm_ring_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_alloc_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "          ring_id = 0x%04"PRIX16"\n", data->ring_id);
	RTE_LOG(INFO, PMD, "  logical_ring_id = 0x%04"PRIX16"\n", data->logical_ring_id);
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "         unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_ring_free_input(const char *string __rte_unused, struct hwrm_ring_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_free_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  ring_type = 0x%02"PRIX8"\n", data->ring_type);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->ring_type == HWRM_RING_FREE_INPUT_RING_TYPE_CMPL ? "CMPL" :
		data->ring_type == HWRM_RING_FREE_INPUT_RING_TYPE_TX ? "TX" :
		data->ring_type == HWRM_RING_FREE_INPUT_RING_TYPE_RX ? "RX" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    ring_id = 0x%04"PRIX16"\n", data->ring_id);
	RTE_LOG(INFO, PMD, "   unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_ring_free_output(const char *string __rte_unused, struct hwrm_ring_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_ring_cmpl_ring_qaggint_params_input(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_qaggint_params_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_cmpl_ring_qaggint_params_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      ring_id = 0x%04"PRIX16"\n", data->ring_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_ring_cmpl_ring_qaggint_params_output(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_qaggint_params_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_cmpl_ring_qaggint_params_output\n");
	RTE_LOG(INFO, PMD, "                    error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "                      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                      resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "                         flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                                 TIMER_RESET : %s\n", (data->flags & HWRM_RING_CMPL_RING_QAGGINT_PARAMS_OUTPUT_FLAGS_TIMER_RESET)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                 RING_IDLE : %s\n", (data->flags & HWRM_RING_CMPL_RING_QAGGINT_PARAMS_OUTPUT_FLAGS_RING_IDLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             num_cmpl_dma_aggr = 0x%04"PRIX16"\n", data->num_cmpl_dma_aggr);
	RTE_LOG(INFO, PMD, "  num_cmpl_dma_aggr_during_int = 0x%04"PRIX16"\n", data->num_cmpl_dma_aggr_during_int);
	RTE_LOG(INFO, PMD, "             cmpl_aggr_dma_tmr = 0x%04"PRIX16"\n", data->cmpl_aggr_dma_tmr);
	RTE_LOG(INFO, PMD, "  cmpl_aggr_dma_tmr_during_int = 0x%04"PRIX16"\n", data->cmpl_aggr_dma_tmr_during_int);
	RTE_LOG(INFO, PMD, "               int_lat_tmr_min = 0x%04"PRIX16"\n", data->int_lat_tmr_min);
	RTE_LOG(INFO, PMD, "               int_lat_tmr_max = 0x%04"PRIX16"\n", data->int_lat_tmr_max);
	RTE_LOG(INFO, PMD, "             num_cmpl_aggr_int = 0x%04"PRIX16"\n", data->num_cmpl_aggr_int);
	RTE_LOG(INFO, PMD, "                      unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "                      unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "                      unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "                      unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "                         valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_ring_cmpl_ring_cfg_aggint_params_input(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_cfg_aggint_params_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_cmpl_ring_cfg_aggint_params_input\n");
	RTE_LOG(INFO, PMD, "                      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                     cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                     target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "                     resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                       ring_id = 0x%04"PRIX16"\n", data->ring_id);
	RTE_LOG(INFO, PMD, "                         flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                                 TIMER_RESET : %s\n", (data->flags & HWRM_RING_CMPL_RING_CFG_AGGINT_PARAMS_INPUT_FLAGS_TIMER_RESET)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                 RING_IDLE : %s\n", (data->flags & HWRM_RING_CMPL_RING_CFG_AGGINT_PARAMS_INPUT_FLAGS_RING_IDLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             num_cmpl_dma_aggr = 0x%04"PRIX16"\n", data->num_cmpl_dma_aggr);
	RTE_LOG(INFO, PMD, "  num_cmpl_dma_aggr_during_int = 0x%04"PRIX16"\n", data->num_cmpl_dma_aggr_during_int);
	RTE_LOG(INFO, PMD, "             cmpl_aggr_dma_tmr = 0x%04"PRIX16"\n", data->cmpl_aggr_dma_tmr);
	RTE_LOG(INFO, PMD, "  cmpl_aggr_dma_tmr_during_int = 0x%04"PRIX16"\n", data->cmpl_aggr_dma_tmr_during_int);
	RTE_LOG(INFO, PMD, "               int_lat_tmr_min = 0x%04"PRIX16"\n", data->int_lat_tmr_min);
	RTE_LOG(INFO, PMD, "               int_lat_tmr_max = 0x%04"PRIX16"\n", data->int_lat_tmr_max);
	RTE_LOG(INFO, PMD, "             num_cmpl_aggr_int = 0x%04"PRIX16"\n", data->num_cmpl_aggr_int);
	RTE_LOG(INFO, PMD, "                   unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "                   unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "                   unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_ring_cmpl_ring_cfg_aggint_params_output(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_cfg_aggint_params_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_cmpl_ring_cfg_aggint_params_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_ring_reset_input(const char *string __rte_unused, struct hwrm_ring_reset_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_reset_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  ring_type = 0x%02"PRIX8"\n", data->ring_type);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->ring_type == HWRM_RING_RESET_INPUT_RING_TYPE_CMPL ? "CMPL" :
		data->ring_type == HWRM_RING_RESET_INPUT_RING_TYPE_TX ? "TX" :
		data->ring_type == HWRM_RING_RESET_INPUT_RING_TYPE_RX ? "RX" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    ring_id = 0x%04"PRIX16"\n", data->ring_id);
	RTE_LOG(INFO, PMD, "   unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_ring_reset_output(const char *string __rte_unused, struct hwrm_ring_reset_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_reset_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_ring_grp_alloc_input(const char *string __rte_unused, struct hwrm_ring_grp_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_grp_alloc_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "         cr = 0x%04"PRIX16"\n", data->cr);
	RTE_LOG(INFO, PMD, "         rr = 0x%04"PRIX16"\n", data->rr);
	RTE_LOG(INFO, PMD, "         ar = 0x%04"PRIX16"\n", data->ar);
	RTE_LOG(INFO, PMD, "         sc = 0x%04"PRIX16"\n", data->sc);
}

void decode_hwrm_ring_grp_alloc_output(const char *string __rte_unused, struct hwrm_ring_grp_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_grp_alloc_output\n");
	RTE_LOG(INFO, PMD, "     error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  ring_group_id = 0x%08"PRIX32"\n", data->ring_group_id);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "          valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_ring_grp_free_input(const char *string __rte_unused, struct hwrm_ring_grp_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_grp_free_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  ring_group_id = 0x%08"PRIX32"\n", data->ring_group_id);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_ring_grp_free_output(const char *string __rte_unused, struct hwrm_ring_grp_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_ring_grp_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_l2_filter_alloc_input(const char *string __rte_unused, struct hwrm_cfa_l2_filter_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_filter_alloc_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "              flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->flags == HWRM_CFA_L2_FILTER_ALLOC_INPUT_FLAGS_PATH ? "PATH" :
		data->flags == HWRM_CFA_L2_FILTER_ALLOC_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_CFA_L2_FILTER_ALLOC_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_CFA_L2_FILTER_ALLOC_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		data->flags == HWRM_CFA_L2_FILTER_ALLOC_INPUT_FLAGS_LOOPBACK ? "LOOPBACK" :
		data->flags == HWRM_CFA_L2_FILTER_ALLOC_INPUT_FLAGS_DROP ? "DROP" :
		data->flags == HWRM_CFA_L2_FILTER_ALLOC_INPUT_FLAGS_OUTERMOST ? "OUTERMOST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                      L2_ADDR = %0*X\n", 11, (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_L2_ADDR_MASK));
	RTE_LOG(INFO, PMD, "                      L2_OVLAN = %0*X\n", 11, (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_L2_OVLAN_MASK));
	RTE_LOG(INFO, PMD, "                      L2_IVLAN = %0*X\n", 11, (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_L2_IVLAN_MASK));
	RTE_LOG(INFO, PMD, "                      T_L2_ADDR = %0*X\n", 11, (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_T_L2_ADDR_MASK));
	RTE_LOG(INFO, PMD, "                      T_L2_OVLAN = %0*X\n", 11, (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_T_L2_OVLAN_MASK));
	RTE_LOG(INFO, PMD, "                      T_L2_IVLAN = %0*X\n", 11, (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_T_L2_IVLAN_MASK));
	RTE_LOG(INFO, PMD, "                      L2_ADDR : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_L2_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      L2_OVLAN : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_L2_OVLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      L2_IVLAN : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_L2_IVLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      T_L2_ADDR : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_T_L2_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      T_L2_OVLAN : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_T_L2_OVLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      T_L2_IVLAN : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_T_L2_IVLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      SRC_TYPE : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_SRC_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      SRC_ID : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_SRC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      TUNNEL_TYPE : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_TUNNEL_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      DST_ID : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_DST_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      MIRROR_VNIC_ID : %s\n", (data->enables & HWRM_CFA_L2_FILTER_ALLOC_INPUT_ENABLES_MIRROR_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         l2_addr[0] = 0x%02"PRIX8"\n", data->l2_addr[0]);
	RTE_LOG(INFO, PMD, "         l2_addr[1] = 0x%02"PRIX8"\n", data->l2_addr[1]);
	RTE_LOG(INFO, PMD, "         l2_addr[2] = 0x%02"PRIX8"\n", data->l2_addr[2]);
	RTE_LOG(INFO, PMD, "         l2_addr[3] = 0x%02"PRIX8"\n", data->l2_addr[3]);
	RTE_LOG(INFO, PMD, "         l2_addr[4] = 0x%02"PRIX8"\n", data->l2_addr[4]);
	RTE_LOG(INFO, PMD, "         l2_addr[5] = 0x%02"PRIX8"\n", data->l2_addr[5]);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    l2_addr_mask[0] = 0x%02"PRIX8"\n", data->l2_addr_mask[0]);
	RTE_LOG(INFO, PMD, "    l2_addr_mask[1] = 0x%02"PRIX8"\n", data->l2_addr_mask[1]);
	RTE_LOG(INFO, PMD, "    l2_addr_mask[2] = 0x%02"PRIX8"\n", data->l2_addr_mask[2]);
	RTE_LOG(INFO, PMD, "    l2_addr_mask[3] = 0x%02"PRIX8"\n", data->l2_addr_mask[3]);
	RTE_LOG(INFO, PMD, "    l2_addr_mask[4] = 0x%02"PRIX8"\n", data->l2_addr_mask[4]);
	RTE_LOG(INFO, PMD, "    l2_addr_mask[5] = 0x%02"PRIX8"\n", data->l2_addr_mask[5]);
	RTE_LOG(INFO, PMD, "           l2_ovlan = 0x%04"PRIX16"\n", data->l2_ovlan);
	RTE_LOG(INFO, PMD, "      l2_ovlan_mask = 0x%04"PRIX16"\n", data->l2_ovlan_mask);
	RTE_LOG(INFO, PMD, "           l2_ivlan = 0x%04"PRIX16"\n", data->l2_ivlan);
	RTE_LOG(INFO, PMD, "      l2_ivlan_mask = 0x%04"PRIX16"\n", data->l2_ivlan_mask);
	RTE_LOG(INFO, PMD, "           unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "           unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       t_l2_addr[0] = 0x%02"PRIX8"\n", data->t_l2_addr[0]);
	RTE_LOG(INFO, PMD, "       t_l2_addr[1] = 0x%02"PRIX8"\n", data->t_l2_addr[1]);
	RTE_LOG(INFO, PMD, "       t_l2_addr[2] = 0x%02"PRIX8"\n", data->t_l2_addr[2]);
	RTE_LOG(INFO, PMD, "       t_l2_addr[3] = 0x%02"PRIX8"\n", data->t_l2_addr[3]);
	RTE_LOG(INFO, PMD, "       t_l2_addr[4] = 0x%02"PRIX8"\n", data->t_l2_addr[4]);
	RTE_LOG(INFO, PMD, "       t_l2_addr[5] = 0x%02"PRIX8"\n", data->t_l2_addr[5]);
	RTE_LOG(INFO, PMD, "           unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "           unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "  t_l2_addr_mask[0] = 0x%02"PRIX8"\n", data->t_l2_addr_mask[0]);
	RTE_LOG(INFO, PMD, "  t_l2_addr_mask[1] = 0x%02"PRIX8"\n", data->t_l2_addr_mask[1]);
	RTE_LOG(INFO, PMD, "  t_l2_addr_mask[2] = 0x%02"PRIX8"\n", data->t_l2_addr_mask[2]);
	RTE_LOG(INFO, PMD, "  t_l2_addr_mask[3] = 0x%02"PRIX8"\n", data->t_l2_addr_mask[3]);
	RTE_LOG(INFO, PMD, "  t_l2_addr_mask[4] = 0x%02"PRIX8"\n", data->t_l2_addr_mask[4]);
	RTE_LOG(INFO, PMD, "  t_l2_addr_mask[5] = 0x%02"PRIX8"\n", data->t_l2_addr_mask[5]);
	RTE_LOG(INFO, PMD, "         t_l2_ovlan = 0x%04"PRIX16"\n", data->t_l2_ovlan);
	RTE_LOG(INFO, PMD, "    t_l2_ovlan_mask = 0x%04"PRIX16"\n", data->t_l2_ovlan_mask);
	RTE_LOG(INFO, PMD, "         t_l2_ivlan = 0x%04"PRIX16"\n", data->t_l2_ivlan);
	RTE_LOG(INFO, PMD, "    t_l2_ivlan_mask = 0x%04"PRIX16"\n", data->t_l2_ivlan_mask);
	RTE_LOG(INFO, PMD, "           src_type = 0x%02"PRIX8"\n", data->src_type);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_NPORT ? "NPORT" :
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_PF ? "PF" :
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_VF ? "VF" :
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_VNIC ? "VNIC" :
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_KONG ? "KONG" :
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_APE ? "APE" :
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_BONO ? "BONO" :
		data->src_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_SRC_TYPE_TANG ? "TANG" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           unused_6 = 0x%02"PRIX8"\n", data->unused_6);
	RTE_LOG(INFO, PMD, "             src_id = 0x%08"PRIX32"\n", data->src_id);
	RTE_LOG(INFO, PMD, "        tunnel_type = 0x%02"PRIX8"\n", data->tunnel_type);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_NONTUNNEL ? "NONTUNNEL" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_VXLAN ? "VXLAN" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_NVGRE ? "NVGRE" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_L2GRE ? "L2GRE" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_IPIP ? "IPIP" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_GENEVE ? "GENEVE" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_MPLS ? "MPLS" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_STT ? "STT" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_IPGRE ? "IPGRE" :
		data->tunnel_type == HWRM_CFA_L2_FILTER_ALLOC_INPUT_TUNNEL_TYPE_ANYTUNNEL ? "ANYTUNNEL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           unused_7 = 0x%02"PRIX8"\n", data->unused_7);
	RTE_LOG(INFO, PMD, "             dst_id = 0x%04"PRIX16"\n", data->dst_id);
	RTE_LOG(INFO, PMD, "     mirror_vnic_id = 0x%04"PRIX16"\n", data->mirror_vnic_id);
	RTE_LOG(INFO, PMD, "           pri_hint = 0x%02"PRIX8"\n", data->pri_hint);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->pri_hint == HWRM_CFA_L2_FILTER_ALLOC_INPUT_PRI_HINT_NO_PREFER ? "NO_PREFER" :
		data->pri_hint == HWRM_CFA_L2_FILTER_ALLOC_INPUT_PRI_HINT_ABOVE_FILTER ? "ABOVE_FILTER" :
		data->pri_hint == HWRM_CFA_L2_FILTER_ALLOC_INPUT_PRI_HINT_BELOW_FILTER ? "BELOW_FILTER" :
		data->pri_hint == HWRM_CFA_L2_FILTER_ALLOC_INPUT_PRI_HINT_MAX ? "MAX" :
		data->pri_hint == HWRM_CFA_L2_FILTER_ALLOC_INPUT_PRI_HINT_MIN ? "MIN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           unused_8 = 0x%02"PRIX8"\n", data->unused_8);
	RTE_LOG(INFO, PMD, "           unused_9 = 0x%08"PRIX32"\n", data->unused_9);
	RTE_LOG(INFO, PMD, "  l2_filter_id_hint = 0x%016"PRIX64"\n", data->l2_filter_id_hint);
}

void decode_hwrm_cfa_l2_filter_alloc_output(const char *string __rte_unused, struct hwrm_cfa_l2_filter_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_filter_alloc_output\n");
	RTE_LOG(INFO, PMD, "    error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  l2_filter_id = 0x%016"PRIX64"\n", data->l2_filter_id);
	RTE_LOG(INFO, PMD, "       flow_id = 0x%08"PRIX32"\n", data->flow_id);
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "      unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "         valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_l2_filter_free_input(const char *string __rte_unused, struct hwrm_cfa_l2_filter_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_filter_free_input\n");
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "     cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "     resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  l2_filter_id = 0x%016"PRIX64"\n", data->l2_filter_id);
}

void decode_hwrm_cfa_l2_filter_free_output(const char *string __rte_unused, struct hwrm_cfa_l2_filter_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_filter_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_l2_filter_cfg_input(const char *string __rte_unused, struct hwrm_cfa_l2_filter_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_filter_cfg_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "               flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                       Value : %s\n",
		data->flags == HWRM_CFA_L2_FILTER_CFG_INPUT_FLAGS_PATH ? "PATH" :
		data->flags == HWRM_CFA_L2_FILTER_CFG_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_CFA_L2_FILTER_CFG_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_CFA_L2_FILTER_CFG_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		data->flags == HWRM_CFA_L2_FILTER_CFG_INPUT_FLAGS_DROP ? "DROP" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                       DST_ID : %s\n", (data->enables & HWRM_CFA_L2_FILTER_CFG_INPUT_ENABLES_DST_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       NEW_MIRROR_VNIC_ID : %s\n", (data->enables & HWRM_CFA_L2_FILTER_CFG_INPUT_ENABLES_NEW_MIRROR_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        l2_filter_id = 0x%016"PRIX64"\n", data->l2_filter_id);
	RTE_LOG(INFO, PMD, "              dst_id = 0x%08"PRIX32"\n", data->dst_id);
	RTE_LOG(INFO, PMD, "  new_mirror_vnic_id = 0x%08"PRIX32"\n", data->new_mirror_vnic_id);
}

void decode_hwrm_cfa_l2_filter_cfg_output(const char *string __rte_unused, struct hwrm_cfa_l2_filter_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_filter_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_l2_set_rx_mask_input(const char *string __rte_unused, struct hwrm_cfa_l2_set_rx_mask_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_set_rx_mask_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "            vnic_id = 0x%08"PRIX32"\n", data->vnic_id);
	RTE_LOG(INFO, PMD, "               mask = 0x%08"PRIX32"\n", data->mask);
	RTE_LOG(INFO, PMD, "                      RESERVED : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_RESERVED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      MCAST : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_MCAST)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      ALL_MCAST : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_ALL_MCAST)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      BCAST : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_BCAST)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PROMISCUOUS : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_PROMISCUOUS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      OUTERMOST : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_OUTERMOST)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      VLANONLY : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_VLANONLY)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      VLAN_NONVLAN : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_VLAN_NONVLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      ANYVLAN_NONVLAN : %s\n", (data->mask & HWRM_CFA_L2_SET_RX_MASK_INPUT_MASK_ANYVLAN_NONVLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        mc_tbl_addr = 0x%016"PRIX64"\n", data->mc_tbl_addr);
	RTE_LOG(INFO, PMD, "     num_mc_entries = 0x%08"PRIX32"\n", data->num_mc_entries);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  vlan_tag_tbl_addr = 0x%016"PRIX64"\n", data->vlan_tag_tbl_addr);
	RTE_LOG(INFO, PMD, "      num_vlan_tags = 0x%08"PRIX32"\n", data->num_vlan_tags);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_cfa_l2_set_rx_mask_output(const char *string __rte_unused, struct hwrm_cfa_l2_set_rx_mask_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_l2_set_rx_mask_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_tunnel_filter_alloc_input(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_tunnel_filter_alloc_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "           flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                   LOOPBACK : %s\n", (data->flags & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_FLAGS_LOOPBACK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                   L2_FILTER_ID : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_L2_FILTER_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   L2_ADDR : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_L2_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   L2_IVLAN : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_L2_IVLAN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   L3_ADDR : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_L3_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   L3_ADDR_TYPE : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_L3_ADDR_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   T_L3_ADDR_TYPE : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_T_L3_ADDR_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   T_L3_ADDR : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_T_L3_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   TUNNEL_TYPE : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_TUNNEL_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   VNI : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_VNI)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   DST_VNIC_ID : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_DST_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   MIRROR_VNIC_ID : %s\n", (data->enables & HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_ENABLES_MIRROR_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    l2_filter_id = 0x%016"PRIX64"\n", data->l2_filter_id);
	RTE_LOG(INFO, PMD, "      l2_addr[0] = 0x%02"PRIX8"\n", data->l2_addr[0]);
	RTE_LOG(INFO, PMD, "      l2_addr[1] = 0x%02"PRIX8"\n", data->l2_addr[1]);
	RTE_LOG(INFO, PMD, "      l2_addr[2] = 0x%02"PRIX8"\n", data->l2_addr[2]);
	RTE_LOG(INFO, PMD, "      l2_addr[3] = 0x%02"PRIX8"\n", data->l2_addr[3]);
	RTE_LOG(INFO, PMD, "      l2_addr[4] = 0x%02"PRIX8"\n", data->l2_addr[4]);
	RTE_LOG(INFO, PMD, "      l2_addr[5] = 0x%02"PRIX8"\n", data->l2_addr[5]);
	RTE_LOG(INFO, PMD, "        l2_ivlan = 0x%04"PRIX16"\n", data->l2_ivlan);
	RTE_LOG(INFO, PMD, "      l3_addr[0] = 0x%08"PRIX32"\n", data->l3_addr[0]);
	RTE_LOG(INFO, PMD, "      l3_addr[1] = 0x%08"PRIX32"\n", data->l3_addr[1]);
	RTE_LOG(INFO, PMD, "      l3_addr[2] = 0x%08"PRIX32"\n", data->l3_addr[2]);
	RTE_LOG(INFO, PMD, "      l3_addr[3] = 0x%08"PRIX32"\n", data->l3_addr[3]);
	RTE_LOG(INFO, PMD, "    t_l3_addr[0] = 0x%08"PRIX32"\n", data->t_l3_addr[0]);
	RTE_LOG(INFO, PMD, "    t_l3_addr[1] = 0x%08"PRIX32"\n", data->t_l3_addr[1]);
	RTE_LOG(INFO, PMD, "    t_l3_addr[2] = 0x%08"PRIX32"\n", data->t_l3_addr[2]);
	RTE_LOG(INFO, PMD, "    t_l3_addr[3] = 0x%08"PRIX32"\n", data->t_l3_addr[3]);
	RTE_LOG(INFO, PMD, "    l3_addr_type = 0x%02"PRIX8"\n", data->l3_addr_type);
	RTE_LOG(INFO, PMD, "  t_l3_addr_type = 0x%02"PRIX8"\n", data->t_l3_addr_type);
	RTE_LOG(INFO, PMD, "     tunnel_type = 0x%02"PRIX8"\n", data->tunnel_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_NONTUNNEL ? "NONTUNNEL" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_VXLAN ? "VXLAN" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_NVGRE ? "NVGRE" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_L2GRE ? "L2GRE" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_IPIP ? "IPIP" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_GENEVE ? "GENEVE" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_MPLS ? "MPLS" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_STT ? "STT" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_IPGRE ? "IPGRE" :
		data->tunnel_type == HWRM_CFA_TUNNEL_FILTER_ALLOC_INPUT_TUNNEL_TYPE_ANYTUNNEL ? "ANYTUNNEL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "             vni = 0x%08"PRIX32"\n", data->vni);
	RTE_LOG(INFO, PMD, "     dst_vnic_id = 0x%08"PRIX32"\n", data->dst_vnic_id);
	RTE_LOG(INFO, PMD, "  mirror_vnic_id = 0x%08"PRIX32"\n", data->mirror_vnic_id);
}

void decode_hwrm_cfa_tunnel_filter_alloc_output(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_tunnel_filter_alloc_output\n");
	RTE_LOG(INFO, PMD, "        error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  tunnel_filter_id = 0x%016"PRIX64"\n", data->tunnel_filter_id);
	RTE_LOG(INFO, PMD, "           flow_id = 0x%08"PRIX32"\n", data->flow_id);
	RTE_LOG(INFO, PMD, "          unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "          unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "          unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "             valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_tunnel_filter_free_input(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_tunnel_filter_free_input\n");
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  tunnel_filter_id = 0x%016"PRIX64"\n", data->tunnel_filter_id);
}

void decode_hwrm_cfa_tunnel_filter_free_output(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_tunnel_filter_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_encap_record_alloc_input(const char *string __rte_unused, struct hwrm_cfa_encap_record_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_encap_record_alloc_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "           flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                   LOOPBACK : %s\n", (data->flags & HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_FLAGS_LOOPBACK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      encap_type = 0x%02"PRIX8"\n", data->encap_type);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_VXLAN ? "VXLAN" :
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_NVGRE ? "NVGRE" :
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_L2GRE ? "L2GRE" :
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_IPIP ? "IPIP" :
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_GENEVE ? "GENEVE" :
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_MPLS ? "MPLS" :
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_VLAN ? "VLAN" :
		data->encap_type == HWRM_CFA_ENCAP_RECORD_ALLOC_INPUT_ENCAP_TYPE_IPGRE ? "IPGRE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "   encap_data[0] = 0x%08"PRIX32"\n", data->encap_data[0]);
	RTE_LOG(INFO, PMD, "   encap_data[1] = 0x%08"PRIX32"\n", data->encap_data[1]);
	RTE_LOG(INFO, PMD, "   encap_data[2] = 0x%08"PRIX32"\n", data->encap_data[2]);
	RTE_LOG(INFO, PMD, "   encap_data[3] = 0x%08"PRIX32"\n", data->encap_data[3]);
	RTE_LOG(INFO, PMD, "   encap_data[4] = 0x%08"PRIX32"\n", data->encap_data[4]);
	RTE_LOG(INFO, PMD, "   encap_data[5] = 0x%08"PRIX32"\n", data->encap_data[5]);
	RTE_LOG(INFO, PMD, "   encap_data[6] = 0x%08"PRIX32"\n", data->encap_data[6]);
	RTE_LOG(INFO, PMD, "   encap_data[7] = 0x%08"PRIX32"\n", data->encap_data[7]);
	RTE_LOG(INFO, PMD, "   encap_data[8] = 0x%08"PRIX32"\n", data->encap_data[8]);
	RTE_LOG(INFO, PMD, "   encap_data[9] = 0x%08"PRIX32"\n", data->encap_data[9]);
	RTE_LOG(INFO, PMD, "  encap_data[10] = 0x%08"PRIX32"\n", data->encap_data[10]);
	RTE_LOG(INFO, PMD, "  encap_data[11] = 0x%08"PRIX32"\n", data->encap_data[11]);
	RTE_LOG(INFO, PMD, "  encap_data[12] = 0x%08"PRIX32"\n", data->encap_data[12]);
	RTE_LOG(INFO, PMD, "  encap_data[13] = 0x%08"PRIX32"\n", data->encap_data[13]);
	RTE_LOG(INFO, PMD, "  encap_data[14] = 0x%08"PRIX32"\n", data->encap_data[14]);
	RTE_LOG(INFO, PMD, "  encap_data[15] = 0x%08"PRIX32"\n", data->encap_data[15]);
}

void decode_hwrm_cfa_encap_record_alloc_output(const char *string __rte_unused, struct hwrm_cfa_encap_record_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_encap_record_alloc_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  encap_record_id = 0x%08"PRIX32"\n", data->encap_record_id);
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "         unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_encap_record_free_input(const char *string __rte_unused, struct hwrm_cfa_encap_record_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_encap_record_free_input\n");
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "        resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  encap_record_id = 0x%08"PRIX32"\n", data->encap_record_id);
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_cfa_encap_record_free_output(const char *string __rte_unused, struct hwrm_cfa_encap_record_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_encap_record_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_ntuple_filter_alloc_input(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_ntuple_filter_alloc_input\n");
	RTE_LOG(INFO, PMD, "               req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "              cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                 seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "              target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "              resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                  flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                          LOOPBACK : %s\n", (data->flags & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_FLAGS_LOOPBACK)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          DROP : %s\n", (data->flags & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_FLAGS_DROP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                          SRC_IPADDR = %0*X\n", 11, (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_SRC_IPADDR_MASK));
	RTE_LOG(INFO, PMD, "                          DST_IPADDR = %0*X\n", 11, (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_DST_IPADDR_MASK));
	RTE_LOG(INFO, PMD, "                          SRC_PORT = %0*X\n", 11, (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_SRC_PORT_MASK));
	RTE_LOG(INFO, PMD, "                          DST_PORT = %0*X\n", 11, (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_DST_PORT_MASK));
	RTE_LOG(INFO, PMD, "                          L2_FILTER_ID : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_L2_FILTER_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          ETHERTYPE : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_ETHERTYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          TUNNEL_TYPE : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_TUNNEL_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          SRC_MACADDR : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_SRC_MACADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          IPADDR_TYPE : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_IPADDR_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          SRC_IPADDR : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_SRC_IPADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          DST_IPADDR : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_DST_IPADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          IP_PROTOCOL : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_IP_PROTOCOL)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          SRC_PORT : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_SRC_PORT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          DST_PORT : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_DST_PORT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          PRI_HINT : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_PRI_HINT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          NTUPLE_FILTER_ID : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_NTUPLE_FILTER_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          DST_ID : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_DST_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          MIRROR_VNIC_ID : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_MIRROR_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                          DST_MACADDR : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_ENABLES_DST_MACADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "           l2_filter_id = 0x%016"PRIX64"\n", data->l2_filter_id);
	RTE_LOG(INFO, PMD, "         src_macaddr[0] = 0x%02"PRIX8"\n", data->src_macaddr[0]);
	RTE_LOG(INFO, PMD, "         src_macaddr[1] = 0x%02"PRIX8"\n", data->src_macaddr[1]);
	RTE_LOG(INFO, PMD, "         src_macaddr[2] = 0x%02"PRIX8"\n", data->src_macaddr[2]);
	RTE_LOG(INFO, PMD, "         src_macaddr[3] = 0x%02"PRIX8"\n", data->src_macaddr[3]);
	RTE_LOG(INFO, PMD, "         src_macaddr[4] = 0x%02"PRIX8"\n", data->src_macaddr[4]);
	RTE_LOG(INFO, PMD, "         src_macaddr[5] = 0x%02"PRIX8"\n", data->src_macaddr[5]);
	RTE_LOG(INFO, PMD, "              ethertype = 0x%04"PRIX16"\n", data->ethertype);
	RTE_LOG(INFO, PMD, "           ip_addr_type = 0x%02"PRIX8"\n", data->ip_addr_type);
	RTE_LOG(INFO, PMD, "                          Value : %s\n",
		data->ip_addr_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_IP_ADDR_TYPE_UNKNOWN ? "UNKNOWN" :
		data->ip_addr_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_IP_ADDR_TYPE_IPV4 ? "IPV4" :
		data->ip_addr_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_IP_ADDR_TYPE_IPV6 ? "IPV6" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            ip_protocol = 0x%02"PRIX8"\n", data->ip_protocol);
	RTE_LOG(INFO, PMD, "                          Value : %s\n",
		data->ip_protocol == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_IP_PROTOCOL_UNKNOWN ? "UNKNOWN" :
		data->ip_protocol == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_IP_PROTOCOL_UDP ? "UDP" :
		data->ip_protocol == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_IP_PROTOCOL_TCP ? "TCP" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                 dst_id = 0x%04"PRIX16"\n", data->dst_id);
	RTE_LOG(INFO, PMD, "         mirror_vnic_id = 0x%04"PRIX16"\n", data->mirror_vnic_id);
	RTE_LOG(INFO, PMD, "            tunnel_type = 0x%02"PRIX8"\n", data->tunnel_type);
	RTE_LOG(INFO, PMD, "                          Value : %s\n",
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_NONTUNNEL ? "NONTUNNEL" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_VXLAN ? "VXLAN" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_NVGRE ? "NVGRE" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_L2GRE ? "L2GRE" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_IPIP ? "IPIP" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_GENEVE ? "GENEVE" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_MPLS ? "MPLS" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_STT ? "STT" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_IPGRE ? "IPGRE" :
		data->tunnel_type == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_TUNNEL_TYPE_ANYTUNNEL ? "ANYTUNNEL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "               pri_hint = 0x%02"PRIX8"\n", data->pri_hint);
	RTE_LOG(INFO, PMD, "                          Value : %s\n",
		data->pri_hint == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_PRI_HINT_NO_PREFER ? "NO_PREFER" :
		data->pri_hint == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_PRI_HINT_ABOVE ? "ABOVE" :
		data->pri_hint == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_PRI_HINT_BELOW ? "BELOW" :
		data->pri_hint == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_PRI_HINT_HIGHEST ? "HIGHEST" :
		data->pri_hint == HWRM_CFA_NTUPLE_FILTER_ALLOC_INPUT_PRI_HINT_LOWEST ? "LOWEST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          src_ipaddr[0] = 0x%08"PRIX32"\n", data->src_ipaddr[0]);
	RTE_LOG(INFO, PMD, "          src_ipaddr[1] = 0x%08"PRIX32"\n", data->src_ipaddr[1]);
	RTE_LOG(INFO, PMD, "          src_ipaddr[2] = 0x%08"PRIX32"\n", data->src_ipaddr[2]);
	RTE_LOG(INFO, PMD, "          src_ipaddr[3] = 0x%08"PRIX32"\n", data->src_ipaddr[3]);
	RTE_LOG(INFO, PMD, "     src_ipaddr_mask[0] = 0x%08"PRIX32"\n", data->src_ipaddr_mask[0]);
	RTE_LOG(INFO, PMD, "     src_ipaddr_mask[1] = 0x%08"PRIX32"\n", data->src_ipaddr_mask[1]);
	RTE_LOG(INFO, PMD, "     src_ipaddr_mask[2] = 0x%08"PRIX32"\n", data->src_ipaddr_mask[2]);
	RTE_LOG(INFO, PMD, "     src_ipaddr_mask[3] = 0x%08"PRIX32"\n", data->src_ipaddr_mask[3]);
	RTE_LOG(INFO, PMD, "          dst_ipaddr[0] = 0x%08"PRIX32"\n", data->dst_ipaddr[0]);
	RTE_LOG(INFO, PMD, "          dst_ipaddr[1] = 0x%08"PRIX32"\n", data->dst_ipaddr[1]);
	RTE_LOG(INFO, PMD, "          dst_ipaddr[2] = 0x%08"PRIX32"\n", data->dst_ipaddr[2]);
	RTE_LOG(INFO, PMD, "          dst_ipaddr[3] = 0x%08"PRIX32"\n", data->dst_ipaddr[3]);
	RTE_LOG(INFO, PMD, "     dst_ipaddr_mask[0] = 0x%08"PRIX32"\n", data->dst_ipaddr_mask[0]);
	RTE_LOG(INFO, PMD, "     dst_ipaddr_mask[1] = 0x%08"PRIX32"\n", data->dst_ipaddr_mask[1]);
	RTE_LOG(INFO, PMD, "     dst_ipaddr_mask[2] = 0x%08"PRIX32"\n", data->dst_ipaddr_mask[2]);
	RTE_LOG(INFO, PMD, "     dst_ipaddr_mask[3] = 0x%08"PRIX32"\n", data->dst_ipaddr_mask[3]);
	RTE_LOG(INFO, PMD, "               src_port = 0x%04"PRIX16"\n", data->src_port);
	RTE_LOG(INFO, PMD, "          src_port_mask = 0x%04"PRIX16"\n", data->src_port_mask);
	RTE_LOG(INFO, PMD, "               dst_port = 0x%04"PRIX16"\n", data->dst_port);
	RTE_LOG(INFO, PMD, "          dst_port_mask = 0x%04"PRIX16"\n", data->dst_port_mask);
	RTE_LOG(INFO, PMD, "  ntuple_filter_id_hint = 0x%016"PRIX64"\n", data->ntuple_filter_id_hint);
}

void decode_hwrm_cfa_ntuple_filter_alloc_output(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_ntuple_filter_alloc_output\n");
	RTE_LOG(INFO, PMD, "        error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  ntuple_filter_id = 0x%016"PRIX64"\n", data->ntuple_filter_id);
	RTE_LOG(INFO, PMD, "           flow_id = 0x%08"PRIX32"\n", data->flow_id);
	RTE_LOG(INFO, PMD, "          unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "          unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "          unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "             valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_ntuple_filter_free_input(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_ntuple_filter_free_input\n");
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  ntuple_filter_id = 0x%016"PRIX64"\n", data->ntuple_filter_id);
}

void decode_hwrm_cfa_ntuple_filter_free_output(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_ntuple_filter_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_ntuple_filter_cfg_input(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_ntuple_filter_cfg_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "             enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                       NEW_DST_ID : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_CFG_INPUT_ENABLES_NEW_DST_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       NEW_MIRROR_VNIC_ID : %s\n", (data->enables & HWRM_CFA_NTUPLE_FILTER_CFG_INPUT_ENABLES_NEW_MIRROR_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "            unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    ntuple_filter_id = 0x%016"PRIX64"\n", data->ntuple_filter_id);
	RTE_LOG(INFO, PMD, "          new_dst_id = 0x%08"PRIX32"\n", data->new_dst_id);
	RTE_LOG(INFO, PMD, "  new_mirror_vnic_id = 0x%08"PRIX32"\n", data->new_mirror_vnic_id);
}

void decode_hwrm_cfa_ntuple_filter_cfg_output(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_ntuple_filter_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_em_flow_alloc_input(const char *string __rte_unused, struct hwrm_cfa_em_flow_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_em_flow_alloc_input\n");
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "        resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "            flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_PATH ? "PATH" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_PATH_TX ? "PATH_TX" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_PATH_RX ? "PATH_RX" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_PATH_LAST ? "PATH_LAST" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_BYTE_CTR ? "BYTE_CTR" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_PKT_CTR ? "PKT_CTR" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_DECAP ? "DECAP" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_ENCAP ? "ENCAP" :
		data->flags == HWRM_CFA_EM_FLOW_ALLOC_INPUT_FLAGS_DROP ? "DROP" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                    L2_FILTER_ID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_L2_FILTER_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    TUNNEL_TYPE : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_TUNNEL_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    TUNNEL_ID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_TUNNEL_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    SRC_MACADDR : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_SRC_MACADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    DST_MACADDR : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_DST_MACADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    OVLAN_VID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_OVLAN_VID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    IVLAN_VID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_IVLAN_VID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    ETHERTYPE : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_ETHERTYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    SRC_IPADDR : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_SRC_IPADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    DST_IPADDR : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_DST_IPADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    IPADDR_TYPE : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_IPADDR_TYPE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    IP_PROTOCOL : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_IP_PROTOCOL)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    SRC_PORT : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_SRC_PORT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    DST_PORT : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_DST_PORT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    DST_ID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_DST_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    MIRROR_VNIC_ID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_MIRROR_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                    ENCAP_RECORD_ID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_ALLOC_INPUT_ENABLES_ENCAP_RECORD_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "     l2_filter_id = 0x%016"PRIX64"\n", data->l2_filter_id);
	RTE_LOG(INFO, PMD, "      tunnel_type = 0x%02"PRIX8"\n", data->tunnel_type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_NONTUNNEL ? "NONTUNNEL" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_VXLAN ? "VXLAN" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_NVGRE ? "NVGRE" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_L2GRE ? "L2GRE" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_IPIP ? "IPIP" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_GENEVE ? "GENEVE" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_MPLS ? "MPLS" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_STT ? "STT" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_IPGRE ? "IPGRE" :
		data->tunnel_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_TUNNEL_TYPE_ANYTUNNEL ? "ANYTUNNEL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        tunnel_id = 0x%08"PRIX32"\n", data->tunnel_id);
	RTE_LOG(INFO, PMD, "   src_macaddr[0] = 0x%02"PRIX8"\n", data->src_macaddr[0]);
	RTE_LOG(INFO, PMD, "   src_macaddr[1] = 0x%02"PRIX8"\n", data->src_macaddr[1]);
	RTE_LOG(INFO, PMD, "   src_macaddr[2] = 0x%02"PRIX8"\n", data->src_macaddr[2]);
	RTE_LOG(INFO, PMD, "   src_macaddr[3] = 0x%02"PRIX8"\n", data->src_macaddr[3]);
	RTE_LOG(INFO, PMD, "   src_macaddr[4] = 0x%02"PRIX8"\n", data->src_macaddr[4]);
	RTE_LOG(INFO, PMD, "   src_macaddr[5] = 0x%02"PRIX8"\n", data->src_macaddr[5]);
	RTE_LOG(INFO, PMD, "         unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "         unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "   dst_macaddr[0] = 0x%02"PRIX8"\n", data->dst_macaddr[0]);
	RTE_LOG(INFO, PMD, "   dst_macaddr[1] = 0x%02"PRIX8"\n", data->dst_macaddr[1]);
	RTE_LOG(INFO, PMD, "   dst_macaddr[2] = 0x%02"PRIX8"\n", data->dst_macaddr[2]);
	RTE_LOG(INFO, PMD, "   dst_macaddr[3] = 0x%02"PRIX8"\n", data->dst_macaddr[3]);
	RTE_LOG(INFO, PMD, "   dst_macaddr[4] = 0x%02"PRIX8"\n", data->dst_macaddr[4]);
	RTE_LOG(INFO, PMD, "   dst_macaddr[5] = 0x%02"PRIX8"\n", data->dst_macaddr[5]);
	RTE_LOG(INFO, PMD, "        ovlan_vid = 0x%04"PRIX16"\n", data->ovlan_vid);
	RTE_LOG(INFO, PMD, "        ivlan_vid = 0x%04"PRIX16"\n", data->ivlan_vid);
	RTE_LOG(INFO, PMD, "        ethertype = 0x%04"PRIX16"\n", data->ethertype);
	RTE_LOG(INFO, PMD, "     ip_addr_type = 0x%02"PRIX8"\n", data->ip_addr_type);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->ip_addr_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_IP_ADDR_TYPE_UNKNOWN ? "UNKNOWN" :
		data->ip_addr_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_IP_ADDR_TYPE_IPV4 ? "IPV4" :
		data->ip_addr_type == HWRM_CFA_EM_FLOW_ALLOC_INPUT_IP_ADDR_TYPE_IPV6 ? "IPV6" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      ip_protocol = 0x%02"PRIX8"\n", data->ip_protocol);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->ip_protocol == HWRM_CFA_EM_FLOW_ALLOC_INPUT_IP_PROTOCOL_UNKNOWN ? "UNKNOWN" :
		data->ip_protocol == HWRM_CFA_EM_FLOW_ALLOC_INPUT_IP_PROTOCOL_UDP ? "UDP" :
		data->ip_protocol == HWRM_CFA_EM_FLOW_ALLOC_INPUT_IP_PROTOCOL_TCP ? "TCP" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "         unused_5 = 0x%02"PRIX8"\n", data->unused_5);
	RTE_LOG(INFO, PMD, "    src_ipaddr[0] = 0x%08"PRIX32"\n", data->src_ipaddr[0]);
	RTE_LOG(INFO, PMD, "    src_ipaddr[1] = 0x%08"PRIX32"\n", data->src_ipaddr[1]);
	RTE_LOG(INFO, PMD, "    src_ipaddr[2] = 0x%08"PRIX32"\n", data->src_ipaddr[2]);
	RTE_LOG(INFO, PMD, "    src_ipaddr[3] = 0x%08"PRIX32"\n", data->src_ipaddr[3]);
	RTE_LOG(INFO, PMD, "    dst_ipaddr[0] = 0x%08"PRIX32"\n", data->dst_ipaddr[0]);
	RTE_LOG(INFO, PMD, "    dst_ipaddr[1] = 0x%08"PRIX32"\n", data->dst_ipaddr[1]);
	RTE_LOG(INFO, PMD, "    dst_ipaddr[2] = 0x%08"PRIX32"\n", data->dst_ipaddr[2]);
	RTE_LOG(INFO, PMD, "    dst_ipaddr[3] = 0x%08"PRIX32"\n", data->dst_ipaddr[3]);
	RTE_LOG(INFO, PMD, "         src_port = 0x%04"PRIX16"\n", data->src_port);
	RTE_LOG(INFO, PMD, "         dst_port = 0x%04"PRIX16"\n", data->dst_port);
	RTE_LOG(INFO, PMD, "           dst_id = 0x%04"PRIX16"\n", data->dst_id);
	RTE_LOG(INFO, PMD, "   mirror_vnic_id = 0x%04"PRIX16"\n", data->mirror_vnic_id);
	RTE_LOG(INFO, PMD, "  encap_record_id = 0x%08"PRIX32"\n", data->encap_record_id);
	RTE_LOG(INFO, PMD, "         unused_6 = 0x%08"PRIX32"\n", data->unused_6);
}

void decode_hwrm_cfa_em_flow_alloc_output(const char *string __rte_unused, struct hwrm_cfa_em_flow_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_em_flow_alloc_output\n");
	RTE_LOG(INFO, PMD, "    error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  em_filter_id = 0x%016"PRIX64"\n", data->em_filter_id);
	RTE_LOG(INFO, PMD, "       flow_id = 0x%08"PRIX32"\n", data->flow_id);
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "      unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "         valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_em_flow_free_input(const char *string __rte_unused, struct hwrm_cfa_em_flow_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_em_flow_free_input\n");
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "     cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "     resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  em_filter_id = 0x%016"PRIX64"\n", data->em_filter_id);
}

void decode_hwrm_cfa_em_flow_free_output(const char *string __rte_unused, struct hwrm_cfa_em_flow_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_em_flow_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_cfa_em_flow_cfg_input(const char *string __rte_unused, struct hwrm_cfa_em_flow_cfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_em_flow_cfg_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "             enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                       NEW_DST_ID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_CFG_INPUT_ENABLES_NEW_DST_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       NEW_MIRROR_VNIC_ID : %s\n", (data->enables & HWRM_CFA_EM_FLOW_CFG_INPUT_ENABLES_NEW_MIRROR_VNIC_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "            unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        em_filter_id = 0x%016"PRIX64"\n", data->em_filter_id);
	RTE_LOG(INFO, PMD, "          new_dst_id = 0x%08"PRIX32"\n", data->new_dst_id);
	RTE_LOG(INFO, PMD, "  new_mirror_vnic_id = 0x%08"PRIX32"\n", data->new_mirror_vnic_id);
}

void decode_hwrm_cfa_em_flow_cfg_output(const char *string __rte_unused, struct hwrm_cfa_em_flow_cfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_cfa_em_flow_cfg_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_tunnel_dst_port_query_input(const char *string __rte_unused, struct hwrm_tunnel_dst_port_query_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_tunnel_dst_port_query_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  tunnel_type = 0x%02"PRIX8"\n", data->tunnel_type);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->tunnel_type == HWRM_TUNNEL_DST_PORT_QUERY_INPUT_TUNNEL_TYPE_VXLAN ? "VXLAN" :
		data->tunnel_type == HWRM_TUNNEL_DST_PORT_QUERY_INPUT_TUNNEL_TYPE_GENEVE ? "GENEVE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "  unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "  unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "  unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "  unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_hwrm_tunnel_dst_port_query_output(const char *string __rte_unused, struct hwrm_tunnel_dst_port_query_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_tunnel_dst_port_query_output\n");
	RTE_LOG(INFO, PMD, "           error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "             req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "               seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "   tunnel_dst_port_id = 0x%04"PRIX16"\n", data->tunnel_dst_port_id);
	RTE_LOG(INFO, PMD, "  tunnel_dst_port_val = 0x%04"PRIX16"\n", data->tunnel_dst_port_val);
	RTE_LOG(INFO, PMD, "             unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "             unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "             unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "                valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_tunnel_dst_port_alloc_input(const char *string __rte_unused, struct hwrm_tunnel_dst_port_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_tunnel_dst_port_alloc_input\n");
	RTE_LOG(INFO, PMD, "             req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "            cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "               seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "            target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "            resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          tunnel_type = 0x%02"PRIX8"\n", data->tunnel_type);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->tunnel_type == HWRM_TUNNEL_DST_PORT_ALLOC_INPUT_TUNNEL_TYPE_VXLAN ? "VXLAN" :
		data->tunnel_type == HWRM_TUNNEL_DST_PORT_ALLOC_INPUT_TUNNEL_TYPE_GENEVE ? "GENEVE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  tunnel_dst_port_val = 0x%04"PRIX16"\n", data->tunnel_dst_port_val);
	RTE_LOG(INFO, PMD, "             unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_tunnel_dst_port_alloc_output(const char *string __rte_unused, struct hwrm_tunnel_dst_port_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_tunnel_dst_port_alloc_output\n");
	RTE_LOG(INFO, PMD, "          error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "            resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  tunnel_dst_port_id = 0x%04"PRIX16"\n", data->tunnel_dst_port_id);
	RTE_LOG(INFO, PMD, "            unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "            unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "            unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "            unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "            unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "               valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_tunnel_dst_port_free_input(const char *string __rte_unused, struct hwrm_tunnel_dst_port_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_tunnel_dst_port_free_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "         tunnel_type = 0x%02"PRIX8"\n", data->tunnel_type);
	RTE_LOG(INFO, PMD, "                       Value : %s\n",
		data->tunnel_type == HWRM_TUNNEL_DST_PORT_FREE_INPUT_TUNNEL_TYPE_VXLAN ? "VXLAN" :
		data->tunnel_type == HWRM_TUNNEL_DST_PORT_FREE_INPUT_TUNNEL_TYPE_GENEVE ? "GENEVE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  tunnel_dst_port_id = 0x%04"PRIX16"\n", data->tunnel_dst_port_id);
	RTE_LOG(INFO, PMD, "            unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_tunnel_dst_port_free_output(const char *string __rte_unused, struct hwrm_tunnel_dst_port_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_tunnel_dst_port_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_stat_ctx_alloc_input(const char *string __rte_unused, struct hwrm_stat_ctx_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_alloc_input\n");
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    stats_dma_addr = 0x%016"PRIX64"\n", data->stats_dma_addr);
	RTE_LOG(INFO, PMD, "  update_period_ms = 0x%08"PRIX32"\n", data->update_period_ms);
	RTE_LOG(INFO, PMD, "    stat_ctx_flags = 0x%02"PRIX8"\n", data->stat_ctx_flags);
	RTE_LOG(INFO, PMD, "                     ROCE : %s\n", (data->stat_ctx_flags & HWRM_STAT_CTX_ALLOC_INPUT_STAT_CTX_FLAGS_ROCE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "       unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "       unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "       unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
}

void decode_hwrm_stat_ctx_alloc_output(const char *string __rte_unused, struct hwrm_stat_ctx_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_alloc_output\n");
	RTE_LOG(INFO, PMD, "   error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  stat_ctx_id = 0x%08"PRIX32"\n", data->stat_ctx_id);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "     unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_stat_ctx_free_input(const char *string __rte_unused, struct hwrm_stat_ctx_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_free_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  stat_ctx_id = 0x%08"PRIX32"\n", data->stat_ctx_id);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_stat_ctx_free_output(const char *string __rte_unused, struct hwrm_stat_ctx_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_free_output\n");
	RTE_LOG(INFO, PMD, "   error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  stat_ctx_id = 0x%08"PRIX32"\n", data->stat_ctx_id);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "     unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_stat_ctx_query_input(const char *string __rte_unused, struct hwrm_stat_ctx_query_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_query_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  stat_ctx_id = 0x%08"PRIX32"\n", data->stat_ctx_id);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_stat_ctx_query_output(const char *string __rte_unused, struct hwrm_stat_ctx_query_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_query_output\n");
	RTE_LOG(INFO, PMD, "      error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "   tx_ucast_pkts = 0x%016"PRIX64"\n", data->tx_ucast_pkts);
	RTE_LOG(INFO, PMD, "   tx_mcast_pkts = 0x%016"PRIX64"\n", data->tx_mcast_pkts);
	RTE_LOG(INFO, PMD, "   tx_bcast_pkts = 0x%016"PRIX64"\n", data->tx_bcast_pkts);
	RTE_LOG(INFO, PMD, "     tx_err_pkts = 0x%016"PRIX64"\n", data->tx_err_pkts);
	RTE_LOG(INFO, PMD, "    tx_drop_pkts = 0x%016"PRIX64"\n", data->tx_drop_pkts);
	RTE_LOG(INFO, PMD, "  tx_ucast_bytes = 0x%016"PRIX64"\n", data->tx_ucast_bytes);
	RTE_LOG(INFO, PMD, "  tx_mcast_bytes = 0x%016"PRIX64"\n", data->tx_mcast_bytes);
	RTE_LOG(INFO, PMD, "  tx_bcast_bytes = 0x%016"PRIX64"\n", data->tx_bcast_bytes);
	RTE_LOG(INFO, PMD, "   rx_ucast_pkts = 0x%016"PRIX64"\n", data->rx_ucast_pkts);
	RTE_LOG(INFO, PMD, "   rx_mcast_pkts = 0x%016"PRIX64"\n", data->rx_mcast_pkts);
	RTE_LOG(INFO, PMD, "   rx_bcast_pkts = 0x%016"PRIX64"\n", data->rx_bcast_pkts);
	RTE_LOG(INFO, PMD, "     rx_err_pkts = 0x%016"PRIX64"\n", data->rx_err_pkts);
	RTE_LOG(INFO, PMD, "    rx_drop_pkts = 0x%016"PRIX64"\n", data->rx_drop_pkts);
	RTE_LOG(INFO, PMD, "  rx_ucast_bytes = 0x%016"PRIX64"\n", data->rx_ucast_bytes);
	RTE_LOG(INFO, PMD, "  rx_mcast_bytes = 0x%016"PRIX64"\n", data->rx_mcast_bytes);
	RTE_LOG(INFO, PMD, "  rx_bcast_bytes = 0x%016"PRIX64"\n", data->rx_bcast_bytes);
	RTE_LOG(INFO, PMD, "     rx_agg_pkts = 0x%016"PRIX64"\n", data->rx_agg_pkts);
	RTE_LOG(INFO, PMD, "    rx_agg_bytes = 0x%016"PRIX64"\n", data->rx_agg_bytes);
	RTE_LOG(INFO, PMD, "   rx_agg_events = 0x%016"PRIX64"\n", data->rx_agg_events);
	RTE_LOG(INFO, PMD, "   rx_agg_aborts = 0x%016"PRIX64"\n", data->rx_agg_aborts);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "           valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_stat_ctx_clr_stats_input(const char *string __rte_unused, struct hwrm_stat_ctx_clr_stats_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_clr_stats_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  stat_ctx_id = 0x%08"PRIX32"\n", data->stat_ctx_id);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_stat_ctx_clr_stats_output(const char *string __rte_unused, struct hwrm_stat_ctx_clr_stats_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_stat_ctx_clr_stats_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_reset_input(const char *string __rte_unused, struct hwrm_fw_reset_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_reset_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  embedded_proc_type = 0x%02"PRIX8"\n", data->embedded_proc_type);
	RTE_LOG(INFO, PMD, "                       Value : %s\n",
		data->embedded_proc_type == HWRM_FW_RESET_INPUT_EMBEDDED_PROC_TYPE_BOOT ? "BOOT" :
		data->embedded_proc_type == HWRM_FW_RESET_INPUT_EMBEDDED_PROC_TYPE_MGMT ? "MGMT" :
		data->embedded_proc_type == HWRM_FW_RESET_INPUT_EMBEDDED_PROC_TYPE_NETCTRL ? "NETCTRL" :
		data->embedded_proc_type == HWRM_FW_RESET_INPUT_EMBEDDED_PROC_TYPE_ROCE ? "ROCE" :
		data->embedded_proc_type == HWRM_FW_RESET_INPUT_EMBEDDED_PROC_TYPE_RSVD ? "RSVD" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      selfrst_status = 0x%02"PRIX8"\n", data->selfrst_status);
	RTE_LOG(INFO, PMD, "                       Value : %s\n",
		data->selfrst_status == HWRM_FW_RESET_INPUT_SELFRST_STATUS_SELFRSTNONE ? "SELFRSTNONE" :
		data->selfrst_status == HWRM_FW_RESET_INPUT_SELFRST_STATUS_SELFRSTASAP ? "SELFRSTASAP" :
		data->selfrst_status == HWRM_FW_RESET_INPUT_SELFRST_STATUS_SELFRSTPCIERST ? "SELFRSTPCIERST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "         unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "         unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_fw_reset_output(const char *string __rte_unused, struct hwrm_fw_reset_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_reset_output\n");
	RTE_LOG(INFO, PMD, "      error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  selfrst_status = 0x%02"PRIX8"\n", data->selfrst_status);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->selfrst_status == HWRM_FW_RESET_OUTPUT_SELFRST_STATUS_SELFRSTNONE ? "SELFRSTNONE" :
		data->selfrst_status == HWRM_FW_RESET_OUTPUT_SELFRST_STATUS_SELFRSTASAP ? "SELFRSTASAP" :
		data->selfrst_status == HWRM_FW_RESET_OUTPUT_SELFRST_STATUS_SELFRSTPCIERST ? "SELFRSTPCIERST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "        unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "           valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_qstatus_input(const char *string __rte_unused, struct hwrm_fw_qstatus_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_qstatus_input\n");
	RTE_LOG(INFO, PMD, "            req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "              seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "           resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  embedded_proc_type = 0x%02"PRIX8"\n", data->embedded_proc_type);
	RTE_LOG(INFO, PMD, "                       Value : %s\n",
		data->embedded_proc_type == HWRM_FW_QSTATUS_INPUT_EMBEDDED_PROC_TYPE_BOOT ? "BOOT" :
		data->embedded_proc_type == HWRM_FW_QSTATUS_INPUT_EMBEDDED_PROC_TYPE_MGMT ? "MGMT" :
		data->embedded_proc_type == HWRM_FW_QSTATUS_INPUT_EMBEDDED_PROC_TYPE_NETCTRL ? "NETCTRL" :
		data->embedded_proc_type == HWRM_FW_QSTATUS_INPUT_EMBEDDED_PROC_TYPE_ROCE ? "ROCE" :
		data->embedded_proc_type == HWRM_FW_QSTATUS_INPUT_EMBEDDED_PROC_TYPE_RSVD ? "RSVD" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "         unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "         unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "         unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "         unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "         unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "         unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_hwrm_fw_qstatus_output(const char *string __rte_unused, struct hwrm_fw_qstatus_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_qstatus_output\n");
	RTE_LOG(INFO, PMD, "      error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  selfrst_status = 0x%02"PRIX8"\n", data->selfrst_status);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->selfrst_status == HWRM_FW_QSTATUS_OUTPUT_SELFRST_STATUS_SELFRSTNONE ? "SELFRSTNONE" :
		data->selfrst_status == HWRM_FW_QSTATUS_OUTPUT_SELFRST_STATUS_SELFRSTASAP ? "SELFRSTASAP" :
		data->selfrst_status == HWRM_FW_QSTATUS_OUTPUT_SELFRST_STATUS_SELFRSTPCIERST ? "SELFRSTPCIERST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "        unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "           valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_set_time_input(const char *string __rte_unused, struct hwrm_fw_set_time_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_set_time_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "         year = 0x%04"PRIX16"\n", data->year);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->year == HWRM_FW_SET_TIME_INPUT_YEAR_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        month = 0x%02"PRIX8"\n", data->month);
	RTE_LOG(INFO, PMD, "          day = 0x%02"PRIX8"\n", data->day);
	RTE_LOG(INFO, PMD, "         hour = 0x%02"PRIX8"\n", data->hour);
	RTE_LOG(INFO, PMD, "       minute = 0x%02"PRIX8"\n", data->minute);
	RTE_LOG(INFO, PMD, "       second = 0x%02"PRIX8"\n", data->second);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  millisecond = 0x%04"PRIX16"\n", data->millisecond);
	RTE_LOG(INFO, PMD, "         zone = 0x%04"PRIX16"\n", data->zone);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->zone == HWRM_FW_SET_TIME_INPUT_ZONE_UTC ? "UTC" :
		data->zone == HWRM_FW_SET_TIME_INPUT_ZONE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_fw_set_time_output(const char *string __rte_unused, struct hwrm_fw_set_time_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_set_time_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_get_time_input(const char *string __rte_unused, struct hwrm_fw_get_time_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_get_time_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_hwrm_fw_get_time_output(const char *string __rte_unused, struct hwrm_fw_get_time_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_get_time_output\n");
	RTE_LOG(INFO, PMD, "   error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "         year = 0x%04"PRIX16"\n", data->year);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->year == HWRM_FW_GET_TIME_OUTPUT_YEAR_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        month = 0x%02"PRIX8"\n", data->month);
	RTE_LOG(INFO, PMD, "          day = 0x%02"PRIX8"\n", data->day);
	RTE_LOG(INFO, PMD, "         hour = 0x%02"PRIX8"\n", data->hour);
	RTE_LOG(INFO, PMD, "       minute = 0x%02"PRIX8"\n", data->minute);
	RTE_LOG(INFO, PMD, "       second = 0x%02"PRIX8"\n", data->second);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  millisecond = 0x%04"PRIX16"\n", data->millisecond);
	RTE_LOG(INFO, PMD, "         zone = 0x%04"PRIX16"\n", data->zone);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->zone == HWRM_FW_GET_TIME_OUTPUT_ZONE_UTC ? "UTC" :
		data->zone == HWRM_FW_GET_TIME_OUTPUT_ZONE_UNKNOWN ? "UNKNOWN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "     unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "     unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "        valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_set_structured_data_input(const char *string __rte_unused, struct hwrm_fw_set_structured_data_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_set_structured_data_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  src_data_addr = 0x%016"PRIX64"\n", data->src_data_addr);
	RTE_LOG(INFO, PMD, "       data_len = 0x%04"PRIX16"\n", data->data_len);
	RTE_LOG(INFO, PMD, "        hdr_cnt = 0x%02"PRIX8"\n", data->hdr_cnt);
	RTE_LOG(INFO, PMD, "    unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "    unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "    unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "    unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "    unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
}

void decode_hwrm_fw_set_structured_data_output(const char *string __rte_unused, struct hwrm_fw_set_structured_data_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_set_structured_data_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_set_structured_data_cmd_err(const char *string __rte_unused, struct hwrm_fw_set_structured_data_cmd_err *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_set_structured_data_cmd_err\n");
	RTE_LOG(INFO, PMD, "         code = 0x%02"PRIX8"\n", data->code);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->code == HWRM_FW_SET_STRUCTURED_DATA_CMD_ERR_CODE_UNKNOWN ? "UNKNOWN" :
		data->code == HWRM_FW_SET_STRUCTURED_DATA_CMD_ERR_CODE_BAD_HDR_CNT ? "BAD_HDR_CNT" :
		data->code == HWRM_FW_SET_STRUCTURED_DATA_CMD_ERR_CODE_BAD_FMT ? "BAD_FMT" :
		data->code == HWRM_FW_SET_STRUCTURED_DATA_CMD_ERR_CODE_BAD_ID ? "BAD_ID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "  unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "  unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "  unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "  unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_hwrm_fw_get_structured_data_input(const char *string __rte_unused, struct hwrm_fw_get_structured_data_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_get_structured_data_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  dest_data_addr = 0x%016"PRIX64"\n", data->dest_data_addr);
	RTE_LOG(INFO, PMD, "        data_len = 0x%04"PRIX16"\n", data->data_len);
	RTE_LOG(INFO, PMD, "    structure_id = 0x%04"PRIX16"\n", data->structure_id);
	RTE_LOG(INFO, PMD, "         subtype = 0x%04"PRIX16"\n", data->subtype);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_ALL ? "ALL" :
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_NEAR_BRIDGE_ADMIN ? "NEAR_BRIDGE_ADMIN" :
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_NEAR_BRIDGE_PEER ? "NEAR_BRIDGE_PEER" :
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_NEAR_BRIDGE_OPERATIONAL ? "NEAR_BRIDGE_OPERATIONAL" :
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_NON_TPMR_ADMIN ? "NON_TPMR_ADMIN" :
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_NON_TPMR_PEER ? "NON_TPMR_PEER" :
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_NON_TPMR_OPERATIONAL ? "NON_TPMR_OPERATIONAL" :
		data->subtype == HWRM_FW_GET_STRUCTURED_DATA_INPUT_SUBTYPE_HOST_OPERATIONAL ? "HOST_OPERATIONAL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           count = 0x%02"PRIX8"\n", data->count);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
}

void decode_hwrm_fw_get_structured_data_output(const char *string __rte_unused, struct hwrm_fw_get_structured_data_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_get_structured_data_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "     hdr_cnt = 0x%02"PRIX8"\n", data->hdr_cnt);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "    unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_get_structured_data_cmd_err(const char *string __rte_unused, struct hwrm_fw_get_structured_data_cmd_err *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_get_structured_data_cmd_err\n");
	RTE_LOG(INFO, PMD, "         code = 0x%02"PRIX8"\n", data->code);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->code == HWRM_FW_GET_STRUCTURED_DATA_CMD_ERR_CODE_UNKNOWN ? "UNKNOWN" :
		data->code == HWRM_FW_GET_STRUCTURED_DATA_CMD_ERR_CODE_BAD_ID ? "BAD_ID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "  unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "  unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "  unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "  unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_hwrm_fw_ipc_mailbox_input(const char *string __rte_unused, struct hwrm_fw_ipc_mailbox_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_ipc_mailbox_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "        flags = 0x%02"PRIX8"\n", data->flags);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     event_id = 0x%02"PRIX8"\n", data->event_id);
	RTE_LOG(INFO, PMD, "      port_id = 0x%02"PRIX8"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  event_data1 = 0x%08"PRIX32"\n", data->event_data1);
	RTE_LOG(INFO, PMD, "  event_data2 = 0x%08"PRIX32"\n", data->event_data2);
	RTE_LOG(INFO, PMD, "     unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_fw_ipc_mailbox_output(const char *string __rte_unused, struct hwrm_fw_ipc_mailbox_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_ipc_mailbox_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fw_ipc_mailbox_cmd_err(const char *string __rte_unused, struct hwrm_fw_ipc_mailbox_cmd_err *data) {
	RTE_LOG(INFO, PMD, "hwrm_fw_ipc_mailbox_cmd_err\n");
	RTE_LOG(INFO, PMD, "         code = 0x%02"PRIX8"\n", data->code);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->code == HWRM_FW_IPC_MAILBOX_CMD_ERR_CODE_UNKNOWN ? "UNKNOWN" :
		data->code == HWRM_FW_IPC_MAILBOX_CMD_ERR_CODE_BAD_ID ? "BAD_ID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "  unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "  unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "  unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "  unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_hwrm_exec_fwd_resp_input(const char *string __rte_unused, struct hwrm_exec_fwd_resp_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_exec_fwd_resp_input\n");
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "             resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      encap_request[0] = 0x%08"PRIX32"\n", data->encap_request[0]);
	RTE_LOG(INFO, PMD, "      encap_request[1] = 0x%08"PRIX32"\n", data->encap_request[1]);
	RTE_LOG(INFO, PMD, "      encap_request[2] = 0x%08"PRIX32"\n", data->encap_request[2]);
	RTE_LOG(INFO, PMD, "      encap_request[3] = 0x%08"PRIX32"\n", data->encap_request[3]);
	RTE_LOG(INFO, PMD, "      encap_request[4] = 0x%08"PRIX32"\n", data->encap_request[4]);
	RTE_LOG(INFO, PMD, "      encap_request[5] = 0x%08"PRIX32"\n", data->encap_request[5]);
	RTE_LOG(INFO, PMD, "      encap_request[6] = 0x%08"PRIX32"\n", data->encap_request[6]);
	RTE_LOG(INFO, PMD, "      encap_request[7] = 0x%08"PRIX32"\n", data->encap_request[7]);
	RTE_LOG(INFO, PMD, "      encap_request[8] = 0x%08"PRIX32"\n", data->encap_request[8]);
	RTE_LOG(INFO, PMD, "      encap_request[9] = 0x%08"PRIX32"\n", data->encap_request[9]);
	RTE_LOG(INFO, PMD, "     encap_request[10] = 0x%08"PRIX32"\n", data->encap_request[10]);
	RTE_LOG(INFO, PMD, "     encap_request[11] = 0x%08"PRIX32"\n", data->encap_request[11]);
	RTE_LOG(INFO, PMD, "     encap_request[12] = 0x%08"PRIX32"\n", data->encap_request[12]);
	RTE_LOG(INFO, PMD, "     encap_request[13] = 0x%08"PRIX32"\n", data->encap_request[13]);
	RTE_LOG(INFO, PMD, "     encap_request[14] = 0x%08"PRIX32"\n", data->encap_request[14]);
	RTE_LOG(INFO, PMD, "     encap_request[15] = 0x%08"PRIX32"\n", data->encap_request[15]);
	RTE_LOG(INFO, PMD, "     encap_request[16] = 0x%08"PRIX32"\n", data->encap_request[16]);
	RTE_LOG(INFO, PMD, "     encap_request[17] = 0x%08"PRIX32"\n", data->encap_request[17]);
	RTE_LOG(INFO, PMD, "     encap_request[18] = 0x%08"PRIX32"\n", data->encap_request[18]);
	RTE_LOG(INFO, PMD, "     encap_request[19] = 0x%08"PRIX32"\n", data->encap_request[19]);
	RTE_LOG(INFO, PMD, "     encap_request[20] = 0x%08"PRIX32"\n", data->encap_request[20]);
	RTE_LOG(INFO, PMD, "     encap_request[21] = 0x%08"PRIX32"\n", data->encap_request[21]);
	RTE_LOG(INFO, PMD, "     encap_request[22] = 0x%08"PRIX32"\n", data->encap_request[22]);
	RTE_LOG(INFO, PMD, "     encap_request[23] = 0x%08"PRIX32"\n", data->encap_request[23]);
	RTE_LOG(INFO, PMD, "     encap_request[24] = 0x%08"PRIX32"\n", data->encap_request[24]);
	RTE_LOG(INFO, PMD, "     encap_request[25] = 0x%08"PRIX32"\n", data->encap_request[25]);
	RTE_LOG(INFO, PMD, "  encap_resp_target_id = 0x%04"PRIX16"\n", data->encap_resp_target_id);
	RTE_LOG(INFO, PMD, "           unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "           unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "           unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_exec_fwd_resp_output(const char *string __rte_unused, struct hwrm_exec_fwd_resp_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_exec_fwd_resp_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_reject_fwd_resp_input(const char *string __rte_unused, struct hwrm_reject_fwd_resp_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_reject_fwd_resp_input\n");
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "             resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      encap_request[0] = 0x%08"PRIX32"\n", data->encap_request[0]);
	RTE_LOG(INFO, PMD, "      encap_request[1] = 0x%08"PRIX32"\n", data->encap_request[1]);
	RTE_LOG(INFO, PMD, "      encap_request[2] = 0x%08"PRIX32"\n", data->encap_request[2]);
	RTE_LOG(INFO, PMD, "      encap_request[3] = 0x%08"PRIX32"\n", data->encap_request[3]);
	RTE_LOG(INFO, PMD, "      encap_request[4] = 0x%08"PRIX32"\n", data->encap_request[4]);
	RTE_LOG(INFO, PMD, "      encap_request[5] = 0x%08"PRIX32"\n", data->encap_request[5]);
	RTE_LOG(INFO, PMD, "      encap_request[6] = 0x%08"PRIX32"\n", data->encap_request[6]);
	RTE_LOG(INFO, PMD, "      encap_request[7] = 0x%08"PRIX32"\n", data->encap_request[7]);
	RTE_LOG(INFO, PMD, "      encap_request[8] = 0x%08"PRIX32"\n", data->encap_request[8]);
	RTE_LOG(INFO, PMD, "      encap_request[9] = 0x%08"PRIX32"\n", data->encap_request[9]);
	RTE_LOG(INFO, PMD, "     encap_request[10] = 0x%08"PRIX32"\n", data->encap_request[10]);
	RTE_LOG(INFO, PMD, "     encap_request[11] = 0x%08"PRIX32"\n", data->encap_request[11]);
	RTE_LOG(INFO, PMD, "     encap_request[12] = 0x%08"PRIX32"\n", data->encap_request[12]);
	RTE_LOG(INFO, PMD, "     encap_request[13] = 0x%08"PRIX32"\n", data->encap_request[13]);
	RTE_LOG(INFO, PMD, "     encap_request[14] = 0x%08"PRIX32"\n", data->encap_request[14]);
	RTE_LOG(INFO, PMD, "     encap_request[15] = 0x%08"PRIX32"\n", data->encap_request[15]);
	RTE_LOG(INFO, PMD, "     encap_request[16] = 0x%08"PRIX32"\n", data->encap_request[16]);
	RTE_LOG(INFO, PMD, "     encap_request[17] = 0x%08"PRIX32"\n", data->encap_request[17]);
	RTE_LOG(INFO, PMD, "     encap_request[18] = 0x%08"PRIX32"\n", data->encap_request[18]);
	RTE_LOG(INFO, PMD, "     encap_request[19] = 0x%08"PRIX32"\n", data->encap_request[19]);
	RTE_LOG(INFO, PMD, "     encap_request[20] = 0x%08"PRIX32"\n", data->encap_request[20]);
	RTE_LOG(INFO, PMD, "     encap_request[21] = 0x%08"PRIX32"\n", data->encap_request[21]);
	RTE_LOG(INFO, PMD, "     encap_request[22] = 0x%08"PRIX32"\n", data->encap_request[22]);
	RTE_LOG(INFO, PMD, "     encap_request[23] = 0x%08"PRIX32"\n", data->encap_request[23]);
	RTE_LOG(INFO, PMD, "     encap_request[24] = 0x%08"PRIX32"\n", data->encap_request[24]);
	RTE_LOG(INFO, PMD, "     encap_request[25] = 0x%08"PRIX32"\n", data->encap_request[25]);
	RTE_LOG(INFO, PMD, "  encap_resp_target_id = 0x%04"PRIX16"\n", data->encap_resp_target_id);
	RTE_LOG(INFO, PMD, "           unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "           unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "           unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_reject_fwd_resp_output(const char *string __rte_unused, struct hwrm_reject_fwd_resp_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_reject_fwd_resp_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fwd_resp_input(const char *string __rte_unused, struct hwrm_fwd_resp_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fwd_resp_input\n");
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "             resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  encap_resp_target_id = 0x%04"PRIX16"\n", data->encap_resp_target_id);
	RTE_LOG(INFO, PMD, "  encap_resp_cmpl_ring = 0x%04"PRIX16"\n", data->encap_resp_cmpl_ring);
	RTE_LOG(INFO, PMD, "        encap_resp_len = 0x%04"PRIX16"\n", data->encap_resp_len);
	RTE_LOG(INFO, PMD, "              unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "              unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       encap_resp_addr = 0x%016"PRIX64"\n", data->encap_resp_addr);
	RTE_LOG(INFO, PMD, "         encap_resp[0] = 0x%08"PRIX32"\n", data->encap_resp[0]);
	RTE_LOG(INFO, PMD, "         encap_resp[1] = 0x%08"PRIX32"\n", data->encap_resp[1]);
	RTE_LOG(INFO, PMD, "         encap_resp[2] = 0x%08"PRIX32"\n", data->encap_resp[2]);
	RTE_LOG(INFO, PMD, "         encap_resp[3] = 0x%08"PRIX32"\n", data->encap_resp[3]);
	RTE_LOG(INFO, PMD, "         encap_resp[4] = 0x%08"PRIX32"\n", data->encap_resp[4]);
	RTE_LOG(INFO, PMD, "         encap_resp[5] = 0x%08"PRIX32"\n", data->encap_resp[5]);
	RTE_LOG(INFO, PMD, "         encap_resp[6] = 0x%08"PRIX32"\n", data->encap_resp[6]);
	RTE_LOG(INFO, PMD, "         encap_resp[7] = 0x%08"PRIX32"\n", data->encap_resp[7]);
	RTE_LOG(INFO, PMD, "         encap_resp[8] = 0x%08"PRIX32"\n", data->encap_resp[8]);
	RTE_LOG(INFO, PMD, "         encap_resp[9] = 0x%08"PRIX32"\n", data->encap_resp[9]);
	RTE_LOG(INFO, PMD, "        encap_resp[10] = 0x%08"PRIX32"\n", data->encap_resp[10]);
	RTE_LOG(INFO, PMD, "        encap_resp[11] = 0x%08"PRIX32"\n", data->encap_resp[11]);
	RTE_LOG(INFO, PMD, "        encap_resp[12] = 0x%08"PRIX32"\n", data->encap_resp[12]);
	RTE_LOG(INFO, PMD, "        encap_resp[13] = 0x%08"PRIX32"\n", data->encap_resp[13]);
	RTE_LOG(INFO, PMD, "        encap_resp[14] = 0x%08"PRIX32"\n", data->encap_resp[14]);
	RTE_LOG(INFO, PMD, "        encap_resp[15] = 0x%08"PRIX32"\n", data->encap_resp[15]);
	RTE_LOG(INFO, PMD, "        encap_resp[16] = 0x%08"PRIX32"\n", data->encap_resp[16]);
	RTE_LOG(INFO, PMD, "        encap_resp[17] = 0x%08"PRIX32"\n", data->encap_resp[17]);
	RTE_LOG(INFO, PMD, "        encap_resp[18] = 0x%08"PRIX32"\n", data->encap_resp[18]);
	RTE_LOG(INFO, PMD, "        encap_resp[19] = 0x%08"PRIX32"\n", data->encap_resp[19]);
	RTE_LOG(INFO, PMD, "        encap_resp[20] = 0x%08"PRIX32"\n", data->encap_resp[20]);
	RTE_LOG(INFO, PMD, "        encap_resp[21] = 0x%08"PRIX32"\n", data->encap_resp[21]);
	RTE_LOG(INFO, PMD, "        encap_resp[22] = 0x%08"PRIX32"\n", data->encap_resp[22]);
	RTE_LOG(INFO, PMD, "        encap_resp[23] = 0x%08"PRIX32"\n", data->encap_resp[23]);
}

void decode_hwrm_fwd_resp_output(const char *string __rte_unused, struct hwrm_fwd_resp_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fwd_resp_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_fwd_async_event_cmpl_input(const char *string __rte_unused, struct hwrm_fwd_async_event_cmpl_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_fwd_async_event_cmpl_input\n");
	RTE_LOG(INFO, PMD, "                     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "                    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "                    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "                    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  encap_async_event_target_id = 0x%04"PRIX16"\n", data->encap_async_event_target_id);
	RTE_LOG(INFO, PMD, "                     unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "                     unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "                  unused_2[0] = 0x%02"PRIX8"\n", data->unused_2[0]);
	RTE_LOG(INFO, PMD, "                  unused_2[1] = 0x%02"PRIX8"\n", data->unused_2[1]);
	RTE_LOG(INFO, PMD, "                  unused_2[2] = 0x%02"PRIX8"\n", data->unused_2[2]);
	RTE_LOG(INFO, PMD, "                     unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "    encap_async_event_cmpl[0] = 0x%08"PRIX32"\n", data->encap_async_event_cmpl[0]);
	RTE_LOG(INFO, PMD, "    encap_async_event_cmpl[1] = 0x%08"PRIX32"\n", data->encap_async_event_cmpl[1]);
	RTE_LOG(INFO, PMD, "    encap_async_event_cmpl[2] = 0x%08"PRIX32"\n", data->encap_async_event_cmpl[2]);
	RTE_LOG(INFO, PMD, "    encap_async_event_cmpl[3] = 0x%08"PRIX32"\n", data->encap_async_event_cmpl[3]);
}

void decode_hwrm_fwd_async_event_cmpl_output(const char *string __rte_unused, struct hwrm_fwd_async_event_cmpl_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_fwd_async_event_cmpl_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_temp_monitor_query_input(const char *string __rte_unused, struct hwrm_temp_monitor_query_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_temp_monitor_query_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_hwrm_temp_monitor_query_output(const char *string __rte_unused, struct hwrm_temp_monitor_query_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_temp_monitor_query_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "        temp = 0x%02"PRIX8"\n", data->temp);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "    unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_wol_filter_alloc_input(const char *string __rte_unused, struct hwrm_wol_filter_alloc_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_filter_alloc_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "              flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "            enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                      MAC_ADDRESS : %s\n", (data->enables & HWRM_WOL_FILTER_ALLOC_INPUT_ENABLES_MAC_ADDRESS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PATTERN_OFFSET : %s\n", (data->enables & HWRM_WOL_FILTER_ALLOC_INPUT_ENABLES_PATTERN_OFFSET)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PATTERN_BUF_SIZE : %s\n", (data->enables & HWRM_WOL_FILTER_ALLOC_INPUT_ENABLES_PATTERN_BUF_SIZE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PATTERN_BUF_ADDR : %s\n", (data->enables & HWRM_WOL_FILTER_ALLOC_INPUT_ENABLES_PATTERN_BUF_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PATTERN_MASK_ADDR : %s\n", (data->enables & HWRM_WOL_FILTER_ALLOC_INPUT_ENABLES_PATTERN_MASK_ADDR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      PATTERN_MASK_SIZE : %s\n", (data->enables & HWRM_WOL_FILTER_ALLOC_INPUT_ENABLES_PATTERN_MASK_SIZE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "            port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "           wol_type = 0x%02"PRIX8"\n", data->wol_type);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->wol_type == HWRM_WOL_FILTER_ALLOC_INPUT_WOL_TYPE_MAGICPKT ? "MAGICPKT" :
		data->wol_type == HWRM_WOL_FILTER_ALLOC_INPUT_WOL_TYPE_BMP ? "BMP" :
		data->wol_type == HWRM_WOL_FILTER_ALLOC_INPUT_WOL_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%08"PRIX32"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "     mac_address[0] = 0x%02"PRIX8"\n", data->mac_address[0]);
	RTE_LOG(INFO, PMD, "     mac_address[1] = 0x%02"PRIX8"\n", data->mac_address[1]);
	RTE_LOG(INFO, PMD, "     mac_address[2] = 0x%02"PRIX8"\n", data->mac_address[2]);
	RTE_LOG(INFO, PMD, "     mac_address[3] = 0x%02"PRIX8"\n", data->mac_address[3]);
	RTE_LOG(INFO, PMD, "     mac_address[4] = 0x%02"PRIX8"\n", data->mac_address[4]);
	RTE_LOG(INFO, PMD, "     mac_address[5] = 0x%02"PRIX8"\n", data->mac_address[5]);
	RTE_LOG(INFO, PMD, "     pattern_offset = 0x%04"PRIX16"\n", data->pattern_offset);
	RTE_LOG(INFO, PMD, "   pattern_buf_size = 0x%04"PRIX16"\n", data->pattern_buf_size);
	RTE_LOG(INFO, PMD, "  pattern_mask_size = 0x%04"PRIX16"\n", data->pattern_mask_size);
	RTE_LOG(INFO, PMD, "           unused_2 = 0x%08"PRIX32"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "   pattern_buf_addr = 0x%016"PRIX64"\n", data->pattern_buf_addr);
	RTE_LOG(INFO, PMD, "  pattern_mask_addr = 0x%016"PRIX64"\n", data->pattern_mask_addr);
}

void decode_hwrm_wol_filter_alloc_output(const char *string __rte_unused, struct hwrm_wol_filter_alloc_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_filter_alloc_output\n");
	RTE_LOG(INFO, PMD, "     error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  wol_filter_id = 0x%02"PRIX8"\n", data->wol_filter_id);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "          valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_wol_filter_free_input(const char *string __rte_unused, struct hwrm_wol_filter_free_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_filter_free_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          flags = 0x%08"PRIX32"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  FREE_ALL_WOL_FILTERS : %s\n", (data->flags & HWRM_WOL_FILTER_FREE_INPUT_FLAGS_FREE_ALL_WOL_FILTERS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                  WOL_FILTER_ID : %s\n", (data->enables & HWRM_WOL_FILTER_FREE_INPUT_ENABLES_WOL_FILTER_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "        port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  wol_filter_id = 0x%02"PRIX8"\n", data->wol_filter_id);
	RTE_LOG(INFO, PMD, "    unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "    unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "    unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "    unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "    unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
}

void decode_hwrm_wol_filter_free_output(const char *string __rte_unused, struct hwrm_wol_filter_free_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_filter_free_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_wol_filter_qcfg_input(const char *string __rte_unused, struct hwrm_wol_filter_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_filter_qcfg_input\n");
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "          cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "          target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "            port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "             handle = 0x%04"PRIX16"\n", data->handle);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "   pattern_buf_addr = 0x%016"PRIX64"\n", data->pattern_buf_addr);
	RTE_LOG(INFO, PMD, "   pattern_buf_size = 0x%04"PRIX16"\n", data->pattern_buf_size);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "        unused_3[0] = 0x%02"PRIX8"\n", data->unused_3[0]);
	RTE_LOG(INFO, PMD, "        unused_3[1] = 0x%02"PRIX8"\n", data->unused_3[1]);
	RTE_LOG(INFO, PMD, "        unused_3[2] = 0x%02"PRIX8"\n", data->unused_3[2]);
	RTE_LOG(INFO, PMD, "           unused_4 = 0x%02"PRIX8"\n", data->unused_4);
	RTE_LOG(INFO, PMD, "  pattern_mask_addr = 0x%016"PRIX64"\n", data->pattern_mask_addr);
	RTE_LOG(INFO, PMD, "  pattern_mask_size = 0x%04"PRIX16"\n", data->pattern_mask_size);
	RTE_LOG(INFO, PMD, "        unused_5[0] = 0x%04"PRIX16"\n", data->unused_5[0]);
	RTE_LOG(INFO, PMD, "        unused_5[1] = 0x%04"PRIX16"\n", data->unused_5[1]);
	RTE_LOG(INFO, PMD, "        unused_5[2] = 0x%04"PRIX16"\n", data->unused_5[2]);
}

void decode_hwrm_wol_filter_qcfg_output(const char *string __rte_unused, struct hwrm_wol_filter_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_filter_qcfg_output\n");
	RTE_LOG(INFO, PMD, "         error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "           req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "           resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "        next_handle = 0x%04"PRIX16"\n", data->next_handle);
	RTE_LOG(INFO, PMD, "      wol_filter_id = 0x%02"PRIX8"\n", data->wol_filter_id);
	RTE_LOG(INFO, PMD, "           wol_type = 0x%02"PRIX8"\n", data->wol_type);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->wol_type == HWRM_WOL_FILTER_QCFG_OUTPUT_WOL_TYPE_MAGICPKT ? "MAGICPKT" :
		data->wol_type == HWRM_WOL_FILTER_QCFG_OUTPUT_WOL_TYPE_BMP ? "BMP" :
		data->wol_type == HWRM_WOL_FILTER_QCFG_OUTPUT_WOL_TYPE_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "     mac_address[0] = 0x%02"PRIX8"\n", data->mac_address[0]);
	RTE_LOG(INFO, PMD, "     mac_address[1] = 0x%02"PRIX8"\n", data->mac_address[1]);
	RTE_LOG(INFO, PMD, "     mac_address[2] = 0x%02"PRIX8"\n", data->mac_address[2]);
	RTE_LOG(INFO, PMD, "     mac_address[3] = 0x%02"PRIX8"\n", data->mac_address[3]);
	RTE_LOG(INFO, PMD, "     mac_address[4] = 0x%02"PRIX8"\n", data->mac_address[4]);
	RTE_LOG(INFO, PMD, "     mac_address[5] = 0x%02"PRIX8"\n", data->mac_address[5]);
	RTE_LOG(INFO, PMD, "     pattern_offset = 0x%04"PRIX16"\n", data->pattern_offset);
	RTE_LOG(INFO, PMD, "       pattern_size = 0x%04"PRIX16"\n", data->pattern_size);
	RTE_LOG(INFO, PMD, "  pattern_mask_size = 0x%04"PRIX16"\n", data->pattern_mask_size);
	RTE_LOG(INFO, PMD, "           unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "           unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "              valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_wol_reason_qcfg_input(const char *string __rte_unused, struct hwrm_wol_reason_qcfg_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_reason_qcfg_input\n");
	RTE_LOG(INFO, PMD, "          req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "            seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "           port_id = 0x%04"PRIX16"\n", data->port_id);
	RTE_LOG(INFO, PMD, "          unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "          unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       unused_2[0] = 0x%02"PRIX8"\n", data->unused_2[0]);
	RTE_LOG(INFO, PMD, "       unused_2[1] = 0x%02"PRIX8"\n", data->unused_2[1]);
	RTE_LOG(INFO, PMD, "       unused_2[2] = 0x%02"PRIX8"\n", data->unused_2[2]);
	RTE_LOG(INFO, PMD, "          unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "  wol_pkt_buf_addr = 0x%016"PRIX64"\n", data->wol_pkt_buf_addr);
	RTE_LOG(INFO, PMD, "  wol_pkt_buf_size = 0x%04"PRIX16"\n", data->wol_pkt_buf_size);
	RTE_LOG(INFO, PMD, "       unused_4[0] = 0x%04"PRIX16"\n", data->unused_4[0]);
	RTE_LOG(INFO, PMD, "       unused_4[1] = 0x%04"PRIX16"\n", data->unused_4[1]);
	RTE_LOG(INFO, PMD, "       unused_4[2] = 0x%04"PRIX16"\n", data->unused_4[2]);
}

void decode_hwrm_wol_reason_qcfg_output(const char *string __rte_unused, struct hwrm_wol_reason_qcfg_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_wol_reason_qcfg_output\n");
	RTE_LOG(INFO, PMD, "     error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  wol_filter_id = 0x%02"PRIX8"\n", data->wol_filter_id);
	RTE_LOG(INFO, PMD, "     wol_reason = 0x%02"PRIX8"\n", data->wol_reason);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->wol_reason == HWRM_WOL_REASON_QCFG_OUTPUT_WOL_REASON_MAGICPKT ? "MAGICPKT" :
		data->wol_reason == HWRM_WOL_REASON_QCFG_OUTPUT_WOL_REASON_BMP ? "BMP" :
		data->wol_reason == HWRM_WOL_REASON_QCFG_OUTPUT_WOL_REASON_INVALID ? "INVALID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    wol_pkt_len = 0x%02"PRIX8"\n", data->wol_pkt_len);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "          valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_dbg_read_direct_input(const char *string __rte_unused, struct hwrm_dbg_read_direct_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_read_direct_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  host_dest_addr = 0x%016"PRIX64"\n", data->host_dest_addr);
	RTE_LOG(INFO, PMD, "       read_addr = 0x%08"PRIX32"\n", data->read_addr);
	RTE_LOG(INFO, PMD, "      read_len32 = 0x%08"PRIX32"\n", data->read_len32);
}

void decode_hwrm_dbg_read_direct_output(const char *string __rte_unused, struct hwrm_dbg_read_direct_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_read_direct_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_dbg_write_direct_input(const char *string __rte_unused, struct hwrm_dbg_write_direct_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_write_direct_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "     write_addr = 0x%08"PRIX32"\n", data->write_addr);
	RTE_LOG(INFO, PMD, "    write_len32 = 0x%08"PRIX32"\n", data->write_len32);
	RTE_LOG(INFO, PMD, "  write_data[0] = 0x%08"PRIX32"\n", data->write_data[0]);
	RTE_LOG(INFO, PMD, "  write_data[1] = 0x%08"PRIX32"\n", data->write_data[1]);
	RTE_LOG(INFO, PMD, "  write_data[2] = 0x%08"PRIX32"\n", data->write_data[2]);
	RTE_LOG(INFO, PMD, "  write_data[3] = 0x%08"PRIX32"\n", data->write_data[3]);
	RTE_LOG(INFO, PMD, "  write_data[4] = 0x%08"PRIX32"\n", data->write_data[4]);
	RTE_LOG(INFO, PMD, "  write_data[5] = 0x%08"PRIX32"\n", data->write_data[5]);
	RTE_LOG(INFO, PMD, "  write_data[6] = 0x%08"PRIX32"\n", data->write_data[6]);
	RTE_LOG(INFO, PMD, "  write_data[7] = 0x%08"PRIX32"\n", data->write_data[7]);
}

void decode_hwrm_dbg_write_direct_output(const char *string __rte_unused, struct hwrm_dbg_write_direct_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_write_direct_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_dbg_read_indirect_input(const char *string __rte_unused, struct hwrm_dbg_read_indirect_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_read_indirect_input\n");
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "             resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "        host_dest_addr = 0x%016"PRIX64"\n", data->host_dest_addr);
	RTE_LOG(INFO, PMD, "    host_dest_addr_len = 0x%08"PRIX32"\n", data->host_dest_addr_len);
	RTE_LOG(INFO, PMD, "  indirect_access_type = 0x%02"PRIX8"\n", data->indirect_access_type);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_TE_MGMT_FILTERS_L2 ? "TE_MGMT_FILTERS_L2" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_TE_MGMT_FILTERS_L3L4 ? "TE_MGMT_FILTERS_L3L4" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_RE_MGMT_FILTERS_L2 ? "RE_MGMT_FILTERS_L2" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_RE_MGMT_FILTERS_L3L4 ? "RE_MGMT_FILTERS_L3L4" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_STAT_CTXS ? "STAT_CTXS" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_L2_TCAM ? "CFA_TX_L2_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_L2_TCAM ? "CFA_RX_L2_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_IPV6_SUBNET_TCAM ? "CFA_TX_IPV6_SUBNET_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_IPV6_SUBNET_TCAM ? "CFA_RX_IPV6_SUBNET_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_SRC_PROPERTIES_TCAM ? "CFA_TX_SRC_PROPERTIES_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_SRC_PROPERTIES_TCAM ? "CFA_RX_SRC_PROPERTIES_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_VEB_LOOKUP_TCAM ? "CFA_VEB_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_PROFILE_LOOKUP_TCAM ? "CFA_TX_PROFILE_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_PROFILE_LOOKUP_TCAM ? "CFA_RX_PROFILE_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_LOOKUP_TCAM ? "CFA_TX_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_READ_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_LOOKUP_TCAM ? "CFA_RX_LOOKUP_TCAM" :
		"Unknown");
	RTE_LOG(INFO, PMD, "              unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "              unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           start_index = 0x%08"PRIX32"\n", data->start_index);
	RTE_LOG(INFO, PMD, "        num_of_entries = 0x%08"PRIX32"\n", data->num_of_entries);
}

void decode_hwrm_dbg_read_indirect_output(const char *string __rte_unused, struct hwrm_dbg_read_indirect_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_read_indirect_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_dbg_write_indirect_input(const char *string __rte_unused, struct hwrm_dbg_write_indirect_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_write_indirect_input\n");
	RTE_LOG(INFO, PMD, "              req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "             cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "             target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "             resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  indirect_access_type = 0x%02"PRIX8"\n", data->indirect_access_type);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_TE_MGMT_FILTERS_L2 ? "TE_MGMT_FILTERS_L2" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_TE_MGMT_FILTERS_L3L4 ? "TE_MGMT_FILTERS_L3L4" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_RE_MGMT_FILTERS_L2 ? "RE_MGMT_FILTERS_L2" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_RE_MGMT_FILTERS_L3L4 ? "RE_MGMT_FILTERS_L3L4" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_STAT_CTXS ? "STAT_CTXS" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_L2_TCAM ? "CFA_TX_L2_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_L2_TCAM ? "CFA_RX_L2_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_IPV6_SUBNET_TCAM ? "CFA_TX_IPV6_SUBNET_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_IPV6_SUBNET_TCAM ? "CFA_RX_IPV6_SUBNET_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_SRC_PROPERTIES_TCAM ? "CFA_TX_SRC_PROPERTIES_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_SRC_PROPERTIES_TCAM ? "CFA_RX_SRC_PROPERTIES_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_VEB_LOOKUP_TCAM ? "CFA_VEB_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_PROFILE_LOOKUP_TCAM ? "CFA_TX_PROFILE_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_PROFILE_LOOKUP_TCAM ? "CFA_RX_PROFILE_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_TX_LOOKUP_TCAM ? "CFA_TX_LOOKUP_TCAM" :
		data->indirect_access_type == HWRM_DBG_WRITE_INDIRECT_INPUT_INDIRECT_ACCESS_TYPE_CFA_RX_LOOKUP_TCAM ? "CFA_RX_LOOKUP_TCAM" :
		"Unknown");
	RTE_LOG(INFO, PMD, "              unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "              unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "           start_index = 0x%08"PRIX32"\n", data->start_index);
	RTE_LOG(INFO, PMD, "        num_of_entries = 0x%08"PRIX32"\n", data->num_of_entries);
	RTE_LOG(INFO, PMD, "              unused_2 = 0x%08"PRIX32"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "         write_data[0] = 0x%08"PRIX32"\n", data->write_data[0]);
	RTE_LOG(INFO, PMD, "         write_data[1] = 0x%08"PRIX32"\n", data->write_data[1]);
	RTE_LOG(INFO, PMD, "         write_data[2] = 0x%08"PRIX32"\n", data->write_data[2]);
	RTE_LOG(INFO, PMD, "         write_data[3] = 0x%08"PRIX32"\n", data->write_data[3]);
	RTE_LOG(INFO, PMD, "         write_data[4] = 0x%08"PRIX32"\n", data->write_data[4]);
	RTE_LOG(INFO, PMD, "         write_data[5] = 0x%08"PRIX32"\n", data->write_data[5]);
	RTE_LOG(INFO, PMD, "         write_data[6] = 0x%08"PRIX32"\n", data->write_data[6]);
	RTE_LOG(INFO, PMD, "         write_data[7] = 0x%08"PRIX32"\n", data->write_data[7]);
}

void decode_hwrm_dbg_write_indirect_output(const char *string __rte_unused, struct hwrm_dbg_write_indirect_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_write_indirect_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_dbg_dump_input(const char *string __rte_unused, struct hwrm_dbg_dump_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_dump_input\n");
	RTE_LOG(INFO, PMD, "                req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "               cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "                  seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "               target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "               resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                  handle = 0x%08"PRIX32"\n", data->handle);
	RTE_LOG(INFO, PMD, "                unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      host_dbg_dump_addr = 0x%016"PRIX64"\n", data->host_dbg_dump_addr);
	RTE_LOG(INFO, PMD, "  host_dbg_dump_addr_len = 0x%016"PRIX64"\n", data->host_dbg_dump_addr_len);
}

void decode_hwrm_dbg_dump_output(const char *string __rte_unused, struct hwrm_dbg_dump_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_dbg_dump_output\n");
	RTE_LOG(INFO, PMD, "    error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    nexthandle = 0x%08"PRIX32"\n", data->nexthandle);
	RTE_LOG(INFO, PMD, "  dbg_data_len = 0x%08"PRIX32"\n", data->dbg_data_len);
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "      unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "      unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "         valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_raw_write_blk_input(const char *string __rte_unused, struct hwrm_nvm_raw_write_blk_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_raw_write_blk_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  host_src_addr = 0x%016"PRIX64"\n", data->host_src_addr);
	RTE_LOG(INFO, PMD, "      dest_addr = 0x%08"PRIX32"\n", data->dest_addr);
	RTE_LOG(INFO, PMD, "            len = 0x%08"PRIX32"\n", data->len);
}

void decode_hwrm_nvm_raw_write_blk_output(const char *string __rte_unused, struct hwrm_nvm_raw_write_blk_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_raw_write_blk_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_read_input(const char *string __rte_unused, struct hwrm_nvm_read_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_read_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  host_dest_addr = 0x%016"PRIX64"\n", data->host_dest_addr);
	RTE_LOG(INFO, PMD, "         dir_idx = 0x%04"PRIX16"\n", data->dir_idx);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "          offset = 0x%08"PRIX32"\n", data->offset);
	RTE_LOG(INFO, PMD, "             len = 0x%08"PRIX32"\n", data->len);
	RTE_LOG(INFO, PMD, "        unused_2 = 0x%08"PRIX32"\n", data->unused_2);
}

void decode_hwrm_nvm_read_output(const char *string __rte_unused, struct hwrm_nvm_read_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_read_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_raw_dump_input(const char *string __rte_unused, struct hwrm_nvm_raw_dump_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_raw_dump_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  host_dest_addr = 0x%016"PRIX64"\n", data->host_dest_addr);
	RTE_LOG(INFO, PMD, "          offset = 0x%08"PRIX32"\n", data->offset);
	RTE_LOG(INFO, PMD, "             len = 0x%08"PRIX32"\n", data->len);
}

void decode_hwrm_nvm_raw_dump_output(const char *string __rte_unused, struct hwrm_nvm_raw_dump_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_raw_dump_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_get_dir_entries_input(const char *string __rte_unused, struct hwrm_nvm_get_dir_entries_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_dir_entries_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  host_dest_addr = 0x%016"PRIX64"\n", data->host_dest_addr);
}

void decode_hwrm_nvm_get_dir_entries_output(const char *string __rte_unused, struct hwrm_nvm_get_dir_entries_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_dir_entries_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_get_dir_info_input(const char *string __rte_unused, struct hwrm_nvm_get_dir_info_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_dir_info_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_hwrm_nvm_get_dir_info_output(const char *string __rte_unused, struct hwrm_nvm_get_dir_info_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_dir_info_output\n");
	RTE_LOG(INFO, PMD, "    error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "       entries = 0x%08"PRIX32"\n", data->entries);
	RTE_LOG(INFO, PMD, "  entry_length = 0x%08"PRIX32"\n", data->entry_length);
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "      unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "      unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "      unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "         valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_write_input(const char *string __rte_unused, struct hwrm_nvm_write_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_write_input\n");
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "        cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "        target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "        resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    host_src_addr = 0x%016"PRIX64"\n", data->host_src_addr);
	RTE_LOG(INFO, PMD, "         dir_type = 0x%04"PRIX16"\n", data->dir_type);
	RTE_LOG(INFO, PMD, "      dir_ordinal = 0x%04"PRIX16"\n", data->dir_ordinal);
	RTE_LOG(INFO, PMD, "          dir_ext = 0x%04"PRIX16"\n", data->dir_ext);
	RTE_LOG(INFO, PMD, "         dir_attr = 0x%04"PRIX16"\n", data->dir_attr);
	RTE_LOG(INFO, PMD, "  dir_data_length = 0x%08"PRIX32"\n", data->dir_data_length);
	RTE_LOG(INFO, PMD, "           option = 0x%04"PRIX16"\n", data->option);
	RTE_LOG(INFO, PMD, "            flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                    KEEP_ORIG_ACTIVE_IMG : %s\n", (data->flags & HWRM_NVM_WRITE_INPUT_FLAGS_KEEP_ORIG_ACTIVE_IMG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  dir_item_length = 0x%08"PRIX32"\n", data->dir_item_length);
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_hwrm_nvm_write_output(const char *string __rte_unused, struct hwrm_nvm_write_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_write_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  dir_item_length = 0x%08"PRIX32"\n", data->dir_item_length);
	RTE_LOG(INFO, PMD, "          dir_idx = 0x%04"PRIX16"\n", data->dir_idx);
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_modify_input(const char *string __rte_unused, struct hwrm_nvm_modify_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_modify_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  host_src_addr = 0x%016"PRIX64"\n", data->host_src_addr);
	RTE_LOG(INFO, PMD, "        dir_idx = 0x%04"PRIX16"\n", data->dir_idx);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "         offset = 0x%08"PRIX32"\n", data->offset);
	RTE_LOG(INFO, PMD, "            len = 0x%08"PRIX32"\n", data->len);
	RTE_LOG(INFO, PMD, "       unused_2 = 0x%08"PRIX32"\n", data->unused_2);
}

void decode_hwrm_nvm_modify_output(const char *string __rte_unused, struct hwrm_nvm_modify_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_modify_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_find_dir_entry_input(const char *string __rte_unused, struct hwrm_nvm_find_dir_entry_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_find_dir_entry_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                DIR_IDX_VALID : %s\n", (data->enables & HWRM_NVM_FIND_DIR_ENTRY_INPUT_ENABLES_DIR_IDX_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      dir_idx = 0x%04"PRIX16"\n", data->dir_idx);
	RTE_LOG(INFO, PMD, "     dir_type = 0x%04"PRIX16"\n", data->dir_type);
	RTE_LOG(INFO, PMD, "  dir_ordinal = 0x%04"PRIX16"\n", data->dir_ordinal);
	RTE_LOG(INFO, PMD, "      dir_ext = 0x%04"PRIX16"\n", data->dir_ext);
	RTE_LOG(INFO, PMD, "  opt_ordinal = 0x%02"PRIX8"\n", data->opt_ordinal);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		(data->opt_ordinal & HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_MASK) == HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_SFT ? "SFT" :
		(data->opt_ordinal & HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_MASK) == HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_EQ ? "EQ" :
		(data->opt_ordinal & HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_MASK) == HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_GE ? "GE" :
		(data->opt_ordinal & HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_MASK) == HWRM_NVM_FIND_DIR_ENTRY_INPUT_OPT_ORDINAL_GT ? "GT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_1[0] = 0x%02"PRIX8"\n", data->unused_1[0]);
	RTE_LOG(INFO, PMD, "  unused_1[1] = 0x%02"PRIX8"\n", data->unused_1[1]);
	RTE_LOG(INFO, PMD, "  unused_1[2] = 0x%02"PRIX8"\n", data->unused_1[2]);
}

void decode_hwrm_nvm_find_dir_entry_output(const char *string __rte_unused, struct hwrm_nvm_find_dir_entry_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_find_dir_entry_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  dir_item_length = 0x%08"PRIX32"\n", data->dir_item_length);
	RTE_LOG(INFO, PMD, "  dir_data_length = 0x%08"PRIX32"\n", data->dir_data_length);
	RTE_LOG(INFO, PMD, "           fw_ver = 0x%08"PRIX32"\n", data->fw_ver);
	RTE_LOG(INFO, PMD, "      dir_ordinal = 0x%04"PRIX16"\n", data->dir_ordinal);
	RTE_LOG(INFO, PMD, "          dir_idx = 0x%04"PRIX16"\n", data->dir_idx);
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "         unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "         unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_erase_dir_entry_input(const char *string __rte_unused, struct hwrm_nvm_erase_dir_entry_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_erase_dir_entry_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      dir_idx = 0x%04"PRIX16"\n", data->dir_idx);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_nvm_erase_dir_entry_output(const char *string __rte_unused, struct hwrm_nvm_erase_dir_entry_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_erase_dir_entry_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_get_dev_info_input(const char *string __rte_unused, struct hwrm_nvm_get_dev_info_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_dev_info_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_hwrm_nvm_get_dev_info_output(const char *string __rte_unused, struct hwrm_nvm_get_dev_info_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_dev_info_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  manufacturer_id = 0x%04"PRIX16"\n", data->manufacturer_id);
	RTE_LOG(INFO, PMD, "        device_id = 0x%04"PRIX16"\n", data->device_id);
	RTE_LOG(INFO, PMD, "      sector_size = 0x%08"PRIX32"\n", data->sector_size);
	RTE_LOG(INFO, PMD, "       nvram_size = 0x%08"PRIX32"\n", data->nvram_size);
	RTE_LOG(INFO, PMD, "    reserved_size = 0x%08"PRIX32"\n", data->reserved_size);
	RTE_LOG(INFO, PMD, "   available_size = 0x%08"PRIX32"\n", data->available_size);
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "         unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_mod_dir_entry_input(const char *string __rte_unused, struct hwrm_nvm_mod_dir_entry_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_mod_dir_entry_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      enables = 0x%08"PRIX32"\n", data->enables);
	RTE_LOG(INFO, PMD, "                CHECKSUM : %s\n", (data->enables & HWRM_NVM_MOD_DIR_ENTRY_INPUT_ENABLES_CHECKSUM)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      dir_idx = 0x%04"PRIX16"\n", data->dir_idx);
	RTE_LOG(INFO, PMD, "  dir_ordinal = 0x%04"PRIX16"\n", data->dir_ordinal);
	RTE_LOG(INFO, PMD, "      dir_ext = 0x%04"PRIX16"\n", data->dir_ext);
	RTE_LOG(INFO, PMD, "     dir_attr = 0x%04"PRIX16"\n", data->dir_attr);
	RTE_LOG(INFO, PMD, "     checksum = 0x%08"PRIX32"\n", data->checksum);
}

void decode_hwrm_nvm_mod_dir_entry_output(const char *string __rte_unused, struct hwrm_nvm_mod_dir_entry_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_mod_dir_entry_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_verify_update_input(const char *string __rte_unused, struct hwrm_nvm_verify_update_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_verify_update_input\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "    cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "       seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "     dir_type = 0x%04"PRIX16"\n", data->dir_type);
	RTE_LOG(INFO, PMD, "  dir_ordinal = 0x%04"PRIX16"\n", data->dir_ordinal);
	RTE_LOG(INFO, PMD, "      dir_ext = 0x%04"PRIX16"\n", data->dir_ext);
	RTE_LOG(INFO, PMD, "     unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_nvm_verify_update_output(const char *string __rte_unused, struct hwrm_nvm_verify_update_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_verify_update_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_install_update_input(const char *string __rte_unused, struct hwrm_nvm_install_update_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_install_update_input\n");
	RTE_LOG(INFO, PMD, "      req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "     cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "        seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "     target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "     resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  install_type = 0x%08"PRIX32"\n", data->install_type);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->install_type == HWRM_NVM_INSTALL_UPDATE_INPUT_INSTALL_TYPE_NORMAL ? "NORMAL" :
		data->install_type == HWRM_NVM_INSTALL_UPDATE_INPUT_INSTALL_TYPE_ALL ? "ALL" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                 ERASE_UNUSED_SPACE : %s\n", (data->flags & HWRM_NVM_INSTALL_UPDATE_INPUT_FLAGS_ERASE_UNUSED_SPACE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                 REMOVE_UNUSED_PKG : %s\n", (data->flags & HWRM_NVM_INSTALL_UPDATE_INPUT_FLAGS_REMOVE_UNUSED_PKG)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_nvm_install_update_output(const char *string __rte_unused, struct hwrm_nvm_install_update_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_install_update_output\n");
	RTE_LOG(INFO, PMD, "       error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "         req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "           seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "         resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "  installed_items = 0x%016"PRIX64"\n", data->installed_items);
	RTE_LOG(INFO, PMD, "           result = 0x%02"PRIX8"\n", data->result);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->result == HWRM_NVM_INSTALL_UPDATE_OUTPUT_RESULT_SUCCESS ? "SUCCESS" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     problem_item = 0x%02"PRIX8"\n", data->problem_item);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->problem_item == HWRM_NVM_INSTALL_UPDATE_OUTPUT_PROBLEM_ITEM_NONE ? "NONE" :
		data->problem_item == HWRM_NVM_INSTALL_UPDATE_OUTPUT_PROBLEM_ITEM_PACKAGE ? "PACKAGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   reset_required = 0x%02"PRIX8"\n", data->reset_required);
	RTE_LOG(INFO, PMD, "                    Value : %s\n",
		data->reset_required == HWRM_NVM_INSTALL_UPDATE_OUTPUT_RESET_REQUIRED_NONE ? "NONE" :
		data->reset_required == HWRM_NVM_INSTALL_UPDATE_OUTPUT_RESET_REQUIRED_PCI ? "PCI" :
		data->reset_required == HWRM_NVM_INSTALL_UPDATE_OUTPUT_RESET_REQUIRED_POWER ? "POWER" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "         unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "         unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "         unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "            valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_get_variable_input(const char *string __rte_unused, struct hwrm_nvm_get_variable_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_variable_input\n");
	RTE_LOG(INFO, PMD, "        req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "       cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "          seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "       target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  dest_data_addr = 0x%016"PRIX64"\n", data->dest_data_addr);
	RTE_LOG(INFO, PMD, "        data_len = 0x%04"PRIX16"\n", data->data_len);
	RTE_LOG(INFO, PMD, "      option_num = 0x%04"PRIX16"\n", data->option_num);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->option_num == HWRM_NVM_GET_VARIABLE_INPUT_OPTION_NUM_RSVD_0 ? "RSVD_0" :
		data->option_num == HWRM_NVM_GET_VARIABLE_INPUT_OPTION_NUM_RSVD_FFFF ? "RSVD_FFFF" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      dimensions = 0x%04"PRIX16"\n", data->dimensions);
	RTE_LOG(INFO, PMD, "         index_0 = 0x%04"PRIX16"\n", data->index_0);
	RTE_LOG(INFO, PMD, "         index_1 = 0x%04"PRIX16"\n", data->index_1);
	RTE_LOG(INFO, PMD, "         index_2 = 0x%04"PRIX16"\n", data->index_2);
	RTE_LOG(INFO, PMD, "         index_3 = 0x%04"PRIX16"\n", data->index_3);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_nvm_get_variable_output(const char *string __rte_unused, struct hwrm_nvm_get_variable_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_get_variable_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    data_len = 0x%04"PRIX16"\n", data->data_len);
	RTE_LOG(INFO, PMD, "  option_num = 0x%04"PRIX16"\n", data->option_num);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->option_num == HWRM_NVM_GET_VARIABLE_OUTPUT_OPTION_NUM_RSVD_0 ? "RSVD_0" :
		data->option_num == HWRM_NVM_GET_VARIABLE_OUTPUT_OPTION_NUM_RSVD_FFFF ? "RSVD_FFFF" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_hwrm_nvm_set_variable_input(const char *string __rte_unused, struct hwrm_nvm_set_variable_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_set_variable_input\n");
	RTE_LOG(INFO, PMD, "       req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "         seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "      target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  src_data_addr = 0x%016"PRIX64"\n", data->src_data_addr);
	RTE_LOG(INFO, PMD, "       data_len = 0x%04"PRIX16"\n", data->data_len);
	RTE_LOG(INFO, PMD, "     option_num = 0x%04"PRIX16"\n", data->option_num);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->option_num == HWRM_NVM_SET_VARIABLE_INPUT_OPTION_NUM_RSVD_0 ? "RSVD_0" :
		data->option_num == HWRM_NVM_SET_VARIABLE_INPUT_OPTION_NUM_RSVD_FFFF ? "RSVD_FFFF" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     dimensions = 0x%04"PRIX16"\n", data->dimensions);
	RTE_LOG(INFO, PMD, "        index_0 = 0x%04"PRIX16"\n", data->index_0);
	RTE_LOG(INFO, PMD, "        index_1 = 0x%04"PRIX16"\n", data->index_1);
	RTE_LOG(INFO, PMD, "        index_2 = 0x%04"PRIX16"\n", data->index_2);
	RTE_LOG(INFO, PMD, "        index_3 = 0x%04"PRIX16"\n", data->index_3);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_hwrm_nvm_set_variable_output(const char *string __rte_unused, struct hwrm_nvm_set_variable_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_nvm_set_variable_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "    unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "    unused_3 = 0x%02"PRIX8"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_cmdq_init(const char *string __rte_unused, struct cmdq_init *data) {
	RTE_LOG(INFO, PMD, "cmdq_init\n");
	RTE_LOG(INFO, PMD, "            cmdq_pbl = 0x%016"PRIX64"\n", data->cmdq_pbl);
	RTE_LOG(INFO, PMD, "  cmdq_size_cmdq_lvl = 0x%04"PRIX16"\n", data->cmdq_size_cmdq_lvl);
	RTE_LOG(INFO, PMD, "        creq_ring_id = 0x%04"PRIX16"\n", data->creq_ring_id);
	RTE_LOG(INFO, PMD, "            prod_idx = 0x%08"PRIX32"\n", data->prod_idx);
}

void decode_cmdq_update(const char *string __rte_unused, struct cmdq_update *data) {
	RTE_LOG(INFO, PMD, "cmdq_update\n");
	RTE_LOG(INFO, PMD, "  reserved64 = 0x%016"PRIX64"\n", data->reserved64);
	RTE_LOG(INFO, PMD, "  reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "    prod_idx = 0x%08"PRIX32"\n", data->prod_idx);
}

void decode_cmdq_base(const char *string __rte_unused, struct cmdq_base *data) {
	RTE_LOG(INFO, PMD, "cmdq_base\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_BASE_OPCODE_CREATE_QP ? "CREATE_QP" :
		data->opcode == CMDQ_BASE_OPCODE_DESTROY_QP ? "DESTROY_QP" :
		data->opcode == CMDQ_BASE_OPCODE_MODIFY_QP ? "MODIFY_QP" :
		data->opcode == CMDQ_BASE_OPCODE_QUERY_QP ? "QUERY_QP" :
		data->opcode == CMDQ_BASE_OPCODE_CREATE_SRQ ? "CREATE_SRQ" :
		data->opcode == CMDQ_BASE_OPCODE_DESTROY_SRQ ? "DESTROY_SRQ" :
		data->opcode == CMDQ_BASE_OPCODE_QUERY_SRQ ? "QUERY_SRQ" :
		data->opcode == CMDQ_BASE_OPCODE_CREATE_CQ ? "CREATE_CQ" :
		data->opcode == CMDQ_BASE_OPCODE_DESTROY_CQ ? "DESTROY_CQ" :
		data->opcode == CMDQ_BASE_OPCODE_RESIZE_CQ ? "RESIZE_CQ" :
		data->opcode == CMDQ_BASE_OPCODE_ALLOCATE_MRW ? "ALLOCATE_MRW" :
		data->opcode == CMDQ_BASE_OPCODE_DEALLOCATE_KEY ? "DEALLOCATE_KEY" :
		data->opcode == CMDQ_BASE_OPCODE_REGISTER_MR ? "REGISTER_MR" :
		data->opcode == CMDQ_BASE_OPCODE_DEREGISTER_MR ? "DEREGISTER_MR" :
		data->opcode == CMDQ_BASE_OPCODE_ADD_GID ? "ADD_GID" :
		data->opcode == CMDQ_BASE_OPCODE_DELETE_GID ? "DELETE_GID" :
		data->opcode == CMDQ_BASE_OPCODE_MODIFY_GID ? "MODIFY_GID" :
		data->opcode == CMDQ_BASE_OPCODE_QUERY_GID ? "QUERY_GID" :
		data->opcode == CMDQ_BASE_OPCODE_CREATE_QP1 ? "CREATE_QP1" :
		data->opcode == CMDQ_BASE_OPCODE_DESTROY_QP1 ? "DESTROY_QP1" :
		data->opcode == CMDQ_BASE_OPCODE_CREATE_AH ? "CREATE_AH" :
		data->opcode == CMDQ_BASE_OPCODE_DESTROY_AH ? "DESTROY_AH" :
		data->opcode == CMDQ_BASE_OPCODE_INITIALIZE_FW ? "INITIALIZE_FW" :
		data->opcode == CMDQ_BASE_OPCODE_DEINITIALIZE_FW ? "DEINITIALIZE_FW" :
		data->opcode == CMDQ_BASE_OPCODE_STOP_FUNC ? "STOP_FUNC" :
		data->opcode == CMDQ_BASE_OPCODE_QUERY_FUNC ? "QUERY_FUNC" :
		data->opcode == CMDQ_BASE_OPCODE_SET_FUNC_RESOURCES ? "SET_FUNC_RESOURCES" :
		data->opcode == CMDQ_BASE_OPCODE_READ_CONTEXT ? "READ_CONTEXT" :
		data->opcode == CMDQ_BASE_OPCODE_VF_BACKCHANNEL_REQUEST ? "VF_BACKCHANNEL_REQUEST" :
		data->opcode == CMDQ_BASE_OPCODE_READ_VF_MEMORY ? "READ_VF_MEMORY" :
		data->opcode == CMDQ_BASE_OPCODE_COMPLETE_VF_REQUEST ? "COMPLETE_VF_REQUEST" :
		data->opcode == CMDQ_BASE_OPCODE_EXTEND_CONTEXT_ARRRAY ? "EXTEND_CONTEXT_ARRRAY" :
		data->opcode == CMDQ_BASE_OPCODE_MAP_TC_TO_COS ? "MAP_TC_TO_COS" :
		data->opcode == CMDQ_BASE_OPCODE_QUERY_VERSION ? "QUERY_VERSION" :
		data->opcode == CMDQ_BASE_OPCODE_MODIFY_ROCE_CC ? "MODIFY_ROCE_CC" :
		data->opcode == CMDQ_BASE_OPCODE_QUERY_ROCE_CC ? "QUERY_ROCE_CC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_cmdq_create_qp(const char *string __rte_unused, struct cmdq_create_qp *data) {
	RTE_LOG(INFO, PMD, "cmdq_create_qp\n");
	RTE_LOG(INFO, PMD, "             opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                      CREATE_QP : %s\n", (data->opcode & CMDQ_CREATE_QP_OPCODE_CREATE_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "           cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "              flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "             cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "          resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "          reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          qp_handle = 0x%016"PRIX64"\n", data->qp_handle);
	RTE_LOG(INFO, PMD, "           qp_flags = 0x%08"PRIX32"\n", data->qp_flags);
	RTE_LOG(INFO, PMD, "                      SRQ_USED : %s\n", (data->qp_flags & CMDQ_CREATE_QP_QP_FLAGS_SRQ_USED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      FORCE_COMPLETION : %s\n", (data->qp_flags & CMDQ_CREATE_QP_QP_FLAGS_FORCE_COMPLETION)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      RESERVED_LKEY_ENABLE : %s\n", (data->qp_flags & CMDQ_CREATE_QP_QP_FLAGS_RESERVED_LKEY_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      FR_PMR_ENABLED : %s\n", (data->qp_flags & CMDQ_CREATE_QP_QP_FLAGS_FR_PMR_ENABLED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->type == CMDQ_CREATE_QP_TYPE_RC ? "RC" :
		data->type == CMDQ_CREATE_QP_TYPE_UD ? "UD" :
		data->type == CMDQ_CREATE_QP_TYPE_RAW_ETHERTYPE ? "RAW_ETHERTYPE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  sq_pg_size_sq_lvl = 0x%02"PRIX8"\n", data->sq_pg_size_sq_lvl);
	RTE_LOG(INFO, PMD, "  rq_pg_size_rq_lvl = 0x%02"PRIX8"\n", data->rq_pg_size_rq_lvl);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "                dpi = 0x%08"PRIX32"\n", data->dpi);
	RTE_LOG(INFO, PMD, "            sq_size = 0x%08"PRIX32"\n", data->sq_size);
	RTE_LOG(INFO, PMD, "            rq_size = 0x%08"PRIX32"\n", data->rq_size);
	RTE_LOG(INFO, PMD, "      sq_fwo_sq_sge = 0x%04"PRIX16"\n", data->sq_fwo_sq_sge);
	RTE_LOG(INFO, PMD, "      rq_fwo_rq_sge = 0x%04"PRIX16"\n", data->rq_fwo_rq_sge);
	RTE_LOG(INFO, PMD, "            scq_cid = 0x%08"PRIX32"\n", data->scq_cid);
	RTE_LOG(INFO, PMD, "            rcq_cid = 0x%08"PRIX32"\n", data->rcq_cid);
	RTE_LOG(INFO, PMD, "            srq_cid = 0x%08"PRIX32"\n", data->srq_cid);
	RTE_LOG(INFO, PMD, "              pd_id = 0x%08"PRIX32"\n", data->pd_id);
	RTE_LOG(INFO, PMD, "             sq_pbl = 0x%016"PRIX64"\n", data->sq_pbl);
	RTE_LOG(INFO, PMD, "             rq_pbl = 0x%016"PRIX64"\n", data->rq_pbl);
	RTE_LOG(INFO, PMD, "          irrq_addr = 0x%016"PRIX64"\n", data->irrq_addr);
	RTE_LOG(INFO, PMD, "          orrq_addr = 0x%016"PRIX64"\n", data->orrq_addr);
}

void decode_cmdq_destroy_qp(const char *string __rte_unused, struct cmdq_destroy_qp *data) {
	RTE_LOG(INFO, PMD, "cmdq_destroy_qp\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              DESTROY_QP : %s\n", (data->opcode & CMDQ_DESTROY_QP_OPCODE_DESTROY_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "     qp_cid = 0x%08"PRIX32"\n", data->qp_cid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_modify_qp(const char *string __rte_unused, struct cmdq_modify_qp *data) {
	RTE_LOG(INFO, PMD, "cmdq_modify_qp\n");
	RTE_LOG(INFO, PMD, "                                      opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                                               Value : %s\n",
		data->opcode == CMDQ_MODIFY_QP_OPCODE_MODIFY_QP ? "MODIFY_QP" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                                    cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "                                       flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                                      cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "                                   resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "                                   reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "                                   resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                                 modify_mask = 0x%08"PRIX32"\n", data->modify_mask);
	RTE_LOG(INFO, PMD, "                                               STATE : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_STATE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               EN_SQD_ASYNC_NOTIFY : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_EN_SQD_ASYNC_NOTIFY)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               ACCESS : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_ACCESS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               PKEY : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_PKEY)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               QKEY : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_QKEY)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               DGID : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_DGID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               FLOW_LABEL : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_FLOW_LABEL)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               SGID_INDEX : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_SGID_INDEX)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               HOP_LIMIT : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_HOP_LIMIT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               TRAFFIC_CLASS : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_TRAFFIC_CLASS)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               DEST_MAC : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_DEST_MAC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               UNUSED : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_UNUSED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               PATH_MTU : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_PATH_MTU)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               TIMEOUT : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_TIMEOUT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               RETRY_CNT : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_RETRY_CNT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               RNR_RETRY : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_RNR_RETRY)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               RQ_PSN : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_RQ_PSN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               MAX_RD_ATOMIC : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_MAX_RD_ATOMIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               MIN_RNR_TIMER : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_MIN_RNR_TIMER)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               SQ_PSN : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_SQ_PSN)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               MAX_DEST_RD_ATOMIC : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_MAX_DEST_RD_ATOMIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               SQ_SIZE : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_SQ_SIZE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               RQ_SIZE : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_RQ_SIZE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               SQ_SGE : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_SQ_SGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               RQ_SGE : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_RQ_SGE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               MAX_INLINE_DATA : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_MAX_INLINE_DATA)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               DEST_QP_ID : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_DEST_QP_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               SRC_MAC : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_SRC_MAC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               VLAN_ID : %s\n", (data->modify_mask & CMDQ_MODIFY_QP_MODIFY_MASK_VLAN_ID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                      qp_cid = 0x%08"PRIX32"\n", data->qp_cid);
	RTE_LOG(INFO, PMD, "  network_type_en_sqd_async_notify_new_state = 0x%02"PRIX8"\n", data->network_type_en_sqd_async_notify_new_state);
	RTE_LOG(INFO, PMD, "                                      access = 0x%02"PRIX8"\n", data->access);
	RTE_LOG(INFO, PMD, "                                               LOCAL_WRITE : %s\n", (data->access & CMDQ_MODIFY_QP_ACCESS_LOCAL_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               REMOTE_WRITE : %s\n", (data->access & CMDQ_MODIFY_QP_ACCESS_REMOTE_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               REMOTE_READ : %s\n", (data->access & CMDQ_MODIFY_QP_ACCESS_REMOTE_READ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                               REMOTE_ATOMIC : %s\n", (data->access & CMDQ_MODIFY_QP_ACCESS_REMOTE_ATOMIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                                        pkey = 0x%04"PRIX16"\n", data->pkey);
	RTE_LOG(INFO, PMD, "                                        qkey = 0x%08"PRIX32"\n", data->qkey);
	RTE_LOG(INFO, PMD, "                                     dgid[0] = 0x%08"PRIX32"\n", data->dgid[0]);
	RTE_LOG(INFO, PMD, "                                     dgid[1] = 0x%08"PRIX32"\n", data->dgid[1]);
	RTE_LOG(INFO, PMD, "                                     dgid[2] = 0x%08"PRIX32"\n", data->dgid[2]);
	RTE_LOG(INFO, PMD, "                                     dgid[3] = 0x%08"PRIX32"\n", data->dgid[3]);
	RTE_LOG(INFO, PMD, "                                  flow_label = 0x%08"PRIX32"\n", data->flow_label);
	RTE_LOG(INFO, PMD, "                                  sgid_index = 0x%04"PRIX16"\n", data->sgid_index);
	RTE_LOG(INFO, PMD, "                                   hop_limit = 0x%02"PRIX8"\n", data->hop_limit);
	RTE_LOG(INFO, PMD, "                               traffic_class = 0x%02"PRIX8"\n", data->traffic_class);
	RTE_LOG(INFO, PMD, "                                 dest_mac[0] = 0x%04"PRIX16"\n", data->dest_mac[0]);
	RTE_LOG(INFO, PMD, "                                 dest_mac[1] = 0x%04"PRIX16"\n", data->dest_mac[1]);
	RTE_LOG(INFO, PMD, "                                 dest_mac[2] = 0x%04"PRIX16"\n", data->dest_mac[2]);
	RTE_LOG(INFO, PMD, "                                    path_mtu = 0x%04"PRIX16"\n", data->path_mtu);
	RTE_LOG(INFO, PMD, "                                               Value : %s\n",
		(data->path_mtu & CMDQ_MODIFY_QP_PATH_MTU_MASK) == CMDQ_MODIFY_QP_PATH_MTU_SFT ? "SFT" :
		(data->path_mtu & CMDQ_MODIFY_QP_PATH_MTU_MASK) == CMDQ_MODIFY_QP_PATH_MTU_MTU_256 ? "MTU_256" :
		(data->path_mtu & CMDQ_MODIFY_QP_PATH_MTU_MASK) == CMDQ_MODIFY_QP_PATH_MTU_MTU_512 ? "MTU_512" :
		(data->path_mtu & CMDQ_MODIFY_QP_PATH_MTU_MASK) == CMDQ_MODIFY_QP_PATH_MTU_MTU_1024 ? "MTU_1024" :
		(data->path_mtu & CMDQ_MODIFY_QP_PATH_MTU_MASK) == CMDQ_MODIFY_QP_PATH_MTU_MTU_2048 ? "MTU_2048" :
		(data->path_mtu & CMDQ_MODIFY_QP_PATH_MTU_MASK) == CMDQ_MODIFY_QP_PATH_MTU_MTU_4096 ? "MTU_4096" :
		(data->path_mtu & CMDQ_MODIFY_QP_PATH_MTU_MASK) == CMDQ_MODIFY_QP_PATH_MTU_MTU_8192 ? "MTU_8192" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                                     timeout = 0x%02"PRIX8"\n", data->timeout);
	RTE_LOG(INFO, PMD, "                                   retry_cnt = 0x%02"PRIX8"\n", data->retry_cnt);
	RTE_LOG(INFO, PMD, "                                   rnr_retry = 0x%02"PRIX8"\n", data->rnr_retry);
	RTE_LOG(INFO, PMD, "                               min_rnr_timer = 0x%02"PRIX8"\n", data->min_rnr_timer);
	RTE_LOG(INFO, PMD, "                                      rq_psn = 0x%08"PRIX32"\n", data->rq_psn);
	RTE_LOG(INFO, PMD, "                                      sq_psn = 0x%08"PRIX32"\n", data->sq_psn);
	RTE_LOG(INFO, PMD, "                               max_rd_atomic = 0x%02"PRIX8"\n", data->max_rd_atomic);
	RTE_LOG(INFO, PMD, "                          max_dest_rd_atomic = 0x%02"PRIX8"\n", data->max_dest_rd_atomic);
	RTE_LOG(INFO, PMD, "                                    unused_2 = 0x%04"PRIX16"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "                                     sq_size = 0x%08"PRIX32"\n", data->sq_size);
	RTE_LOG(INFO, PMD, "                                     rq_size = 0x%08"PRIX32"\n", data->rq_size);
	RTE_LOG(INFO, PMD, "                                      sq_sge = 0x%04"PRIX16"\n", data->sq_sge);
	RTE_LOG(INFO, PMD, "                                      rq_sge = 0x%04"PRIX16"\n", data->rq_sge);
	RTE_LOG(INFO, PMD, "                             max_inline_data = 0x%08"PRIX32"\n", data->max_inline_data);
	RTE_LOG(INFO, PMD, "                                  dest_qp_id = 0x%08"PRIX32"\n", data->dest_qp_id);
	RTE_LOG(INFO, PMD, "                                    unused_3 = 0x%08"PRIX32"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "                                  src_mac[0] = 0x%04"PRIX16"\n", data->src_mac[0]);
	RTE_LOG(INFO, PMD, "                                  src_mac[1] = 0x%04"PRIX16"\n", data->src_mac[1]);
	RTE_LOG(INFO, PMD, "                                  src_mac[2] = 0x%04"PRIX16"\n", data->src_mac[2]);
	RTE_LOG(INFO, PMD, "                   vlan_pcp_vlan_dei_vlan_id = 0x%04"PRIX16"\n", data->vlan_pcp_vlan_dei_vlan_id);
}

void decode_cmdq_query_qp(const char *string __rte_unused, struct cmdq_query_qp *data) {
	RTE_LOG(INFO, PMD, "cmdq_query_qp\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              QUERY_QP : %s\n", (data->opcode & CMDQ_QUERY_QP_OPCODE_QUERY_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "     qp_cid = 0x%08"PRIX32"\n", data->qp_cid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_create_srq(const char *string __rte_unused, struct cmdq_create_srq *data) {
	RTE_LOG(INFO, PMD, "cmdq_create_srq\n");
	RTE_LOG(INFO, PMD, "       opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->opcode == CMDQ_CREATE_SRQ_OPCODE_CREATE_SRQ ? "CREATE_SRQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "        flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "       cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "    resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "    reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "   srq_handle = 0x%016"PRIX64"\n", data->srq_handle);
	RTE_LOG(INFO, PMD, "  pg_size_lvl = 0x%04"PRIX16"\n", data->pg_size_lvl);
	RTE_LOG(INFO, PMD, "    eventq_id = 0x%04"PRIX16"\n", data->eventq_id);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		(data->eventq_id & CMDQ_CREATE_SRQ_EVENTQ_ID_MASK) == CMDQ_CREATE_SRQ_EVENTQ_ID_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     srq_size = 0x%04"PRIX16"\n", data->srq_size);
	RTE_LOG(INFO, PMD, "      srq_fwo = 0x%04"PRIX16"\n", data->srq_fwo);
	RTE_LOG(INFO, PMD, "          dpi = 0x%08"PRIX32"\n", data->dpi);
	RTE_LOG(INFO, PMD, "        pd_id = 0x%08"PRIX32"\n", data->pd_id);
	RTE_LOG(INFO, PMD, "          pbl = 0x%016"PRIX64"\n", data->pbl);
}

void decode_cmdq_destroy_srq(const char *string __rte_unused, struct cmdq_destroy_srq *data) {
	RTE_LOG(INFO, PMD, "cmdq_destroy_srq\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_DESTROY_SRQ_OPCODE_DESTROY_SRQ ? "DESTROY_SRQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    srq_cid = 0x%08"PRIX32"\n", data->srq_cid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_query_srq(const char *string __rte_unused, struct cmdq_query_srq *data) {
	RTE_LOG(INFO, PMD, "cmdq_query_srq\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              QUERY_SRQ : %s\n", (data->opcode & CMDQ_QUERY_SRQ_OPCODE_QUERY_SRQ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    srq_cid = 0x%08"PRIX32"\n", data->srq_cid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_create_cq(const char *string __rte_unused, struct cmdq_create_cq *data) {
	RTE_LOG(INFO, PMD, "cmdq_create_cq\n");
	RTE_LOG(INFO, PMD, "         opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->opcode == CMDQ_CREATE_CQ_OPCODE_CREATE_CQ ? "CREATE_CQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "          flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "      resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "      reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "      resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      cq_handle = 0x%016"PRIX64"\n", data->cq_handle);
	RTE_LOG(INFO, PMD, "    pg_size_lvl = 0x%08"PRIX32"\n", data->pg_size_lvl);
	RTE_LOG(INFO, PMD, "  cq_fco_cnq_id = 0x%08"PRIX32"\n", data->cq_fco_cnq_id);
	RTE_LOG(INFO, PMD, "            dpi = 0x%08"PRIX32"\n", data->dpi);
	RTE_LOG(INFO, PMD, "        cq_size = 0x%08"PRIX32"\n", data->cq_size);
	RTE_LOG(INFO, PMD, "            pbl = 0x%016"PRIX64"\n", data->pbl);
}

void decode_cmdq_destroy_cq(const char *string __rte_unused, struct cmdq_destroy_cq *data) {
	RTE_LOG(INFO, PMD, "cmdq_destroy_cq\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_DESTROY_CQ_OPCODE_DESTROY_CQ ? "DESTROY_CQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "     cq_cid = 0x%08"PRIX32"\n", data->cq_cid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_resize_cq(const char *string __rte_unused, struct cmdq_resize_cq *data) {
	RTE_LOG(INFO, PMD, "cmdq_resize_cq\n");
	RTE_LOG(INFO, PMD, "                   opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                            Value : %s\n",
		data->opcode == CMDQ_RESIZE_CQ_OPCODE_RESIZE_CQ ? "RESIZE_CQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                 cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "                    flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                   cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "                resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "                reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "                resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                   cq_cid = 0x%08"PRIX32"\n", data->cq_cid);
	RTE_LOG(INFO, PMD, "  new_cq_size_pg_size_lvl = 0x%08"PRIX32"\n", data->new_cq_size_pg_size_lvl);
	RTE_LOG(INFO, PMD, "                  new_pbl = 0x%016"PRIX64"\n", data->new_pbl);
	RTE_LOG(INFO, PMD, "               new_cq_fco = 0x%08"PRIX32"\n", data->new_cq_fco);
	RTE_LOG(INFO, PMD, "                 unused_2 = 0x%08"PRIX32"\n", data->unused_2);
}

void decode_cmdq_allocate_mrw(const char *string __rte_unused, struct cmdq_allocate_mrw *data) {
	RTE_LOG(INFO, PMD, "cmdq_allocate_mrw\n");
	RTE_LOG(INFO, PMD, "      opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->opcode == CMDQ_ALLOCATE_MRW_OPCODE_ALLOCATE_MRW ? "ALLOCATE_MRW" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "       flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "      cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "   resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "   reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "   resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  mrw_handle = 0x%016"PRIX64"\n", data->mrw_handle);
	RTE_LOG(INFO, PMD, "   mrw_flags = 0x%02"PRIX8"\n", data->mrw_flags);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->mrw_flags & CMDQ_ALLOCATE_MRW_MRW_FLAGS_MASK) == CMDQ_ALLOCATE_MRW_MRW_FLAGS_SFT ? "SFT" :
		(data->mrw_flags & CMDQ_ALLOCATE_MRW_MRW_FLAGS_MASK) == CMDQ_ALLOCATE_MRW_MRW_FLAGS_MR ? "MR" :
		(data->mrw_flags & CMDQ_ALLOCATE_MRW_MRW_FLAGS_MASK) == CMDQ_ALLOCATE_MRW_MRW_FLAGS_PMR ? "PMR" :
		(data->mrw_flags & CMDQ_ALLOCATE_MRW_MRW_FLAGS_MASK) == CMDQ_ALLOCATE_MRW_MRW_FLAGS_MW_TYPE1 ? "MW_TYPE1" :
		(data->mrw_flags & CMDQ_ALLOCATE_MRW_MRW_FLAGS_MASK) == CMDQ_ALLOCATE_MRW_MRW_FLAGS_MW_TYPE2A ? "MW_TYPE2A" :
		(data->mrw_flags & CMDQ_ALLOCATE_MRW_MRW_FLAGS_MASK) == CMDQ_ALLOCATE_MRW_MRW_FLAGS_MW_TYPE2B ? "MW_TYPE2B" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      access = 0x%02"PRIX8"\n", data->access);
	RTE_LOG(INFO, PMD, "               RESERVED = %0*X\n", 12, ((data->access & CMDQ_ALLOCATE_MRW_ACCESS_RESERVED_MASK) >> CMDQ_ALLOCATE_MRW_ACCESS_RESERVED_SFT));
	RTE_LOG(INFO, PMD, "               CONSUMER_OWNED_KEY : %s\n", (data->access & CMDQ_ALLOCATE_MRW_ACCESS_CONSUMER_OWNED_KEY)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "       pd_id = 0x%08"PRIX32"\n", data->pd_id);
}

void decode_cmdq_deallocate_key(const char *string __rte_unused, struct cmdq_deallocate_key *data) {
	RTE_LOG(INFO, PMD, "cmdq_deallocate_key\n");
	RTE_LOG(INFO, PMD, "       opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->opcode == CMDQ_DEALLOCATE_KEY_OPCODE_DEALLOCATE_KEY ? "DEALLOCATE_KEY" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "        flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "       cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "    resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "    reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    mrw_flags = 0x%02"PRIX8"\n", data->mrw_flags);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		(data->mrw_flags & CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MASK) == CMDQ_DEALLOCATE_KEY_MRW_FLAGS_SFT ? "SFT" :
		(data->mrw_flags & CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MASK) == CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MR ? "MR" :
		(data->mrw_flags & CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MASK) == CMDQ_DEALLOCATE_KEY_MRW_FLAGS_PMR ? "PMR" :
		(data->mrw_flags & CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MASK) == CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MW_TYPE1 ? "MW_TYPE1" :
		(data->mrw_flags & CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MASK) == CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MW_TYPE2A ? "MW_TYPE2A" :
		(data->mrw_flags & CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MASK) == CMDQ_DEALLOCATE_KEY_MRW_FLAGS_MW_TYPE2B ? "MW_TYPE2B" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_1[0] = 0x%02"PRIX8"\n", data->unused_1[0]);
	RTE_LOG(INFO, PMD, "  unused_1[1] = 0x%02"PRIX8"\n", data->unused_1[1]);
	RTE_LOG(INFO, PMD, "  unused_1[2] = 0x%02"PRIX8"\n", data->unused_1[2]);
	RTE_LOG(INFO, PMD, "          key = 0x%08"PRIX32"\n", data->key);
}

void decode_cmdq_register_mr(const char *string __rte_unused, struct cmdq_register_mr *data) {
	RTE_LOG(INFO, PMD, "cmdq_register_mr\n");
	RTE_LOG(INFO, PMD, "            opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                     Value : %s\n",
		data->opcode == CMDQ_REGISTER_MR_OPCODE_REGISTER_MR ? "REGISTER_MR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "             flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "            cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "         resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "         reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "         resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  log2_pg_size_lvl = 0x%02"PRIX8"\n", data->log2_pg_size_lvl);
	RTE_LOG(INFO, PMD, "            access = 0x%02"PRIX8"\n", data->access);
	RTE_LOG(INFO, PMD, "                     LOCAL_WRITE : %s\n", (data->access & CMDQ_REGISTER_MR_ACCESS_LOCAL_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     REMOTE_READ : %s\n", (data->access & CMDQ_REGISTER_MR_ACCESS_REMOTE_READ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     REMOTE_WRITE : %s\n", (data->access & CMDQ_REGISTER_MR_ACCESS_REMOTE_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     REMOTE_ATOMIC : %s\n", (data->access & CMDQ_REGISTER_MR_ACCESS_REMOTE_ATOMIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     MW_BIND : %s\n", (data->access & CMDQ_REGISTER_MR_ACCESS_MW_BIND)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     ZERO_BASED : %s\n", (data->access & CMDQ_REGISTER_MR_ACCESS_ZERO_BASED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "          unused_1 = 0x%04"PRIX16"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "               key = 0x%08"PRIX32"\n", data->key);
	RTE_LOG(INFO, PMD, "               pbl = 0x%016"PRIX64"\n", data->pbl);
	RTE_LOG(INFO, PMD, "                va = 0x%016"PRIX64"\n", data->va);
	RTE_LOG(INFO, PMD, "           mr_size = 0x%016"PRIX64"\n", data->mr_size);
}

void decode_cmdq_deregister_mr(const char *string __rte_unused, struct cmdq_deregister_mr *data) {
	RTE_LOG(INFO, PMD, "cmdq_deregister_mr\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              DEREGISTER_MR : %s\n", (data->opcode & CMDQ_DEREGISTER_MR_OPCODE_DEREGISTER_MR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "       lkey = 0x%08"PRIX32"\n", data->lkey);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_add_gid(const char *string __rte_unused, struct cmdq_add_gid *data) {
	RTE_LOG(INFO, PMD, "cmdq_add_gid\n");
	RTE_LOG(INFO, PMD, "      opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->opcode == CMDQ_ADD_GID_OPCODE_ADD_GID ? "ADD_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "       flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "      cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "   resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "   reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "   resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      gid[0] = 0x%08"PRIX32"\n", data->gid[0]);
	RTE_LOG(INFO, PMD, "      gid[1] = 0x%08"PRIX32"\n", data->gid[1]);
	RTE_LOG(INFO, PMD, "      gid[2] = 0x%08"PRIX32"\n", data->gid[2]);
	RTE_LOG(INFO, PMD, "      gid[3] = 0x%08"PRIX32"\n", data->gid[3]);
	RTE_LOG(INFO, PMD, "  src_mac[0] = 0x%04"PRIX16"\n", data->src_mac[0]);
	RTE_LOG(INFO, PMD, "  src_mac[1] = 0x%04"PRIX16"\n", data->src_mac[1]);
	RTE_LOG(INFO, PMD, "  src_mac[2] = 0x%04"PRIX16"\n", data->src_mac[2]);
	RTE_LOG(INFO, PMD, "        vlan = 0x%04"PRIX16"\n", data->vlan);
	RTE_LOG(INFO, PMD, "               VLAN_ID = %0*X\n", 13, ((data->vlan & CMDQ_ADD_GID_VLAN_VLAN_ID_MASK) >> CMDQ_ADD_GID_VLAN_VLAN_ID_SFT));
	RTE_LOG(INFO, PMD, "               TPID = %0*X\n", 11, ((data->vlan & CMDQ_ADD_GID_VLAN_TPID_MASK) >> CMDQ_ADD_GID_VLAN_TPID_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_88A8 ? "TPID_TPID_88A8" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_8100 ? "TPID_TPID_8100" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_9100 ? "TPID_TPID_9100" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_9200 ? "TPID_TPID_9200" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_9300 ? "TPID_TPID_9300" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_CFG1 ? "TPID_TPID_CFG1" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_CFG2 ? "TPID_TPID_CFG2" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_TPID_CFG3 ? "TPID_TPID_CFG3" :
		data->vlan == CMDQ_ADD_GID_VLAN_TPID_LAST ? "TPID_LAST" :
		data->vlan == CMDQ_ADD_GID_VLAN_VLAN_EN ? "VLAN_EN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        ipid = 0x%04"PRIX16"\n", data->ipid);
	RTE_LOG(INFO, PMD, "   stats_ctx = 0x%04"PRIX16"\n", data->stats_ctx);
	RTE_LOG(INFO, PMD, "               STATS_CTX_ID = %0*X\n", 14, ((data->stats_ctx & CMDQ_ADD_GID_STATS_CTX_STATS_CTX_ID_MASK) >> CMDQ_ADD_GID_STATS_CTX_STATS_CTX_ID_SFT));
	RTE_LOG(INFO, PMD, "               STATS_CTX_VALID : %s\n", (data->stats_ctx & CMDQ_ADD_GID_STATS_CTX_STATS_CTX_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_delete_gid(const char *string __rte_unused, struct cmdq_delete_gid *data) {
	RTE_LOG(INFO, PMD, "cmdq_delete_gid\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_DELETE_GID_OPCODE_DELETE_GID ? "DELETE_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  gid_index = 0x%04"PRIX16"\n", data->gid_index);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "   unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_cmdq_modify_gid(const char *string __rte_unused, struct cmdq_modify_gid *data) {
	RTE_LOG(INFO, PMD, "cmdq_modify_gid\n");
	RTE_LOG(INFO, PMD, "      opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->opcode == CMDQ_MODIFY_GID_OPCODE_MODIFY_GID ? "MODIFY_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "    cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "       flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "      cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "   resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "   reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "   resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "      gid[0] = 0x%08"PRIX32"\n", data->gid[0]);
	RTE_LOG(INFO, PMD, "      gid[1] = 0x%08"PRIX32"\n", data->gid[1]);
	RTE_LOG(INFO, PMD, "      gid[2] = 0x%08"PRIX32"\n", data->gid[2]);
	RTE_LOG(INFO, PMD, "      gid[3] = 0x%08"PRIX32"\n", data->gid[3]);
	RTE_LOG(INFO, PMD, "  src_mac[0] = 0x%04"PRIX16"\n", data->src_mac[0]);
	RTE_LOG(INFO, PMD, "  src_mac[1] = 0x%04"PRIX16"\n", data->src_mac[1]);
	RTE_LOG(INFO, PMD, "  src_mac[2] = 0x%04"PRIX16"\n", data->src_mac[2]);
	RTE_LOG(INFO, PMD, "        vlan = 0x%04"PRIX16"\n", data->vlan);
	RTE_LOG(INFO, PMD, "               VLAN_ID = %0*X\n", 13, ((data->vlan & CMDQ_MODIFY_GID_VLAN_VLAN_ID_MASK) >> CMDQ_MODIFY_GID_VLAN_VLAN_ID_SFT));
	RTE_LOG(INFO, PMD, "               TPID = %0*X\n", 11, ((data->vlan & CMDQ_MODIFY_GID_VLAN_TPID_MASK) >> CMDQ_MODIFY_GID_VLAN_TPID_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_88A8 ? "TPID_TPID_88A8" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_8100 ? "TPID_TPID_8100" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_9100 ? "TPID_TPID_9100" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_9200 ? "TPID_TPID_9200" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_9300 ? "TPID_TPID_9300" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_CFG1 ? "TPID_TPID_CFG1" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_CFG2 ? "TPID_TPID_CFG2" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_TPID_CFG3 ? "TPID_TPID_CFG3" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_TPID_LAST ? "TPID_LAST" :
		data->vlan == CMDQ_MODIFY_GID_VLAN_VLAN_EN ? "VLAN_EN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        ipid = 0x%04"PRIX16"\n", data->ipid);
	RTE_LOG(INFO, PMD, "   gid_index = 0x%04"PRIX16"\n", data->gid_index);
	RTE_LOG(INFO, PMD, "   stats_ctx = 0x%04"PRIX16"\n", data->stats_ctx);
	RTE_LOG(INFO, PMD, "               STATS_CTX_ID = %0*X\n", 14, ((data->stats_ctx & CMDQ_MODIFY_GID_STATS_CTX_STATS_CTX_ID_MASK) >> CMDQ_MODIFY_GID_STATS_CTX_STATS_CTX_ID_SFT));
	RTE_LOG(INFO, PMD, "               STATS_CTX_VALID : %s\n", (data->stats_ctx & CMDQ_MODIFY_GID_STATS_CTX_STATS_CTX_VALID)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%04"PRIX16"\n", data->unused_0);
}

void decode_cmdq_query_gid(const char *string __rte_unused, struct cmdq_query_gid *data) {
	RTE_LOG(INFO, PMD, "cmdq_query_gid\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_QUERY_GID_OPCODE_QUERY_GID ? "QUERY_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  gid_index = 0x%04"PRIX16"\n", data->gid_index);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "   unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_cmdq_create_qp1(const char *string __rte_unused, struct cmdq_create_qp1 *data) {
	RTE_LOG(INFO, PMD, "cmdq_create_qp1\n");
	RTE_LOG(INFO, PMD, "             opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->opcode == CMDQ_CREATE_QP1_OPCODE_CREATE_QP1 ? "CREATE_QP1" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "              flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "             cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "          resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "          reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "          resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "          qp_handle = 0x%016"PRIX64"\n", data->qp_handle);
	RTE_LOG(INFO, PMD, "           qp_flags = 0x%08"PRIX32"\n", data->qp_flags);
	RTE_LOG(INFO, PMD, "                      SRQ_USED : %s\n", (data->qp_flags & CMDQ_CREATE_QP1_QP_FLAGS_SRQ_USED)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      FORCE_COMPLETION : %s\n", (data->qp_flags & CMDQ_CREATE_QP1_QP_FLAGS_FORCE_COMPLETION)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                      RESERVED_LKEY_ENABLE : %s\n", (data->qp_flags & CMDQ_CREATE_QP1_QP_FLAGS_RESERVED_LKEY_ENABLE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                      GSI : %s\n", (data->type & CMDQ_CREATE_QP1_TYPE_GSI)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  sq_pg_size_sq_lvl = 0x%02"PRIX8"\n", data->sq_pg_size_sq_lvl);
	RTE_LOG(INFO, PMD, "  rq_pg_size_rq_lvl = 0x%02"PRIX8"\n", data->rq_pg_size_rq_lvl);
	RTE_LOG(INFO, PMD, "           unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "                dpi = 0x%08"PRIX32"\n", data->dpi);
	RTE_LOG(INFO, PMD, "            sq_size = 0x%08"PRIX32"\n", data->sq_size);
	RTE_LOG(INFO, PMD, "            rq_size = 0x%08"PRIX32"\n", data->rq_size);
	RTE_LOG(INFO, PMD, "      sq_fwo_sq_sge = 0x%04"PRIX16"\n", data->sq_fwo_sq_sge);
	RTE_LOG(INFO, PMD, "      rq_fwo_rq_sge = 0x%04"PRIX16"\n", data->rq_fwo_rq_sge);
	RTE_LOG(INFO, PMD, "            scq_cid = 0x%08"PRIX32"\n", data->scq_cid);
	RTE_LOG(INFO, PMD, "            rcq_cid = 0x%08"PRIX32"\n", data->rcq_cid);
	RTE_LOG(INFO, PMD, "            srq_cid = 0x%08"PRIX32"\n", data->srq_cid);
	RTE_LOG(INFO, PMD, "              pd_id = 0x%08"PRIX32"\n", data->pd_id);
	RTE_LOG(INFO, PMD, "             sq_pbl = 0x%016"PRIX64"\n", data->sq_pbl);
	RTE_LOG(INFO, PMD, "             rq_pbl = 0x%016"PRIX64"\n", data->rq_pbl);
}

void decode_cmdq_destroy_qp1(const char *string __rte_unused, struct cmdq_destroy_qp1 *data) {
	RTE_LOG(INFO, PMD, "cmdq_destroy_qp1\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_DESTROY_QP1_OPCODE_DESTROY_QP1 ? "DESTROY_QP1" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    qp1_cid = 0x%08"PRIX32"\n", data->qp1_cid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_create_ah(const char *string __rte_unused, struct cmdq_create_ah *data) {
	RTE_LOG(INFO, PMD, "cmdq_create_ah\n");
	RTE_LOG(INFO, PMD, "                   opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                            Value : %s\n",
		data->opcode == CMDQ_CREATE_AH_OPCODE_CREATE_AH ? "CREATE_AH" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                 cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "                    flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                   cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "                resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "                reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "                resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "                ah_handle = 0x%016"PRIX64"\n", data->ah_handle);
	RTE_LOG(INFO, PMD, "                  dgid[0] = 0x%08"PRIX32"\n", data->dgid[0]);
	RTE_LOG(INFO, PMD, "                  dgid[1] = 0x%08"PRIX32"\n", data->dgid[1]);
	RTE_LOG(INFO, PMD, "                  dgid[2] = 0x%08"PRIX32"\n", data->dgid[2]);
	RTE_LOG(INFO, PMD, "                  dgid[3] = 0x%08"PRIX32"\n", data->dgid[3]);
	RTE_LOG(INFO, PMD, "                     type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                            Value : %s\n",
		data->type == CMDQ_CREATE_AH_TYPE_V1 ? "V1" :
		data->type == CMDQ_CREATE_AH_TYPE_V2IPV4 ? "V2IPV4" :
		data->type == CMDQ_CREATE_AH_TYPE_V2IPV6 ? "V2IPV6" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                hop_limit = 0x%02"PRIX8"\n", data->hop_limit);
	RTE_LOG(INFO, PMD, "               sgid_index = 0x%04"PRIX16"\n", data->sgid_index);
	RTE_LOG(INFO, PMD, "  dest_vlan_id_flow_label = 0x%08"PRIX32"\n", data->dest_vlan_id_flow_label);
	RTE_LOG(INFO, PMD, "                    pd_id = 0x%08"PRIX32"\n", data->pd_id);
	RTE_LOG(INFO, PMD, "                 unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "              dest_mac[0] = 0x%04"PRIX16"\n", data->dest_mac[0]);
	RTE_LOG(INFO, PMD, "              dest_mac[1] = 0x%04"PRIX16"\n", data->dest_mac[1]);
	RTE_LOG(INFO, PMD, "              dest_mac[2] = 0x%04"PRIX16"\n", data->dest_mac[2]);
	RTE_LOG(INFO, PMD, "            traffic_class = 0x%02"PRIX8"\n", data->traffic_class);
	RTE_LOG(INFO, PMD, "                 unused_1 = 0x%02"PRIX8"\n", data->unused_1);
}

void decode_cmdq_destroy_ah(const char *string __rte_unused, struct cmdq_destroy_ah *data) {
	RTE_LOG(INFO, PMD, "cmdq_destroy_ah\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_DESTROY_AH_OPCODE_DESTROY_AH ? "DESTROY_AH" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "     ah_cid = 0x%08"PRIX32"\n", data->ah_cid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_initialize_fw(const char *string __rte_unused, struct cmdq_initialize_fw *data) {
	RTE_LOG(INFO, PMD, "cmdq_initialize_fw\n");
	RTE_LOG(INFO, PMD, "               opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                        INITIALIZE_FW : %s\n", (data->opcode & CMDQ_INITIALIZE_FW_OPCODE_INITIALIZE_FW)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "             cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "                flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "               cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "            reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "            resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "  qpc_pg_size_qpc_lvl = 0x%02"PRIX8"\n", data->qpc_pg_size_qpc_lvl);
	RTE_LOG(INFO, PMD, "  mrw_pg_size_mrw_lvl = 0x%02"PRIX8"\n", data->mrw_pg_size_mrw_lvl);
	RTE_LOG(INFO, PMD, "  srq_pg_size_srq_lvl = 0x%02"PRIX8"\n", data->srq_pg_size_srq_lvl);
	RTE_LOG(INFO, PMD, "    cq_pg_size_cq_lvl = 0x%02"PRIX8"\n", data->cq_pg_size_cq_lvl);
	RTE_LOG(INFO, PMD, "  tqm_pg_size_tqm_lvl = 0x%02"PRIX8"\n", data->tqm_pg_size_tqm_lvl);
	RTE_LOG(INFO, PMD, "  tim_pg_size_tim_lvl = 0x%02"PRIX8"\n", data->tim_pg_size_tim_lvl);
	RTE_LOG(INFO, PMD, "           reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "         qpc_page_dir = 0x%016"PRIX64"\n", data->qpc_page_dir);
	RTE_LOG(INFO, PMD, "         mrw_page_dir = 0x%016"PRIX64"\n", data->mrw_page_dir);
	RTE_LOG(INFO, PMD, "         srq_page_dir = 0x%016"PRIX64"\n", data->srq_page_dir);
	RTE_LOG(INFO, PMD, "          cq_page_dir = 0x%016"PRIX64"\n", data->cq_page_dir);
	RTE_LOG(INFO, PMD, "         tqm_page_dir = 0x%016"PRIX64"\n", data->tqm_page_dir);
	RTE_LOG(INFO, PMD, "         tim_page_dir = 0x%016"PRIX64"\n", data->tim_page_dir);
	RTE_LOG(INFO, PMD, "         number_of_qp = 0x%08"PRIX32"\n", data->number_of_qp);
	RTE_LOG(INFO, PMD, "        number_of_mrw = 0x%08"PRIX32"\n", data->number_of_mrw);
	RTE_LOG(INFO, PMD, "        number_of_srq = 0x%08"PRIX32"\n", data->number_of_srq);
	RTE_LOG(INFO, PMD, "         number_of_cq = 0x%08"PRIX32"\n", data->number_of_cq);
	RTE_LOG(INFO, PMD, "        max_qp_per_vf = 0x%08"PRIX32"\n", data->max_qp_per_vf);
	RTE_LOG(INFO, PMD, "       max_mrw_per_vf = 0x%08"PRIX32"\n", data->max_mrw_per_vf);
	RTE_LOG(INFO, PMD, "       max_srq_per_vf = 0x%08"PRIX32"\n", data->max_srq_per_vf);
	RTE_LOG(INFO, PMD, "        max_cq_per_vf = 0x%08"PRIX32"\n", data->max_cq_per_vf);
	RTE_LOG(INFO, PMD, "       max_gid_per_vf = 0x%08"PRIX32"\n", data->max_gid_per_vf);
	RTE_LOG(INFO, PMD, "          stat_ctx_id = 0x%08"PRIX32"\n", data->stat_ctx_id);
}

void decode_cmdq_deinitialize_fw(const char *string __rte_unused, struct cmdq_deinitialize_fw *data) {
	RTE_LOG(INFO, PMD, "cmdq_deinitialize_fw\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_DEINITIALIZE_FW_OPCODE_DEINITIALIZE_FW ? "DEINITIALIZE_FW" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_cmdq_stop_func(const char *string __rte_unused, struct cmdq_stop_func *data) {
	RTE_LOG(INFO, PMD, "cmdq_stop_func\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_STOP_FUNC_OPCODE_STOP_FUNC ? "STOP_FUNC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_cmdq_query_func(const char *string __rte_unused, struct cmdq_query_func *data) {
	RTE_LOG(INFO, PMD, "cmdq_query_func\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_QUERY_FUNC_OPCODE_QUERY_FUNC ? "QUERY_FUNC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_cmdq_set_func_resources(const char *string __rte_unused, struct cmdq_set_func_resources *data) {
	RTE_LOG(INFO, PMD, "cmdq_set_func_resources\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_SET_FUNC_RESOURCES_OPCODE_SET_FUNC_RESOURCES ? "SET_FUNC_RESOURCES" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_cmdq_read_context(const char *string __rte_unused, struct cmdq_read_context *data) {
	RTE_LOG(INFO, PMD, "cmdq_read_context\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_READ_CONTEXT_OPCODE_READ_CONTEXT ? "READ_CONTEXT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "   type_xid = 0x%08"PRIX32"\n", data->type_xid);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_vf_backchannel_request(const char *string __rte_unused, struct cmdq_vf_backchannel_request *data) {
	RTE_LOG(INFO, PMD, "cmdq_vf_backchannel_request\n");
	RTE_LOG(INFO, PMD, "          opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->opcode == CMDQ_VF_BACKCHANNEL_REQUEST_OPCODE_VF_BACKCHANNEL_REQUEST ? "VF_BACKCHANNEL_REQUEST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "           flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "          cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "       resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "       reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "       resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "    command_addr = 0x%016"PRIX64"\n", data->command_addr);
	RTE_LOG(INFO, PMD, "  command_length = 0x%04"PRIX16"\n", data->command_length);
	RTE_LOG(INFO, PMD, "     unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "     unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "     unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_cmdq_read_vf_memory(const char *string __rte_unused, struct cmdq_read_vf_memory *data) {
	RTE_LOG(INFO, PMD, "cmdq_read_vf_memory\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_READ_VF_MEMORY_OPCODE_READ_VF_MEMORY ? "READ_VF_MEMORY" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "       addr = 0x%016"PRIX64"\n", data->addr);
	RTE_LOG(INFO, PMD, "      vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "     length = 0x%04"PRIX16"\n", data->length);
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_complete_vf_request(const char *string __rte_unused, struct cmdq_complete_vf_request *data) {
	RTE_LOG(INFO, PMD, "cmdq_complete_vf_request\n");
	RTE_LOG(INFO, PMD, "       opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->opcode == CMDQ_COMPLETE_VF_REQUEST_OPCODE_COMPLETE_VF_REQUEST ? "COMPLETE_VF_REQUEST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "     cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "        flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "       cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "    resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "    reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "    resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "         addr = 0x%016"PRIX64"\n", data->addr);
	RTE_LOG(INFO, PMD, "      vf_misc = 0x%08"PRIX32"\n", data->vf_misc);
	RTE_LOG(INFO, PMD, "        vf_id = 0x%04"PRIX16"\n", data->vf_id);
	RTE_LOG(INFO, PMD, "    vf_cookie = 0x%04"PRIX16"\n", data->vf_cookie);
	RTE_LOG(INFO, PMD, "    vf_status = 0x%02"PRIX8"\n", data->vf_status);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "  unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "  unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "  unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "  unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

void decode_cmdq_map_tc_to_cos(const char *string __rte_unused, struct cmdq_map_tc_to_cos *data) {
	RTE_LOG(INFO, PMD, "cmdq_map_tc_to_cos\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_MAP_TC_TO_COS_OPCODE_MAP_TC_TO_COS ? "MAP_TC_TO_COS" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "       cos0 = 0x%04"PRIX16"\n", data->cos0);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->cos0 == CMDQ_MAP_TC_TO_COS_COS0_NO_CHANGE ? "NO_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "       cos1 = 0x%04"PRIX16"\n", data->cos1);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->cos1 == CMDQ_MAP_TC_TO_COS_COS1_DISABLE ? "DISABLE" :
		data->cos1 == CMDQ_MAP_TC_TO_COS_COS1_NO_CHANGE ? "NO_CHANGE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_cmdq_query_version(const char *string __rte_unused, struct cmdq_query_version *data) {
	RTE_LOG(INFO, PMD, "cmdq_query_version\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_QUERY_VERSION_OPCODE_QUERY_VERSION ? "QUERY_VERSION" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_cmdq_modify_roce_cc(const char *string __rte_unused, struct cmdq_modify_roce_cc *data) {
	RTE_LOG(INFO, PMD, "cmdq_modify_roce_cc\n");
	RTE_LOG(INFO, PMD, "        opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->opcode == CMDQ_MODIFY_ROCE_CC_OPCODE_MODIFY_ROCE_CC ? "MODIFY_ROCE_CC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "         flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "        cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "     reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "     resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
	RTE_LOG(INFO, PMD, "   modify_mask = 0x%08"PRIX32"\n", data->modify_mask);
	RTE_LOG(INFO, PMD, "                 ENABLE_CC : %s\n", (data->modify_mask & CMDQ_MODIFY_ROCE_CC_MODIFY_MASK_ENABLE_CC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "     enable_cc = 0x%08"PRIX32"\n", data->enable_cc);
	RTE_LOG(INFO, PMD, "    reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "      unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "    reserved64 = 0x%016"PRIX64"\n", data->reserved64);
	RTE_LOG(INFO, PMD, "  reserved64_1 = 0x%016"PRIX64"\n", data->reserved64_1);
}

void decode_cmdq_query_roce_cc(const char *string __rte_unused, struct cmdq_query_roce_cc *data) {
	RTE_LOG(INFO, PMD, "cmdq_query_roce_cc\n");
	RTE_LOG(INFO, PMD, "     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->opcode == CMDQ_QUERY_ROCE_CC_OPCODE_QUERY_ROCE_CC ? "QUERY_ROCE_CC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   cmd_size = 0x%02"PRIX8"\n", data->cmd_size);
	RTE_LOG(INFO, PMD, "      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_creq_base(const char *string __rte_unused, struct creq_base *data) {
	RTE_LOG(INFO, PMD, "creq_base\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_BASE_TYPE_MASK) == CREQ_BASE_TYPE_SFT ? "SFT" :
		(data->type & CREQ_BASE_TYPE_MASK) == CREQ_BASE_TYPE_QP_EVENT ? "QP_EVENT" :
		(data->type & CREQ_BASE_TYPE_MASK) == CREQ_BASE_TYPE_FUNC_EVENT ? "FUNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved56[0] = 0x%02"PRIX8"\n", data->reserved56[0]);
	RTE_LOG(INFO, PMD, "  reserved56[1] = 0x%02"PRIX8"\n", data->reserved56[1]);
	RTE_LOG(INFO, PMD, "  reserved56[2] = 0x%02"PRIX8"\n", data->reserved56[2]);
	RTE_LOG(INFO, PMD, "  reserved56[3] = 0x%02"PRIX8"\n", data->reserved56[3]);
	RTE_LOG(INFO, PMD, "  reserved56[4] = 0x%02"PRIX8"\n", data->reserved56[4]);
	RTE_LOG(INFO, PMD, "  reserved56[5] = 0x%02"PRIX8"\n", data->reserved56[5]);
	RTE_LOG(INFO, PMD, "  reserved56[6] = 0x%02"PRIX8"\n", data->reserved56[6]);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_func_event(const char *string __rte_unused, struct creq_func_event *data) {
	RTE_LOG(INFO, PMD, "creq_func_event\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_FUNC_EVENT_TYPE_MASK) == CREQ_FUNC_EVENT_TYPE_SFT ? "SFT" :
		(data->type & CREQ_FUNC_EVENT_TYPE_MASK) == CREQ_FUNC_EVENT_TYPE_FUNC_EVENT ? "FUNC_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved56[0] = 0x%02"PRIX8"\n", data->reserved56[0]);
	RTE_LOG(INFO, PMD, "  reserved56[1] = 0x%02"PRIX8"\n", data->reserved56[1]);
	RTE_LOG(INFO, PMD, "  reserved56[2] = 0x%02"PRIX8"\n", data->reserved56[2]);
	RTE_LOG(INFO, PMD, "  reserved56[3] = 0x%02"PRIX8"\n", data->reserved56[3]);
	RTE_LOG(INFO, PMD, "  reserved56[4] = 0x%02"PRIX8"\n", data->reserved56[4]);
	RTE_LOG(INFO, PMD, "  reserved56[5] = 0x%02"PRIX8"\n", data->reserved56[5]);
	RTE_LOG(INFO, PMD, "  reserved56[6] = 0x%02"PRIX8"\n", data->reserved56[6]);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_FUNC_EVENT_EVENT_TX_WQE_ERROR ? "TX_WQE_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_TX_DATA_ERROR ? "TX_DATA_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_RX_WQE_ERROR ? "RX_WQE_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_RX_DATA_ERROR ? "RX_DATA_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_CQ_ERROR ? "CQ_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_TQM_ERROR ? "TQM_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_CFCQ_ERROR ? "CFCQ_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_CFCS_ERROR ? "CFCS_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_CFCC_ERROR ? "CFCC_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_CFCM_ERROR ? "CFCM_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_TIM_ERROR ? "TIM_ERROR" :
		data->event == CREQ_FUNC_EVENT_EVENT_VF_COMM_REQUEST ? "VF_COMM_REQUEST" :
		data->event == CREQ_FUNC_EVENT_EVENT_RESOURCE_EXHAUSTED ? "RESOURCE_EXHAUSTED" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_qp_event(const char *string __rte_unused, struct creq_qp_event *data) {
	RTE_LOG(INFO, PMD, "creq_qp_event\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_QP_EVENT_TYPE_MASK) == CREQ_QP_EVENT_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QP_EVENT_TYPE_MASK) == CREQ_QP_EVENT_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_QP_EVENT_EVENT_CREATE_QP ? "CREATE_QP" :
		data->event == CREQ_QP_EVENT_EVENT_DESTROY_QP ? "DESTROY_QP" :
		data->event == CREQ_QP_EVENT_EVENT_MODIFY_QP ? "MODIFY_QP" :
		data->event == CREQ_QP_EVENT_EVENT_QUERY_QP ? "QUERY_QP" :
		data->event == CREQ_QP_EVENT_EVENT_CREATE_SRQ ? "CREATE_SRQ" :
		data->event == CREQ_QP_EVENT_EVENT_DESTROY_SRQ ? "DESTROY_SRQ" :
		data->event == CREQ_QP_EVENT_EVENT_QUERY_SRQ ? "QUERY_SRQ" :
		data->event == CREQ_QP_EVENT_EVENT_CREATE_CQ ? "CREATE_CQ" :
		data->event == CREQ_QP_EVENT_EVENT_DESTROY_CQ ? "DESTROY_CQ" :
		data->event == CREQ_QP_EVENT_EVENT_RESIZE_CQ ? "RESIZE_CQ" :
		data->event == CREQ_QP_EVENT_EVENT_ALLOCATE_MRW ? "ALLOCATE_MRW" :
		data->event == CREQ_QP_EVENT_EVENT_DEALLOCATE_KEY ? "DEALLOCATE_KEY" :
		data->event == CREQ_QP_EVENT_EVENT_REGISTER_MR ? "REGISTER_MR" :
		data->event == CREQ_QP_EVENT_EVENT_DEREGISTER_MR ? "DEREGISTER_MR" :
		data->event == CREQ_QP_EVENT_EVENT_ADD_GID ? "ADD_GID" :
		data->event == CREQ_QP_EVENT_EVENT_DELETE_GID ? "DELETE_GID" :
		data->event == CREQ_QP_EVENT_EVENT_MODIFY_GID ? "MODIFY_GID" :
		data->event == CREQ_QP_EVENT_EVENT_QUERY_GID ? "QUERY_GID" :
		data->event == CREQ_QP_EVENT_EVENT_CREATE_QP1 ? "CREATE_QP1" :
		data->event == CREQ_QP_EVENT_EVENT_DESTROY_QP1 ? "DESTROY_QP1" :
		data->event == CREQ_QP_EVENT_EVENT_CREATE_AH ? "CREATE_AH" :
		data->event == CREQ_QP_EVENT_EVENT_DESTROY_AH ? "DESTROY_AH" :
		data->event == CREQ_QP_EVENT_EVENT_INITIALIZE_FW ? "INITIALIZE_FW" :
		data->event == CREQ_QP_EVENT_EVENT_DEINITIALIZE_FW ? "DEINITIALIZE_FW" :
		data->event == CREQ_QP_EVENT_EVENT_STOP_FUNC ? "STOP_FUNC" :
		data->event == CREQ_QP_EVENT_EVENT_QUERY_FUNC ? "QUERY_FUNC" :
		data->event == CREQ_QP_EVENT_EVENT_SET_FUNC_RESOURCES ? "SET_FUNC_RESOURCES" :
		data->event == CREQ_QP_EVENT_EVENT_MAP_TC_TO_COS ? "MAP_TC_TO_COS" :
		data->event == CREQ_QP_EVENT_EVENT_QUERY_VERSION ? "QUERY_VERSION" :
		data->event == CREQ_QP_EVENT_EVENT_MODIFY_ROCE_CC ? "MODIFY_ROCE_CC" :
		data->event == CREQ_QP_EVENT_EVENT_QUERY_ROCE_CC ? "QUERY_ROCE_CC" :
		data->event == CREQ_QP_EVENT_EVENT_QP_ERROR_NOTIFICATION ? "QP_ERROR_NOTIFICATION" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_create_qp_resp(const char *string __rte_unused, struct creq_create_qp_resp *data) {
	RTE_LOG(INFO, PMD, "creq_create_qp_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_CREATE_QP_RESP_TYPE_MASK) == CREQ_CREATE_QP_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_CREATE_QP_RESP_TYPE_MASK) == CREQ_CREATE_QP_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  CREATE_QP : %s\n", (data->event & CREQ_CREATE_QP_RESP_EVENT_CREATE_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_destroy_qp_resp(const char *string __rte_unused, struct creq_destroy_qp_resp *data) {
	RTE_LOG(INFO, PMD, "creq_destroy_qp_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_DESTROY_QP_RESP_TYPE_MASK) == CREQ_DESTROY_QP_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DESTROY_QP_RESP_TYPE_MASK) == CREQ_DESTROY_QP_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  DESTROY_QP : %s\n", (data->event & CREQ_DESTROY_QP_RESP_EVENT_DESTROY_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_modify_qp_resp(const char *string __rte_unused, struct creq_modify_qp_resp *data) {
	RTE_LOG(INFO, PMD, "creq_modify_qp_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_MODIFY_QP_RESP_TYPE_MASK) == CREQ_MODIFY_QP_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_MODIFY_QP_RESP_TYPE_MASK) == CREQ_MODIFY_QP_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_MODIFY_QP_RESP_EVENT_MODIFY_QP ? "MODIFY_QP" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_qp_resp(const char *string __rte_unused, struct creq_query_qp_resp *data) {
	RTE_LOG(INFO, PMD, "creq_query_qp_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_QUERY_QP_RESP_TYPE_MASK) == CREQ_QUERY_QP_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QUERY_QP_RESP_TYPE_MASK) == CREQ_QUERY_QP_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "           size = 0x%08"PRIX32"\n", data->size);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  QUERY_QP : %s\n", (data->event & CREQ_QUERY_QP_RESP_EVENT_QUERY_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_qp_resp_sb(const char *string __rte_unused, struct creq_query_qp_resp_sb *data) {
	RTE_LOG(INFO, PMD, "creq_query_qp_resp_sb\n");
	RTE_LOG(INFO, PMD, "                     opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                              QUERY_QP : %s\n", (data->opcode & CREQ_QUERY_QP_RESP_SB_OPCODE_QUERY_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                     status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "                     cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "                      flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "                  resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "                  reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "                        xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "  en_sqd_async_notify_state = 0x%02"PRIX8"\n", data->en_sqd_async_notify_state);
	RTE_LOG(INFO, PMD, "                     access = 0x%02"PRIX8"\n", data->access);
	RTE_LOG(INFO, PMD, "                              LOCAL_WRITE : %s\n", (data->access & CREQ_QUERY_QP_RESP_SB_ACCESS_LOCAL_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                              REMOTE_WRITE : %s\n", (data->access & CREQ_QUERY_QP_RESP_SB_ACCESS_REMOTE_WRITE)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                              REMOTE_READ : %s\n", (data->access & CREQ_QUERY_QP_RESP_SB_ACCESS_REMOTE_READ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                              REMOTE_ATOMIC : %s\n", (data->access & CREQ_QUERY_QP_RESP_SB_ACCESS_REMOTE_ATOMIC)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                       pkey = 0x%04"PRIX16"\n", data->pkey);
	RTE_LOG(INFO, PMD, "                       qkey = 0x%08"PRIX32"\n", data->qkey);
	RTE_LOG(INFO, PMD, "                 reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "                    dgid[0] = 0x%08"PRIX32"\n", data->dgid[0]);
	RTE_LOG(INFO, PMD, "                    dgid[1] = 0x%08"PRIX32"\n", data->dgid[1]);
	RTE_LOG(INFO, PMD, "                    dgid[2] = 0x%08"PRIX32"\n", data->dgid[2]);
	RTE_LOG(INFO, PMD, "                    dgid[3] = 0x%08"PRIX32"\n", data->dgid[3]);
	RTE_LOG(INFO, PMD, "                 flow_label = 0x%08"PRIX32"\n", data->flow_label);
	RTE_LOG(INFO, PMD, "                 sgid_index = 0x%04"PRIX16"\n", data->sgid_index);
	RTE_LOG(INFO, PMD, "                  hop_limit = 0x%02"PRIX8"\n", data->hop_limit);
	RTE_LOG(INFO, PMD, "              traffic_class = 0x%02"PRIX8"\n", data->traffic_class);
	RTE_LOG(INFO, PMD, "                dest_mac[0] = 0x%04"PRIX16"\n", data->dest_mac[0]);
	RTE_LOG(INFO, PMD, "                dest_mac[1] = 0x%04"PRIX16"\n", data->dest_mac[1]);
	RTE_LOG(INFO, PMD, "                dest_mac[2] = 0x%04"PRIX16"\n", data->dest_mac[2]);
	RTE_LOG(INFO, PMD, "      path_mtu_dest_vlan_id = 0x%04"PRIX16"\n", data->path_mtu_dest_vlan_id);
	RTE_LOG(INFO, PMD, "                    timeout = 0x%02"PRIX8"\n", data->timeout);
	RTE_LOG(INFO, PMD, "                  retry_cnt = 0x%02"PRIX8"\n", data->retry_cnt);
	RTE_LOG(INFO, PMD, "                  rnr_retry = 0x%02"PRIX8"\n", data->rnr_retry);
	RTE_LOG(INFO, PMD, "              min_rnr_timer = 0x%02"PRIX8"\n", data->min_rnr_timer);
	RTE_LOG(INFO, PMD, "                     rq_psn = 0x%08"PRIX32"\n", data->rq_psn);
	RTE_LOG(INFO, PMD, "                     sq_psn = 0x%08"PRIX32"\n", data->sq_psn);
	RTE_LOG(INFO, PMD, "              max_rd_atomic = 0x%02"PRIX8"\n", data->max_rd_atomic);
	RTE_LOG(INFO, PMD, "         max_dest_rd_atomic = 0x%02"PRIX8"\n", data->max_dest_rd_atomic);
	RTE_LOG(INFO, PMD, "                    tos_ecn = 0x%04"PRIX16"\n", data->tos_ecn);
	RTE_LOG(INFO, PMD, "                              Value : %s\n",
		(data->tos_ecn & CREQ_QUERY_QP_RESP_SB_TOS_ECN_MASK) == CREQ_QUERY_QP_RESP_SB_TOS_ECN_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                    sq_size = 0x%08"PRIX32"\n", data->sq_size);
	RTE_LOG(INFO, PMD, "                    rq_size = 0x%08"PRIX32"\n", data->rq_size);
	RTE_LOG(INFO, PMD, "                     sq_sge = 0x%04"PRIX16"\n", data->sq_sge);
	RTE_LOG(INFO, PMD, "                     rq_sge = 0x%04"PRIX16"\n", data->rq_sge);
	RTE_LOG(INFO, PMD, "            max_inline_data = 0x%08"PRIX32"\n", data->max_inline_data);
	RTE_LOG(INFO, PMD, "                 dest_qp_id = 0x%08"PRIX32"\n", data->dest_qp_id);
	RTE_LOG(INFO, PMD, "                   unused_1 = 0x%08"PRIX32"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "                 src_mac[0] = 0x%04"PRIX16"\n", data->src_mac[0]);
	RTE_LOG(INFO, PMD, "                 src_mac[1] = 0x%04"PRIX16"\n", data->src_mac[1]);
	RTE_LOG(INFO, PMD, "                 src_mac[2] = 0x%04"PRIX16"\n", data->src_mac[2]);
	RTE_LOG(INFO, PMD, "  vlan_pcp_vlan_dei_vlan_id = 0x%04"PRIX16"\n", data->vlan_pcp_vlan_dei_vlan_id);
}

void decode_creq_create_srq_resp(const char *string __rte_unused, struct creq_create_srq_resp *data) {
	RTE_LOG(INFO, PMD, "creq_create_srq_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_CREATE_SRQ_RESP_TYPE_MASK) == CREQ_CREATE_SRQ_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_CREATE_SRQ_RESP_TYPE_MASK) == CREQ_CREATE_SRQ_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_CREATE_SRQ_RESP_EVENT_CREATE_SRQ ? "CREATE_SRQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_destroy_srq_resp(const char *string __rte_unused, struct creq_destroy_srq_resp *data) {
	RTE_LOG(INFO, PMD, "creq_destroy_srq_resp\n");
	RTE_LOG(INFO, PMD, "               type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		(data->type & CREQ_DESTROY_SRQ_RESP_TYPE_MASK) == CREQ_DESTROY_SRQ_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DESTROY_SRQ_RESP_TYPE_MASK) == CREQ_DESTROY_SRQ_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "             cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "                xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "                  v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "              event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->event == CREQ_DESTROY_SRQ_RESP_EVENT_DESTROY_SRQ ? "DESTROY_SRQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  enable_for_arm[0] = 0x%04"PRIX16"\n", data->enable_for_arm[0]);
	RTE_LOG(INFO, PMD, "                      SFT : %s\n", (data->enable_for_arm[0] & CREQ_DESTROY_SRQ_RESP_ENABLE_FOR_ARM_SFT)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  enable_for_arm[1] = 0x%04"PRIX16"\n", data->enable_for_arm[1]);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		(data->enable_for_arm[1] & CREQ_DESTROY_SRQ_RESP_ENABLE_FOR_ARM_MASK) == CREQ_DESTROY_SRQ_RESP_ENABLE_FOR_ARM_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  enable_for_arm[2] = 0x%04"PRIX16"\n", data->enable_for_arm[2]);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		(data->enable_for_arm[2] & CREQ_DESTROY_SRQ_RESP_ENABLE_FOR_ARM_MASK) == CREQ_DESTROY_SRQ_RESP_ENABLE_FOR_ARM_SFT ? "SFT" :
		"Unknown");
}

void decode_creq_query_srq_resp(const char *string __rte_unused, struct creq_query_srq_resp *data) {
	RTE_LOG(INFO, PMD, "creq_query_srq_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_QUERY_SRQ_RESP_TYPE_MASK) == CREQ_QUERY_SRQ_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QUERY_SRQ_RESP_TYPE_MASK) == CREQ_QUERY_SRQ_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "           size = 0x%08"PRIX32"\n", data->size);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  QUERY_SRQ : %s\n", (data->event & CREQ_QUERY_SRQ_RESP_EVENT_QUERY_SRQ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_srq_resp_sb(const char *string __rte_unused, struct creq_query_srq_resp_sb *data) {
	RTE_LOG(INFO, PMD, "creq_query_srq_resp_sb\n");
	RTE_LOG(INFO, PMD, "      opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "               QUERY_SRQ : %s\n", (data->opcode & CREQ_QUERY_SRQ_RESP_SB_OPCODE_QUERY_SRQ)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "      status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "      cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "       flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "   resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "   reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "         xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "   srq_limit = 0x%04"PRIX16"\n", data->srq_limit);
	RTE_LOG(INFO, PMD, "  reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "     data[0] = 0x%08"PRIX32"\n", data->data[0]);
	RTE_LOG(INFO, PMD, "     data[1] = 0x%08"PRIX32"\n", data->data[1]);
	RTE_LOG(INFO, PMD, "     data[2] = 0x%08"PRIX32"\n", data->data[2]);
	RTE_LOG(INFO, PMD, "     data[3] = 0x%08"PRIX32"\n", data->data[3]);
}

void decode_creq_create_cq_resp(const char *string __rte_unused, struct creq_create_cq_resp *data) {
	RTE_LOG(INFO, PMD, "creq_create_cq_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_CREATE_CQ_RESP_TYPE_MASK) == CREQ_CREATE_CQ_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_CREATE_CQ_RESP_TYPE_MASK) == CREQ_CREATE_CQ_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_CREATE_CQ_RESP_EVENT_CREATE_CQ ? "CREATE_CQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_destroy_cq_resp(const char *string __rte_unused, struct creq_destroy_cq_resp *data) {
	RTE_LOG(INFO, PMD, "creq_destroy_cq_resp\n");
	RTE_LOG(INFO, PMD, "              type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                     Value : %s\n",
		(data->type & CREQ_DESTROY_CQ_RESP_TYPE_MASK) == CREQ_DESTROY_CQ_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DESTROY_CQ_RESP_TYPE_MASK) == CREQ_DESTROY_CQ_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "            status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "            cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "               xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "                 v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "             event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                     Value : %s\n",
		data->event == CREQ_DESTROY_CQ_RESP_EVENT_DESTROY_CQ ? "DESTROY_CQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        cq_arm_lvl = 0x%04"PRIX16"\n", data->cq_arm_lvl);
	RTE_LOG(INFO, PMD, "                     Value : %s\n",
		(data->cq_arm_lvl & CREQ_DESTROY_CQ_RESP_CQ_ARM_LVL_MASK) == CREQ_DESTROY_CQ_RESP_CQ_ARM_LVL_SFT ? "SFT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  total_cnq_events = 0x%04"PRIX16"\n", data->total_cnq_events);
	RTE_LOG(INFO, PMD, "        reserved16 = 0x%04"PRIX16"\n", data->reserved16);
}

void decode_creq_resize_cq_resp(const char *string __rte_unused, struct creq_resize_cq_resp *data) {
	RTE_LOG(INFO, PMD, "creq_resize_cq_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_RESIZE_CQ_RESP_TYPE_MASK) == CREQ_RESIZE_CQ_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_RESIZE_CQ_RESP_TYPE_MASK) == CREQ_RESIZE_CQ_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_RESIZE_CQ_RESP_EVENT_RESIZE_CQ ? "RESIZE_CQ" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_allocate_mrw_resp(const char *string __rte_unused, struct creq_allocate_mrw_resp *data) {
	RTE_LOG(INFO, PMD, "creq_allocate_mrw_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_ALLOCATE_MRW_RESP_TYPE_MASK) == CREQ_ALLOCATE_MRW_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_ALLOCATE_MRW_RESP_TYPE_MASK) == CREQ_ALLOCATE_MRW_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_ALLOCATE_MRW_RESP_EVENT_ALLOCATE_MRW ? "ALLOCATE_MRW" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_deallocate_key_resp(const char *string __rte_unused, struct creq_deallocate_key_resp *data) {
	RTE_LOG(INFO, PMD, "creq_deallocate_key_resp\n");
	RTE_LOG(INFO, PMD, "               type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		(data->type & CREQ_DEALLOCATE_KEY_RESP_TYPE_MASK) == CREQ_DEALLOCATE_KEY_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DEALLOCATE_KEY_RESP_TYPE_MASK) == CREQ_DEALLOCATE_KEY_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "             status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "             cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "                xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "                  v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "              event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->event == CREQ_DEALLOCATE_KEY_RESP_EVENT_DEALLOCATE_KEY ? "DEALLOCATE_KEY" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "  bound_window_info = 0x%08"PRIX32"\n", data->bound_window_info);
}

void decode_creq_register_mr_resp(const char *string __rte_unused, struct creq_register_mr_resp *data) {
	RTE_LOG(INFO, PMD, "creq_register_mr_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_REGISTER_MR_RESP_TYPE_MASK) == CREQ_REGISTER_MR_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_REGISTER_MR_RESP_TYPE_MASK) == CREQ_REGISTER_MR_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_REGISTER_MR_RESP_EVENT_REGISTER_MR ? "REGISTER_MR" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_deregister_mr_resp(const char *string __rte_unused, struct creq_deregister_mr_resp *data) {
	RTE_LOG(INFO, PMD, "creq_deregister_mr_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_DEREGISTER_MR_RESP_TYPE_MASK) == CREQ_DEREGISTER_MR_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DEREGISTER_MR_RESP_TYPE_MASK) == CREQ_DEREGISTER_MR_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  DEREGISTER_MR : %s\n", (data->event & CREQ_DEREGISTER_MR_RESP_EVENT_DEREGISTER_MR)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "     reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "  bound_windows = 0x%08"PRIX32"\n", data->bound_windows);
}

void decode_creq_add_gid_resp(const char *string __rte_unused, struct creq_add_gid_resp *data) {
	RTE_LOG(INFO, PMD, "creq_add_gid_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_ADD_GID_RESP_TYPE_MASK) == CREQ_ADD_GID_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_ADD_GID_RESP_TYPE_MASK) == CREQ_ADD_GID_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_ADD_GID_RESP_EVENT_ADD_GID ? "ADD_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_delete_gid_resp(const char *string __rte_unused, struct creq_delete_gid_resp *data) {
	RTE_LOG(INFO, PMD, "creq_delete_gid_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_DELETE_GID_RESP_TYPE_MASK) == CREQ_DELETE_GID_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DELETE_GID_RESP_TYPE_MASK) == CREQ_DELETE_GID_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_DELETE_GID_RESP_EVENT_DELETE_GID ? "DELETE_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_modify_gid_resp(const char *string __rte_unused, struct creq_modify_gid_resp *data) {
	RTE_LOG(INFO, PMD, "creq_modify_gid_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_MODIFY_GID_RESP_TYPE_MASK) == CREQ_MODIFY_GID_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_MODIFY_GID_RESP_TYPE_MASK) == CREQ_MODIFY_GID_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_MODIFY_GID_RESP_EVENT_ADD_GID ? "ADD_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_gid_resp(const char *string __rte_unused, struct creq_query_gid_resp *data) {
	RTE_LOG(INFO, PMD, "creq_query_gid_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_QUERY_GID_RESP_TYPE_MASK) == CREQ_QUERY_GID_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QUERY_GID_RESP_TYPE_MASK) == CREQ_QUERY_GID_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "           size = 0x%08"PRIX32"\n", data->size);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_QUERY_GID_RESP_EVENT_QUERY_GID ? "QUERY_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_gid_resp_sb(const char *string __rte_unused, struct creq_query_gid_resp_sb *data) {
	RTE_LOG(INFO, PMD, "creq_query_gid_resp_sb\n");
	RTE_LOG(INFO, PMD, "      opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->opcode == CREQ_QUERY_GID_RESP_SB_OPCODE_QUERY_GID ? "QUERY_GID" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "      cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "       flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "   resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "   reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "      gid[0] = 0x%08"PRIX32"\n", data->gid[0]);
	RTE_LOG(INFO, PMD, "      gid[1] = 0x%08"PRIX32"\n", data->gid[1]);
	RTE_LOG(INFO, PMD, "      gid[2] = 0x%08"PRIX32"\n", data->gid[2]);
	RTE_LOG(INFO, PMD, "      gid[3] = 0x%08"PRIX32"\n", data->gid[3]);
	RTE_LOG(INFO, PMD, "  src_mac[0] = 0x%04"PRIX16"\n", data->src_mac[0]);
	RTE_LOG(INFO, PMD, "  src_mac[1] = 0x%04"PRIX16"\n", data->src_mac[1]);
	RTE_LOG(INFO, PMD, "  src_mac[2] = 0x%04"PRIX16"\n", data->src_mac[2]);
	RTE_LOG(INFO, PMD, "        vlan = 0x%04"PRIX16"\n", data->vlan);
	RTE_LOG(INFO, PMD, "               VLAN_ID = %0*X\n", 13, ((data->vlan & CREQ_QUERY_GID_RESP_SB_VLAN_VLAN_ID_MASK) >> CREQ_QUERY_GID_RESP_SB_VLAN_VLAN_ID_SFT));
	RTE_LOG(INFO, PMD, "               TPID = %0*X\n", 11, ((data->vlan & CREQ_QUERY_GID_RESP_SB_VLAN_TPID_MASK) >> CREQ_QUERY_GID_RESP_SB_VLAN_TPID_SFT));
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_88A8 ? "TPID_TPID_88A8" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_8100 ? "TPID_TPID_8100" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_9100 ? "TPID_TPID_9100" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_9200 ? "TPID_TPID_9200" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_9300 ? "TPID_TPID_9300" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_CFG1 ? "TPID_TPID_CFG1" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_CFG2 ? "TPID_TPID_CFG2" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_TPID_CFG3 ? "TPID_TPID_CFG3" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_TPID_LAST ? "TPID_LAST" :
		data->vlan == CREQ_QUERY_GID_RESP_SB_VLAN_VLAN_EN ? "VLAN_EN" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        ipid = 0x%04"PRIX16"\n", data->ipid);
	RTE_LOG(INFO, PMD, "   gid_index = 0x%04"PRIX16"\n", data->gid_index);
	RTE_LOG(INFO, PMD, "    unused_0 = 0x%08"PRIX32"\n", data->unused_0);
}

void decode_creq_create_qp1_resp(const char *string __rte_unused, struct creq_create_qp1_resp *data) {
	RTE_LOG(INFO, PMD, "creq_create_qp1_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_CREATE_QP1_RESP_TYPE_MASK) == CREQ_CREATE_QP1_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_CREATE_QP1_RESP_TYPE_MASK) == CREQ_CREATE_QP1_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_CREATE_QP1_RESP_EVENT_CREATE_QP1 ? "CREATE_QP1" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_destroy_qp1_resp(const char *string __rte_unused, struct creq_destroy_qp1_resp *data) {
	RTE_LOG(INFO, PMD, "creq_destroy_qp1_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_DESTROY_QP1_RESP_TYPE_MASK) == CREQ_DESTROY_QP1_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DESTROY_QP1_RESP_TYPE_MASK) == CREQ_DESTROY_QP1_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_DESTROY_QP1_RESP_EVENT_DESTROY_QP1 ? "DESTROY_QP1" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_create_ah_resp(const char *string __rte_unused, struct creq_create_ah_resp *data) {
	RTE_LOG(INFO, PMD, "creq_create_ah_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_CREATE_AH_RESP_TYPE_MASK) == CREQ_CREATE_AH_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_CREATE_AH_RESP_TYPE_MASK) == CREQ_CREATE_AH_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_CREATE_AH_RESP_EVENT_CREATE_AH ? "CREATE_AH" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_destroy_ah_resp(const char *string __rte_unused, struct creq_destroy_ah_resp *data) {
	RTE_LOG(INFO, PMD, "creq_destroy_ah_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_DESTROY_AH_RESP_TYPE_MASK) == CREQ_DESTROY_AH_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DESTROY_AH_RESP_TYPE_MASK) == CREQ_DESTROY_AH_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "            xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_DESTROY_AH_RESP_EVENT_DESTROY_AH ? "DESTROY_AH" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_initialize_fw_resp(const char *string __rte_unused, struct creq_initialize_fw_resp *data) {
	RTE_LOG(INFO, PMD, "creq_initialize_fw_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_INITIALIZE_FW_RESP_TYPE_MASK) == CREQ_INITIALIZE_FW_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_INITIALIZE_FW_RESP_TYPE_MASK) == CREQ_INITIALIZE_FW_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  INITIALIZE_FW : %s\n", (data->event & CREQ_INITIALIZE_FW_RESP_EVENT_INITIALIZE_FW)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_deinitialize_fw_resp(const char *string __rte_unused, struct creq_deinitialize_fw_resp *data) {
	RTE_LOG(INFO, PMD, "creq_deinitialize_fw_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_DEINITIALIZE_FW_RESP_TYPE_MASK) == CREQ_DEINITIALIZE_FW_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_DEINITIALIZE_FW_RESP_TYPE_MASK) == CREQ_DEINITIALIZE_FW_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_DEINITIALIZE_FW_RESP_EVENT_DEINITIALIZE_FW ? "DEINITIALIZE_FW" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_stop_func_resp(const char *string __rte_unused, struct creq_stop_func_resp *data) {
	RTE_LOG(INFO, PMD, "creq_stop_func_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_STOP_FUNC_RESP_TYPE_MASK) == CREQ_STOP_FUNC_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_STOP_FUNC_RESP_TYPE_MASK) == CREQ_STOP_FUNC_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_STOP_FUNC_RESP_EVENT_STOP_FUNC ? "STOP_FUNC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_func_resp(const char *string __rte_unused, struct creq_query_func_resp *data) {
	RTE_LOG(INFO, PMD, "creq_query_func_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_QUERY_FUNC_RESP_TYPE_MASK) == CREQ_QUERY_FUNC_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QUERY_FUNC_RESP_TYPE_MASK) == CREQ_QUERY_FUNC_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "           size = 0x%08"PRIX32"\n", data->size);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_QUERY_FUNC_RESP_EVENT_QUERY_FUNC ? "QUERY_FUNC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_func_resp_sb(const char *string __rte_unused, struct creq_query_func_resp_sb *data) {
	RTE_LOG(INFO, PMD, "creq_query_func_resp_sb\n");
	RTE_LOG(INFO, PMD, "               opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                        Value : %s\n",
		data->opcode == CREQ_QUERY_FUNC_RESP_SB_OPCODE_QUERY_FUNC ? "QUERY_FUNC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "               status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "               cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "                flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "            resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "            reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "          max_mr_size = 0x%016"PRIX64"\n", data->max_mr_size);
	RTE_LOG(INFO, PMD, "               max_qp = 0x%08"PRIX32"\n", data->max_qp);
	RTE_LOG(INFO, PMD, "            max_qp_wr = 0x%04"PRIX16"\n", data->max_qp_wr);
	RTE_LOG(INFO, PMD, "        dev_cap_flags = 0x%04"PRIX16"\n", data->dev_cap_flags);
	RTE_LOG(INFO, PMD, "                        RESIZE_QP : %s\n", (data->dev_cap_flags & CREQ_QUERY_FUNC_RESP_SB_DEV_CAP_FLAGS_RESIZE_QP)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "               max_cq = 0x%08"PRIX32"\n", data->max_cq);
	RTE_LOG(INFO, PMD, "              max_cqe = 0x%08"PRIX32"\n", data->max_cqe);
	RTE_LOG(INFO, PMD, "               max_pd = 0x%08"PRIX32"\n", data->max_pd);
	RTE_LOG(INFO, PMD, "              max_sge = 0x%02"PRIX8"\n", data->max_sge);
	RTE_LOG(INFO, PMD, "          max_srq_sge = 0x%02"PRIX8"\n", data->max_srq_sge);
	RTE_LOG(INFO, PMD, "       max_qp_rd_atom = 0x%02"PRIX8"\n", data->max_qp_rd_atom);
	RTE_LOG(INFO, PMD, "  max_qp_init_rd_atom = 0x%02"PRIX8"\n", data->max_qp_init_rd_atom);
	RTE_LOG(INFO, PMD, "               max_mr = 0x%08"PRIX32"\n", data->max_mr);
	RTE_LOG(INFO, PMD, "               max_mw = 0x%08"PRIX32"\n", data->max_mw);
	RTE_LOG(INFO, PMD, "       max_raw_eth_qp = 0x%08"PRIX32"\n", data->max_raw_eth_qp);
	RTE_LOG(INFO, PMD, "               max_ah = 0x%08"PRIX32"\n", data->max_ah);
	RTE_LOG(INFO, PMD, "              max_fmr = 0x%08"PRIX32"\n", data->max_fmr);
	RTE_LOG(INFO, PMD, "           max_srq_wr = 0x%08"PRIX32"\n", data->max_srq_wr);
	RTE_LOG(INFO, PMD, "            max_pkeys = 0x%08"PRIX32"\n", data->max_pkeys);
	RTE_LOG(INFO, PMD, "      max_inline_data = 0x%08"PRIX32"\n", data->max_inline_data);
	RTE_LOG(INFO, PMD, "      max_map_per_fmr = 0x%02"PRIX8"\n", data->max_map_per_fmr);
	RTE_LOG(INFO, PMD, "     l2_db_space_size = 0x%02"PRIX8"\n", data->l2_db_space_size);
	RTE_LOG(INFO, PMD, "              max_srq = 0x%04"PRIX16"\n", data->max_srq);
	RTE_LOG(INFO, PMD, "              max_gid = 0x%08"PRIX32"\n", data->max_gid);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[0] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[0]);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[1] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[1]);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[2] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[2]);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[3] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[3]);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[4] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[4]);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[5] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[5]);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[6] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[6]);
	RTE_LOG(INFO, PMD, "    tqm_alloc_reqs[7] = 0x%08"PRIX32"\n", data->tqm_alloc_reqs[7]);
}

void decode_creq_set_func_resources_resp(const char *string __rte_unused, struct creq_set_func_resources_resp *data) {
	RTE_LOG(INFO, PMD, "creq_set_func_resources_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_SET_FUNC_RESOURCES_RESP_TYPE_MASK) == CREQ_SET_FUNC_RESOURCES_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_SET_FUNC_RESOURCES_RESP_TYPE_MASK) == CREQ_SET_FUNC_RESOURCES_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_SET_FUNC_RESOURCES_RESP_EVENT_SET_FUNC_RESOURCES ? "SET_FUNC_RESOURCES" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_map_tc_to_cos_resp(const char *string __rte_unused, struct creq_map_tc_to_cos_resp *data) {
	RTE_LOG(INFO, PMD, "creq_map_tc_to_cos_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_MAP_TC_TO_COS_RESP_TYPE_MASK) == CREQ_MAP_TC_TO_COS_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_MAP_TC_TO_COS_RESP_TYPE_MASK) == CREQ_MAP_TC_TO_COS_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_MAP_TC_TO_COS_RESP_EVENT_MAP_TC_TO_COS ? "MAP_TC_TO_COS" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_version_resp(const char *string __rte_unused, struct creq_query_version_resp *data) {
	RTE_LOG(INFO, PMD, "creq_query_version_resp\n");
	RTE_LOG(INFO, PMD, "        type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		(data->type & CREQ_QUERY_VERSION_RESP_TYPE_MASK) == CREQ_QUERY_VERSION_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QUERY_VERSION_RESP_TYPE_MASK) == CREQ_QUERY_VERSION_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "      status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "      cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "      fw_maj = 0x%02"PRIX8"\n", data->fw_maj);
	RTE_LOG(INFO, PMD, "    fw_minor = 0x%02"PRIX8"\n", data->fw_minor);
	RTE_LOG(INFO, PMD, "      fw_bld = 0x%02"PRIX8"\n", data->fw_bld);
	RTE_LOG(INFO, PMD, "     fw_rsvd = 0x%02"PRIX8"\n", data->fw_rsvd);
	RTE_LOG(INFO, PMD, "           v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "       event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "               Value : %s\n",
		data->event == CREQ_QUERY_VERSION_RESP_EVENT_QUERY_VERSION ? "QUERY_VERSION" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved16 = 0x%04"PRIX16"\n", data->reserved16);
	RTE_LOG(INFO, PMD, "    intf_maj = 0x%02"PRIX8"\n", data->intf_maj);
	RTE_LOG(INFO, PMD, "  intf_minor = 0x%02"PRIX8"\n", data->intf_minor);
	RTE_LOG(INFO, PMD, "    intf_bld = 0x%02"PRIX8"\n", data->intf_bld);
	RTE_LOG(INFO, PMD, "   intf_rsvd = 0x%02"PRIX8"\n", data->intf_rsvd);
}

void decode_creq_modify_roce_cc_resp(const char *string __rte_unused, struct creq_modify_roce_cc_resp *data) {
	RTE_LOG(INFO, PMD, "creq_modify_roce_cc_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_MODIFY_ROCE_CC_RESP_TYPE_MASK) == CREQ_MODIFY_ROCE_CC_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_MODIFY_ROCE_CC_RESP_TYPE_MASK) == CREQ_MODIFY_ROCE_CC_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "     reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_MODIFY_ROCE_CC_RESP_EVENT_MODIFY_ROCE_CC ? "MODIFY_ROCE_CC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_roce_cc_resp(const char *string __rte_unused, struct creq_query_roce_cc_resp *data) {
	RTE_LOG(INFO, PMD, "creq_query_roce_cc_resp\n");
	RTE_LOG(INFO, PMD, "           type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		(data->type & CREQ_QUERY_ROCE_CC_RESP_TYPE_MASK) == CREQ_QUERY_ROCE_CC_RESP_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QUERY_ROCE_CC_RESP_TYPE_MASK) == CREQ_QUERY_ROCE_CC_RESP_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "         status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "         cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "           size = 0x%08"PRIX32"\n", data->size);
	RTE_LOG(INFO, PMD, "              v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "          event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->event == CREQ_QUERY_ROCE_CC_RESP_EVENT_QUERY_ROCE_CC ? "QUERY_ROCE_CC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  reserved48[0] = 0x%04"PRIX16"\n", data->reserved48[0]);
	RTE_LOG(INFO, PMD, "  reserved48[1] = 0x%04"PRIX16"\n", data->reserved48[1]);
	RTE_LOG(INFO, PMD, "  reserved48[2] = 0x%04"PRIX16"\n", data->reserved48[2]);
}

void decode_creq_query_roce_cc_resp_sb(const char *string __rte_unused, struct creq_query_roce_cc_resp_sb *data) {
	RTE_LOG(INFO, PMD, "creq_query_roce_cc_resp_sb\n");
	RTE_LOG(INFO, PMD, "        opcode = 0x%02"PRIX8"\n", data->opcode);
	RTE_LOG(INFO, PMD, "                 Value : %s\n",
		data->opcode == CREQ_QUERY_ROCE_CC_RESP_SB_OPCODE_QUERY_ROCE_CC ? "QUERY_ROCE_CC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "        cookie = 0x%04"PRIX16"\n", data->cookie);
	RTE_LOG(INFO, PMD, "         flags = 0x%04"PRIX16"\n", data->flags);
	RTE_LOG(INFO, PMD, "     resp_size = 0x%02"PRIX8"\n", data->resp_size);
	RTE_LOG(INFO, PMD, "     reserved8 = 0x%02"PRIX8"\n", data->reserved8);
	RTE_LOG(INFO, PMD, "     enable_cc = 0x%08"PRIX32"\n", data->enable_cc);
	RTE_LOG(INFO, PMD, "    reserved32 = 0x%08"PRIX32"\n", data->reserved32);
	RTE_LOG(INFO, PMD, "    reserved64 = 0x%016"PRIX64"\n", data->reserved64);
	RTE_LOG(INFO, PMD, "  reserved64_1 = 0x%016"PRIX64"\n", data->reserved64_1);
}

void decode_creq_qp_error_notification(const char *string __rte_unused, struct creq_qp_error_notification *data) {
	RTE_LOG(INFO, PMD, "creq_qp_error_notification\n");
	RTE_LOG(INFO, PMD, "                  type = 0x%02"PRIX8"\n", data->type);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		(data->type & CREQ_QP_ERROR_NOTIFICATION_TYPE_MASK) == CREQ_QP_ERROR_NOTIFICATION_TYPE_SFT ? "SFT" :
		(data->type & CREQ_QP_ERROR_NOTIFICATION_TYPE_MASK) == CREQ_QP_ERROR_NOTIFICATION_TYPE_QP_EVENT ? "QP_EVENT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                status = 0x%02"PRIX8"\n", data->status);
	RTE_LOG(INFO, PMD, "   req_slow_path_state = 0x%02"PRIX8"\n", data->req_slow_path_state);
	RTE_LOG(INFO, PMD, "  req_err_state_reason = 0x%02"PRIX8"\n", data->req_err_state_reason);
	RTE_LOG(INFO, PMD, "                   xid = 0x%08"PRIX32"\n", data->xid);
	RTE_LOG(INFO, PMD, "                     v = 0x%02"PRIX8"\n", data->v);
	RTE_LOG(INFO, PMD, "                 event = 0x%02"PRIX8"\n", data->event);
	RTE_LOG(INFO, PMD, "                         Value : %s\n",
		data->event == CREQ_QP_ERROR_NOTIFICATION_EVENT_QP_ERROR_NOTIFICATION ? "QP_ERROR_NOTIFICATION" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   res_slow_path_state = 0x%02"PRIX8"\n", data->res_slow_path_state);
	RTE_LOG(INFO, PMD, "  res_err_state_reason = 0x%02"PRIX8"\n", data->res_err_state_reason);
	RTE_LOG(INFO, PMD, "           sq_cons_idx = 0x%04"PRIX16"\n", data->sq_cons_idx);
	RTE_LOG(INFO, PMD, "           rq_cons_idx = 0x%04"PRIX16"\n", data->rq_cons_idx);
}

void decode_input(const char *string __rte_unused, struct input *data) {
	RTE_LOG(INFO, PMD, "input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  cmpl_ring = 0x%04"PRIX16"\n", data->cmpl_ring);
	RTE_LOG(INFO, PMD, "     seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "  target_id = 0x%04"PRIX16"\n", data->target_id);
	RTE_LOG(INFO, PMD, "  resp_addr = 0x%016"PRIX64"\n", data->resp_addr);
}

void decode_output(const char *string __rte_unused, struct output *data) {
	RTE_LOG(INFO, PMD, "output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
}

void decode_hwrm_short_input(const char *string __rte_unused, struct hwrm_short_input *data) {
	RTE_LOG(INFO, PMD, "hwrm_short_input\n");
	RTE_LOG(INFO, PMD, "   req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  signature = 0x%04"PRIX16"\n", data->signature);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->signature == HWRM_SHORT_INPUT_SIGNATURE_SHORT_CMD ? "SHORT_CMD" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%04"PRIX16"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       size = 0x%04"PRIX16"\n", data->size);
	RTE_LOG(INFO, PMD, "   req_addr = 0x%016"PRIX64"\n", data->req_addr);
}

void decode_cmd_nums(const char *string __rte_unused, struct cmd_nums *data) {
	RTE_LOG(INFO, PMD, "cmd_nums\n");
	RTE_LOG(INFO, PMD, "     req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_ret_codes(const char *string __rte_unused, struct ret_codes *data) {
	RTE_LOG(INFO, PMD, "ret_codes\n");
	RTE_LOG(INFO, PMD, "   error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_err_output(const char *string __rte_unused, struct hwrm_err_output *data) {
	RTE_LOG(INFO, PMD, "hwrm_err_output\n");
	RTE_LOG(INFO, PMD, "  error_code = 0x%04"PRIX16"\n", data->error_code);
	RTE_LOG(INFO, PMD, "    req_type = 0x%04"PRIX16"\n", data->req_type);
	RTE_LOG(INFO, PMD, "      seq_id = 0x%04"PRIX16"\n", data->seq_id);
	RTE_LOG(INFO, PMD, "    resp_len = 0x%04"PRIX16"\n", data->resp_len);
	RTE_LOG(INFO, PMD, "    opaque_0 = 0x%08"PRIX32"\n", data->opaque_0);
	RTE_LOG(INFO, PMD, "    opaque_1 = 0x%04"PRIX16"\n", data->opaque_1);
	RTE_LOG(INFO, PMD, "     cmd_err = 0x%02"PRIX8"\n", data->cmd_err);
	RTE_LOG(INFO, PMD, "       valid = 0x%02"PRIX8"\n", data->valid);
}

void decode_tx_port_stats(const char *string __rte_unused, struct tx_port_stats *data) {
	RTE_LOG(INFO, PMD, "tx_port_stats\n");
	RTE_LOG(INFO, PMD, "             tx_64b_frames = 0x%016"PRIX64"\n", data->tx_64b_frames);
	RTE_LOG(INFO, PMD, "        tx_65b_127b_frames = 0x%016"PRIX64"\n", data->tx_65b_127b_frames);
	RTE_LOG(INFO, PMD, "       tx_128b_255b_frames = 0x%016"PRIX64"\n", data->tx_128b_255b_frames);
	RTE_LOG(INFO, PMD, "       tx_256b_511b_frames = 0x%016"PRIX64"\n", data->tx_256b_511b_frames);
	RTE_LOG(INFO, PMD, "      tx_512b_1023b_frames = 0x%016"PRIX64"\n", data->tx_512b_1023b_frames);
	RTE_LOG(INFO, PMD, "      tx_1024b_1518_frames = 0x%016"PRIX64"\n", data->tx_1024b_1518_frames);
	RTE_LOG(INFO, PMD, "       tx_good_vlan_frames = 0x%016"PRIX64"\n", data->tx_good_vlan_frames);
	RTE_LOG(INFO, PMD, "      tx_1519b_2047_frames = 0x%016"PRIX64"\n", data->tx_1519b_2047_frames);
	RTE_LOG(INFO, PMD, "     tx_2048b_4095b_frames = 0x%016"PRIX64"\n", data->tx_2048b_4095b_frames);
	RTE_LOG(INFO, PMD, "     tx_4096b_9216b_frames = 0x%016"PRIX64"\n", data->tx_4096b_9216b_frames);
	RTE_LOG(INFO, PMD, "    tx_9217b_16383b_frames = 0x%016"PRIX64"\n", data->tx_9217b_16383b_frames);
	RTE_LOG(INFO, PMD, "            tx_good_frames = 0x%016"PRIX64"\n", data->tx_good_frames);
	RTE_LOG(INFO, PMD, "           tx_total_frames = 0x%016"PRIX64"\n", data->tx_total_frames);
	RTE_LOG(INFO, PMD, "           tx_ucast_frames = 0x%016"PRIX64"\n", data->tx_ucast_frames);
	RTE_LOG(INFO, PMD, "           tx_mcast_frames = 0x%016"PRIX64"\n", data->tx_mcast_frames);
	RTE_LOG(INFO, PMD, "           tx_bcast_frames = 0x%016"PRIX64"\n", data->tx_bcast_frames);
	RTE_LOG(INFO, PMD, "           tx_pause_frames = 0x%016"PRIX64"\n", data->tx_pause_frames);
	RTE_LOG(INFO, PMD, "             tx_pfc_frames = 0x%016"PRIX64"\n", data->tx_pfc_frames);
	RTE_LOG(INFO, PMD, "          tx_jabber_frames = 0x%016"PRIX64"\n", data->tx_jabber_frames);
	RTE_LOG(INFO, PMD, "         tx_fcs_err_frames = 0x%016"PRIX64"\n", data->tx_fcs_err_frames);
	RTE_LOG(INFO, PMD, "         tx_control_frames = 0x%016"PRIX64"\n", data->tx_control_frames);
	RTE_LOG(INFO, PMD, "          tx_oversz_frames = 0x%016"PRIX64"\n", data->tx_oversz_frames);
	RTE_LOG(INFO, PMD, "     tx_single_dfrl_frames = 0x%016"PRIX64"\n", data->tx_single_dfrl_frames);
	RTE_LOG(INFO, PMD, "      tx_multi_dfrl_frames = 0x%016"PRIX64"\n", data->tx_multi_dfrl_frames);
	RTE_LOG(INFO, PMD, "     tx_single_coll_frames = 0x%016"PRIX64"\n", data->tx_single_coll_frames);
	RTE_LOG(INFO, PMD, "      tx_multi_coll_frames = 0x%016"PRIX64"\n", data->tx_multi_coll_frames);
	RTE_LOG(INFO, PMD, "       tx_late_coll_frames = 0x%016"PRIX64"\n", data->tx_late_coll_frames);
	RTE_LOG(INFO, PMD, "  tx_excessive_coll_frames = 0x%016"PRIX64"\n", data->tx_excessive_coll_frames);
	RTE_LOG(INFO, PMD, "            tx_frag_frames = 0x%016"PRIX64"\n", data->tx_frag_frames);
	RTE_LOG(INFO, PMD, "                    tx_err = 0x%016"PRIX64"\n", data->tx_err);
	RTE_LOG(INFO, PMD, "          tx_tagged_frames = 0x%016"PRIX64"\n", data->tx_tagged_frames);
	RTE_LOG(INFO, PMD, "      tx_dbl_tagged_frames = 0x%016"PRIX64"\n", data->tx_dbl_tagged_frames);
	RTE_LOG(INFO, PMD, "            tx_runt_frames = 0x%016"PRIX64"\n", data->tx_runt_frames);
	RTE_LOG(INFO, PMD, "         tx_fifo_underruns = 0x%016"PRIX64"\n", data->tx_fifo_underruns);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri0 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri0);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri1 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri1);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri2 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri2);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri3 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri3);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri4 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri4);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri5 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri5);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri6 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri6);
	RTE_LOG(INFO, PMD, "    tx_pfc_ena_frames_pri7 = 0x%016"PRIX64"\n", data->tx_pfc_ena_frames_pri7);
	RTE_LOG(INFO, PMD, "         tx_eee_lpi_events = 0x%016"PRIX64"\n", data->tx_eee_lpi_events);
	RTE_LOG(INFO, PMD, "       tx_eee_lpi_duration = 0x%016"PRIX64"\n", data->tx_eee_lpi_duration);
	RTE_LOG(INFO, PMD, "      tx_llfc_logical_msgs = 0x%016"PRIX64"\n", data->tx_llfc_logical_msgs);
	RTE_LOG(INFO, PMD, "              tx_hcfc_msgs = 0x%016"PRIX64"\n", data->tx_hcfc_msgs);
	RTE_LOG(INFO, PMD, "       tx_total_collisions = 0x%016"PRIX64"\n", data->tx_total_collisions);
	RTE_LOG(INFO, PMD, "                  tx_bytes = 0x%016"PRIX64"\n", data->tx_bytes);
	RTE_LOG(INFO, PMD, "           tx_xthol_frames = 0x%016"PRIX64"\n", data->tx_xthol_frames);
	RTE_LOG(INFO, PMD, "           tx_stat_discard = 0x%016"PRIX64"\n", data->tx_stat_discard);
	RTE_LOG(INFO, PMD, "             tx_stat_error = 0x%016"PRIX64"\n", data->tx_stat_error);
}

void decode_rx_port_stats(const char *string __rte_unused, struct rx_port_stats *data) {
	RTE_LOG(INFO, PMD, "rx_port_stats\n");
	RTE_LOG(INFO, PMD, "                      rx_64b_frames = 0x%016"PRIX64"\n", data->rx_64b_frames);
	RTE_LOG(INFO, PMD, "                 rx_65b_127b_frames = 0x%016"PRIX64"\n", data->rx_65b_127b_frames);
	RTE_LOG(INFO, PMD, "                rx_128b_255b_frames = 0x%016"PRIX64"\n", data->rx_128b_255b_frames);
	RTE_LOG(INFO, PMD, "                rx_256b_511b_frames = 0x%016"PRIX64"\n", data->rx_256b_511b_frames);
	RTE_LOG(INFO, PMD, "               rx_512b_1023b_frames = 0x%016"PRIX64"\n", data->rx_512b_1023b_frames);
	RTE_LOG(INFO, PMD, "               rx_1024b_1518_frames = 0x%016"PRIX64"\n", data->rx_1024b_1518_frames);
	RTE_LOG(INFO, PMD, "                rx_good_vlan_frames = 0x%016"PRIX64"\n", data->rx_good_vlan_frames);
	RTE_LOG(INFO, PMD, "              rx_1519b_2047b_frames = 0x%016"PRIX64"\n", data->rx_1519b_2047b_frames);
	RTE_LOG(INFO, PMD, "              rx_2048b_4095b_frames = 0x%016"PRIX64"\n", data->rx_2048b_4095b_frames);
	RTE_LOG(INFO, PMD, "              rx_4096b_9216b_frames = 0x%016"PRIX64"\n", data->rx_4096b_9216b_frames);
	RTE_LOG(INFO, PMD, "             rx_9217b_16383b_frames = 0x%016"PRIX64"\n", data->rx_9217b_16383b_frames);
	RTE_LOG(INFO, PMD, "                    rx_total_frames = 0x%016"PRIX64"\n", data->rx_total_frames);
	RTE_LOG(INFO, PMD, "                    rx_ucast_frames = 0x%016"PRIX64"\n", data->rx_ucast_frames);
	RTE_LOG(INFO, PMD, "                    rx_mcast_frames = 0x%016"PRIX64"\n", data->rx_mcast_frames);
	RTE_LOG(INFO, PMD, "                    rx_bcast_frames = 0x%016"PRIX64"\n", data->rx_bcast_frames);
	RTE_LOG(INFO, PMD, "                  rx_fcs_err_frames = 0x%016"PRIX64"\n", data->rx_fcs_err_frames);
	RTE_LOG(INFO, PMD, "                     rx_ctrl_frames = 0x%016"PRIX64"\n", data->rx_ctrl_frames);
	RTE_LOG(INFO, PMD, "                    rx_pause_frames = 0x%016"PRIX64"\n", data->rx_pause_frames);
	RTE_LOG(INFO, PMD, "                      rx_pfc_frames = 0x%016"PRIX64"\n", data->rx_pfc_frames);
	RTE_LOG(INFO, PMD, "       rx_unsupported_opcode_frames = 0x%016"PRIX64"\n", data->rx_unsupported_opcode_frames);
	RTE_LOG(INFO, PMD, "  rx_unsupported_da_pausepfc_frames = 0x%016"PRIX64"\n", data->rx_unsupported_da_pausepfc_frames);
	RTE_LOG(INFO, PMD, "                 rx_wrong_sa_frames = 0x%016"PRIX64"\n", data->rx_wrong_sa_frames);
	RTE_LOG(INFO, PMD, "                rx_align_err_frames = 0x%016"PRIX64"\n", data->rx_align_err_frames);
	RTE_LOG(INFO, PMD, "                  rx_oor_len_frames = 0x%016"PRIX64"\n", data->rx_oor_len_frames);
	RTE_LOG(INFO, PMD, "                 rx_code_err_frames = 0x%016"PRIX64"\n", data->rx_code_err_frames);
	RTE_LOG(INFO, PMD, "            rx_false_carrier_frames = 0x%016"PRIX64"\n", data->rx_false_carrier_frames);
	RTE_LOG(INFO, PMD, "                    rx_ovrsz_frames = 0x%016"PRIX64"\n", data->rx_ovrsz_frames);
	RTE_LOG(INFO, PMD, "                      rx_jbr_frames = 0x%016"PRIX64"\n", data->rx_jbr_frames);
	RTE_LOG(INFO, PMD, "                  rx_mtu_err_frames = 0x%016"PRIX64"\n", data->rx_mtu_err_frames);
	RTE_LOG(INFO, PMD, "                rx_match_crc_frames = 0x%016"PRIX64"\n", data->rx_match_crc_frames);
	RTE_LOG(INFO, PMD, "              rx_promiscuous_frames = 0x%016"PRIX64"\n", data->rx_promiscuous_frames);
	RTE_LOG(INFO, PMD, "                   rx_tagged_frames = 0x%016"PRIX64"\n", data->rx_tagged_frames);
	RTE_LOG(INFO, PMD, "            rx_double_tagged_frames = 0x%016"PRIX64"\n", data->rx_double_tagged_frames);
	RTE_LOG(INFO, PMD, "                    rx_trunc_frames = 0x%016"PRIX64"\n", data->rx_trunc_frames);
	RTE_LOG(INFO, PMD, "                     rx_good_frames = 0x%016"PRIX64"\n", data->rx_good_frames);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri0 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri0);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri1 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri1);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri2 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri2);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri3 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri3);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri4 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri4);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri5 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri5);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri6 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri6);
	RTE_LOG(INFO, PMD, "        rx_pfc_xon2xoff_frames_pri7 = 0x%016"PRIX64"\n", data->rx_pfc_xon2xoff_frames_pri7);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri0 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri0);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri1 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri1);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri2 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri2);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri3 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri3);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri4 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri4);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri5 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri5);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri6 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri6);
	RTE_LOG(INFO, PMD, "             rx_pfc_ena_frames_pri7 = 0x%016"PRIX64"\n", data->rx_pfc_ena_frames_pri7);
	RTE_LOG(INFO, PMD, "              rx_sch_crc_err_frames = 0x%016"PRIX64"\n", data->rx_sch_crc_err_frames);
	RTE_LOG(INFO, PMD, "                   rx_undrsz_frames = 0x%016"PRIX64"\n", data->rx_undrsz_frames);
	RTE_LOG(INFO, PMD, "                     rx_frag_frames = 0x%016"PRIX64"\n", data->rx_frag_frames);
	RTE_LOG(INFO, PMD, "                  rx_eee_lpi_events = 0x%016"PRIX64"\n", data->rx_eee_lpi_events);
	RTE_LOG(INFO, PMD, "                rx_eee_lpi_duration = 0x%016"PRIX64"\n", data->rx_eee_lpi_duration);
	RTE_LOG(INFO, PMD, "              rx_llfc_physical_msgs = 0x%016"PRIX64"\n", data->rx_llfc_physical_msgs);
	RTE_LOG(INFO, PMD, "               rx_llfc_logical_msgs = 0x%016"PRIX64"\n", data->rx_llfc_logical_msgs);
	RTE_LOG(INFO, PMD, "          rx_llfc_msgs_with_crc_err = 0x%016"PRIX64"\n", data->rx_llfc_msgs_with_crc_err);
	RTE_LOG(INFO, PMD, "                       rx_hcfc_msgs = 0x%016"PRIX64"\n", data->rx_hcfc_msgs);
	RTE_LOG(INFO, PMD, "          rx_hcfc_msgs_with_crc_err = 0x%016"PRIX64"\n", data->rx_hcfc_msgs_with_crc_err);
	RTE_LOG(INFO, PMD, "                           rx_bytes = 0x%016"PRIX64"\n", data->rx_bytes);
	RTE_LOG(INFO, PMD, "                      rx_runt_bytes = 0x%016"PRIX64"\n", data->rx_runt_bytes);
	RTE_LOG(INFO, PMD, "                     rx_runt_frames = 0x%016"PRIX64"\n", data->rx_runt_frames);
	RTE_LOG(INFO, PMD, "                    rx_stat_discard = 0x%016"PRIX64"\n", data->rx_stat_discard);
	RTE_LOG(INFO, PMD, "                        rx_stat_err = 0x%016"PRIX64"\n", data->rx_stat_err);
}

void decode_ctx_hw_stats64(const char *string __rte_unused, struct ctx_hw_stats64 *data) {
	RTE_LOG(INFO, PMD, "ctx_hw_stats64\n");
	RTE_LOG(INFO, PMD, "    rx_ucast_pkts = 0x%016"PRIX64"\n", data->rx_ucast_pkts);
	RTE_LOG(INFO, PMD, "    rx_mcast_pkts = 0x%016"PRIX64"\n", data->rx_mcast_pkts);
	RTE_LOG(INFO, PMD, "    rx_bcast_pkts = 0x%016"PRIX64"\n", data->rx_bcast_pkts);
	RTE_LOG(INFO, PMD, "     rx_drop_pkts = 0x%016"PRIX64"\n", data->rx_drop_pkts);
	RTE_LOG(INFO, PMD, "  rx_discard_pkts = 0x%016"PRIX64"\n", data->rx_discard_pkts);
	RTE_LOG(INFO, PMD, "   rx_ucast_bytes = 0x%016"PRIX64"\n", data->rx_ucast_bytes);
	RTE_LOG(INFO, PMD, "   rx_mcast_bytes = 0x%016"PRIX64"\n", data->rx_mcast_bytes);
	RTE_LOG(INFO, PMD, "   rx_bcast_bytes = 0x%016"PRIX64"\n", data->rx_bcast_bytes);
	RTE_LOG(INFO, PMD, "    tx_ucast_pkts = 0x%016"PRIX64"\n", data->tx_ucast_pkts);
	RTE_LOG(INFO, PMD, "    tx_mcast_pkts = 0x%016"PRIX64"\n", data->tx_mcast_pkts);
	RTE_LOG(INFO, PMD, "    tx_bcast_pkts = 0x%016"PRIX64"\n", data->tx_bcast_pkts);
	RTE_LOG(INFO, PMD, "     tx_drop_pkts = 0x%016"PRIX64"\n", data->tx_drop_pkts);
	RTE_LOG(INFO, PMD, "  tx_discard_pkts = 0x%016"PRIX64"\n", data->tx_discard_pkts);
	RTE_LOG(INFO, PMD, "   tx_ucast_bytes = 0x%016"PRIX64"\n", data->tx_ucast_bytes);
	RTE_LOG(INFO, PMD, "   tx_mcast_bytes = 0x%016"PRIX64"\n", data->tx_mcast_bytes);
	RTE_LOG(INFO, PMD, "   tx_bcast_bytes = 0x%016"PRIX64"\n", data->tx_bcast_bytes);
	RTE_LOG(INFO, PMD, "         tpa_pkts = 0x%016"PRIX64"\n", data->tpa_pkts);
	RTE_LOG(INFO, PMD, "        tpa_bytes = 0x%016"PRIX64"\n", data->tpa_bytes);
	RTE_LOG(INFO, PMD, "       tpa_events = 0x%016"PRIX64"\n", data->tpa_events);
	RTE_LOG(INFO, PMD, "       tpa_aborts = 0x%016"PRIX64"\n", data->tpa_aborts);
}

void decode_ctx_hw_stats(const char *string __rte_unused, struct ctx_hw_stats *data) {
	RTE_LOG(INFO, PMD, "ctx_hw_stats\n");
	RTE_LOG(INFO, PMD, "    rx_ucast_pkts = 0x%016"PRIX64"\n", data->rx_ucast_pkts);
	RTE_LOG(INFO, PMD, "    rx_mcast_pkts = 0x%016"PRIX64"\n", data->rx_mcast_pkts);
	RTE_LOG(INFO, PMD, "    rx_bcast_pkts = 0x%016"PRIX64"\n", data->rx_bcast_pkts);
	RTE_LOG(INFO, PMD, "  rx_discard_pkts = 0x%016"PRIX64"\n", data->rx_discard_pkts);
	RTE_LOG(INFO, PMD, "     rx_drop_pkts = 0x%016"PRIX64"\n", data->rx_drop_pkts);
	RTE_LOG(INFO, PMD, "   rx_ucast_bytes = 0x%016"PRIX64"\n", data->rx_ucast_bytes);
	RTE_LOG(INFO, PMD, "   rx_mcast_bytes = 0x%016"PRIX64"\n", data->rx_mcast_bytes);
	RTE_LOG(INFO, PMD, "   rx_bcast_bytes = 0x%016"PRIX64"\n", data->rx_bcast_bytes);
	RTE_LOG(INFO, PMD, "    tx_ucast_pkts = 0x%016"PRIX64"\n", data->tx_ucast_pkts);
	RTE_LOG(INFO, PMD, "    tx_mcast_pkts = 0x%016"PRIX64"\n", data->tx_mcast_pkts);
	RTE_LOG(INFO, PMD, "    tx_bcast_pkts = 0x%016"PRIX64"\n", data->tx_bcast_pkts);
	RTE_LOG(INFO, PMD, "  tx_discard_pkts = 0x%016"PRIX64"\n", data->tx_discard_pkts);
	RTE_LOG(INFO, PMD, "     tx_drop_pkts = 0x%016"PRIX64"\n", data->tx_drop_pkts);
	RTE_LOG(INFO, PMD, "   tx_ucast_bytes = 0x%016"PRIX64"\n", data->tx_ucast_bytes);
	RTE_LOG(INFO, PMD, "   tx_mcast_bytes = 0x%016"PRIX64"\n", data->tx_mcast_bytes);
	RTE_LOG(INFO, PMD, "   tx_bcast_bytes = 0x%016"PRIX64"\n", data->tx_bcast_bytes);
	RTE_LOG(INFO, PMD, "         tpa_pkts = 0x%016"PRIX64"\n", data->tpa_pkts);
	RTE_LOG(INFO, PMD, "        tpa_bytes = 0x%016"PRIX64"\n", data->tpa_bytes);
	RTE_LOG(INFO, PMD, "       tpa_events = 0x%016"PRIX64"\n", data->tpa_events);
	RTE_LOG(INFO, PMD, "       tpa_aborts = 0x%016"PRIX64"\n", data->tpa_aborts);
}

void decode_hwrm_struct_hdr(const char *string __rte_unused, struct hwrm_struct_hdr *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_hdr\n");
	RTE_LOG(INFO, PMD, "    struct_id = 0x%04"PRIX16"\n", data->struct_id);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_LLDP_CFG ? "LLDP_CFG" :
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_DCBX_ETS ? "DCBX_ETS" :
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_DCBX_PFC ? "DCBX_PFC" :
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_DCBX_APP ? "DCBX_APP" :
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_DCBX_FEATURE_STATE ? "DCBX_FEATURE_STATE" :
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_LLDP_GENERIC ? "LLDP_GENERIC" :
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_LLDP_DEVICE ? "LLDP_DEVICE" :
		data->struct_id == HWRM_STRUCT_HDR_STRUCT_ID_PORT_DESCRIPTION ? "PORT_DESCRIPTION" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          len = 0x%04"PRIX16"\n", data->len);
	RTE_LOG(INFO, PMD, "      version = 0x%02"PRIX8"\n", data->version);
	RTE_LOG(INFO, PMD, "        count = 0x%02"PRIX8"\n", data->count);
	RTE_LOG(INFO, PMD, "      subtype = 0x%04"PRIX16"\n", data->subtype);
	RTE_LOG(INFO, PMD, "  next_offset = 0x%04"PRIX16"\n", data->next_offset);
	RTE_LOG(INFO, PMD, "                Value : %s\n",
		data->next_offset == HWRM_STRUCT_HDR_NEXT_OFFSET_LAST ? "LAST" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%04"PRIX16"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%04"PRIX16"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%04"PRIX16"\n", data->unused_0[2]);
}

void decode_hwrm_struct_data_dcbx_ets(const char *string __rte_unused, struct hwrm_struct_data_dcbx_ets *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_dcbx_ets\n");
	RTE_LOG(INFO, PMD, "     destination = 0x%02"PRIX8"\n", data->destination);
	RTE_LOG(INFO, PMD, "                   CONFIGURATION : %s\n", (data->destination & HWRM_STRUCT_DATA_DCBX_ETS_DESTINATION_CONFIGURATION)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "                   RECOMMMENDATION : %s\n", (data->destination & HWRM_STRUCT_DATA_DCBX_ETS_DESTINATION_RECOMMMENDATION)?"ON":"OFF");
	RTE_LOG(INFO, PMD, "         max_tcs = 0x%02"PRIX8"\n", data->max_tcs);
	RTE_LOG(INFO, PMD, "        unused_0 = 0x%04"PRIX16"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  pri0_to_tc_map = 0x%02"PRIX8"\n", data->pri0_to_tc_map);
	RTE_LOG(INFO, PMD, "  pri1_to_tc_map = 0x%02"PRIX8"\n", data->pri1_to_tc_map);
	RTE_LOG(INFO, PMD, "  pri2_to_tc_map = 0x%02"PRIX8"\n", data->pri2_to_tc_map);
	RTE_LOG(INFO, PMD, "  pri3_to_tc_map = 0x%02"PRIX8"\n", data->pri3_to_tc_map);
	RTE_LOG(INFO, PMD, "  pri4_to_tc_map = 0x%02"PRIX8"\n", data->pri4_to_tc_map);
	RTE_LOG(INFO, PMD, "  pri5_to_tc_map = 0x%02"PRIX8"\n", data->pri5_to_tc_map);
	RTE_LOG(INFO, PMD, "  pri6_to_tc_map = 0x%02"PRIX8"\n", data->pri6_to_tc_map);
	RTE_LOG(INFO, PMD, "  pri7_to_tc_map = 0x%02"PRIX8"\n", data->pri7_to_tc_map);
	RTE_LOG(INFO, PMD, "   tc0_to_bw_map = 0x%02"PRIX8"\n", data->tc0_to_bw_map);
	RTE_LOG(INFO, PMD, "   tc1_to_bw_map = 0x%02"PRIX8"\n", data->tc1_to_bw_map);
	RTE_LOG(INFO, PMD, "   tc2_to_bw_map = 0x%02"PRIX8"\n", data->tc2_to_bw_map);
	RTE_LOG(INFO, PMD, "   tc3_to_bw_map = 0x%02"PRIX8"\n", data->tc3_to_bw_map);
	RTE_LOG(INFO, PMD, "   tc4_to_bw_map = 0x%02"PRIX8"\n", data->tc4_to_bw_map);
	RTE_LOG(INFO, PMD, "   tc5_to_bw_map = 0x%02"PRIX8"\n", data->tc5_to_bw_map);
	RTE_LOG(INFO, PMD, "   tc6_to_bw_map = 0x%02"PRIX8"\n", data->tc6_to_bw_map);
	RTE_LOG(INFO, PMD, "   tc7_to_bw_map = 0x%02"PRIX8"\n", data->tc7_to_bw_map);
	RTE_LOG(INFO, PMD, "  tc0_to_tsa_map = 0x%02"PRIX8"\n", data->tc0_to_tsa_map);
	RTE_LOG(INFO, PMD, "                   Value : %s\n",
		data->tc0_to_tsa_map == HWRM_STRUCT_DATA_DCBX_ETS_TC0_TO_TSA_MAP_TSA_TYPE_SP ? "TSA_TYPE_SP" :
		data->tc0_to_tsa_map == HWRM_STRUCT_DATA_DCBX_ETS_TC0_TO_TSA_MAP_TSA_TYPE_CBS ? "TSA_TYPE_CBS" :
		data->tc0_to_tsa_map == HWRM_STRUCT_DATA_DCBX_ETS_TC0_TO_TSA_MAP_TSA_TYPE_ETS ? "TSA_TYPE_ETS" :
		data->tc0_to_tsa_map == HWRM_STRUCT_DATA_DCBX_ETS_TC0_TO_TSA_MAP_TSA_TYPE_VENDOR_SPECIFIC ? "TSA_TYPE_VENDOR_SPECIFIC" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  tc1_to_tsa_map = 0x%02"PRIX8"\n", data->tc1_to_tsa_map);
	RTE_LOG(INFO, PMD, "  tc2_to_tsa_map = 0x%02"PRIX8"\n", data->tc2_to_tsa_map);
	RTE_LOG(INFO, PMD, "  tc3_to_tsa_map = 0x%02"PRIX8"\n", data->tc3_to_tsa_map);
	RTE_LOG(INFO, PMD, "  tc4_to_tsa_map = 0x%02"PRIX8"\n", data->tc4_to_tsa_map);
	RTE_LOG(INFO, PMD, "  tc5_to_tsa_map = 0x%02"PRIX8"\n", data->tc5_to_tsa_map);
	RTE_LOG(INFO, PMD, "  tc6_to_tsa_map = 0x%02"PRIX8"\n", data->tc6_to_tsa_map);
	RTE_LOG(INFO, PMD, "  tc7_to_tsa_map = 0x%02"PRIX8"\n", data->tc7_to_tsa_map);
	RTE_LOG(INFO, PMD, "        unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_struct_data_dcbx_pfc(const char *string __rte_unused, struct hwrm_struct_data_dcbx_pfc *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_dcbx_pfc\n");
	RTE_LOG(INFO, PMD, "  pfc_priority_bitmap = 0x%02"PRIX8"\n", data->pfc_priority_bitmap);
	RTE_LOG(INFO, PMD, "          max_pfc_tcs = 0x%02"PRIX8"\n", data->max_pfc_tcs);
	RTE_LOG(INFO, PMD, "                  mbc = 0x%02"PRIX8"\n", data->mbc);
	RTE_LOG(INFO, PMD, "          unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "          unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "          unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "          unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "          unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
}

void decode_hwrm_struct_data_dcbx_app(const char *string __rte_unused, struct hwrm_struct_data_dcbx_app *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_dcbx_app\n");
	RTE_LOG(INFO, PMD, "        protocol_id = 0x%04"PRIX16"\n", data->protocol_id);
	RTE_LOG(INFO, PMD, "  protocol_selector = 0x%02"PRIX8"\n", data->protocol_selector);
	RTE_LOG(INFO, PMD, "                      Value : %s\n",
		data->protocol_selector == HWRM_STRUCT_DATA_DCBX_APP_PROTOCOL_SELECTOR_ETHER_TYPE ? "ETHER_TYPE" :
		data->protocol_selector == HWRM_STRUCT_DATA_DCBX_APP_PROTOCOL_SELECTOR_TCP_PORT ? "TCP_PORT" :
		data->protocol_selector == HWRM_STRUCT_DATA_DCBX_APP_PROTOCOL_SELECTOR_UDP_PORT ? "UDP_PORT" :
		data->protocol_selector == HWRM_STRUCT_DATA_DCBX_APP_PROTOCOL_SELECTOR_TCP_UDP_PORT ? "TCP_UDP_PORT" :
		"Unknown");
	RTE_LOG(INFO, PMD, "           priority = 0x%02"PRIX8"\n", data->priority);
	RTE_LOG(INFO, PMD, "              valid = 0x%02"PRIX8"\n", data->valid);
	RTE_LOG(INFO, PMD, "        unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "        unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "        unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
}

void decode_hwrm_struct_data_dcbx_feature_state(const char *string __rte_unused, struct hwrm_struct_data_dcbx_feature_state *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_dcbx_feature_state\n");
	RTE_LOG(INFO, PMD, "   unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "  ets_state = 0x%02"PRIX8"\n", data->ets_state);
	RTE_LOG(INFO, PMD, "  pfc_state = 0x%02"PRIX8"\n", data->pfc_state);
	RTE_LOG(INFO, PMD, "  app_state = 0x%02"PRIX8"\n", data->app_state);
	RTE_LOG(INFO, PMD, "              Value : %s\n",
		data->app_state == HWRM_STRUCT_DATA_DCBX_FEATURE_STATE_APP_STATE_ENABLE_BIT_POS ? "ENABLE_BIT_POS" :
		data->app_state == HWRM_STRUCT_DATA_DCBX_FEATURE_STATE_APP_STATE_WILLING_BIT_POS ? "WILLING_BIT_POS" :
		data->app_state == HWRM_STRUCT_DATA_DCBX_FEATURE_STATE_APP_STATE_ADVERTISE_BIT_POS ? "ADVERTISE_BIT_POS" :
		"Unknown");
	RTE_LOG(INFO, PMD, "   unused_1 = 0x%08"PRIX32"\n", data->unused_1);
}

void decode_hwrm_struct_data_lldp(const char *string __rte_unused, struct hwrm_struct_data_lldp *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_lldp\n");
	RTE_LOG(INFO, PMD, "                     admin_state = 0x%02"PRIX8"\n", data->admin_state);
	RTE_LOG(INFO, PMD, "                                   Value : %s\n",
		data->admin_state == HWRM_STRUCT_DATA_LLDP_ADMIN_STATE_DISABLE ? "DISABLE" :
		data->admin_state == HWRM_STRUCT_DATA_LLDP_ADMIN_STATE_TX ? "TX" :
		data->admin_state == HWRM_STRUCT_DATA_LLDP_ADMIN_STATE_RX ? "RX" :
		data->admin_state == HWRM_STRUCT_DATA_LLDP_ADMIN_STATE_ENABLE ? "ENABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "          port_description_state = 0x%02"PRIX8"\n", data->port_description_state);
	RTE_LOG(INFO, PMD, "                                   Value : %s\n",
		data->port_description_state == HWRM_STRUCT_DATA_LLDP_PORT_DESCRIPTION_STATE_DISABLE ? "DISABLE" :
		data->port_description_state == HWRM_STRUCT_DATA_LLDP_PORT_DESCRIPTION_STATE_ENABLE ? "ENABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "               system_name_state = 0x%02"PRIX8"\n", data->system_name_state);
	RTE_LOG(INFO, PMD, "                                   Value : %s\n",
		data->system_name_state == HWRM_STRUCT_DATA_LLDP_SYSTEM_NAME_STATE_DISABLE ? "DISABLE" :
		data->system_name_state == HWRM_STRUCT_DATA_LLDP_SYSTEM_NAME_STATE_ENABLE ? "ENABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "               system_desc_state = 0x%02"PRIX8"\n", data->system_desc_state);
	RTE_LOG(INFO, PMD, "                                   Value : %s\n",
		data->system_desc_state == HWRM_STRUCT_DATA_LLDP_SYSTEM_DESC_STATE_DISABLE ? "DISABLE" :
		data->system_desc_state == HWRM_STRUCT_DATA_LLDP_SYSTEM_DESC_STATE_ENABLE ? "ENABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                system_cap_state = 0x%02"PRIX8"\n", data->system_cap_state);
	RTE_LOG(INFO, PMD, "                                   Value : %s\n",
		data->system_cap_state == HWRM_STRUCT_DATA_LLDP_SYSTEM_CAP_STATE_DISABLE ? "DISABLE" :
		data->system_cap_state == HWRM_STRUCT_DATA_LLDP_SYSTEM_CAP_STATE_ENABLE ? "ENABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                 mgmt_addr_state = 0x%02"PRIX8"\n", data->mgmt_addr_state);
	RTE_LOG(INFO, PMD, "                                   Value : %s\n",
		data->mgmt_addr_state == HWRM_STRUCT_DATA_LLDP_MGMT_ADDR_STATE_DISABLE ? "DISABLE" :
		data->mgmt_addr_state == HWRM_STRUCT_DATA_LLDP_MGMT_ADDR_STATE_ENABLE ? "ENABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "  async_event_notification_state = 0x%02"PRIX8"\n", data->async_event_notification_state);
	RTE_LOG(INFO, PMD, "                                   Value : %s\n",
		data->async_event_notification_state == HWRM_STRUCT_DATA_LLDP_ASYNC_EVENT_NOTIFICATION_STATE_DISABLE ? "DISABLE" :
		data->async_event_notification_state == HWRM_STRUCT_DATA_LLDP_ASYNC_EVENT_NOTIFICATION_STATE_ENABLE ? "ENABLE" :
		"Unknown");
	RTE_LOG(INFO, PMD, "                        unused_0 = 0x%02"PRIX8"\n", data->unused_0);
}

void decode_hwrm_struct_data_lldp_generic(const char *string __rte_unused, struct hwrm_struct_data_lldp_generic *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_lldp_generic\n");
	RTE_LOG(INFO, PMD, "       tlv_type = 0x%02"PRIX8"\n", data->tlv_type);
	RTE_LOG(INFO, PMD, "                  Value : %s\n",
		data->tlv_type == HWRM_STRUCT_DATA_LLDP_GENERIC_TLV_TYPE_CHASSIS ? "CHASSIS" :
		data->tlv_type == HWRM_STRUCT_DATA_LLDP_GENERIC_TLV_TYPE_PORT ? "PORT" :
		data->tlv_type == HWRM_STRUCT_DATA_LLDP_GENERIC_TLV_TYPE_SYSTEM_NAME ? "SYSTEM_NAME" :
		data->tlv_type == HWRM_STRUCT_DATA_LLDP_GENERIC_TLV_TYPE_SYSTEM_DESCRIPTION ? "SYSTEM_DESCRIPTION" :
		data->tlv_type == HWRM_STRUCT_DATA_LLDP_GENERIC_TLV_TYPE_PORT_NAME ? "PORT_NAME" :
		data->tlv_type == HWRM_STRUCT_DATA_LLDP_GENERIC_TLV_TYPE_PORT_DESCRIPTION ? "PORT_DESCRIPTION" :
		"Unknown");
	RTE_LOG(INFO, PMD, "        subtype = 0x%02"PRIX8"\n", data->subtype);
	RTE_LOG(INFO, PMD, "         length = 0x%02"PRIX8"\n", data->length);
	RTE_LOG(INFO, PMD, "       unused_0 = 0x%02"PRIX8"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "       unused_1 = 0x%08"PRIX32"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "   tlv_value[0] = 0x%08"PRIX32"\n", data->tlv_value[0]);
	RTE_LOG(INFO, PMD, "   tlv_value[1] = 0x%08"PRIX32"\n", data->tlv_value[1]);
	RTE_LOG(INFO, PMD, "   tlv_value[2] = 0x%08"PRIX32"\n", data->tlv_value[2]);
	RTE_LOG(INFO, PMD, "   tlv_value[3] = 0x%08"PRIX32"\n", data->tlv_value[3]);
	RTE_LOG(INFO, PMD, "   tlv_value[4] = 0x%08"PRIX32"\n", data->tlv_value[4]);
	RTE_LOG(INFO, PMD, "   tlv_value[5] = 0x%08"PRIX32"\n", data->tlv_value[5]);
	RTE_LOG(INFO, PMD, "   tlv_value[6] = 0x%08"PRIX32"\n", data->tlv_value[6]);
	RTE_LOG(INFO, PMD, "   tlv_value[7] = 0x%08"PRIX32"\n", data->tlv_value[7]);
	RTE_LOG(INFO, PMD, "   tlv_value[8] = 0x%08"PRIX32"\n", data->tlv_value[8]);
	RTE_LOG(INFO, PMD, "   tlv_value[9] = 0x%08"PRIX32"\n", data->tlv_value[9]);
	RTE_LOG(INFO, PMD, "  tlv_value[10] = 0x%08"PRIX32"\n", data->tlv_value[10]);
	RTE_LOG(INFO, PMD, "  tlv_value[11] = 0x%08"PRIX32"\n", data->tlv_value[11]);
	RTE_LOG(INFO, PMD, "  tlv_value[12] = 0x%08"PRIX32"\n", data->tlv_value[12]);
	RTE_LOG(INFO, PMD, "  tlv_value[13] = 0x%08"PRIX32"\n", data->tlv_value[13]);
	RTE_LOG(INFO, PMD, "  tlv_value[14] = 0x%08"PRIX32"\n", data->tlv_value[14]);
	RTE_LOG(INFO, PMD, "  tlv_value[15] = 0x%08"PRIX32"\n", data->tlv_value[15]);
	RTE_LOG(INFO, PMD, "  tlv_value[16] = 0x%08"PRIX32"\n", data->tlv_value[16]);
	RTE_LOG(INFO, PMD, "  tlv_value[17] = 0x%08"PRIX32"\n", data->tlv_value[17]);
	RTE_LOG(INFO, PMD, "  tlv_value[18] = 0x%08"PRIX32"\n", data->tlv_value[18]);
	RTE_LOG(INFO, PMD, "  tlv_value[19] = 0x%08"PRIX32"\n", data->tlv_value[19]);
	RTE_LOG(INFO, PMD, "  tlv_value[20] = 0x%08"PRIX32"\n", data->tlv_value[20]);
	RTE_LOG(INFO, PMD, "  tlv_value[21] = 0x%08"PRIX32"\n", data->tlv_value[21]);
	RTE_LOG(INFO, PMD, "  tlv_value[22] = 0x%08"PRIX32"\n", data->tlv_value[22]);
	RTE_LOG(INFO, PMD, "  tlv_value[23] = 0x%08"PRIX32"\n", data->tlv_value[23]);
	RTE_LOG(INFO, PMD, "  tlv_value[24] = 0x%08"PRIX32"\n", data->tlv_value[24]);
	RTE_LOG(INFO, PMD, "  tlv_value[25] = 0x%08"PRIX32"\n", data->tlv_value[25]);
	RTE_LOG(INFO, PMD, "  tlv_value[26] = 0x%08"PRIX32"\n", data->tlv_value[26]);
	RTE_LOG(INFO, PMD, "  tlv_value[27] = 0x%08"PRIX32"\n", data->tlv_value[27]);
	RTE_LOG(INFO, PMD, "  tlv_value[28] = 0x%08"PRIX32"\n", data->tlv_value[28]);
	RTE_LOG(INFO, PMD, "  tlv_value[29] = 0x%08"PRIX32"\n", data->tlv_value[29]);
	RTE_LOG(INFO, PMD, "  tlv_value[30] = 0x%08"PRIX32"\n", data->tlv_value[30]);
	RTE_LOG(INFO, PMD, "  tlv_value[31] = 0x%08"PRIX32"\n", data->tlv_value[31]);
	RTE_LOG(INFO, PMD, "  tlv_value[32] = 0x%08"PRIX32"\n", data->tlv_value[32]);
	RTE_LOG(INFO, PMD, "  tlv_value[33] = 0x%08"PRIX32"\n", data->tlv_value[33]);
	RTE_LOG(INFO, PMD, "  tlv_value[34] = 0x%08"PRIX32"\n", data->tlv_value[34]);
	RTE_LOG(INFO, PMD, "  tlv_value[35] = 0x%08"PRIX32"\n", data->tlv_value[35]);
	RTE_LOG(INFO, PMD, "  tlv_value[36] = 0x%08"PRIX32"\n", data->tlv_value[36]);
	RTE_LOG(INFO, PMD, "  tlv_value[37] = 0x%08"PRIX32"\n", data->tlv_value[37]);
	RTE_LOG(INFO, PMD, "  tlv_value[38] = 0x%08"PRIX32"\n", data->tlv_value[38]);
	RTE_LOG(INFO, PMD, "  tlv_value[39] = 0x%08"PRIX32"\n", data->tlv_value[39]);
	RTE_LOG(INFO, PMD, "  tlv_value[40] = 0x%08"PRIX32"\n", data->tlv_value[40]);
	RTE_LOG(INFO, PMD, "  tlv_value[41] = 0x%08"PRIX32"\n", data->tlv_value[41]);
	RTE_LOG(INFO, PMD, "  tlv_value[42] = 0x%08"PRIX32"\n", data->tlv_value[42]);
	RTE_LOG(INFO, PMD, "  tlv_value[43] = 0x%08"PRIX32"\n", data->tlv_value[43]);
	RTE_LOG(INFO, PMD, "  tlv_value[44] = 0x%08"PRIX32"\n", data->tlv_value[44]);
	RTE_LOG(INFO, PMD, "  tlv_value[45] = 0x%08"PRIX32"\n", data->tlv_value[45]);
	RTE_LOG(INFO, PMD, "  tlv_value[46] = 0x%08"PRIX32"\n", data->tlv_value[46]);
	RTE_LOG(INFO, PMD, "  tlv_value[47] = 0x%08"PRIX32"\n", data->tlv_value[47]);
	RTE_LOG(INFO, PMD, "  tlv_value[48] = 0x%08"PRIX32"\n", data->tlv_value[48]);
	RTE_LOG(INFO, PMD, "  tlv_value[49] = 0x%08"PRIX32"\n", data->tlv_value[49]);
	RTE_LOG(INFO, PMD, "  tlv_value[50] = 0x%08"PRIX32"\n", data->tlv_value[50]);
	RTE_LOG(INFO, PMD, "  tlv_value[51] = 0x%08"PRIX32"\n", data->tlv_value[51]);
	RTE_LOG(INFO, PMD, "  tlv_value[52] = 0x%08"PRIX32"\n", data->tlv_value[52]);
	RTE_LOG(INFO, PMD, "  tlv_value[53] = 0x%08"PRIX32"\n", data->tlv_value[53]);
	RTE_LOG(INFO, PMD, "  tlv_value[54] = 0x%08"PRIX32"\n", data->tlv_value[54]);
	RTE_LOG(INFO, PMD, "  tlv_value[55] = 0x%08"PRIX32"\n", data->tlv_value[55]);
	RTE_LOG(INFO, PMD, "  tlv_value[56] = 0x%08"PRIX32"\n", data->tlv_value[56]);
	RTE_LOG(INFO, PMD, "  tlv_value[57] = 0x%08"PRIX32"\n", data->tlv_value[57]);
	RTE_LOG(INFO, PMD, "  tlv_value[58] = 0x%08"PRIX32"\n", data->tlv_value[58]);
	RTE_LOG(INFO, PMD, "  tlv_value[59] = 0x%08"PRIX32"\n", data->tlv_value[59]);
	RTE_LOG(INFO, PMD, "  tlv_value[60] = 0x%08"PRIX32"\n", data->tlv_value[60]);
	RTE_LOG(INFO, PMD, "  tlv_value[61] = 0x%08"PRIX32"\n", data->tlv_value[61]);
	RTE_LOG(INFO, PMD, "  tlv_value[62] = 0x%08"PRIX32"\n", data->tlv_value[62]);
	RTE_LOG(INFO, PMD, "  tlv_value[63] = 0x%08"PRIX32"\n", data->tlv_value[63]);
}

void decode_hwrm_struct_data_lldp_device(const char *string __rte_unused, struct hwrm_struct_data_lldp_device *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_lldp_device\n");
	RTE_LOG(INFO, PMD, "                   ttl = 0x%04"PRIX16"\n", data->ttl);
	RTE_LOG(INFO, PMD, "         mgmt_addr_len = 0x%02"PRIX8"\n", data->mgmt_addr_len);
	RTE_LOG(INFO, PMD, "        mgmt_addr_type = 0x%02"PRIX8"\n", data->mgmt_addr_type);
	RTE_LOG(INFO, PMD, "              unused_0 = 0x%08"PRIX32"\n", data->unused_0);
	RTE_LOG(INFO, PMD, "          mgmt_addr[0] = 0x%08"PRIX32"\n", data->mgmt_addr[0]);
	RTE_LOG(INFO, PMD, "          mgmt_addr[1] = 0x%08"PRIX32"\n", data->mgmt_addr[1]);
	RTE_LOG(INFO, PMD, "          mgmt_addr[2] = 0x%08"PRIX32"\n", data->mgmt_addr[2]);
	RTE_LOG(INFO, PMD, "          mgmt_addr[3] = 0x%08"PRIX32"\n", data->mgmt_addr[3]);
	RTE_LOG(INFO, PMD, "          mgmt_addr[4] = 0x%08"PRIX32"\n", data->mgmt_addr[4]);
	RTE_LOG(INFO, PMD, "          mgmt_addr[5] = 0x%08"PRIX32"\n", data->mgmt_addr[5]);
	RTE_LOG(INFO, PMD, "          mgmt_addr[6] = 0x%08"PRIX32"\n", data->mgmt_addr[6]);
	RTE_LOG(INFO, PMD, "          mgmt_addr[7] = 0x%08"PRIX32"\n", data->mgmt_addr[7]);
	RTE_LOG(INFO, PMD, "           system_caps = 0x%08"PRIX32"\n", data->system_caps);
	RTE_LOG(INFO, PMD, "         intf_num_type = 0x%02"PRIX8"\n", data->intf_num_type);
	RTE_LOG(INFO, PMD, "  mgmt_addr_oid_length = 0x%02"PRIX8"\n", data->mgmt_addr_oid_length);
	RTE_LOG(INFO, PMD, "              unused_1 = 0x%02"PRIX8"\n", data->unused_1);
	RTE_LOG(INFO, PMD, "              unused_2 = 0x%02"PRIX8"\n", data->unused_2);
	RTE_LOG(INFO, PMD, "              intf_num = 0x%08"PRIX32"\n", data->intf_num);
	RTE_LOG(INFO, PMD, "              unused_3 = 0x%08"PRIX32"\n", data->unused_3);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[0] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[0]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[1] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[1]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[2] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[2]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[3] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[3]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[4] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[4]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[5] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[5]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[6] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[6]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[7] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[7]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[8] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[8]);
	RTE_LOG(INFO, PMD, "      mgmt_addr_oid[9] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[9]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[10] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[10]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[11] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[11]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[12] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[12]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[13] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[13]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[14] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[14]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[15] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[15]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[16] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[16]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[17] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[17]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[18] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[18]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[19] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[19]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[20] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[20]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[21] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[21]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[22] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[22]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[23] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[23]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[24] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[24]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[25] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[25]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[26] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[26]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[27] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[27]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[28] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[28]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[29] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[29]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[30] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[30]);
	RTE_LOG(INFO, PMD, "     mgmt_addr_oid[31] = 0x%08"PRIX32"\n", data->mgmt_addr_oid[31]);
}

void decode_hwrm_struct_data_port_description(const char *string __rte_unused, struct hwrm_struct_data_port_description *data) {
	RTE_LOG(INFO, PMD, "hwrm_struct_data_port_description\n");
	RTE_LOG(INFO, PMD, "      port_id = 0x%02"PRIX8"\n", data->port_id);
	RTE_LOG(INFO, PMD, "  unused_0[0] = 0x%02"PRIX8"\n", data->unused_0[0]);
	RTE_LOG(INFO, PMD, "  unused_0[1] = 0x%02"PRIX8"\n", data->unused_0[1]);
	RTE_LOG(INFO, PMD, "  unused_0[2] = 0x%02"PRIX8"\n", data->unused_0[2]);
	RTE_LOG(INFO, PMD, "  unused_0[3] = 0x%02"PRIX8"\n", data->unused_0[3]);
	RTE_LOG(INFO, PMD, "  unused_0[4] = 0x%02"PRIX8"\n", data->unused_0[4]);
	RTE_LOG(INFO, PMD, "  unused_0[5] = 0x%02"PRIX8"\n", data->unused_0[5]);
	RTE_LOG(INFO, PMD, "  unused_0[6] = 0x%02"PRIX8"\n", data->unused_0[6]);
}

#endif
