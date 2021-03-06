#ifndef __EFFECT_H__
#define __EFFECT_H__


#include "effect_comm.h"
#include "k3_isp_io.h"

#define CAMERA_MAX_SETTING_SIZE	2000
#define CAMERA_MAX_EXPO_TABLE_SIZE 10
#define DNS_MAX_STEP 6//7
//#define DNS_MAX_FINE_STEP 3
#define SHARPNESS_MAX_STEP 7

/******************************************************************************
	ae_params_s
 ******************************************************************************/
 typedef struct _ae_target_s {
	u8 default_target_y_low;
	u8 default_target_y_high;
} ae_target_s;

typedef struct _percent_s{
	u8 percent_w;
	u8 percent_h;
 } percent_s;

typedef struct _ae_win_s {
	percent_s win_2x2;
	percent_s win_3x3[CAMERA_MERERING_MAX];

	bool roi_enable;

	u8 default_weight[13];
	u8 default_weight_shift;
	
	u8 touch_weight[13];
	u8 touch_weight_shift;
} ae_win_s;

typedef struct _expo_table {
	u32 expo; /* in fact this is the reciprocal of expo */
	u32 iso;
} expo_table_t;

typedef struct _ae_params_s {
	ae_target_s target_y[5];
	ae_win_s ae_win;
	u8 max_expo_gap;

	u32 iso_max;
	u32 iso_min;

	u16 auto_fps_th[4]; /* low2mid, mid2high,high2mid, mid2low */
    u16 auto_fps_manual_iso_th[4];
	u32 fps[4]; /* fps_max, fps_middle, fps_min, fps_min_cap*/

	u8 expo_night; /* for example: 5 mean max expo is 1/5s */
	u8 expo_action; /* for example: 100 mean max expo is 1/100s */

	expo_table_t cap_expo_table[CAMERA_MAX_EXPO_TABLE_SIZE];
	u32 ev_numerator;
	u32 ev_denominator;
} ae_params_s;

/******************************************************************************
	af_param_s
 ******************************************************************************/
typedef struct _focus_area_param {
	u32 percent_w;
	u32 percent_h;
	u32 max_zoom_ratio;
	u32 min_height_ratio;
	
	/* to be used for multiwindow focus */
	u32 weight[25]; 
} focus_area_param;

typedef struct _contrast_threshold_s {
	u32 base_low;
	u32 base_high;
	u32 ultralow;
	u32 low;
} contrast_threshold;

typedef struct _judge_result_s {
	u32 error_mindiff;
	u32 error_minsteps;
	u32 low_contrast;
	u32 error_lum;
	u32 stat_th_percent;
} judge_result;

typedef struct _caf_trigger_s {
	u32 cmp_contrast;
	u32 cmp_lum;
	u32 cmp_ae;
	u32 cmp_awb;
	u32 cmp_diff_xyz;

	u32 var_ratio_contrast;	
	u32 var_ratio_lum;		
	u32 var_diff_xyz;		

	u32 min_trigger_lum;	
	u32 min_trigger_contrast_diff; 
	u32 min_trigger_lum_diff;	

	u32 goto_infinite_timeout;

	int stat_cmp_start_frame;
	int stat_cmp_end_frame;
	u32 stat_skip_frame;

	u32 stat_frame;
	u32 stat_frame_low;

	u32 restart_diff_xyz;
} caf_trigger_s;


typedef struct _focus_algo_s {
	bool software_stat;
	contrast_threshold param_th;	
	judge_result  param_judge;

	u32 infinity_hold_frames;
	u32 rewind_hold_frames;

	u32 try_dir_range;
	caf_trigger_s  caf_trigger;
	u32 calc_coarse_size;
} focus_algo_s;

typedef struct _af_param_s {
	focus_area_param focus_area;
	focus_algo_s focus_algo;
} af_param_s;


/******************************************************************************
	flash_param
 ******************************************************************************/
typedef struct _awb_gain {
	u16 b_gain;
	u16 gb_gain;
	u16 gr_gain;
	u16 r_gain;
} awb_gain_t;


typedef struct _red_clip_s {
	bool rcc_enable;

	u8 frame_interval;

	u8 detect_range;

	u8 rect_row_num;
	u8 rect_col_num;

	u16 preview_width_high;
	u16 preview_width_low;
	u8 uv_resample_high;
	u8 uv_resample_middle;
	u8 uv_resample_low;

	u8 refbin_low;
	u8 refbin_high;

	u8 v_th_high;
	u8 v_th_low;	
} red_clip_s;

/******************************************************************************
	sharpness
 ******************************************************************************/
typedef struct _sharpness_s {
	u32 sharpness_preview;
	u32 sharpness_capture;
} sharpness_cfg_s;


/******************************************************************************
	Denoise
 ******************************************************************************/


typedef struct _raw_dns_coff{
    u8 sigma_coff[DNS_MAX_STEP];
    u8 gsl_coff[DNS_MAX_STEP];
    u8 rbsl_coff[DNS_MAX_STEP];
}raw_dns_coff;

typedef struct _denoise_s{
    raw_dns_coff raw_dns_preview;
    raw_dns_coff raw_dns_capture;
    raw_dns_coff raw_dns_flash;

    u8 g_dns_caputure_1_band;
    u8 g_dns_flash_1_band;

    u8 uv_dns_preview[DNS_MAX_STEP];
    u8 uv_dns_capture[DNS_MAX_STEP];
    u8 uv_dns_flash[DNS_MAX_STEP];
}denoise_s;

typedef struct _denoise_cam{
    denoise_s zsl_on;
    denoise_s zsl_off;
}denoise_cam;
/******************************************************************************
	flash_param_s
 ******************************************************************************/
typedef struct _aecawb_step {
	u8 stable_range0; /* UNSTABLE2STABLE_RANGE: 0x1c14a */
	u8 stable_range1; /* STABLE2UNSTABLE_RANGE: 0x1c14b */
	u8 fast_step; /* 0x1c14c */
	u8 slow_step; /* 0x1c14e */
	u8 awb_step; /* 0x1c184 */
} aecawb_step_t;


typedef struct _assistant_af_s {
	u32 gainth_high;
	u32 lumth_1ow;
	u32 lumth_high;

	u32 test_max_cnt;
	flash_lum_level flash_level;
} assistant_af_s;

typedef struct _flash_capture_s {
	u32 trigger_gain;

	flash_lum_level preflash_level;
	flash_lum_level capflash_level;
	u8 cap2pre_ratio;

	u32 default_target_y;
	u32 test_max_cnt;
	u32 over_expo_th;
	u32 lowlight_th;
	u32 lowCT_th;
} flash_capture_s;


typedef struct _flash_param_s {
	awb_gain_t gain;
	aecawb_step_t aecawb_step;	
	flash_lum_level videoflash_level;
	assistant_af_s assistant_af;
	flash_capture_s flash_capture;
} flash_param_s;


/******************************************************************************
	effect_params
 ******************************************************************************/
typedef struct _effect_params {

	struct isp_reg_t isp_settings[CAMERA_MAX_SETTING_SIZE];

	ae_params_s ae_param;

	af_param_s af_param;

	awb_gain_t mwb_gain[CAMERA_WHITEBALANCE_MAX];

	red_clip_s rcc;

	sharpness_cfg_s sharpness[SHARPNESS_MAX_STEP];

	denoise_cam dns;
	
	u8 uv_saturation[CAMERA_SCENE_MAX];
	
	flash_param_s flash;
	struct isp_reg_t hdr_movie_isp_settings[CAMERA_MAX_SETTING_SIZE];
} effect_params;

#endif

