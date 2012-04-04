/* DO NOT EDIT - Generated automatically by build.py */

static struct single_row_lut Scud_2300_fcc_temp = {
    .x      = {-20, -10, 0, 25, 40, 60},
    .y      = {2383, 2384, 2383, 2405, 2394, 2375},
    .cols   = 6
};

static struct single_row_lut Scud_2300_fcc_sf = {
    .x      = {0, 100, 200, 300, 400, 500},
    .y      = {100, 96, 94, 92, 90, 88},
    .cols   = 6
};

static struct sf_lut Scud_2300_pc_sf = {
    .rows = 1,
    .cols = 1,
    .row_entries = {0},
    .percent = {100},
    .sf = {
        {100}
     }
};


static struct sf_lut Scud_2300_rbatt_sf = {
    .rows = 28,
    .cols = 6,
    .row_entries = {-20, -10, 0, 25, 40, 60},
    .percent = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
    .sf = {
        {2495, 1392, 575, 120, 88, 79},
        {2485, 1388, 575, 120, 88, 79},
        {2229, 1291, 578, 123, 91, 81},
        {2110, 1223, 588, 128, 95, 83},
        {2109, 1213, 602, 134, 100, 86},
        {2092, 1225, 645, 144, 105, 89},
        {2101, 1198, 644, 157, 111, 93},
        {2143, 1204, 641, 175, 122, 98},
        {2181, 1223, 623, 179, 132, 103},
        {2228, 1257, 627, 147, 117, 96},
        {2297, 1304, 660, 126, 94, 83},
        {2395, 1373, 701, 131, 97, 86},
        {2515, 1464, 761, 138, 103, 90},
        {2647, 1572, 854, 145, 109, 94},
        {2783, 1686, 966, 151, 105, 91},
        {2936, 1797, 1082, 152, 101, 85},
        {3121, 1920, 1186, 154, 102, 85},
        {3382, 2075, 1315, 155, 102, 85},
        {7335, 3166, 1493, 161, 109, 91},
        {7860, 3403, 1592, 164, 111, 91},
        {8439, 3667, 1693, 170, 113, 92},
        {9032, 3931, 1822, 174, 114, 93},
        {9640, 4237, 1947, 183, 116, 96},
        {10324, 4549, 2041, 271, 120, 98},
        {11030, 4890, 2186, 198, 242, 103},
        {11844, 5393, 2489, 210, 224, 189},
        {12576, 5776, 2538, 250, 126, 122},
        {14123, 6603, 3046, 383, 160, 104},
    }
};

static struct pc_temp_ocv_lut Scud_2300_pc_temp_ocv = {
    .rows = 29,
    .cols = 6,
    .temp = {-20, -10, 0, 25, 40, 60},
    .percent = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    .ocv = {
        {4333, 4331, 4327, 4323, 4318, 4312},
        {4253, 4256, 4258, 4262, 4258, 4254},
        {4189, 4194, 4198, 4205, 4202, 4199},
        {4131, 4139, 4144, 4151, 4148, 4145},
        {4080, 4088, 4094, 4100, 4097, 4094},
        {4013, 4035, 4045, 4052, 4050, 4046},
        {3953, 3973, 3989, 4003, 4003, 4001},
        {3912, 3926, 3942, 3963, 3964, 3961},
        {3875, 3887, 3897, 3921, 3922, 3921},
        {3845, 3855, 3860, 3874, 3876, 3875},
        {3824, 3830, 3833, 3840, 3840, 3840},
        {3808, 3811, 3812, 3817, 3817, 3817},
        {3796, 3798, 3797, 3799, 3799, 3798},
        {3783, 3786, 3786, 3784, 3783, 3782},
        {3770, 3774, 3775, 3772, 3767, 3760},
        {3756, 3758, 3762, 3758, 3750, 3737},
        {3740, 3739, 3738, 3735, 3728, 3714},
        {3718, 3717, 3712, 3696, 3689, 3681},
        {3686, 3693, 3689, 3682, 3674, 3664},
        {3677, 3689, 3685, 3680, 3673, 3662},
        {3668, 3684, 3679, 3678, 3671, 3660},
        {3657, 3677, 3671, 3674, 3667, 3655},
        {3641, 3664, 3657, 3663, 3655, 3642},
        {3619, 3643, 3635, 3639, 3629, 3613},
        {3589, 3608, 3603, 3596, 3593, 3573},
        {3543, 3560, 3560, 3542, 3544, 3526},
        {3469, 3485, 3485, 3473, 3472, 3456},
        {3372, 3381, 3385, 3379, 3371, 3355},
        {3200, 3200, 3200, 3200, 3200, 3200},
    }
};

struct hisi_smartstar_coul_battery_data Scud_2300_battery_data = {
    .id_voltage_min = 1700,
    .id_voltage_max = 2000,
    .fcc = 2300,
    .fcc_temp_lut  = &Scud_2300_fcc_temp,
    .fcc_sf_lut = &Scud_2300_fcc_sf,
    .pc_temp_ocv_lut = &Scud_2300_pc_temp_ocv,
    .pc_sf_lut = &Scud_2300_pc_sf,
    .rbatt_sf_lut = &Scud_2300_rbatt_sf,
    .default_rbatt_mohm = 100,
    .max_currentmA = 1200,
    .max_voltagemV = 4352,
    .max_cin_currentmA = 1200,
    .terminal_currentmA = 100,
    .charge_in_temp_5 = 3,
    .charge_in_temp_10 = 3,
    .batt_brand = "Scud0410",
};