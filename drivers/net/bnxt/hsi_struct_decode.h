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

#ifdef HSI_DEBUG
#include "hsi_struct_def_dpdk.h"

void decode_bd_base(const char *string __rte_unused, struct bd_base *data);
void decode_tx_bd_short(const char *string __rte_unused, struct tx_bd_short *data);
void decode_tx_bd_long(const char *string __rte_unused, struct tx_bd_long *data);
void decode_tx_bd_long_hi(const char *string __rte_unused, struct tx_bd_long_hi *data);
void decode_tx_bd_empty(const char *string __rte_unused, struct tx_bd_empty *data);
void decode_rx_prod_pkt_bd(const char *string __rte_unused, struct rx_prod_pkt_bd *data);
void decode_rx_prod_bfr_bd(const char *string __rte_unused, struct rx_prod_bfr_bd *data);
void decode_rx_prod_agg_bd(const char *string __rte_unused, struct rx_prod_agg_bd *data);
void decode_cmpl_base(const char *string __rte_unused, struct cmpl_base *data);
void decode_tx_cmpl(const char *string __rte_unused, struct tx_cmpl *data);
void decode_rx_pkt_cmpl(const char *string __rte_unused, struct rx_pkt_cmpl *data);
void decode_rx_pkt_cmpl_hi(const char *string __rte_unused, struct rx_pkt_cmpl_hi *data);
void decode_rx_tpa_start_cmpl(const char *string __rte_unused, struct rx_tpa_start_cmpl *data);
void decode_rx_tpa_start_cmpl_hi(const char *string __rte_unused, struct rx_tpa_start_cmpl_hi *data);
void decode_rx_tpa_end_cmpl(const char *string __rte_unused, struct rx_tpa_end_cmpl *data);
void decode_rx_tpa_end_cmpl_hi(const char *string __rte_unused, struct rx_tpa_end_cmpl_hi *data);
void decode_rx_abuf_cmpl(const char *string __rte_unused, struct rx_abuf_cmpl *data);
void decode_eject_cmpl(const char *string __rte_unused, struct eject_cmpl *data);
void decode_hwrm_cmpl(const char *string __rte_unused, struct hwrm_cmpl *data);
void decode_hwrm_fwd_req_cmpl(const char *string __rte_unused, struct hwrm_fwd_req_cmpl *data);
void decode_hwrm_fwd_resp_cmpl(const char *string __rte_unused, struct hwrm_fwd_resp_cmpl *data);
void decode_hwrm_async_event_cmpl(const char *string __rte_unused, struct hwrm_async_event_cmpl *data);
void decode_hwrm_async_event_cmpl_link_status_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_status_change *data);
void decode_hwrm_async_event_cmpl_link_mtu_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_mtu_change *data);
void decode_hwrm_async_event_cmpl_link_speed_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_speed_change *data);
void decode_hwrm_async_event_cmpl_dcb_config_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_dcb_config_change *data);
void decode_hwrm_async_event_cmpl_port_conn_not_allowed(const char *string __rte_unused, struct hwrm_async_event_cmpl_port_conn_not_allowed *data);
void decode_hwrm_async_event_cmpl_link_speed_cfg_not_allowed(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_speed_cfg_not_allowed *data);
void decode_hwrm_async_event_cmpl_link_speed_cfg_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_link_speed_cfg_change *data);
void decode_hwrm_async_event_cmpl_port_phy_cfg_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_port_phy_cfg_change *data);
void decode_hwrm_async_event_cmpl_func_drvr_unload(const char *string __rte_unused, struct hwrm_async_event_cmpl_func_drvr_unload *data);
void decode_hwrm_async_event_cmpl_func_drvr_load(const char *string __rte_unused, struct hwrm_async_event_cmpl_func_drvr_load *data);
void decode_hwrm_async_event_cmpl_func_flr_proc_cmplt(const char *string __rte_unused, struct hwrm_async_event_cmpl_func_flr_proc_cmplt *data);
void decode_hwrm_async_event_cmpl_pf_drvr_unload(const char *string __rte_unused, struct hwrm_async_event_cmpl_pf_drvr_unload *data);
void decode_hwrm_async_event_cmpl_pf_drvr_load(const char *string __rte_unused, struct hwrm_async_event_cmpl_pf_drvr_load *data);
void decode_hwrm_async_event_cmpl_vf_flr(const char *string __rte_unused, struct hwrm_async_event_cmpl_vf_flr *data);
void decode_hwrm_async_event_cmpl_vf_mac_addr_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_vf_mac_addr_change *data);
void decode_hwrm_async_event_cmpl_pf_vf_comm_status_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_pf_vf_comm_status_change *data);
void decode_hwrm_async_event_cmpl_vf_cfg_change(const char *string __rte_unused, struct hwrm_async_event_cmpl_vf_cfg_change *data);
void decode_hwrm_async_event_cmpl_hwrm_error(const char *string __rte_unused, struct hwrm_async_event_cmpl_hwrm_error *data);
void decode_tx_doorbell(const char *string __rte_unused, struct tx_doorbell *data);
void decode_rx_doorbell(const char *string __rte_unused, struct rx_doorbell *data);
void decode_cmpl_doorbell(const char *string __rte_unused, struct cmpl_doorbell *data);
void decode_status_doorbell(const char *string __rte_unused, struct status_doorbell *data);
void decode_push32_doorbell(const char *string __rte_unused, struct push32_doorbell *data);
void decode_dbr_dbr(const char *string __rte_unused, struct dbr_dbr *data);
void decode_dbr_dbr32(const char *string __rte_unused, struct dbr_dbr32 *data);
void decode_sq_base(const char *string __rte_unused, struct sq_base *data);
void decode_sq_sge(const char *string __rte_unused, struct sq_sge *data);
void decode_sq_psn_search(const char *string __rte_unused, struct sq_psn_search *data);
void decode_sq_send(const char *string __rte_unused, struct sq_send *data);
void decode_sq_send_raweth_qp1(const char *string __rte_unused, struct sq_send_raweth_qp1 *data);
void decode_sq_rdma(const char *string __rte_unused, struct sq_rdma *data);
void decode_sq_atomic(const char *string __rte_unused, struct sq_atomic *data);
void decode_sq_localinvalidate(const char *string __rte_unused, struct sq_localinvalidate *data);
void decode_sq_fr_pmr(const char *string __rte_unused, struct sq_fr_pmr *data);
void decode_sq_bind(const char *string __rte_unused, struct sq_bind *data);
void decode_rq_wqe(const char *string __rte_unused, struct rq_wqe *data);
void decode_cq_base(const char *string __rte_unused, struct cq_base *data);
void decode_cq_req(const char *string __rte_unused, struct cq_req *data);
void decode_cq_res_rc(const char *string __rte_unused, struct cq_res_rc *data);
void decode_cq_res_ud(const char *string __rte_unused, struct cq_res_ud *data);
void decode_cq_res_raweth_qp1(const char *string __rte_unused, struct cq_res_raweth_qp1 *data);
void decode_cq_terminal(const char *string __rte_unused, struct cq_terminal *data);
void decode_cq_cutoff(const char *string __rte_unused, struct cq_cutoff *data);
void decode_nq_base(const char *string __rte_unused, struct nq_base *data);
void decode_nq_cn(const char *string __rte_unused, struct nq_cn *data);
void decode_nq_srq_event(const char *string __rte_unused, struct nq_srq_event *data);
void decode_nq_dbq_event(const char *string __rte_unused, struct nq_dbq_event *data);
void decode_xrrq_irrq(const char *string __rte_unused, struct xrrq_irrq *data);
void decode_xrrq_orrq(const char *string __rte_unused, struct xrrq_orrq *data);
void decode_ptu_pte(const char *string __rte_unused, struct ptu_pte *data);
void decode_ptu_pde(const char *string __rte_unused, struct ptu_pde *data);
void decode_hwrm_ver_get_input(const char *string __rte_unused, struct hwrm_ver_get_input *data);
void decode_hwrm_ver_get_output(const char *string __rte_unused, struct hwrm_ver_get_output *data);
void decode_hwrm_func_reset_input(const char *string __rte_unused, struct hwrm_func_reset_input *data);
void decode_hwrm_func_reset_output(const char *string __rte_unused, struct hwrm_func_reset_output *data);
void decode_hwrm_func_getfid_input(const char *string __rte_unused, struct hwrm_func_getfid_input *data);
void decode_hwrm_func_getfid_output(const char *string __rte_unused, struct hwrm_func_getfid_output *data);
void decode_hwrm_func_vf_alloc_input(const char *string __rte_unused, struct hwrm_func_vf_alloc_input *data);
void decode_hwrm_func_vf_alloc_output(const char *string __rte_unused, struct hwrm_func_vf_alloc_output *data);
void decode_hwrm_func_vf_free_input(const char *string __rte_unused, struct hwrm_func_vf_free_input *data);
void decode_hwrm_func_vf_free_output(const char *string __rte_unused, struct hwrm_func_vf_free_output *data);
void decode_hwrm_func_vf_cfg_input(const char *string __rte_unused, struct hwrm_func_vf_cfg_input *data);
void decode_hwrm_func_vf_cfg_output(const char *string __rte_unused, struct hwrm_func_vf_cfg_output *data);
void decode_hwrm_func_qcaps_input(const char *string __rte_unused, struct hwrm_func_qcaps_input *data);
void decode_hwrm_func_qcaps_output(const char *string __rte_unused, struct hwrm_func_qcaps_output *data);
void decode_hwrm_func_qcfg_input(const char *string __rte_unused, struct hwrm_func_qcfg_input *data);
void decode_hwrm_func_qcfg_output(const char *string __rte_unused, struct hwrm_func_qcfg_output *data);
void decode_hwrm_func_cfg_input(const char *string __rte_unused, struct hwrm_func_cfg_input *data);
void decode_hwrm_func_cfg_output(const char *string __rte_unused, struct hwrm_func_cfg_output *data);
void decode_hwrm_func_qstats_input(const char *string __rte_unused, struct hwrm_func_qstats_input *data);
void decode_hwrm_func_qstats_output(const char *string __rte_unused, struct hwrm_func_qstats_output *data);
void decode_hwrm_func_clr_stats_input(const char *string __rte_unused, struct hwrm_func_clr_stats_input *data);
void decode_hwrm_func_clr_stats_output(const char *string __rte_unused, struct hwrm_func_clr_stats_output *data);
void decode_hwrm_func_vf_resc_free_input(const char *string __rte_unused, struct hwrm_func_vf_resc_free_input *data);
void decode_hwrm_func_vf_resc_free_output(const char *string __rte_unused, struct hwrm_func_vf_resc_free_output *data);
void decode_hwrm_func_vf_vnic_ids_query_input(const char *string __rte_unused, struct hwrm_func_vf_vnic_ids_query_input *data);
void decode_hwrm_func_vf_vnic_ids_query_output(const char *string __rte_unused, struct hwrm_func_vf_vnic_ids_query_output *data);
void decode_hwrm_func_drv_rgtr_input(const char *string __rte_unused, struct hwrm_func_drv_rgtr_input *data);
void decode_hwrm_func_drv_rgtr_output(const char *string __rte_unused, struct hwrm_func_drv_rgtr_output *data);
void decode_hwrm_func_drv_unrgtr_input(const char *string __rte_unused, struct hwrm_func_drv_unrgtr_input *data);
void decode_hwrm_func_drv_unrgtr_output(const char *string __rte_unused, struct hwrm_func_drv_unrgtr_output *data);
void decode_hwrm_func_buf_rgtr_input(const char *string __rte_unused, struct hwrm_func_buf_rgtr_input *data);
void decode_hwrm_func_buf_rgtr_output(const char *string __rte_unused, struct hwrm_func_buf_rgtr_output *data);
void decode_hwrm_func_buf_unrgtr_input(const char *string __rte_unused, struct hwrm_func_buf_unrgtr_input *data);
void decode_hwrm_func_buf_unrgtr_output(const char *string __rte_unused, struct hwrm_func_buf_unrgtr_output *data);
void decode_hwrm_func_drv_qver_input(const char *string __rte_unused, struct hwrm_func_drv_qver_input *data);
void decode_hwrm_func_drv_qver_output(const char *string __rte_unused, struct hwrm_func_drv_qver_output *data);
void decode_hwrm_port_phy_cfg_input(const char *string __rte_unused, struct hwrm_port_phy_cfg_input *data);
void decode_hwrm_port_phy_cfg_output(const char *string __rte_unused, struct hwrm_port_phy_cfg_output *data);
void decode_hwrm_port_phy_qcfg_input(const char *string __rte_unused, struct hwrm_port_phy_qcfg_input *data);
void decode_hwrm_port_phy_qcfg_output(const char *string __rte_unused, struct hwrm_port_phy_qcfg_output *data);
void decode_hwrm_port_mac_cfg_input(const char *string __rte_unused, struct hwrm_port_mac_cfg_input *data);
void decode_hwrm_port_mac_cfg_output(const char *string __rte_unused, struct hwrm_port_mac_cfg_output *data);
void decode_hwrm_port_mac_qcfg_input(const char *string __rte_unused, struct hwrm_port_mac_qcfg_input *data);
void decode_hwrm_port_mac_qcfg_output(const char *string __rte_unused, struct hwrm_port_mac_qcfg_output *data);
void decode_hwrm_port_qstats_input(const char *string __rte_unused, struct hwrm_port_qstats_input *data);
void decode_hwrm_port_qstats_output(const char *string __rte_unused, struct hwrm_port_qstats_output *data);
void decode_hwrm_port_lpbk_qstats_input(const char *string __rte_unused, struct hwrm_port_lpbk_qstats_input *data);
void decode_hwrm_port_lpbk_qstats_output(const char *string __rte_unused, struct hwrm_port_lpbk_qstats_output *data);
void decode_hwrm_port_clr_stats_input(const char *string __rte_unused, struct hwrm_port_clr_stats_input *data);
void decode_hwrm_port_clr_stats_output(const char *string __rte_unused, struct hwrm_port_clr_stats_output *data);
void decode_hwrm_port_lpbk_clr_stats_input(const char *string __rte_unused, struct hwrm_port_lpbk_clr_stats_input *data);
void decode_hwrm_port_lpbk_clr_stats_output(const char *string __rte_unused, struct hwrm_port_lpbk_clr_stats_output *data);
void decode_hwrm_port_ts_query_input(const char *string __rte_unused, struct hwrm_port_ts_query_input *data);
void decode_hwrm_port_ts_query_output(const char *string __rte_unused, struct hwrm_port_ts_query_output *data);
void decode_hwrm_port_phy_qcaps_input(const char *string __rte_unused, struct hwrm_port_phy_qcaps_input *data);
void decode_hwrm_port_phy_qcaps_output(const char *string __rte_unused, struct hwrm_port_phy_qcaps_output *data);
void decode_hwrm_port_phy_i2c_write_input(const char *string __rte_unused, struct hwrm_port_phy_i2c_write_input *data);
void decode_hwrm_port_phy_i2c_write_output(const char *string __rte_unused, struct hwrm_port_phy_i2c_write_output *data);
void decode_hwrm_port_phy_i2c_read_input(const char *string __rte_unused, struct hwrm_port_phy_i2c_read_input *data);
void decode_hwrm_port_phy_i2c_read_output(const char *string __rte_unused, struct hwrm_port_phy_i2c_read_output *data);
void decode_hwrm_port_led_cfg_input(const char *string __rte_unused, struct hwrm_port_led_cfg_input *data);
void decode_hwrm_port_led_cfg_output(const char *string __rte_unused, struct hwrm_port_led_cfg_output *data);
void decode_hwrm_port_led_qcfg_input(const char *string __rte_unused, struct hwrm_port_led_qcfg_input *data);
void decode_hwrm_port_led_qcfg_output(const char *string __rte_unused, struct hwrm_port_led_qcfg_output *data);
void decode_hwrm_port_led_qcaps_input(const char *string __rte_unused, struct hwrm_port_led_qcaps_input *data);
void decode_hwrm_port_led_qcaps_output(const char *string __rte_unused, struct hwrm_port_led_qcaps_output *data);
void decode_hwrm_queue_qportcfg_input(const char *string __rte_unused, struct hwrm_queue_qportcfg_input *data);
void decode_hwrm_queue_qportcfg_output(const char *string __rte_unused, struct hwrm_queue_qportcfg_output *data);
void decode_hwrm_queue_qcfg_input(const char *string __rte_unused, struct hwrm_queue_qcfg_input *data);
void decode_hwrm_queue_qcfg_output(const char *string __rte_unused, struct hwrm_queue_qcfg_output *data);
void decode_hwrm_queue_cfg_input(const char *string __rte_unused, struct hwrm_queue_cfg_input *data);
void decode_hwrm_queue_cfg_output(const char *string __rte_unused, struct hwrm_queue_cfg_output *data);
void decode_hwrm_queue_pfcenable_qcfg_input(const char *string __rte_unused, struct hwrm_queue_pfcenable_qcfg_input *data);
void decode_hwrm_queue_pfcenable_qcfg_output(const char *string __rte_unused, struct hwrm_queue_pfcenable_qcfg_output *data);
void decode_hwrm_queue_pfcenable_cfg_input(const char *string __rte_unused, struct hwrm_queue_pfcenable_cfg_input *data);
void decode_hwrm_queue_pfcenable_cfg_output(const char *string __rte_unused, struct hwrm_queue_pfcenable_cfg_output *data);
void decode_hwrm_queue_pri2cos_qcfg_input(const char *string __rte_unused, struct hwrm_queue_pri2cos_qcfg_input *data);
void decode_hwrm_queue_pri2cos_qcfg_output(const char *string __rte_unused, struct hwrm_queue_pri2cos_qcfg_output *data);
void decode_hwrm_queue_pri2cos_cfg_input(const char *string __rte_unused, struct hwrm_queue_pri2cos_cfg_input *data);
void decode_hwrm_queue_pri2cos_cfg_output(const char *string __rte_unused, struct hwrm_queue_pri2cos_cfg_output *data);
void decode_hwrm_queue_cos2bw_qcfg_input(const char *string __rte_unused, struct hwrm_queue_cos2bw_qcfg_input *data);
void decode_hwrm_queue_cos2bw_qcfg_output(const char *string __rte_unused, struct hwrm_queue_cos2bw_qcfg_output *data);
void decode_hwrm_queue_cos2bw_cfg_input(const char *string __rte_unused, struct hwrm_queue_cos2bw_cfg_input *data);
void decode_hwrm_queue_cos2bw_cfg_output(const char *string __rte_unused, struct hwrm_queue_cos2bw_cfg_output *data);
void decode_hwrm_vnic_alloc_input(const char *string __rte_unused, struct hwrm_vnic_alloc_input *data);
void decode_hwrm_vnic_alloc_output(const char *string __rte_unused, struct hwrm_vnic_alloc_output *data);
void decode_hwrm_vnic_free_input(const char *string __rte_unused, struct hwrm_vnic_free_input *data);
void decode_hwrm_vnic_free_output(const char *string __rte_unused, struct hwrm_vnic_free_output *data);
void decode_hwrm_vnic_cfg_input(const char *string __rte_unused, struct hwrm_vnic_cfg_input *data);
void decode_hwrm_vnic_cfg_output(const char *string __rte_unused, struct hwrm_vnic_cfg_output *data);
void decode_hwrm_vnic_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_qcfg_input *data);
void decode_hwrm_vnic_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_qcfg_output *data);
void decode_hwrm_vnic_qcaps_input(const char *string __rte_unused, struct hwrm_vnic_qcaps_input *data);
void decode_hwrm_vnic_qcaps_output(const char *string __rte_unused, struct hwrm_vnic_qcaps_output *data);
void decode_hwrm_vnic_tpa_cfg_input(const char *string __rte_unused, struct hwrm_vnic_tpa_cfg_input *data);
void decode_hwrm_vnic_tpa_cfg_output(const char *string __rte_unused, struct hwrm_vnic_tpa_cfg_output *data);
void decode_hwrm_vnic_tpa_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_tpa_qcfg_input *data);
void decode_hwrm_vnic_tpa_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_tpa_qcfg_output *data);
void decode_hwrm_vnic_rss_cfg_input(const char *string __rte_unused, struct hwrm_vnic_rss_cfg_input *data);
void decode_hwrm_vnic_rss_cfg_output(const char *string __rte_unused, struct hwrm_vnic_rss_cfg_output *data);
void decode_hwrm_vnic_rss_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_rss_qcfg_input *data);
void decode_hwrm_vnic_rss_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_rss_qcfg_output *data);
void decode_hwrm_vnic_plcmodes_cfg_input(const char *string __rte_unused, struct hwrm_vnic_plcmodes_cfg_input *data);
void decode_hwrm_vnic_plcmodes_cfg_output(const char *string __rte_unused, struct hwrm_vnic_plcmodes_cfg_output *data);
void decode_hwrm_vnic_plcmodes_qcfg_input(const char *string __rte_unused, struct hwrm_vnic_plcmodes_qcfg_input *data);
void decode_hwrm_vnic_plcmodes_qcfg_output(const char *string __rte_unused, struct hwrm_vnic_plcmodes_qcfg_output *data);
void decode_hwrm_vnic_rss_cos_lb_ctx_alloc_input(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_alloc_input *data);
void decode_hwrm_vnic_rss_cos_lb_ctx_alloc_output(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_alloc_output *data);
void decode_hwrm_vnic_rss_cos_lb_ctx_free_input(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_free_input *data);
void decode_hwrm_vnic_rss_cos_lb_ctx_free_output(const char *string __rte_unused, struct hwrm_vnic_rss_cos_lb_ctx_free_output *data);
void decode_hwrm_ring_alloc_input(const char *string __rte_unused, struct hwrm_ring_alloc_input *data);
void decode_hwrm_ring_alloc_output(const char *string __rte_unused, struct hwrm_ring_alloc_output *data);
void decode_hwrm_ring_free_input(const char *string __rte_unused, struct hwrm_ring_free_input *data);
void decode_hwrm_ring_free_output(const char *string __rte_unused, struct hwrm_ring_free_output *data);
void decode_hwrm_ring_cmpl_ring_qaggint_params_input(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_qaggint_params_input *data);
void decode_hwrm_ring_cmpl_ring_qaggint_params_output(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_qaggint_params_output *data);
void decode_hwrm_ring_cmpl_ring_cfg_aggint_params_input(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_cfg_aggint_params_input *data);
void decode_hwrm_ring_cmpl_ring_cfg_aggint_params_output(const char *string __rte_unused, struct hwrm_ring_cmpl_ring_cfg_aggint_params_output *data);
void decode_hwrm_ring_reset_input(const char *string __rte_unused, struct hwrm_ring_reset_input *data);
void decode_hwrm_ring_reset_output(const char *string __rte_unused, struct hwrm_ring_reset_output *data);
void decode_hwrm_ring_grp_alloc_input(const char *string __rte_unused, struct hwrm_ring_grp_alloc_input *data);
void decode_hwrm_ring_grp_alloc_output(const char *string __rte_unused, struct hwrm_ring_grp_alloc_output *data);
void decode_hwrm_ring_grp_free_input(const char *string __rte_unused, struct hwrm_ring_grp_free_input *data);
void decode_hwrm_ring_grp_free_output(const char *string __rte_unused, struct hwrm_ring_grp_free_output *data);
void decode_hwrm_cfa_l2_filter_alloc_input(const char *string __rte_unused, struct hwrm_cfa_l2_filter_alloc_input *data);
void decode_hwrm_cfa_l2_filter_alloc_output(const char *string __rte_unused, struct hwrm_cfa_l2_filter_alloc_output *data);
void decode_hwrm_cfa_l2_filter_free_input(const char *string __rte_unused, struct hwrm_cfa_l2_filter_free_input *data);
void decode_hwrm_cfa_l2_filter_free_output(const char *string __rte_unused, struct hwrm_cfa_l2_filter_free_output *data);
void decode_hwrm_cfa_l2_filter_cfg_input(const char *string __rte_unused, struct hwrm_cfa_l2_filter_cfg_input *data);
void decode_hwrm_cfa_l2_filter_cfg_output(const char *string __rte_unused, struct hwrm_cfa_l2_filter_cfg_output *data);
void decode_hwrm_cfa_l2_set_rx_mask_input(const char *string __rte_unused, struct hwrm_cfa_l2_set_rx_mask_input *data);
void decode_hwrm_cfa_l2_set_rx_mask_output(const char *string __rte_unused, struct hwrm_cfa_l2_set_rx_mask_output *data);
void decode_hwrm_cfa_tunnel_filter_alloc_input(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_alloc_input *data);
void decode_hwrm_cfa_tunnel_filter_alloc_output(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_alloc_output *data);
void decode_hwrm_cfa_tunnel_filter_free_input(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_free_input *data);
void decode_hwrm_cfa_tunnel_filter_free_output(const char *string __rte_unused, struct hwrm_cfa_tunnel_filter_free_output *data);
void decode_hwrm_cfa_encap_record_alloc_input(const char *string __rte_unused, struct hwrm_cfa_encap_record_alloc_input *data);
void decode_hwrm_cfa_encap_record_alloc_output(const char *string __rte_unused, struct hwrm_cfa_encap_record_alloc_output *data);
void decode_hwrm_cfa_encap_record_free_input(const char *string __rte_unused, struct hwrm_cfa_encap_record_free_input *data);
void decode_hwrm_cfa_encap_record_free_output(const char *string __rte_unused, struct hwrm_cfa_encap_record_free_output *data);
void decode_hwrm_cfa_ntuple_filter_alloc_input(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_alloc_input *data);
void decode_hwrm_cfa_ntuple_filter_alloc_output(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_alloc_output *data);
void decode_hwrm_cfa_ntuple_filter_free_input(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_free_input *data);
void decode_hwrm_cfa_ntuple_filter_free_output(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_free_output *data);
void decode_hwrm_cfa_ntuple_filter_cfg_input(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_cfg_input *data);
void decode_hwrm_cfa_ntuple_filter_cfg_output(const char *string __rte_unused, struct hwrm_cfa_ntuple_filter_cfg_output *data);
void decode_hwrm_cfa_em_flow_alloc_input(const char *string __rte_unused, struct hwrm_cfa_em_flow_alloc_input *data);
void decode_hwrm_cfa_em_flow_alloc_output(const char *string __rte_unused, struct hwrm_cfa_em_flow_alloc_output *data);
void decode_hwrm_cfa_em_flow_free_input(const char *string __rte_unused, struct hwrm_cfa_em_flow_free_input *data);
void decode_hwrm_cfa_em_flow_free_output(const char *string __rte_unused, struct hwrm_cfa_em_flow_free_output *data);
void decode_hwrm_cfa_em_flow_cfg_input(const char *string __rte_unused, struct hwrm_cfa_em_flow_cfg_input *data);
void decode_hwrm_cfa_em_flow_cfg_output(const char *string __rte_unused, struct hwrm_cfa_em_flow_cfg_output *data);
void decode_hwrm_tunnel_dst_port_query_input(const char *string __rte_unused, struct hwrm_tunnel_dst_port_query_input *data);
void decode_hwrm_tunnel_dst_port_query_output(const char *string __rte_unused, struct hwrm_tunnel_dst_port_query_output *data);
void decode_hwrm_tunnel_dst_port_alloc_input(const char *string __rte_unused, struct hwrm_tunnel_dst_port_alloc_input *data);
void decode_hwrm_tunnel_dst_port_alloc_output(const char *string __rte_unused, struct hwrm_tunnel_dst_port_alloc_output *data);
void decode_hwrm_tunnel_dst_port_free_input(const char *string __rte_unused, struct hwrm_tunnel_dst_port_free_input *data);
void decode_hwrm_tunnel_dst_port_free_output(const char *string __rte_unused, struct hwrm_tunnel_dst_port_free_output *data);
void decode_hwrm_stat_ctx_alloc_input(const char *string __rte_unused, struct hwrm_stat_ctx_alloc_input *data);
void decode_hwrm_stat_ctx_alloc_output(const char *string __rte_unused, struct hwrm_stat_ctx_alloc_output *data);
void decode_hwrm_stat_ctx_free_input(const char *string __rte_unused, struct hwrm_stat_ctx_free_input *data);
void decode_hwrm_stat_ctx_free_output(const char *string __rte_unused, struct hwrm_stat_ctx_free_output *data);
void decode_hwrm_stat_ctx_query_input(const char *string __rte_unused, struct hwrm_stat_ctx_query_input *data);
void decode_hwrm_stat_ctx_query_output(const char *string __rte_unused, struct hwrm_stat_ctx_query_output *data);
void decode_hwrm_stat_ctx_clr_stats_input(const char *string __rte_unused, struct hwrm_stat_ctx_clr_stats_input *data);
void decode_hwrm_stat_ctx_clr_stats_output(const char *string __rte_unused, struct hwrm_stat_ctx_clr_stats_output *data);
void decode_hwrm_fw_reset_input(const char *string __rte_unused, struct hwrm_fw_reset_input *data);
void decode_hwrm_fw_reset_output(const char *string __rte_unused, struct hwrm_fw_reset_output *data);
void decode_hwrm_fw_qstatus_input(const char *string __rte_unused, struct hwrm_fw_qstatus_input *data);
void decode_hwrm_fw_qstatus_output(const char *string __rte_unused, struct hwrm_fw_qstatus_output *data);
void decode_hwrm_fw_set_time_input(const char *string __rte_unused, struct hwrm_fw_set_time_input *data);
void decode_hwrm_fw_set_time_output(const char *string __rte_unused, struct hwrm_fw_set_time_output *data);
void decode_hwrm_fw_get_time_input(const char *string __rte_unused, struct hwrm_fw_get_time_input *data);
void decode_hwrm_fw_get_time_output(const char *string __rte_unused, struct hwrm_fw_get_time_output *data);
void decode_hwrm_fw_set_structured_data_input(const char *string __rte_unused, struct hwrm_fw_set_structured_data_input *data);
void decode_hwrm_fw_set_structured_data_output(const char *string __rte_unused, struct hwrm_fw_set_structured_data_output *data);
void decode_hwrm_fw_set_structured_data_cmd_err(const char *string __rte_unused, struct hwrm_fw_set_structured_data_cmd_err *data);
void decode_hwrm_fw_get_structured_data_input(const char *string __rte_unused, struct hwrm_fw_get_structured_data_input *data);
void decode_hwrm_fw_get_structured_data_output(const char *string __rte_unused, struct hwrm_fw_get_structured_data_output *data);
void decode_hwrm_fw_get_structured_data_cmd_err(const char *string __rte_unused, struct hwrm_fw_get_structured_data_cmd_err *data);
void decode_hwrm_fw_ipc_mailbox_input(const char *string __rte_unused, struct hwrm_fw_ipc_mailbox_input *data);
void decode_hwrm_fw_ipc_mailbox_output(const char *string __rte_unused, struct hwrm_fw_ipc_mailbox_output *data);
void decode_hwrm_fw_ipc_mailbox_cmd_err(const char *string __rte_unused, struct hwrm_fw_ipc_mailbox_cmd_err *data);
void decode_hwrm_exec_fwd_resp_input(const char *string __rte_unused, struct hwrm_exec_fwd_resp_input *data);
void decode_hwrm_exec_fwd_resp_output(const char *string __rte_unused, struct hwrm_exec_fwd_resp_output *data);
void decode_hwrm_reject_fwd_resp_input(const char *string __rte_unused, struct hwrm_reject_fwd_resp_input *data);
void decode_hwrm_reject_fwd_resp_output(const char *string __rte_unused, struct hwrm_reject_fwd_resp_output *data);
void decode_hwrm_fwd_resp_input(const char *string __rte_unused, struct hwrm_fwd_resp_input *data);
void decode_hwrm_fwd_resp_output(const char *string __rte_unused, struct hwrm_fwd_resp_output *data);
void decode_hwrm_fwd_async_event_cmpl_input(const char *string __rte_unused, struct hwrm_fwd_async_event_cmpl_input *data);
void decode_hwrm_fwd_async_event_cmpl_output(const char *string __rte_unused, struct hwrm_fwd_async_event_cmpl_output *data);
void decode_hwrm_temp_monitor_query_input(const char *string __rte_unused, struct hwrm_temp_monitor_query_input *data);
void decode_hwrm_temp_monitor_query_output(const char *string __rte_unused, struct hwrm_temp_monitor_query_output *data);
void decode_hwrm_wol_filter_alloc_input(const char *string __rte_unused, struct hwrm_wol_filter_alloc_input *data);
void decode_hwrm_wol_filter_alloc_output(const char *string __rte_unused, struct hwrm_wol_filter_alloc_output *data);
void decode_hwrm_wol_filter_free_input(const char *string __rte_unused, struct hwrm_wol_filter_free_input *data);
void decode_hwrm_wol_filter_free_output(const char *string __rte_unused, struct hwrm_wol_filter_free_output *data);
void decode_hwrm_wol_filter_qcfg_input(const char *string __rte_unused, struct hwrm_wol_filter_qcfg_input *data);
void decode_hwrm_wol_filter_qcfg_output(const char *string __rte_unused, struct hwrm_wol_filter_qcfg_output *data);
void decode_hwrm_wol_reason_qcfg_input(const char *string __rte_unused, struct hwrm_wol_reason_qcfg_input *data);
void decode_hwrm_wol_reason_qcfg_output(const char *string __rte_unused, struct hwrm_wol_reason_qcfg_output *data);
void decode_hwrm_dbg_read_direct_input(const char *string __rte_unused, struct hwrm_dbg_read_direct_input *data);
void decode_hwrm_dbg_read_direct_output(const char *string __rte_unused, struct hwrm_dbg_read_direct_output *data);
void decode_hwrm_dbg_write_direct_input(const char *string __rte_unused, struct hwrm_dbg_write_direct_input *data);
void decode_hwrm_dbg_write_direct_output(const char *string __rte_unused, struct hwrm_dbg_write_direct_output *data);
void decode_hwrm_dbg_read_indirect_input(const char *string __rte_unused, struct hwrm_dbg_read_indirect_input *data);
void decode_hwrm_dbg_read_indirect_output(const char *string __rte_unused, struct hwrm_dbg_read_indirect_output *data);
void decode_hwrm_dbg_write_indirect_input(const char *string __rte_unused, struct hwrm_dbg_write_indirect_input *data);
void decode_hwrm_dbg_write_indirect_output(const char *string __rte_unused, struct hwrm_dbg_write_indirect_output *data);
void decode_hwrm_dbg_dump_input(const char *string __rte_unused, struct hwrm_dbg_dump_input *data);
void decode_hwrm_dbg_dump_output(const char *string __rte_unused, struct hwrm_dbg_dump_output *data);
void decode_hwrm_nvm_raw_write_blk_input(const char *string __rte_unused, struct hwrm_nvm_raw_write_blk_input *data);
void decode_hwrm_nvm_raw_write_blk_output(const char *string __rte_unused, struct hwrm_nvm_raw_write_blk_output *data);
void decode_hwrm_nvm_read_input(const char *string __rte_unused, struct hwrm_nvm_read_input *data);
void decode_hwrm_nvm_read_output(const char *string __rte_unused, struct hwrm_nvm_read_output *data);
void decode_hwrm_nvm_raw_dump_input(const char *string __rte_unused, struct hwrm_nvm_raw_dump_input *data);
void decode_hwrm_nvm_raw_dump_output(const char *string __rte_unused, struct hwrm_nvm_raw_dump_output *data);
void decode_hwrm_nvm_get_dir_entries_input(const char *string __rte_unused, struct hwrm_nvm_get_dir_entries_input *data);
void decode_hwrm_nvm_get_dir_entries_output(const char *string __rte_unused, struct hwrm_nvm_get_dir_entries_output *data);
void decode_hwrm_nvm_get_dir_info_input(const char *string __rte_unused, struct hwrm_nvm_get_dir_info_input *data);
void decode_hwrm_nvm_get_dir_info_output(const char *string __rte_unused, struct hwrm_nvm_get_dir_info_output *data);
void decode_hwrm_nvm_write_input(const char *string __rte_unused, struct hwrm_nvm_write_input *data);
void decode_hwrm_nvm_write_output(const char *string __rte_unused, struct hwrm_nvm_write_output *data);
void decode_hwrm_nvm_modify_input(const char *string __rte_unused, struct hwrm_nvm_modify_input *data);
void decode_hwrm_nvm_modify_output(const char *string __rte_unused, struct hwrm_nvm_modify_output *data);
void decode_hwrm_nvm_find_dir_entry_input(const char *string __rte_unused, struct hwrm_nvm_find_dir_entry_input *data);
void decode_hwrm_nvm_find_dir_entry_output(const char *string __rte_unused, struct hwrm_nvm_find_dir_entry_output *data);
void decode_hwrm_nvm_erase_dir_entry_input(const char *string __rte_unused, struct hwrm_nvm_erase_dir_entry_input *data);
void decode_hwrm_nvm_erase_dir_entry_output(const char *string __rte_unused, struct hwrm_nvm_erase_dir_entry_output *data);
void decode_hwrm_nvm_get_dev_info_input(const char *string __rte_unused, struct hwrm_nvm_get_dev_info_input *data);
void decode_hwrm_nvm_get_dev_info_output(const char *string __rte_unused, struct hwrm_nvm_get_dev_info_output *data);
void decode_hwrm_nvm_mod_dir_entry_input(const char *string __rte_unused, struct hwrm_nvm_mod_dir_entry_input *data);
void decode_hwrm_nvm_mod_dir_entry_output(const char *string __rte_unused, struct hwrm_nvm_mod_dir_entry_output *data);
void decode_hwrm_nvm_verify_update_input(const char *string __rte_unused, struct hwrm_nvm_verify_update_input *data);
void decode_hwrm_nvm_verify_update_output(const char *string __rte_unused, struct hwrm_nvm_verify_update_output *data);
void decode_hwrm_nvm_install_update_input(const char *string __rte_unused, struct hwrm_nvm_install_update_input *data);
void decode_hwrm_nvm_install_update_output(const char *string __rte_unused, struct hwrm_nvm_install_update_output *data);
void decode_hwrm_nvm_get_variable_input(const char *string __rte_unused, struct hwrm_nvm_get_variable_input *data);
void decode_hwrm_nvm_get_variable_output(const char *string __rte_unused, struct hwrm_nvm_get_variable_output *data);
void decode_hwrm_nvm_set_variable_input(const char *string __rte_unused, struct hwrm_nvm_set_variable_input *data);
void decode_hwrm_nvm_set_variable_output(const char *string __rte_unused, struct hwrm_nvm_set_variable_output *data);
void decode_cmdq_init(const char *string __rte_unused, struct cmdq_init *data);
void decode_cmdq_update(const char *string __rte_unused, struct cmdq_update *data);
void decode_cmdq_base(const char *string __rte_unused, struct cmdq_base *data);
void decode_cmdq_create_qp(const char *string __rte_unused, struct cmdq_create_qp *data);
void decode_cmdq_destroy_qp(const char *string __rte_unused, struct cmdq_destroy_qp *data);
void decode_cmdq_modify_qp(const char *string __rte_unused, struct cmdq_modify_qp *data);
void decode_cmdq_query_qp(const char *string __rte_unused, struct cmdq_query_qp *data);
void decode_cmdq_create_srq(const char *string __rte_unused, struct cmdq_create_srq *data);
void decode_cmdq_destroy_srq(const char *string __rte_unused, struct cmdq_destroy_srq *data);
void decode_cmdq_query_srq(const char *string __rte_unused, struct cmdq_query_srq *data);
void decode_cmdq_create_cq(const char *string __rte_unused, struct cmdq_create_cq *data);
void decode_cmdq_destroy_cq(const char *string __rte_unused, struct cmdq_destroy_cq *data);
void decode_cmdq_resize_cq(const char *string __rte_unused, struct cmdq_resize_cq *data);
void decode_cmdq_allocate_mrw(const char *string __rte_unused, struct cmdq_allocate_mrw *data);
void decode_cmdq_deallocate_key(const char *string __rte_unused, struct cmdq_deallocate_key *data);
void decode_cmdq_register_mr(const char *string __rte_unused, struct cmdq_register_mr *data);
void decode_cmdq_deregister_mr(const char *string __rte_unused, struct cmdq_deregister_mr *data);
void decode_cmdq_add_gid(const char *string __rte_unused, struct cmdq_add_gid *data);
void decode_cmdq_delete_gid(const char *string __rte_unused, struct cmdq_delete_gid *data);
void decode_cmdq_modify_gid(const char *string __rte_unused, struct cmdq_modify_gid *data);
void decode_cmdq_query_gid(const char *string __rte_unused, struct cmdq_query_gid *data);
void decode_cmdq_create_qp1(const char *string __rte_unused, struct cmdq_create_qp1 *data);
void decode_cmdq_destroy_qp1(const char *string __rte_unused, struct cmdq_destroy_qp1 *data);
void decode_cmdq_create_ah(const char *string __rte_unused, struct cmdq_create_ah *data);
void decode_cmdq_destroy_ah(const char *string __rte_unused, struct cmdq_destroy_ah *data);
void decode_cmdq_initialize_fw(const char *string __rte_unused, struct cmdq_initialize_fw *data);
void decode_cmdq_deinitialize_fw(const char *string __rte_unused, struct cmdq_deinitialize_fw *data);
void decode_cmdq_stop_func(const char *string __rte_unused, struct cmdq_stop_func *data);
void decode_cmdq_query_func(const char *string __rte_unused, struct cmdq_query_func *data);
void decode_cmdq_set_func_resources(const char *string __rte_unused, struct cmdq_set_func_resources *data);
void decode_cmdq_read_context(const char *string __rte_unused, struct cmdq_read_context *data);
void decode_cmdq_vf_backchannel_request(const char *string __rte_unused, struct cmdq_vf_backchannel_request *data);
void decode_cmdq_read_vf_memory(const char *string __rte_unused, struct cmdq_read_vf_memory *data);
void decode_cmdq_complete_vf_request(const char *string __rte_unused, struct cmdq_complete_vf_request *data);
void decode_cmdq_map_tc_to_cos(const char *string __rte_unused, struct cmdq_map_tc_to_cos *data);
void decode_cmdq_query_version(const char *string __rte_unused, struct cmdq_query_version *data);
void decode_cmdq_modify_roce_cc(const char *string __rte_unused, struct cmdq_modify_roce_cc *data);
void decode_cmdq_query_roce_cc(const char *string __rte_unused, struct cmdq_query_roce_cc *data);
void decode_creq_base(const char *string __rte_unused, struct creq_base *data);
void decode_creq_func_event(const char *string __rte_unused, struct creq_func_event *data);
void decode_creq_qp_event(const char *string __rte_unused, struct creq_qp_event *data);
void decode_creq_create_qp_resp(const char *string __rte_unused, struct creq_create_qp_resp *data);
void decode_creq_destroy_qp_resp(const char *string __rte_unused, struct creq_destroy_qp_resp *data);
void decode_creq_modify_qp_resp(const char *string __rte_unused, struct creq_modify_qp_resp *data);
void decode_creq_query_qp_resp(const char *string __rte_unused, struct creq_query_qp_resp *data);
void decode_creq_query_qp_resp_sb(const char *string __rte_unused, struct creq_query_qp_resp_sb *data);
void decode_creq_create_srq_resp(const char *string __rte_unused, struct creq_create_srq_resp *data);
void decode_creq_destroy_srq_resp(const char *string __rte_unused, struct creq_destroy_srq_resp *data);
void decode_creq_query_srq_resp(const char *string __rte_unused, struct creq_query_srq_resp *data);
void decode_creq_query_srq_resp_sb(const char *string __rte_unused, struct creq_query_srq_resp_sb *data);
void decode_creq_create_cq_resp(const char *string __rte_unused, struct creq_create_cq_resp *data);
void decode_creq_destroy_cq_resp(const char *string __rte_unused, struct creq_destroy_cq_resp *data);
void decode_creq_resize_cq_resp(const char *string __rte_unused, struct creq_resize_cq_resp *data);
void decode_creq_allocate_mrw_resp(const char *string __rte_unused, struct creq_allocate_mrw_resp *data);
void decode_creq_deallocate_key_resp(const char *string __rte_unused, struct creq_deallocate_key_resp *data);
void decode_creq_register_mr_resp(const char *string __rte_unused, struct creq_register_mr_resp *data);
void decode_creq_deregister_mr_resp(const char *string __rte_unused, struct creq_deregister_mr_resp *data);
void decode_creq_add_gid_resp(const char *string __rte_unused, struct creq_add_gid_resp *data);
void decode_creq_delete_gid_resp(const char *string __rte_unused, struct creq_delete_gid_resp *data);
void decode_creq_modify_gid_resp(const char *string __rte_unused, struct creq_modify_gid_resp *data);
void decode_creq_query_gid_resp(const char *string __rte_unused, struct creq_query_gid_resp *data);
void decode_creq_query_gid_resp_sb(const char *string __rte_unused, struct creq_query_gid_resp_sb *data);
void decode_creq_create_qp1_resp(const char *string __rte_unused, struct creq_create_qp1_resp *data);
void decode_creq_destroy_qp1_resp(const char *string __rte_unused, struct creq_destroy_qp1_resp *data);
void decode_creq_create_ah_resp(const char *string __rte_unused, struct creq_create_ah_resp *data);
void decode_creq_destroy_ah_resp(const char *string __rte_unused, struct creq_destroy_ah_resp *data);
void decode_creq_initialize_fw_resp(const char *string __rte_unused, struct creq_initialize_fw_resp *data);
void decode_creq_deinitialize_fw_resp(const char *string __rte_unused, struct creq_deinitialize_fw_resp *data);
void decode_creq_stop_func_resp(const char *string __rte_unused, struct creq_stop_func_resp *data);
void decode_creq_query_func_resp(const char *string __rte_unused, struct creq_query_func_resp *data);
void decode_creq_query_func_resp_sb(const char *string __rte_unused, struct creq_query_func_resp_sb *data);
void decode_creq_set_func_resources_resp(const char *string __rte_unused, struct creq_set_func_resources_resp *data);
void decode_creq_map_tc_to_cos_resp(const char *string __rte_unused, struct creq_map_tc_to_cos_resp *data);
void decode_creq_query_version_resp(const char *string __rte_unused, struct creq_query_version_resp *data);
void decode_creq_modify_roce_cc_resp(const char *string __rte_unused, struct creq_modify_roce_cc_resp *data);
void decode_creq_query_roce_cc_resp(const char *string __rte_unused, struct creq_query_roce_cc_resp *data);
void decode_creq_query_roce_cc_resp_sb(const char *string __rte_unused, struct creq_query_roce_cc_resp_sb *data);
void decode_creq_qp_error_notification(const char *string __rte_unused, struct creq_qp_error_notification *data);
void decode_input(const char *string __rte_unused, struct input *data);
void decode_output(const char *string __rte_unused, struct output *data);
void decode_hwrm_short_input(const char *string __rte_unused, struct hwrm_short_input *data);
void decode_cmd_nums(const char *string __rte_unused, struct cmd_nums *data);
void decode_ret_codes(const char *string __rte_unused, struct ret_codes *data);
void decode_hwrm_err_output(const char *string __rte_unused, struct hwrm_err_output *data);
void decode_tx_port_stats(const char *string __rte_unused, struct tx_port_stats *data);
void decode_rx_port_stats(const char *string __rte_unused, struct rx_port_stats *data);
void decode_ctx_hw_stats64(const char *string __rte_unused, struct ctx_hw_stats64 *data);
void decode_ctx_hw_stats(const char *string __rte_unused, struct ctx_hw_stats *data);
void decode_hwrm_struct_hdr(const char *string __rte_unused, struct hwrm_struct_hdr *data);
void decode_hwrm_struct_data_dcbx_ets(const char *string __rte_unused, struct hwrm_struct_data_dcbx_ets *data);
void decode_hwrm_struct_data_dcbx_pfc(const char *string __rte_unused, struct hwrm_struct_data_dcbx_pfc *data);
void decode_hwrm_struct_data_dcbx_app(const char *string __rte_unused, struct hwrm_struct_data_dcbx_app *data);
void decode_hwrm_struct_data_dcbx_feature_state(const char *string __rte_unused, struct hwrm_struct_data_dcbx_feature_state *data);
void decode_hwrm_struct_data_lldp(const char *string __rte_unused, struct hwrm_struct_data_lldp *data);
void decode_hwrm_struct_data_lldp_generic(const char *string __rte_unused, struct hwrm_struct_data_lldp_generic *data);
void decode_hwrm_struct_data_lldp_device(const char *string __rte_unused, struct hwrm_struct_data_lldp_device *data);
void decode_hwrm_struct_data_port_description(const char *string __rte_unused, struct hwrm_struct_data_port_description *data);
#define HWRM_DECODE_INPUT(buf) do { \
	switch(rte_le_to_cpu_16(((struct input *)buf)->req_type)) { \
	case HWRM_VER_GET:\
		decode_hwrm_ver_get_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_RESET:\
		decode_hwrm_func_reset_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_GETFID:\
		decode_hwrm_func_getfid_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_ALLOC:\
		decode_hwrm_func_vf_alloc_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_FREE:\
		decode_hwrm_func_vf_free_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_CFG:\
		decode_hwrm_func_vf_cfg_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_QCAPS:\
		decode_hwrm_func_qcaps_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_QCFG:\
		decode_hwrm_func_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_CFG:\
		decode_hwrm_func_cfg_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_QSTATS:\
		decode_hwrm_func_qstats_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_CLR_STATS:\
		decode_hwrm_func_clr_stats_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_RESC_FREE:\
		decode_hwrm_func_vf_resc_free_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_VNIC_IDS_QUERY:\
		decode_hwrm_func_vf_vnic_ids_query_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_DRV_RGTR:\
		decode_hwrm_func_drv_rgtr_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_DRV_UNRGTR:\
		decode_hwrm_func_drv_unrgtr_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_BUF_RGTR:\
		decode_hwrm_func_buf_rgtr_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_BUF_UNRGTR:\
		decode_hwrm_func_buf_unrgtr_input(NULL, (void *)buf); break;\
	case HWRM_FUNC_DRV_QVER:\
		decode_hwrm_func_drv_qver_input(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_CFG:\
		decode_hwrm_port_phy_cfg_input(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_QCFG:\
		decode_hwrm_port_phy_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_PORT_MAC_CFG:\
		decode_hwrm_port_mac_cfg_input(NULL, (void *)buf); break;\
	case HWRM_PORT_MAC_QCFG:\
		decode_hwrm_port_mac_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_PORT_QSTATS:\
		decode_hwrm_port_qstats_input(NULL, (void *)buf); break;\
	case HWRM_PORT_LPBK_QSTATS:\
		decode_hwrm_port_lpbk_qstats_input(NULL, (void *)buf); break;\
	case HWRM_PORT_CLR_STATS:\
		decode_hwrm_port_clr_stats_input(NULL, (void *)buf); break;\
	case HWRM_PORT_LPBK_CLR_STATS:\
		decode_hwrm_port_lpbk_clr_stats_input(NULL, (void *)buf); break;\
	case HWRM_PORT_TS_QUERY:\
		decode_hwrm_port_ts_query_input(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_QCAPS:\
		decode_hwrm_port_phy_qcaps_input(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_I2C_WRITE:\
		decode_hwrm_port_phy_i2c_write_input(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_I2C_READ:\
		decode_hwrm_port_phy_i2c_read_input(NULL, (void *)buf); break;\
	case HWRM_PORT_LED_CFG:\
		decode_hwrm_port_led_cfg_input(NULL, (void *)buf); break;\
	case HWRM_PORT_LED_QCFG:\
		decode_hwrm_port_led_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_PORT_LED_QCAPS:\
		decode_hwrm_port_led_qcaps_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_QPORTCFG:\
		decode_hwrm_queue_qportcfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_QCFG:\
		decode_hwrm_queue_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_CFG:\
		decode_hwrm_queue_cfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PFCENABLE_QCFG:\
		decode_hwrm_queue_pfcenable_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PFCENABLE_CFG:\
		decode_hwrm_queue_pfcenable_cfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PRI2COS_QCFG:\
		decode_hwrm_queue_pri2cos_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PRI2COS_CFG:\
		decode_hwrm_queue_pri2cos_cfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_COS2BW_QCFG:\
		decode_hwrm_queue_cos2bw_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_QUEUE_COS2BW_CFG:\
		decode_hwrm_queue_cos2bw_cfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_ALLOC:\
		decode_hwrm_vnic_alloc_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_FREE:\
		decode_hwrm_vnic_free_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_CFG:\
		decode_hwrm_vnic_cfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_QCFG:\
		decode_hwrm_vnic_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_QCAPS:\
		decode_hwrm_vnic_qcaps_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_TPA_CFG:\
		decode_hwrm_vnic_tpa_cfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_TPA_QCFG:\
		decode_hwrm_vnic_tpa_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_CFG:\
		decode_hwrm_vnic_rss_cfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_QCFG:\
		decode_hwrm_vnic_rss_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_PLCMODES_CFG:\
		decode_hwrm_vnic_plcmodes_cfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_PLCMODES_QCFG:\
		decode_hwrm_vnic_plcmodes_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_COS_LB_CTX_ALLOC:\
		decode_hwrm_vnic_rss_cos_lb_ctx_alloc_input(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_COS_LB_CTX_FREE:\
		decode_hwrm_vnic_rss_cos_lb_ctx_free_input(NULL, (void *)buf); break;\
	case HWRM_RING_ALLOC:\
		decode_hwrm_ring_alloc_input(NULL, (void *)buf); break;\
	case HWRM_RING_FREE:\
		decode_hwrm_ring_free_input(NULL, (void *)buf); break;\
	case HWRM_RING_CMPL_RING_QAGGINT_PARAMS:\
		decode_hwrm_ring_cmpl_ring_qaggint_params_input(NULL, (void *)buf); break;\
	case HWRM_RING_CMPL_RING_CFG_AGGINT_PARAMS:\
		decode_hwrm_ring_cmpl_ring_cfg_aggint_params_input(NULL, (void *)buf); break;\
	case HWRM_RING_RESET:\
		decode_hwrm_ring_reset_input(NULL, (void *)buf); break;\
	case HWRM_RING_GRP_ALLOC:\
		decode_hwrm_ring_grp_alloc_input(NULL, (void *)buf); break;\
	case HWRM_RING_GRP_FREE:\
		decode_hwrm_ring_grp_free_input(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_FILTER_ALLOC:\
		decode_hwrm_cfa_l2_filter_alloc_input(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_FILTER_FREE:\
		decode_hwrm_cfa_l2_filter_free_input(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_FILTER_CFG:\
		decode_hwrm_cfa_l2_filter_cfg_input(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_SET_RX_MASK:\
		decode_hwrm_cfa_l2_set_rx_mask_input(NULL, (void *)buf); break;\
	case HWRM_CFA_TUNNEL_FILTER_ALLOC:\
		decode_hwrm_cfa_tunnel_filter_alloc_input(NULL, (void *)buf); break;\
	case HWRM_CFA_TUNNEL_FILTER_FREE:\
		decode_hwrm_cfa_tunnel_filter_free_input(NULL, (void *)buf); break;\
	case HWRM_CFA_ENCAP_RECORD_ALLOC:\
		decode_hwrm_cfa_encap_record_alloc_input(NULL, (void *)buf); break;\
	case HWRM_CFA_ENCAP_RECORD_FREE:\
		decode_hwrm_cfa_encap_record_free_input(NULL, (void *)buf); break;\
	case HWRM_CFA_NTUPLE_FILTER_ALLOC:\
		decode_hwrm_cfa_ntuple_filter_alloc_input(NULL, (void *)buf); break;\
	case HWRM_CFA_NTUPLE_FILTER_FREE:\
		decode_hwrm_cfa_ntuple_filter_free_input(NULL, (void *)buf); break;\
	case HWRM_CFA_NTUPLE_FILTER_CFG:\
		decode_hwrm_cfa_ntuple_filter_cfg_input(NULL, (void *)buf); break;\
	case HWRM_CFA_EM_FLOW_ALLOC:\
		decode_hwrm_cfa_em_flow_alloc_input(NULL, (void *)buf); break;\
	case HWRM_CFA_EM_FLOW_FREE:\
		decode_hwrm_cfa_em_flow_free_input(NULL, (void *)buf); break;\
	case HWRM_CFA_EM_FLOW_CFG:\
		decode_hwrm_cfa_em_flow_cfg_input(NULL, (void *)buf); break;\
	case HWRM_TUNNEL_DST_PORT_QUERY:\
		decode_hwrm_tunnel_dst_port_query_input(NULL, (void *)buf); break;\
	case HWRM_TUNNEL_DST_PORT_ALLOC:\
		decode_hwrm_tunnel_dst_port_alloc_input(NULL, (void *)buf); break;\
	case HWRM_TUNNEL_DST_PORT_FREE:\
		decode_hwrm_tunnel_dst_port_free_input(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_ALLOC:\
		decode_hwrm_stat_ctx_alloc_input(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_FREE:\
		decode_hwrm_stat_ctx_free_input(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_QUERY:\
		decode_hwrm_stat_ctx_query_input(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_CLR_STATS:\
		decode_hwrm_stat_ctx_clr_stats_input(NULL, (void *)buf); break;\
	case HWRM_FW_RESET:\
		decode_hwrm_fw_reset_input(NULL, (void *)buf); break;\
	case HWRM_FW_QSTATUS:\
		decode_hwrm_fw_qstatus_input(NULL, (void *)buf); break;\
	case HWRM_FW_SET_TIME:\
		decode_hwrm_fw_set_time_input(NULL, (void *)buf); break;\
	case HWRM_FW_GET_TIME:\
		decode_hwrm_fw_get_time_input(NULL, (void *)buf); break;\
	case HWRM_FW_SET_STRUCTURED_DATA:\
		decode_hwrm_fw_set_structured_data_input(NULL, (void *)buf); break;\
	case HWRM_FW_GET_STRUCTURED_DATA:\
		decode_hwrm_fw_get_structured_data_input(NULL, (void *)buf); break;\
	case HWRM_FW_IPC_MAILBOX:\
		decode_hwrm_fw_ipc_mailbox_input(NULL, (void *)buf); break;\
	case HWRM_EXEC_FWD_RESP:\
		decode_hwrm_exec_fwd_resp_input(NULL, (void *)buf); break;\
	case HWRM_REJECT_FWD_RESP:\
		decode_hwrm_reject_fwd_resp_input(NULL, (void *)buf); break;\
	case HWRM_FWD_RESP:\
		decode_hwrm_fwd_resp_input(NULL, (void *)buf); break;\
	case HWRM_FWD_ASYNC_EVENT_CMPL:\
		decode_hwrm_fwd_async_event_cmpl_input(NULL, (void *)buf); break;\
	case HWRM_TEMP_MONITOR_QUERY:\
		decode_hwrm_temp_monitor_query_input(NULL, (void *)buf); break;\
	case HWRM_WOL_FILTER_ALLOC:\
		decode_hwrm_wol_filter_alloc_input(NULL, (void *)buf); break;\
	case HWRM_WOL_FILTER_FREE:\
		decode_hwrm_wol_filter_free_input(NULL, (void *)buf); break;\
	case HWRM_WOL_FILTER_QCFG:\
		decode_hwrm_wol_filter_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_WOL_REASON_QCFG:\
		decode_hwrm_wol_reason_qcfg_input(NULL, (void *)buf); break;\
	case HWRM_DBG_READ_DIRECT:\
		decode_hwrm_dbg_read_direct_input(NULL, (void *)buf); break;\
	case HWRM_DBG_WRITE_DIRECT:\
		decode_hwrm_dbg_write_direct_input(NULL, (void *)buf); break;\
	case HWRM_DBG_READ_INDIRECT:\
		decode_hwrm_dbg_read_indirect_input(NULL, (void *)buf); break;\
	case HWRM_DBG_WRITE_INDIRECT:\
		decode_hwrm_dbg_write_indirect_input(NULL, (void *)buf); break;\
	case HWRM_DBG_DUMP:\
		decode_hwrm_dbg_dump_input(NULL, (void *)buf); break;\
	case HWRM_NVM_RAW_WRITE_BLK:\
		decode_hwrm_nvm_raw_write_blk_input(NULL, (void *)buf); break;\
	case HWRM_NVM_READ:\
		decode_hwrm_nvm_read_input(NULL, (void *)buf); break;\
	case HWRM_NVM_RAW_DUMP:\
		decode_hwrm_nvm_raw_dump_input(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_DIR_ENTRIES:\
		decode_hwrm_nvm_get_dir_entries_input(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_DIR_INFO:\
		decode_hwrm_nvm_get_dir_info_input(NULL, (void *)buf); break;\
	case HWRM_NVM_WRITE:\
		decode_hwrm_nvm_write_input(NULL, (void *)buf); break;\
	case HWRM_NVM_MODIFY:\
		decode_hwrm_nvm_modify_input(NULL, (void *)buf); break;\
	case HWRM_NVM_FIND_DIR_ENTRY:\
		decode_hwrm_nvm_find_dir_entry_input(NULL, (void *)buf); break;\
	case HWRM_NVM_ERASE_DIR_ENTRY:\
		decode_hwrm_nvm_erase_dir_entry_input(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_DEV_INFO:\
		decode_hwrm_nvm_get_dev_info_input(NULL, (void *)buf); break;\
	case HWRM_NVM_MOD_DIR_ENTRY:\
		decode_hwrm_nvm_mod_dir_entry_input(NULL, (void *)buf); break;\
	case HWRM_NVM_VERIFY_UPDATE:\
		decode_hwrm_nvm_verify_update_input(NULL, (void *)buf); break;\
	case HWRM_NVM_INSTALL_UPDATE:\
		decode_hwrm_nvm_install_update_input(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_VARIABLE:\
		decode_hwrm_nvm_get_variable_input(NULL, (void *)buf); break;\
	case HWRM_NVM_SET_VARIABLE:\
		decode_hwrm_nvm_set_variable_input(NULL, (void *)buf); break;\
	} \
} while(0)
#define HWRM_DECODE_OUTPUT(buf) do { \
	switch(rte_le_to_cpu_16(((struct output *)buf)->req_type)) { \
	case HWRM_VER_GET:\
		decode_hwrm_ver_get_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_RESET:\
		decode_hwrm_func_reset_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_GETFID:\
		decode_hwrm_func_getfid_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_ALLOC:\
		decode_hwrm_func_vf_alloc_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_FREE:\
		decode_hwrm_func_vf_free_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_CFG:\
		decode_hwrm_func_vf_cfg_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_QCAPS:\
		decode_hwrm_func_qcaps_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_QCFG:\
		decode_hwrm_func_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_CFG:\
		decode_hwrm_func_cfg_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_QSTATS:\
		decode_hwrm_func_qstats_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_CLR_STATS:\
		decode_hwrm_func_clr_stats_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_RESC_FREE:\
		decode_hwrm_func_vf_resc_free_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_VF_VNIC_IDS_QUERY:\
		decode_hwrm_func_vf_vnic_ids_query_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_DRV_RGTR:\
		decode_hwrm_func_drv_rgtr_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_DRV_UNRGTR:\
		decode_hwrm_func_drv_unrgtr_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_BUF_RGTR:\
		decode_hwrm_func_buf_rgtr_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_BUF_UNRGTR:\
		decode_hwrm_func_buf_unrgtr_output(NULL, (void *)buf); break;\
	case HWRM_FUNC_DRV_QVER:\
		decode_hwrm_func_drv_qver_output(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_CFG:\
		decode_hwrm_port_phy_cfg_output(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_QCFG:\
		decode_hwrm_port_phy_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_PORT_MAC_CFG:\
		decode_hwrm_port_mac_cfg_output(NULL, (void *)buf); break;\
	case HWRM_PORT_MAC_QCFG:\
		decode_hwrm_port_mac_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_PORT_QSTATS:\
		decode_hwrm_port_qstats_output(NULL, (void *)buf); break;\
	case HWRM_PORT_LPBK_QSTATS:\
		decode_hwrm_port_lpbk_qstats_output(NULL, (void *)buf); break;\
	case HWRM_PORT_CLR_STATS:\
		decode_hwrm_port_clr_stats_output(NULL, (void *)buf); break;\
	case HWRM_PORT_LPBK_CLR_STATS:\
		decode_hwrm_port_lpbk_clr_stats_output(NULL, (void *)buf); break;\
	case HWRM_PORT_TS_QUERY:\
		decode_hwrm_port_ts_query_output(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_QCAPS:\
		decode_hwrm_port_phy_qcaps_output(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_I2C_WRITE:\
		decode_hwrm_port_phy_i2c_write_output(NULL, (void *)buf); break;\
	case HWRM_PORT_PHY_I2C_READ:\
		decode_hwrm_port_phy_i2c_read_output(NULL, (void *)buf); break;\
	case HWRM_PORT_LED_CFG:\
		decode_hwrm_port_led_cfg_output(NULL, (void *)buf); break;\
	case HWRM_PORT_LED_QCFG:\
		decode_hwrm_port_led_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_PORT_LED_QCAPS:\
		decode_hwrm_port_led_qcaps_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_QPORTCFG:\
		decode_hwrm_queue_qportcfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_QCFG:\
		decode_hwrm_queue_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_CFG:\
		decode_hwrm_queue_cfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PFCENABLE_QCFG:\
		decode_hwrm_queue_pfcenable_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PFCENABLE_CFG:\
		decode_hwrm_queue_pfcenable_cfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PRI2COS_QCFG:\
		decode_hwrm_queue_pri2cos_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_PRI2COS_CFG:\
		decode_hwrm_queue_pri2cos_cfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_COS2BW_QCFG:\
		decode_hwrm_queue_cos2bw_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_QUEUE_COS2BW_CFG:\
		decode_hwrm_queue_cos2bw_cfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_ALLOC:\
		decode_hwrm_vnic_alloc_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_FREE:\
		decode_hwrm_vnic_free_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_CFG:\
		decode_hwrm_vnic_cfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_QCFG:\
		decode_hwrm_vnic_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_QCAPS:\
		decode_hwrm_vnic_qcaps_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_TPA_CFG:\
		decode_hwrm_vnic_tpa_cfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_TPA_QCFG:\
		decode_hwrm_vnic_tpa_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_CFG:\
		decode_hwrm_vnic_rss_cfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_QCFG:\
		decode_hwrm_vnic_rss_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_PLCMODES_CFG:\
		decode_hwrm_vnic_plcmodes_cfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_PLCMODES_QCFG:\
		decode_hwrm_vnic_plcmodes_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_COS_LB_CTX_ALLOC:\
		decode_hwrm_vnic_rss_cos_lb_ctx_alloc_output(NULL, (void *)buf); break;\
	case HWRM_VNIC_RSS_COS_LB_CTX_FREE:\
		decode_hwrm_vnic_rss_cos_lb_ctx_free_output(NULL, (void *)buf); break;\
	case HWRM_RING_ALLOC:\
		decode_hwrm_ring_alloc_output(NULL, (void *)buf); break;\
	case HWRM_RING_FREE:\
		decode_hwrm_ring_free_output(NULL, (void *)buf); break;\
	case HWRM_RING_CMPL_RING_QAGGINT_PARAMS:\
		decode_hwrm_ring_cmpl_ring_qaggint_params_output(NULL, (void *)buf); break;\
	case HWRM_RING_CMPL_RING_CFG_AGGINT_PARAMS:\
		decode_hwrm_ring_cmpl_ring_cfg_aggint_params_output(NULL, (void *)buf); break;\
	case HWRM_RING_RESET:\
		decode_hwrm_ring_reset_output(NULL, (void *)buf); break;\
	case HWRM_RING_GRP_ALLOC:\
		decode_hwrm_ring_grp_alloc_output(NULL, (void *)buf); break;\
	case HWRM_RING_GRP_FREE:\
		decode_hwrm_ring_grp_free_output(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_FILTER_ALLOC:\
		decode_hwrm_cfa_l2_filter_alloc_output(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_FILTER_FREE:\
		decode_hwrm_cfa_l2_filter_free_output(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_FILTER_CFG:\
		decode_hwrm_cfa_l2_filter_cfg_output(NULL, (void *)buf); break;\
	case HWRM_CFA_L2_SET_RX_MASK:\
		decode_hwrm_cfa_l2_set_rx_mask_output(NULL, (void *)buf); break;\
	case HWRM_CFA_TUNNEL_FILTER_ALLOC:\
		decode_hwrm_cfa_tunnel_filter_alloc_output(NULL, (void *)buf); break;\
	case HWRM_CFA_TUNNEL_FILTER_FREE:\
		decode_hwrm_cfa_tunnel_filter_free_output(NULL, (void *)buf); break;\
	case HWRM_CFA_ENCAP_RECORD_ALLOC:\
		decode_hwrm_cfa_encap_record_alloc_output(NULL, (void *)buf); break;\
	case HWRM_CFA_ENCAP_RECORD_FREE:\
		decode_hwrm_cfa_encap_record_free_output(NULL, (void *)buf); break;\
	case HWRM_CFA_NTUPLE_FILTER_ALLOC:\
		decode_hwrm_cfa_ntuple_filter_alloc_output(NULL, (void *)buf); break;\
	case HWRM_CFA_NTUPLE_FILTER_FREE:\
		decode_hwrm_cfa_ntuple_filter_free_output(NULL, (void *)buf); break;\
	case HWRM_CFA_NTUPLE_FILTER_CFG:\
		decode_hwrm_cfa_ntuple_filter_cfg_output(NULL, (void *)buf); break;\
	case HWRM_CFA_EM_FLOW_ALLOC:\
		decode_hwrm_cfa_em_flow_alloc_output(NULL, (void *)buf); break;\
	case HWRM_CFA_EM_FLOW_FREE:\
		decode_hwrm_cfa_em_flow_free_output(NULL, (void *)buf); break;\
	case HWRM_CFA_EM_FLOW_CFG:\
		decode_hwrm_cfa_em_flow_cfg_output(NULL, (void *)buf); break;\
	case HWRM_TUNNEL_DST_PORT_QUERY:\
		decode_hwrm_tunnel_dst_port_query_output(NULL, (void *)buf); break;\
	case HWRM_TUNNEL_DST_PORT_ALLOC:\
		decode_hwrm_tunnel_dst_port_alloc_output(NULL, (void *)buf); break;\
	case HWRM_TUNNEL_DST_PORT_FREE:\
		decode_hwrm_tunnel_dst_port_free_output(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_ALLOC:\
		decode_hwrm_stat_ctx_alloc_output(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_FREE:\
		decode_hwrm_stat_ctx_free_output(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_QUERY:\
		decode_hwrm_stat_ctx_query_output(NULL, (void *)buf); break;\
	case HWRM_STAT_CTX_CLR_STATS:\
		decode_hwrm_stat_ctx_clr_stats_output(NULL, (void *)buf); break;\
	case HWRM_FW_RESET:\
		decode_hwrm_fw_reset_output(NULL, (void *)buf); break;\
	case HWRM_FW_QSTATUS:\
		decode_hwrm_fw_qstatus_output(NULL, (void *)buf); break;\
	case HWRM_FW_SET_TIME:\
		decode_hwrm_fw_set_time_output(NULL, (void *)buf); break;\
	case HWRM_FW_GET_TIME:\
		decode_hwrm_fw_get_time_output(NULL, (void *)buf); break;\
	case HWRM_FW_SET_STRUCTURED_DATA:\
		decode_hwrm_fw_set_structured_data_output(NULL, (void *)buf); break;\
	case HWRM_FW_GET_STRUCTURED_DATA:\
		decode_hwrm_fw_get_structured_data_output(NULL, (void *)buf); break;\
	case HWRM_FW_IPC_MAILBOX:\
		decode_hwrm_fw_ipc_mailbox_output(NULL, (void *)buf); break;\
	case HWRM_EXEC_FWD_RESP:\
		decode_hwrm_exec_fwd_resp_output(NULL, (void *)buf); break;\
	case HWRM_REJECT_FWD_RESP:\
		decode_hwrm_reject_fwd_resp_output(NULL, (void *)buf); break;\
	case HWRM_FWD_RESP:\
		decode_hwrm_fwd_resp_output(NULL, (void *)buf); break;\
	case HWRM_FWD_ASYNC_EVENT_CMPL:\
		decode_hwrm_fwd_async_event_cmpl_output(NULL, (void *)buf); break;\
	case HWRM_TEMP_MONITOR_QUERY:\
		decode_hwrm_temp_monitor_query_output(NULL, (void *)buf); break;\
	case HWRM_WOL_FILTER_ALLOC:\
		decode_hwrm_wol_filter_alloc_output(NULL, (void *)buf); break;\
	case HWRM_WOL_FILTER_FREE:\
		decode_hwrm_wol_filter_free_output(NULL, (void *)buf); break;\
	case HWRM_WOL_FILTER_QCFG:\
		decode_hwrm_wol_filter_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_WOL_REASON_QCFG:\
		decode_hwrm_wol_reason_qcfg_output(NULL, (void *)buf); break;\
	case HWRM_DBG_READ_DIRECT:\
		decode_hwrm_dbg_read_direct_output(NULL, (void *)buf); break;\
	case HWRM_DBG_WRITE_DIRECT:\
		decode_hwrm_dbg_write_direct_output(NULL, (void *)buf); break;\
	case HWRM_DBG_READ_INDIRECT:\
		decode_hwrm_dbg_read_indirect_output(NULL, (void *)buf); break;\
	case HWRM_DBG_WRITE_INDIRECT:\
		decode_hwrm_dbg_write_indirect_output(NULL, (void *)buf); break;\
	case HWRM_DBG_DUMP:\
		decode_hwrm_dbg_dump_output(NULL, (void *)buf); break;\
	case HWRM_NVM_RAW_WRITE_BLK:\
		decode_hwrm_nvm_raw_write_blk_output(NULL, (void *)buf); break;\
	case HWRM_NVM_READ:\
		decode_hwrm_nvm_read_output(NULL, (void *)buf); break;\
	case HWRM_NVM_RAW_DUMP:\
		decode_hwrm_nvm_raw_dump_output(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_DIR_ENTRIES:\
		decode_hwrm_nvm_get_dir_entries_output(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_DIR_INFO:\
		decode_hwrm_nvm_get_dir_info_output(NULL, (void *)buf); break;\
	case HWRM_NVM_WRITE:\
		decode_hwrm_nvm_write_output(NULL, (void *)buf); break;\
	case HWRM_NVM_MODIFY:\
		decode_hwrm_nvm_modify_output(NULL, (void *)buf); break;\
	case HWRM_NVM_FIND_DIR_ENTRY:\
		decode_hwrm_nvm_find_dir_entry_output(NULL, (void *)buf); break;\
	case HWRM_NVM_ERASE_DIR_ENTRY:\
		decode_hwrm_nvm_erase_dir_entry_output(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_DEV_INFO:\
		decode_hwrm_nvm_get_dev_info_output(NULL, (void *)buf); break;\
	case HWRM_NVM_MOD_DIR_ENTRY:\
		decode_hwrm_nvm_mod_dir_entry_output(NULL, (void *)buf); break;\
	case HWRM_NVM_VERIFY_UPDATE:\
		decode_hwrm_nvm_verify_update_output(NULL, (void *)buf); break;\
	case HWRM_NVM_INSTALL_UPDATE:\
		decode_hwrm_nvm_install_update_output(NULL, (void *)buf); break;\
	case HWRM_NVM_GET_VARIABLE:\
		decode_hwrm_nvm_get_variable_output(NULL, (void *)buf); break;\
	case HWRM_NVM_SET_VARIABLE:\
		decode_hwrm_nvm_set_variable_output(NULL, (void *)buf); break;\
	} \
} while(0)
#else
#define decode_bd_base(x, y) {}
#define decode_tx_bd_short(x, y) {}
#define decode_tx_bd_long(x, y) {}
#define decode_tx_bd_long_hi(x, y) {}
#define decode_tx_bd_empty(x, y) {}
#define decode_rx_prod_pkt_bd(x, y) {}
#define decode_rx_prod_bfr_bd(x, y) {}
#define decode_rx_prod_agg_bd(x, y) {}
#define decode_cmpl_base(x, y) {}
#define decode_tx_cmpl(x, y) {}
#define decode_rx_pkt_cmpl(x, y) {}
#define decode_rx_pkt_cmpl_hi(x, y) {}
#define decode_rx_tpa_start_cmpl(x, y) {}
#define decode_rx_tpa_start_cmpl_hi(x, y) {}
#define decode_rx_tpa_end_cmpl(x, y) {}
#define decode_rx_tpa_end_cmpl_hi(x, y) {}
#define decode_rx_abuf_cmpl(x, y) {}
#define decode_eject_cmpl(x, y) {}
#define decode_hwrm_cmpl(x, y) {}
#define decode_hwrm_fwd_req_cmpl(x, y) {}
#define decode_hwrm_fwd_resp_cmpl(x, y) {}
#define decode_hwrm_async_event_cmpl(x, y) {}
#define decode_hwrm_async_event_cmpl_link_status_change(x, y) {}
#define decode_hwrm_async_event_cmpl_link_mtu_change(x, y) {}
#define decode_hwrm_async_event_cmpl_link_speed_change(x, y) {}
#define decode_hwrm_async_event_cmpl_dcb_config_change(x, y) {}
#define decode_hwrm_async_event_cmpl_port_conn_not_allowed(x, y) {}
#define decode_hwrm_async_event_cmpl_link_speed_cfg_not_allowed(x, y) {}
#define decode_hwrm_async_event_cmpl_link_speed_cfg_change(x, y) {}
#define decode_hwrm_async_event_cmpl_port_phy_cfg_change(x, y) {}
#define decode_hwrm_async_event_cmpl_func_drvr_unload(x, y) {}
#define decode_hwrm_async_event_cmpl_func_drvr_load(x, y) {}
#define decode_hwrm_async_event_cmpl_func_flr_proc_cmplt(x, y) {}
#define decode_hwrm_async_event_cmpl_pf_drvr_unload(x, y) {}
#define decode_hwrm_async_event_cmpl_pf_drvr_load(x, y) {}
#define decode_hwrm_async_event_cmpl_vf_flr(x, y) {}
#define decode_hwrm_async_event_cmpl_vf_mac_addr_change(x, y) {}
#define decode_hwrm_async_event_cmpl_pf_vf_comm_status_change(x, y) {}
#define decode_hwrm_async_event_cmpl_vf_cfg_change(x, y) {}
#define decode_hwrm_async_event_cmpl_hwrm_error(x, y) {}
#define decode_tx_doorbell(x, y) {}
#define decode_rx_doorbell(x, y) {}
#define decode_cmpl_doorbell(x, y) {}
#define decode_status_doorbell(x, y) {}
#define decode_push32_doorbell(x, y) {}
#define decode_dbr_dbr(x, y) {}
#define decode_dbr_dbr32(x, y) {}
#define decode_sq_base(x, y) {}
#define decode_sq_sge(x, y) {}
#define decode_sq_psn_search(x, y) {}
#define decode_sq_send(x, y) {}
#define decode_sq_send_raweth_qp1(x, y) {}
#define decode_sq_rdma(x, y) {}
#define decode_sq_atomic(x, y) {}
#define decode_sq_localinvalidate(x, y) {}
#define decode_sq_fr_pmr(x, y) {}
#define decode_sq_bind(x, y) {}
#define decode_rq_wqe(x, y) {}
#define decode_cq_base(x, y) {}
#define decode_cq_req(x, y) {}
#define decode_cq_res_rc(x, y) {}
#define decode_cq_res_ud(x, y) {}
#define decode_cq_res_raweth_qp1(x, y) {}
#define decode_cq_terminal(x, y) {}
#define decode_cq_cutoff(x, y) {}
#define decode_nq_base(x, y) {}
#define decode_nq_cn(x, y) {}
#define decode_nq_srq_event(x, y) {}
#define decode_nq_dbq_event(x, y) {}
#define decode_xrrq_irrq(x, y) {}
#define decode_xrrq_orrq(x, y) {}
#define decode_ptu_pte(x, y) {}
#define decode_ptu_pde(x, y) {}
#define decode_hwrm_ver_get_input(x, y) {}
#define decode_hwrm_ver_get_output(x, y) {}
#define decode_hwrm_func_reset_input(x, y) {}
#define decode_hwrm_func_reset_output(x, y) {}
#define decode_hwrm_func_getfid_input(x, y) {}
#define decode_hwrm_func_getfid_output(x, y) {}
#define decode_hwrm_func_vf_alloc_input(x, y) {}
#define decode_hwrm_func_vf_alloc_output(x, y) {}
#define decode_hwrm_func_vf_free_input(x, y) {}
#define decode_hwrm_func_vf_free_output(x, y) {}
#define decode_hwrm_func_vf_cfg_input(x, y) {}
#define decode_hwrm_func_vf_cfg_output(x, y) {}
#define decode_hwrm_func_qcaps_input(x, y) {}
#define decode_hwrm_func_qcaps_output(x, y) {}
#define decode_hwrm_func_qcfg_input(x, y) {}
#define decode_hwrm_func_qcfg_output(x, y) {}
#define decode_hwrm_func_cfg_input(x, y) {}
#define decode_hwrm_func_cfg_output(x, y) {}
#define decode_hwrm_func_qstats_input(x, y) {}
#define decode_hwrm_func_qstats_output(x, y) {}
#define decode_hwrm_func_clr_stats_input(x, y) {}
#define decode_hwrm_func_clr_stats_output(x, y) {}
#define decode_hwrm_func_vf_resc_free_input(x, y) {}
#define decode_hwrm_func_vf_resc_free_output(x, y) {}
#define decode_hwrm_func_vf_vnic_ids_query_input(x, y) {}
#define decode_hwrm_func_vf_vnic_ids_query_output(x, y) {}
#define decode_hwrm_func_drv_rgtr_input(x, y) {}
#define decode_hwrm_func_drv_rgtr_output(x, y) {}
#define decode_hwrm_func_drv_unrgtr_input(x, y) {}
#define decode_hwrm_func_drv_unrgtr_output(x, y) {}
#define decode_hwrm_func_buf_rgtr_input(x, y) {}
#define decode_hwrm_func_buf_rgtr_output(x, y) {}
#define decode_hwrm_func_buf_unrgtr_input(x, y) {}
#define decode_hwrm_func_buf_unrgtr_output(x, y) {}
#define decode_hwrm_func_drv_qver_input(x, y) {}
#define decode_hwrm_func_drv_qver_output(x, y) {}
#define decode_hwrm_port_phy_cfg_input(x, y) {}
#define decode_hwrm_port_phy_cfg_output(x, y) {}
#define decode_hwrm_port_phy_qcfg_input(x, y) {}
#define decode_hwrm_port_phy_qcfg_output(x, y) {}
#define decode_hwrm_port_mac_cfg_input(x, y) {}
#define decode_hwrm_port_mac_cfg_output(x, y) {}
#define decode_hwrm_port_mac_qcfg_input(x, y) {}
#define decode_hwrm_port_mac_qcfg_output(x, y) {}
#define decode_hwrm_port_qstats_input(x, y) {}
#define decode_hwrm_port_qstats_output(x, y) {}
#define decode_hwrm_port_lpbk_qstats_input(x, y) {}
#define decode_hwrm_port_lpbk_qstats_output(x, y) {}
#define decode_hwrm_port_clr_stats_input(x, y) {}
#define decode_hwrm_port_clr_stats_output(x, y) {}
#define decode_hwrm_port_lpbk_clr_stats_input(x, y) {}
#define decode_hwrm_port_lpbk_clr_stats_output(x, y) {}
#define decode_hwrm_port_ts_query_input(x, y) {}
#define decode_hwrm_port_ts_query_output(x, y) {}
#define decode_hwrm_port_phy_qcaps_input(x, y) {}
#define decode_hwrm_port_phy_qcaps_output(x, y) {}
#define decode_hwrm_port_phy_i2c_write_input(x, y) {}
#define decode_hwrm_port_phy_i2c_write_output(x, y) {}
#define decode_hwrm_port_phy_i2c_read_input(x, y) {}
#define decode_hwrm_port_phy_i2c_read_output(x, y) {}
#define decode_hwrm_port_led_cfg_input(x, y) {}
#define decode_hwrm_port_led_cfg_output(x, y) {}
#define decode_hwrm_port_led_qcfg_input(x, y) {}
#define decode_hwrm_port_led_qcfg_output(x, y) {}
#define decode_hwrm_port_led_qcaps_input(x, y) {}
#define decode_hwrm_port_led_qcaps_output(x, y) {}
#define decode_hwrm_queue_qportcfg_input(x, y) {}
#define decode_hwrm_queue_qportcfg_output(x, y) {}
#define decode_hwrm_queue_qcfg_input(x, y) {}
#define decode_hwrm_queue_qcfg_output(x, y) {}
#define decode_hwrm_queue_cfg_input(x, y) {}
#define decode_hwrm_queue_cfg_output(x, y) {}
#define decode_hwrm_queue_pfcenable_qcfg_input(x, y) {}
#define decode_hwrm_queue_pfcenable_qcfg_output(x, y) {}
#define decode_hwrm_queue_pfcenable_cfg_input(x, y) {}
#define decode_hwrm_queue_pfcenable_cfg_output(x, y) {}
#define decode_hwrm_queue_pri2cos_qcfg_input(x, y) {}
#define decode_hwrm_queue_pri2cos_qcfg_output(x, y) {}
#define decode_hwrm_queue_pri2cos_cfg_input(x, y) {}
#define decode_hwrm_queue_pri2cos_cfg_output(x, y) {}
#define decode_hwrm_queue_cos2bw_qcfg_input(x, y) {}
#define decode_hwrm_queue_cos2bw_qcfg_output(x, y) {}
#define decode_hwrm_queue_cos2bw_cfg_input(x, y) {}
#define decode_hwrm_queue_cos2bw_cfg_output(x, y) {}
#define decode_hwrm_vnic_alloc_input(x, y) {}
#define decode_hwrm_vnic_alloc_output(x, y) {}
#define decode_hwrm_vnic_free_input(x, y) {}
#define decode_hwrm_vnic_free_output(x, y) {}
#define decode_hwrm_vnic_cfg_input(x, y) {}
#define decode_hwrm_vnic_cfg_output(x, y) {}
#define decode_hwrm_vnic_qcfg_input(x, y) {}
#define decode_hwrm_vnic_qcfg_output(x, y) {}
#define decode_hwrm_vnic_qcaps_input(x, y) {}
#define decode_hwrm_vnic_qcaps_output(x, y) {}
#define decode_hwrm_vnic_tpa_cfg_input(x, y) {}
#define decode_hwrm_vnic_tpa_cfg_output(x, y) {}
#define decode_hwrm_vnic_tpa_qcfg_input(x, y) {}
#define decode_hwrm_vnic_tpa_qcfg_output(x, y) {}
#define decode_hwrm_vnic_rss_cfg_input(x, y) {}
#define decode_hwrm_vnic_rss_cfg_output(x, y) {}
#define decode_hwrm_vnic_rss_qcfg_input(x, y) {}
#define decode_hwrm_vnic_rss_qcfg_output(x, y) {}
#define decode_hwrm_vnic_plcmodes_cfg_input(x, y) {}
#define decode_hwrm_vnic_plcmodes_cfg_output(x, y) {}
#define decode_hwrm_vnic_plcmodes_qcfg_input(x, y) {}
#define decode_hwrm_vnic_plcmodes_qcfg_output(x, y) {}
#define decode_hwrm_vnic_rss_cos_lb_ctx_alloc_input(x, y) {}
#define decode_hwrm_vnic_rss_cos_lb_ctx_alloc_output(x, y) {}
#define decode_hwrm_vnic_rss_cos_lb_ctx_free_input(x, y) {}
#define decode_hwrm_vnic_rss_cos_lb_ctx_free_output(x, y) {}
#define decode_hwrm_ring_alloc_input(x, y) {}
#define decode_hwrm_ring_alloc_output(x, y) {}
#define decode_hwrm_ring_free_input(x, y) {}
#define decode_hwrm_ring_free_output(x, y) {}
#define decode_hwrm_ring_cmpl_ring_qaggint_params_input(x, y) {}
#define decode_hwrm_ring_cmpl_ring_qaggint_params_output(x, y) {}
#define decode_hwrm_ring_cmpl_ring_cfg_aggint_params_input(x, y) {}
#define decode_hwrm_ring_cmpl_ring_cfg_aggint_params_output(x, y) {}
#define decode_hwrm_ring_reset_input(x, y) {}
#define decode_hwrm_ring_reset_output(x, y) {}
#define decode_hwrm_ring_grp_alloc_input(x, y) {}
#define decode_hwrm_ring_grp_alloc_output(x, y) {}
#define decode_hwrm_ring_grp_free_input(x, y) {}
#define decode_hwrm_ring_grp_free_output(x, y) {}
#define decode_hwrm_cfa_l2_filter_alloc_input(x, y) {}
#define decode_hwrm_cfa_l2_filter_alloc_output(x, y) {}
#define decode_hwrm_cfa_l2_filter_free_input(x, y) {}
#define decode_hwrm_cfa_l2_filter_free_output(x, y) {}
#define decode_hwrm_cfa_l2_filter_cfg_input(x, y) {}
#define decode_hwrm_cfa_l2_filter_cfg_output(x, y) {}
#define decode_hwrm_cfa_l2_set_rx_mask_input(x, y) {}
#define decode_hwrm_cfa_l2_set_rx_mask_output(x, y) {}
#define decode_hwrm_cfa_tunnel_filter_alloc_input(x, y) {}
#define decode_hwrm_cfa_tunnel_filter_alloc_output(x, y) {}
#define decode_hwrm_cfa_tunnel_filter_free_input(x, y) {}
#define decode_hwrm_cfa_tunnel_filter_free_output(x, y) {}
#define decode_hwrm_cfa_encap_record_alloc_input(x, y) {}
#define decode_hwrm_cfa_encap_record_alloc_output(x, y) {}
#define decode_hwrm_cfa_encap_record_free_input(x, y) {}
#define decode_hwrm_cfa_encap_record_free_output(x, y) {}
#define decode_hwrm_cfa_ntuple_filter_alloc_input(x, y) {}
#define decode_hwrm_cfa_ntuple_filter_alloc_output(x, y) {}
#define decode_hwrm_cfa_ntuple_filter_free_input(x, y) {}
#define decode_hwrm_cfa_ntuple_filter_free_output(x, y) {}
#define decode_hwrm_cfa_ntuple_filter_cfg_input(x, y) {}
#define decode_hwrm_cfa_ntuple_filter_cfg_output(x, y) {}
#define decode_hwrm_cfa_em_flow_alloc_input(x, y) {}
#define decode_hwrm_cfa_em_flow_alloc_output(x, y) {}
#define decode_hwrm_cfa_em_flow_free_input(x, y) {}
#define decode_hwrm_cfa_em_flow_free_output(x, y) {}
#define decode_hwrm_cfa_em_flow_cfg_input(x, y) {}
#define decode_hwrm_cfa_em_flow_cfg_output(x, y) {}
#define decode_hwrm_tunnel_dst_port_query_input(x, y) {}
#define decode_hwrm_tunnel_dst_port_query_output(x, y) {}
#define decode_hwrm_tunnel_dst_port_alloc_input(x, y) {}
#define decode_hwrm_tunnel_dst_port_alloc_output(x, y) {}
#define decode_hwrm_tunnel_dst_port_free_input(x, y) {}
#define decode_hwrm_tunnel_dst_port_free_output(x, y) {}
#define decode_hwrm_stat_ctx_alloc_input(x, y) {}
#define decode_hwrm_stat_ctx_alloc_output(x, y) {}
#define decode_hwrm_stat_ctx_free_input(x, y) {}
#define decode_hwrm_stat_ctx_free_output(x, y) {}
#define decode_hwrm_stat_ctx_query_input(x, y) {}
#define decode_hwrm_stat_ctx_query_output(x, y) {}
#define decode_hwrm_stat_ctx_clr_stats_input(x, y) {}
#define decode_hwrm_stat_ctx_clr_stats_output(x, y) {}
#define decode_hwrm_fw_reset_input(x, y) {}
#define decode_hwrm_fw_reset_output(x, y) {}
#define decode_hwrm_fw_qstatus_input(x, y) {}
#define decode_hwrm_fw_qstatus_output(x, y) {}
#define decode_hwrm_fw_set_time_input(x, y) {}
#define decode_hwrm_fw_set_time_output(x, y) {}
#define decode_hwrm_fw_get_time_input(x, y) {}
#define decode_hwrm_fw_get_time_output(x, y) {}
#define decode_hwrm_fw_set_structured_data_input(x, y) {}
#define decode_hwrm_fw_set_structured_data_output(x, y) {}
#define decode_hwrm_fw_set_structured_data_cmd_err(x, y) {}
#define decode_hwrm_fw_get_structured_data_input(x, y) {}
#define decode_hwrm_fw_get_structured_data_output(x, y) {}
#define decode_hwrm_fw_get_structured_data_cmd_err(x, y) {}
#define decode_hwrm_fw_ipc_mailbox_input(x, y) {}
#define decode_hwrm_fw_ipc_mailbox_output(x, y) {}
#define decode_hwrm_fw_ipc_mailbox_cmd_err(x, y) {}
#define decode_hwrm_exec_fwd_resp_input(x, y) {}
#define decode_hwrm_exec_fwd_resp_output(x, y) {}
#define decode_hwrm_reject_fwd_resp_input(x, y) {}
#define decode_hwrm_reject_fwd_resp_output(x, y) {}
#define decode_hwrm_fwd_resp_input(x, y) {}
#define decode_hwrm_fwd_resp_output(x, y) {}
#define decode_hwrm_fwd_async_event_cmpl_input(x, y) {}
#define decode_hwrm_fwd_async_event_cmpl_output(x, y) {}
#define decode_hwrm_temp_monitor_query_input(x, y) {}
#define decode_hwrm_temp_monitor_query_output(x, y) {}
#define decode_hwrm_wol_filter_alloc_input(x, y) {}
#define decode_hwrm_wol_filter_alloc_output(x, y) {}
#define decode_hwrm_wol_filter_free_input(x, y) {}
#define decode_hwrm_wol_filter_free_output(x, y) {}
#define decode_hwrm_wol_filter_qcfg_input(x, y) {}
#define decode_hwrm_wol_filter_qcfg_output(x, y) {}
#define decode_hwrm_wol_reason_qcfg_input(x, y) {}
#define decode_hwrm_wol_reason_qcfg_output(x, y) {}
#define decode_hwrm_dbg_read_direct_input(x, y) {}
#define decode_hwrm_dbg_read_direct_output(x, y) {}
#define decode_hwrm_dbg_write_direct_input(x, y) {}
#define decode_hwrm_dbg_write_direct_output(x, y) {}
#define decode_hwrm_dbg_read_indirect_input(x, y) {}
#define decode_hwrm_dbg_read_indirect_output(x, y) {}
#define decode_hwrm_dbg_write_indirect_input(x, y) {}
#define decode_hwrm_dbg_write_indirect_output(x, y) {}
#define decode_hwrm_dbg_dump_input(x, y) {}
#define decode_hwrm_dbg_dump_output(x, y) {}
#define decode_hwrm_nvm_raw_write_blk_input(x, y) {}
#define decode_hwrm_nvm_raw_write_blk_output(x, y) {}
#define decode_hwrm_nvm_read_input(x, y) {}
#define decode_hwrm_nvm_read_output(x, y) {}
#define decode_hwrm_nvm_raw_dump_input(x, y) {}
#define decode_hwrm_nvm_raw_dump_output(x, y) {}
#define decode_hwrm_nvm_get_dir_entries_input(x, y) {}
#define decode_hwrm_nvm_get_dir_entries_output(x, y) {}
#define decode_hwrm_nvm_get_dir_info_input(x, y) {}
#define decode_hwrm_nvm_get_dir_info_output(x, y) {}
#define decode_hwrm_nvm_write_input(x, y) {}
#define decode_hwrm_nvm_write_output(x, y) {}
#define decode_hwrm_nvm_modify_input(x, y) {}
#define decode_hwrm_nvm_modify_output(x, y) {}
#define decode_hwrm_nvm_find_dir_entry_input(x, y) {}
#define decode_hwrm_nvm_find_dir_entry_output(x, y) {}
#define decode_hwrm_nvm_erase_dir_entry_input(x, y) {}
#define decode_hwrm_nvm_erase_dir_entry_output(x, y) {}
#define decode_hwrm_nvm_get_dev_info_input(x, y) {}
#define decode_hwrm_nvm_get_dev_info_output(x, y) {}
#define decode_hwrm_nvm_mod_dir_entry_input(x, y) {}
#define decode_hwrm_nvm_mod_dir_entry_output(x, y) {}
#define decode_hwrm_nvm_verify_update_input(x, y) {}
#define decode_hwrm_nvm_verify_update_output(x, y) {}
#define decode_hwrm_nvm_install_update_input(x, y) {}
#define decode_hwrm_nvm_install_update_output(x, y) {}
#define decode_hwrm_nvm_get_variable_input(x, y) {}
#define decode_hwrm_nvm_get_variable_output(x, y) {}
#define decode_hwrm_nvm_set_variable_input(x, y) {}
#define decode_hwrm_nvm_set_variable_output(x, y) {}
#define decode_cmdq_init(x, y) {}
#define decode_cmdq_update(x, y) {}
#define decode_cmdq_base(x, y) {}
#define decode_cmdq_create_qp(x, y) {}
#define decode_cmdq_destroy_qp(x, y) {}
#define decode_cmdq_modify_qp(x, y) {}
#define decode_cmdq_query_qp(x, y) {}
#define decode_cmdq_create_srq(x, y) {}
#define decode_cmdq_destroy_srq(x, y) {}
#define decode_cmdq_query_srq(x, y) {}
#define decode_cmdq_create_cq(x, y) {}
#define decode_cmdq_destroy_cq(x, y) {}
#define decode_cmdq_resize_cq(x, y) {}
#define decode_cmdq_allocate_mrw(x, y) {}
#define decode_cmdq_deallocate_key(x, y) {}
#define decode_cmdq_register_mr(x, y) {}
#define decode_cmdq_deregister_mr(x, y) {}
#define decode_cmdq_add_gid(x, y) {}
#define decode_cmdq_delete_gid(x, y) {}
#define decode_cmdq_modify_gid(x, y) {}
#define decode_cmdq_query_gid(x, y) {}
#define decode_cmdq_create_qp1(x, y) {}
#define decode_cmdq_destroy_qp1(x, y) {}
#define decode_cmdq_create_ah(x, y) {}
#define decode_cmdq_destroy_ah(x, y) {}
#define decode_cmdq_initialize_fw(x, y) {}
#define decode_cmdq_deinitialize_fw(x, y) {}
#define decode_cmdq_stop_func(x, y) {}
#define decode_cmdq_query_func(x, y) {}
#define decode_cmdq_set_func_resources(x, y) {}
#define decode_cmdq_read_context(x, y) {}
#define decode_cmdq_vf_backchannel_request(x, y) {}
#define decode_cmdq_read_vf_memory(x, y) {}
#define decode_cmdq_complete_vf_request(x, y) {}
#define decode_cmdq_map_tc_to_cos(x, y) {}
#define decode_cmdq_query_version(x, y) {}
#define decode_cmdq_modify_roce_cc(x, y) {}
#define decode_cmdq_query_roce_cc(x, y) {}
#define decode_creq_base(x, y) {}
#define decode_creq_func_event(x, y) {}
#define decode_creq_qp_event(x, y) {}
#define decode_creq_create_qp_resp(x, y) {}
#define decode_creq_destroy_qp_resp(x, y) {}
#define decode_creq_modify_qp_resp(x, y) {}
#define decode_creq_query_qp_resp(x, y) {}
#define decode_creq_query_qp_resp_sb(x, y) {}
#define decode_creq_create_srq_resp(x, y) {}
#define decode_creq_destroy_srq_resp(x, y) {}
#define decode_creq_query_srq_resp(x, y) {}
#define decode_creq_query_srq_resp_sb(x, y) {}
#define decode_creq_create_cq_resp(x, y) {}
#define decode_creq_destroy_cq_resp(x, y) {}
#define decode_creq_resize_cq_resp(x, y) {}
#define decode_creq_allocate_mrw_resp(x, y) {}
#define decode_creq_deallocate_key_resp(x, y) {}
#define decode_creq_register_mr_resp(x, y) {}
#define decode_creq_deregister_mr_resp(x, y) {}
#define decode_creq_add_gid_resp(x, y) {}
#define decode_creq_delete_gid_resp(x, y) {}
#define decode_creq_modify_gid_resp(x, y) {}
#define decode_creq_query_gid_resp(x, y) {}
#define decode_creq_query_gid_resp_sb(x, y) {}
#define decode_creq_create_qp1_resp(x, y) {}
#define decode_creq_destroy_qp1_resp(x, y) {}
#define decode_creq_create_ah_resp(x, y) {}
#define decode_creq_destroy_ah_resp(x, y) {}
#define decode_creq_initialize_fw_resp(x, y) {}
#define decode_creq_deinitialize_fw_resp(x, y) {}
#define decode_creq_stop_func_resp(x, y) {}
#define decode_creq_query_func_resp(x, y) {}
#define decode_creq_query_func_resp_sb(x, y) {}
#define decode_creq_set_func_resources_resp(x, y) {}
#define decode_creq_map_tc_to_cos_resp(x, y) {}
#define decode_creq_query_version_resp(x, y) {}
#define decode_creq_modify_roce_cc_resp(x, y) {}
#define decode_creq_query_roce_cc_resp(x, y) {}
#define decode_creq_query_roce_cc_resp_sb(x, y) {}
#define decode_creq_qp_error_notification(x, y) {}
#define decode_input(x, y) {}
#define decode_output(x, y) {}
#define decode_hwrm_short_input(x, y) {}
#define decode_cmd_nums(x, y) {}
#define decode_ret_codes(x, y) {}
#define decode_hwrm_err_output(x, y) {}
#define decode_tx_port_stats(x, y) {}
#define decode_rx_port_stats(x, y) {}
#define decode_ctx_hw_stats64(x, y) {}
#define decode_ctx_hw_stats(x, y) {}
#define decode_hwrm_struct_hdr(x, y) {}
#define decode_hwrm_struct_data_dcbx_ets(x, y) {}
#define decode_hwrm_struct_data_dcbx_pfc(x, y) {}
#define decode_hwrm_struct_data_dcbx_app(x, y) {}
#define decode_hwrm_struct_data_dcbx_feature_state(x, y) {}
#define decode_hwrm_struct_data_lldp(x, y) {}
#define decode_hwrm_struct_data_lldp_generic(x, y) {}
#define decode_hwrm_struct_data_lldp_device(x, y) {}
#define decode_hwrm_struct_data_port_description(x, y) {}
#endif
