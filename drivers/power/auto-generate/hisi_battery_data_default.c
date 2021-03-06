/* This file should be auto-generated by tool, please don't manully modify it.*/

static struct single_row_lut lithium_2600_fcc_temp = {
	.x		= {-30, -20, -10, 0, 10, 25, 40, 65},
	.y		= {2600, 2600, 2600, 2600, 2600, 2600, 2600, 2600},
	.cols	= 8
};

static struct single_row_lut lithium_2600_fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut lithium_2600_pc_sf = {
	.rows		= 1,
	.cols		= 1,
	.row_entries		= {0},
	.percent	= {100},
	.sf			= {
				{100}
	}
};

static struct sf_lut lithium_2600_rbatt_sf = {
        .rows           = 28,
        .cols           = 8,
        /* row_entries are temperature */
        .row_entries            = {-30, -20, -10, 0, 10, 25, 40, 65},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {

						{805, 388, 268, 206, 138, 100, 87, 79},
						{809, 396, 264, 204, 140, 103, 89, 81},
						{823, 393, 258, 201, 141, 104, 91, 83},
						{843, 400, 255, 197, 141, 105, 92, 84},
						{865, 406, 254, 195, 141, 106, 93, 85},
						{893, 411, 253, 194, 141, 106, 94, 86},
						{940, 424, 255, 195, 137, 106, 94, 86},
						{1003, 443, 258, 195, 136, 105, 93, 86},
						{1077, 470, 264, 196, 136, 99, 87, 81},
						{1163, 502, 273, 197, 137, 99, 88, 81},
						{1275, 540, 288, 203, 139, 100, 89, 83},
						{1409, 585, 308, 211, 144, 102, 90, 85},
						{1563, 636, 333, 220, 151, 105, 92, 86},
						{1741, 696, 361, 231, 159, 109, 94, 86},
						{1936, 773, 393, 240, 167, 112, 96, 83},
						{2233, 872, 436, 248, 174, 113, 95, 85},
						{2705, 1020, 491, 268, 179, 111, 93, 84},
						{3557, 1280, 592, 321, 209, 114, 93, 84},
						{2866, 850, 379, 222, 155, 104, 89, 83},
						{3127, 918, 399, 225, 156, 105, 90, 83},
						{3513, 1022, 428, 238, 160, 106, 91, 84},
						{4007, 1154, 471, 254, 166, 108, 92, 85},
						{4620, 1351, 531, 277, 173, 110, 93, 85},
						{5463, 1640, 618, 306, 182, 110, 92, 84},
						{6643, 2085, 749, 348, 195, 110, 91, 83},
						{8405, 2778, 963, 422, 222, 115, 93, 85},
						{11033, 3875, 1297, 536, 262, 123, 97, 89},
						{15461, 6760, 1857, 729, 330, 143, 103, 93},
					}
};

static struct pc_temp_ocv_lut lithium_2600_pc_temp_ocv = {
	.rows		= 29,
	.cols		= 8,
	.temp		= {-30, -20, -10, 0, 10, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4173, 4172, 4171, 4169, 4169, 4150, 4163, 4158},
				{4089, 4100, 4107, 4110, 4112, 4058, 4110, 4107},
				{4011, 4049, 4061, 4066, 4068, 4005, 4066, 4062},
				{3955, 3987, 4011, 4020, 4025, 3978, 4026, 4022},
				{3914, 3945, 3964, 3978, 3988, 3934, 3988, 3984},
				{3879, 3909, 3931, 3941, 3955, 3890, 3955, 3951},
				{3852, 3874, 3897, 3907, 3924, 3860, 3926, 3920},
				{3830, 3845, 3866, 3876, 3884, 3829, 3899, 3893},
				{3811, 3821, 3839, 3849, 3852, 3801, 3870, 3865},
				{3795, 3801, 3815, 3824, 3827, 3779, 3827, 3826},
				{3781, 3786, 3794, 3803, 3806, 3763, 3806, 3804},
				{3766, 3772, 3776, 3788, 3789, 3739, 3789, 3789},
				{3752, 3760, 3762, 3776, 3777, 3721, 3777, 3776},
				{3737, 3749, 3751, 3768, 3771, 3707, 3767, 3765},
				{3722, 3737, 3740, 3761, 3765, 3688, 3760, 3751},
				{3706, 3725, 3728, 3749, 3757, 3658, 3749, 3729},
				{3686, 3712, 3717, 3724, 3736, 3641, 3726, 3708},
				{3661, 3695, 3703, 3701, 3701, 3610, 3692, 3677},
				{3625, 3671, 3687, 3686, 3679, 3595, 3667, 3654},
				{3616, 3664, 3682, 3681, 3676, 3579, 3666, 3652},
				{3604, 3655, 3675, 3677, 3673, 3569, 3664, 3650},
				{3591, 3644, 3668, 3672, 3670, 3554, 3661, 3648},
				{3575, 3630, 3659, 3666, 3666, 3530, 3656, 3640},
				{3556, 3609, 3643, 3655, 3656, 3511, 3639, 3616},
				{3532, 3582, 3616, 3626, 3626, 3483, 3600, 3574},
				{3499, 3544, 3571, 3576, 3572, 3439, 3545, 3519},
				{3451, 3485, 3505, 3503, 3500, 3382, 3477, 3453},
				{3371, 3388, 3402, 3400, 3401, 3273, 3382, 3359},
				{3200, 3200, 3200, 3200, 3200, 3180, 3200, 3200}
			}
};

struct hisi_smartstar_coul_battery_data default_battery_data = {
		.fcc			= 2600,
		.fcc_temp_lut		= &lithium_2600_fcc_temp,
		.fcc_sf_lut		= &lithium_2600_fcc_sf,
		.pc_temp_ocv_lut	= &lithium_2600_pc_temp_ocv,
		.pc_sf_lut		= &lithium_2600_pc_sf,
		.rbatt_sf_lut		= &lithium_2600_rbatt_sf,
		.default_rbatt_mohm        = 211,
};

