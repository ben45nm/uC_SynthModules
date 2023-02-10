

// dig.h
int dig_SIZE = 4096;
const int16_t dig_DATA[4096] =
{-55, -11, 34, 80, 122, 171, 210, 262, 298, 352, 389, 439, 482, 524, 575, 613, 663, 705, 750, 795, 841, 883, 931, 973, 1018, 1066, 1105, 1157, 1194, 1244, 1288, 1330, 1378, 1421, 1465, 1513, 1553, 1601, 1644, 1691, 1733, 1779, 1824, 1867, 1914, 1957, 2002, 2047, 2091, 2137, 2179, 2227, 2269, 2314, 2361, 2402, 2450, 2492, 2537, 2583, 2626, 2673, 2713, 2764, 2801, 2853, 2892, 2939, 2984, 3026, 3074, 3115, 3163, 3204, 3251, 3295, 3337, 3386, 3426, 3474, 3517, 3559, 3607, 3651, 3693, 3740, 3783, 3827, 3874, 3914, 3963, 4002, 4053, 4091, 4139, 4183, 4225, 4272, 4313, 4362, 4401, 4451, 4488, 4540, 4577, 4628, 4666, 4715, 4757, 4800, 4847, 4887, 4938, 4974, 5024, 5065, 5110, 5154, 5199, 5240, 5289, 5327, 5376, 5418, 5460, 5510, 5545, 5598, 5635, 5683, 5726, 5768, 5815, 5856, 5900, 5947, 5987, 6033, 6077, 6117, 6167, 6204, 6255, 6291, 6342, 6378, 6430, 6466, 6516, 6554, 6602, 6643, 6687, 6733, 6772, 6819, 6862, 6904, 6949, 6992, 7034, 7080, 7122, 7164, 7211, 7250, 7298, 7335, 7386, 7422, 7472, 7509, 7558, 7595, 7645, 7681, 7731, 7769, 7815, 7857, 7900, 7944, 7985, 8032, 8069, 8119, 8156, 8202, 8245, 8286, 8330, 8375, 8412, 8463, 8497, 8548, 8584, 8632, 8670, 8717, 8756, 8803, 8840, 8889, 8925, 8973, 9012, 9057, 9098, 9141, 9185, 9222, 9273, 9307, 9355, 9396, 9436, 9482, 9520, 9567, 9605, 9652, 9689, 9735, 9774, 9820, 9858, 9904, 9942, 9989, 10026, 10071, 10112, 10153, 10198, 10237, 10279, 10324, 10360, 10409, 10445, 10489, 10531, 10572, 10613, 10658, 10695, 10740, 10779, 10823, 10862, 10907, 10945, 10989, 11029, 11070, 11112, 11154, 11195, 11236, 11278, 11316, 11362, 11399, 11444, 11483, 11523, 11567, 11605, 11649, 11687, 11731, 11769, 11812, 11853, 11891, 11936, 11973, 12017, 12055, 12098, 12136, 12180, 12218, 12259, 12301, 12340, 12381, 12422, 12461, 12503, 12543, 12582, 12625, 12663, 12704, 12745, 12782, 12829, 12861, 12908, 12943, 12986, 13024, 13068, 13102, 13147, 13185, 13223, 13268, 13301, 13346, 13384, 13424, 13463, 13503, 13543, 13582, 13623, 13661, 13700, 13742, 13778, 13822, 13855, 13901, 13935, 13977, 4971, 5051, 5144, 5221, 5312, 5395, 5480, 5566, 5649, 5737, 5819, 5906, 5989, 6076, 6158, 6247, 6327, 6414, 6499, 6582, 6668, 6753, 6835, 6923, 7004, 7091, 7174, 7259, 7343, 7427, 7513, 7594, 7682, 7762, 7850, 7931, 8017, 8101, 8182, 8272, 8348, 8439, 8517, 8605, 8688, 8769, 8857, 8935, 9023, 9107, 9185, 9277, 9351, 9442, 9521, 9606, 9689, 9773, 9854, 9940, 10020, 10106, 10187, 10272, 10352, 10439, 10517, 10605, 10683, 10770, 10849, 10935, 11016, 11098, 11182, 11263, 11347, 11429, 11511, 11593, 11677, 11757, 11841, 11924, 12002, 12090, 12167, 12252, 12334, 12414, 12497, 12580, 12660, 12743, 12825, 12904, 12992, 13065, 13154, 13232, 13312, 13400, 13473, 13561, 13639, 13720, 13804, 13882, 13966, 14045, 14128, 14207, 14289, 14371, 14450, 14533, 14612, 14693, 14775, 14855, 14936, 15015, 15098, 15176, 15259, 15338, 15419, 15498, 15580, 15659, 15741, 15819, 15901, 15980, 16059, 16142, 16220, 16299, 16382, 16457, 16542, 16618, 16700, 16777, 16860, 16936, 17019, 17096, 17176, 17256, 17335, 17412, 17498, 17567, 17656, 17728, 17812, 17887, 17969, 18045, 18127, 18204, 18283, 18362, 18439, 18522, 18594, 18680, 18751, 18837, 18908, 18993, 19066, 19147, 19226, 19300, 19384, 19457, 19537, 19616, 19690, 19774, 19845, 19930, 20000, 20085, 20155, 20242, 20308, 20399, 20462, 20552, 20620, 20704, 20776, 20857, 20932, 21009, 21089, 21161, 21243, 21316, 21396, 21470, 21549, 21622, 21705, 21775, 21856, 21931, 22004, 22088, 22157, 22237, 22313, 22388, 22464, 22542, 22616, 22693, 22769, 22845, 22919, 22998, 23070, 23149, 23223, 23299, 23373, 23451, 23524, 23602, 23674, 23753, 23823, 23905, 23974, 24052, 24127, 24200, 24278, 24350, 24426, 24501, 24575, 24650, 24725, 24798, 24874, 24949, 25020, 25099, 25169, 25246, 25318, 25394, 25467, 25542, 25614, 25690, 25762, 25837, 25911, 25983, 26058, 26132, 26202, 26283, 26345, 26431, 26493, 26575, 26643, 26718, 26791, 26863, 26937, 27010, 27081, 27158, 27224, 27304, 27371, 27447, 27517, 27592, 27661, 27739, 27804, 27883, 27950, 28025, 28097, 28167, 28243, 28309, 28387, 28453, 28530, 28597, 28673, 28741, 28814, 28886, 28955, 29030, 29098, 29083, 29012, 28939, 28869, 28799, 28727, 28656, 28587, 28512, 28447, 28372, 28302, 28234, 28159, 28095, 28018, 27952, 27880, 27810, 27741, 27670, 27599, 27531, 27460, 27390, 27321, 27252, 27179, 27113, 27041, 26973, 26904, 26833, 26764, 26695, 26627, 26556, 26489, 26417, 26351, 26280, 26213, 26143, 26074, 26006, 25938, 25868, 25801, 25730, 25665, 25594, 25528, 25457, 25392, 25321, 25256, 25185, 25119, 25051, 24982, 24917, 24846, 24782, 24710, 24647, 24576, 24512, 24442, 24376, 24308, 24243, 24172, 24110, 24037, 23978, 23902, 23846, 23767, 23712, 23636, 23577, 23505, 23443, 23372, 23311, 23240, 26032, 26050, 26071, 26090, 26112, 26128, 26152, 26168, 26190, 26209, 26229, 26246, 26269, 26284, 26308, 26324, 26344, 26363, 26381, 26402, 26419, 26439, 26456, 26477, 26493, 26515, 26530, 26551, 26567, 26588, 26603, 26625, 26639, 26662, 26674, 26697, 26712, 26732, 26747, 26768, 26781, 26804, 26817, 26838, 26852, 26872, 26886, 26908, 26919, 26943, 26953, 26975, 26990, 27006, 27024, 27040, 27056, 27076, 27087, 27108, 27121, 27140, 27154, 27172, 27186, 27206, 27216, 27237, 27249, 27268, 27282, 27299, 27311, 27332, 27341, 27363, 27372, 27394, 27402, 27423, 27435, 27450, 27467, 27479, 27496, 27510, 27524, 27541, 27551, 27571, 27581, 27597, 27612, 27624, 27642, 27651, 27671, 27678, 27697, 27710, 27721, 27741, 27746, 27766, 27777, 27790, 27807, 27814, 27834, 27841, 27859, 27869, 27883, 27897, 27906, 27925, 27930, 27950, 27958, 27971, 27987, 27992, 28014, 28016, 28038, 28042, 28059, 28069, 28081, 28094, 28105, 28115, 28130, 28138, 28154, 28160, 28177, 28182, 28200, 28206, 28220, 28229, 28243, 28249, 28267, 28269, 28288, 28292, 28308, 28314, 28328, 28336, 28347, 28358, 28366, 28380, 28386, 28398, 28409, 28415, 28429, 28437, 28445, 28459, 28463, 28477, 28483, 28495, 28503, 28511, 28522, 28530, 28539, 28550, 28555, 28567, 28574, 28582, 28594, 28598, 28610, 28617, 28624, 28635, 28640, 28651, 28657, 28667, 28672, 28683, 28688, 28698, 28703, 28714, 28718, 28728, 28734, 28741, 28749, 28757, 28762, 28770, 28778, 28782, 28793, 28795, 28806, 28809, 28819, 28823, 28829, 28839, 28839, 28852, 28854, 28861, 28868, 28872, 28878, 28886, 28889, 28898, 28899, 28909, 28911, 28918, 28925, 28925, 28938, 28934, 28948, 28946, 28954, 28960, 28961, 28971, 28969, 28980, 28979, 28989, 28987, 28998, 28996, 29005, 29007, 29009, 29017, 29019, 29021, 29029, 29028, 29035, 29036, 29042, 29043, 29048, 29051, 29053, 29058, 29059, 29064, 29065, 29070, 29070, 29077, 29073, 29084, 29078, 29087, 29087, 29087, 29094, 29091, 29097, 29098, 29099, 29102, 29102, 29108, 29103, 29112, 29107, 29113, 29112, 29115, 29115, 29116, 29119, 29117, 29121, 29121, 29121, 29122, 29124, 29123, 29125, 29125, 29124, 29127, 29125, 29127, 29126, 29126, 29128, 29124, 29129, 29124, 29127, 29126, 29123, 29129, 29120, 29128, 29119, 29125, 29120, 29122, 29120, 29118, 29117, 29118, 29115, 29114, 29113, 29111, 29110, 29108, 29108, 29103, 29106, 29099, 29101, 29096, 29099, 29089, 29096, 29085, 29089, 29085, 29080, 29083, 29072, 29080, 29066, 29074, 29062, 29066, 29057, 29061, 29049, 29055, 29045, 29045, 29041, 29036, 29035, 29029, 29028, 29021, 29020, 29015, 29011, 29006, 29005, 28996, 28998, 28988, 28987, 28981, 28978, 28971, 28970, 28961, 28961, 28951, 28951, 28942, 28939, 28935, 28927, 28924, 28918, 28911, 28909, 28901, 28896, 28890, 28885, 28878, 28874, 28867, 28861, 28855, 28849, 28842, 28837, 28831, 28823, 28817, 28811, 28803, 28799, 28790, 28784, 28777, 28769, 28765, 28754, 28751, 28740, 28735, 28726, 28721, 28710, 28707, 28695, 28690, 28681, 28674, 28665, 28659, 28648, 28644, 28631, 28628, 28614, 28611, 28599, 28592, 28583, 28575, 28565, 28558, 28548, 28539, 28530, 28522, 28511, 28505, 28492, 28486, 28473, 28468, 28454, 28449, 28435, 28428, 28418, 28406, 28400, 28386, 28379, 28367, 28357, 28347, 28337, 28328, 28314, 28307, 28293, 28286, 28274, 28261, 28255, 28237, 28234, 28216, 28211, 28194, 28187, 28174, 28163, 28151, 28141, 28125, 28121, 28102, 28095, 28081, 28069, 28057, 28048, 28030, 28024, 28007, 27997, 27986, 27970, 27960, 27946, 27935, 27920, 27912, 27891, 27888, 27865, 27861, 27840, 27835, 27814, 27806, 27790, 27777, 27766, 27748, 27739, 27721, 27711, 27694, 27683, 27667, 27653, 27642, 27622, 27615, 27593, 27585, 27568, 27553, 27541, 27522, 27512, 27494, 27481, 27466, 27449, 27438, 27419, 27406, 27390, 27376, 27359, 27345, 27329, 27312, 27301, 27279, 27270, 27247, 27239, 27216, 27206, 27185, 27173, 27153, 27141, 27121, 27107, 27090, 27072, 27059, 27038, 27025, 27006, 26990, 26974, 26955, 26941, 26920, 26907, 26887, 26870, 26856, 26834, 26820, 26800, 26785, 26765, 26750, 26729, 26714, 26695, 26676, 26662, 26637, 26627, 26601, 26590, 26566, 26551, 26531, 26513, 26495, 26475, 26459, 26435, 26424, 26396, 26386, 26361, 26344, 26325, 26305, 26287, 26267, 26248, 26227, 26211, 26187, 26172, 26147, 26133, 26109, 26092, 26069, 26052, 26030, 26010, 25993, 25967, 25953, 25927, 25911, 25887, 25870, 25847, 25827, 25807, 25783, 25768, 25741, 25725, 25701, 25679, 25663, 25635, 25620, 25594, 25575, 25554, 25530, 25512, 25486, 25469, 25444, 25423, 25402, 25378, 25360, 25332, 25317, 25288, 25271, 25246, 25224, 25203, 25178, 25160, 25130, 25116, 25086, 25068, 25044, 25019, 25000, 24972, 24955, 24925, 24910, 24877, 24865, 24830, 24817, 24785, 24768, 24740, 24719, 24694, 24670, 24649, 24620, 24602, 24572, 24554, 24524, 24506, 24475, 24458, 24427, 24408, 24379, 24358, 24332, 24307, 24284, 24257, 24234, 24209, 24183, 24159, 24133, 24109, 24084, 24057, 24035, 24005, 23984, 23957, 21480, 21510, 21529, 21562, 21580, 21614, 21631, 21666, 21683, 21717, 21736, 21768, 21790, 21818, 21844, 21870, 21897, 21923, 21949, 21978, 21999, 22033, 22054, 22083, 22111, 22134, 22165, 22189, 22220, 22240, 22277, 22293, 22330, 22351, 22382, 22407, 22436, 22463, 22490, 22519, 22545, 22574, 22601, 22630, 22655, 22688, 22711, 22741, 22771, 22794, 22829, 22852, 22882, 22912, 22937, 22968, 22997, 23022, 23056, 23079, 23113, 23138, 23168, 23198, 23224, 23258, 23281, 23316, 23341, 23371, 23403, 23428, 23461, 23488, 23519, 23548, 23578, 23606, 23637, 23668, 23694, 23729, 23754, 23787, 23816, 23845, 23877, 23906, 23938, 23964, 24000, 24024, 24061, 24086, 24119, 24150, 24179, 24211, 24240, 24272, 24305, 24330, 24367, 24393, 24428, 24457, 24489, 24518, 24552, 24581, 24614, 24644, 24677, 24706, 24740, 24769, 24804, 24832, 24867, 24896, 24929, 24961, 24992, 25025, 25056, 25090, 25119, 25153, 25185, 25216, 25251, 25280, 25315, 25346, 25378, 25412, 25443, 25477, 25510, 25538, 25580, 25601, 25646, 25668, 25709, 25737, 25773, 25804, 25838, 25871, 25905, 25936, 25972, 26003, 26039, 26069, 26105, 26138, 26171, 26206, 26238, 26272, 26307, 26340, 26372, 26410, 26440, 26476, 26511, 26540, 26581, 26609, 26648, 26679, 26716, 26746, 26786, 26815, 26854, 26885, 26922, 26955, 26990, 27026, 27058, 27095, 27130, 27162, 27201, 27233, 27267, 27307, 27336, 27376, 27408, 27444, 27479, 27517, 27547, 27588, 27619, 27657, 27692, 27726, 27764, 27798, 27834, 27870, 27906, 27940, 27979, 28011, 28050, 28085, 28120, 28157, 28193, 28228, 28267, 28299, 28339, 28373, 28410, 28446, 28484, 28517, 28559, 28588, 28631, 28665, 28701, 28740, 28773, 28814, 28847, 28888, 28919, 28962, 28994, 29035, 29069, 29108, 29108, 29072, 29035, 28996, 28961, 28923, 28884, 28850, 28810, 28772, 28738, 28696, 28662, 28623, 28586, 28547, 28510, 28473, 28434, 28399, 28356, 28324, 28280, 28249, 28205, 28170, 28131, 28094, 28054, 28018, 27977, 27943, 27900, 27866, 27823, 27789, 27748, 27711, 27671, 27634, 27594, 27556, 27519, 27477, 27442, 13153, 1684, 1643, 1606, 1566, 1526, 1490, 1448, 1412, 1370, 1333, 1292, 1256, 1213, 1177, 1136, 1096, 1061, 1015, 981, 939, 901, 861, 822, 780, 744, 702, 664, 623, 584, 544, 504, 465, 424, 386, 343, 307, 263, 227, 184, 146, 104, 65, 25, -15, -56, -95, -137, -175, -217, -258, -295, -340, -375, -421, -458, -499, -542, -577, -625, -659, -704, -742, -785, -824, -865, -908, -943, -993, -1025, -1071, -1111, -1150, -1195, -1231, -1277, -1313, -1359, -1397, -1440, -1478, -1524, -1561, -1604, -1647, -1683, -1732, -1766, -1813, -1850, -1895, -1934, -1977, -2018, -2059, -2102, -2142, -2186, -2223, -2271, -2307, -2353, -2392, -2434, -2478, -2517, -2562, -2600, -2645, -2686, -2727, -2771, -2811, -2854, -2896, -2938, -2979, -3023, -3064, -3107, -3147, -3192, -3232, -3277, -3317, -3359, -3402, -3445, -3487, -3530, -3571, -3614, -3655, -3701, -3741, -3784, -3827, -3868, -3913, -3954, -3996, -4040, -4082, -4126, -4166, -4212, -4251, -4298, -4337, -4383, -4423, -4467, -4513, -4549, -4599, -4637, -4681, -4727, -4765, -4812, -4854, -4896, -4940, -4982, -5026, -5070, -5111, -5156, -5198, -5242, -5285, -5328, -5370, -5417, -5455, -5504, -5543, -5588, -5631, -5675, -5717, -5763, -5803, -5849, -5891, -5936, -5978, -6022, -6065, -6110, -6152, -6197, -6238, -6284, -6328, -6369, -6416, -6456, -6503, -6544, -6591, -6630, -6679, -6719, -6763, -6809, -6851, -6894, -6942, -6979, -7030, -7068, -7116, -7158, -7202, -7246, -7290, -7334, -7378, -7422, -7466, -7509, -7555, -7597, -7642, -7687, -7729, -7774, -7820, -7859, -7910, -7947, -7997, -8038, -8083, -8127, -8171, -8214, -8263, -8300, -8351, -8391, -8434, -8485, -8520, -8575, -8607, -8663, -8698, -8749, -8790, -8835, -8878, -8926, -8965, -9016, -9053, -9105, -9141, -9194, -9231, -9281, -9322, -9368, -9411, -9458, -9499, -9548, -9588, -9635, -9678, -9724, -9767, -9814, -9854, -9905, -9941, -9996, -10029, -10086, -10118, -10173, -10210, -10260, -10302, -10347, -10392, -7621, 2357, 2317, 2267, 2228, 2179, 2137, 2091, 2047, 2002, 1958, 1912, 1869, 1823, 1779, 1734, 1690, 1644, 1601, 1555, 1509, 1469, 1418, 1379, 1331, 1287, 1242, 1199, 1151, 1111, 1060, 1022, 972, 931, 883, 841, 794, 751, 706, 660, 617, 571, 526, 483, 437, 391, 350, 299, 262, 210, 171, 122, 80, 34, -12, -53, -102, -144, -189, -237, -275, -328, -365, -417, -456, -503, -548, -593, -636, -684, -724, -774, -815, -861, -906, -951, -994, -1041, -1083, -1132, -1172, -1220, -1262, -1310, -1352, -1399, -1441, -1489, -1530, -1578, -1621, -1666, -1711, -1755, -1800, -1845, -1889, -1934, -1979, -2024, -2067, -2113, -2157, -2202, -2248, -2290, -2336, -2381, -2424, -2472, -2512, -2561, -2602, -2649, -2694, -2735, -2784, -2825, -2872, -2916, -2959, -3006, -3048, -3094, -3139, -3182, -3228, -3271, -3317, -3361, -3404, -3452, -3490, -3544, -3578, -3632, -3669, -3716, -3763, -3802, -3853, -3892, -3937, -3986, -4023, -4075, -4114, -4159, -4206, -4247, -4294, -4338, -4379, -4428, -4468, -4516, -4556, -4607, -4641, -4697, -4731, -4781, -4825, -4864, -4916, -4953, -5002, -5043, -5090, -5130, -5179, -5219, -5265, -5309, -5353, -5396, -5443, -5482, -5530, -5572, -5618, -5659, -5707, -5745, -5795, -5834, -5882, -5922, -5969, -6012, -6054, -6101, -6141, -6188, -6230, -6276, -6315, -6365, -6402, -6452, -6491, -6538, -6578, -6625, -6667, -6710, -6757, -6795, -6844, -6884, -6928, -6974, -7014, -7060, -7103, -7145, -7190, -7232, -7277, -7319, -7364, -7404, -7452, -7490, -7538, -7578, -7624, -7664, -7710, -7752, -7795, -7839, -7881, -7925, -7968, -8011, -8053, -8099, -8137, -8186, -8223, -8272, -8311, -8354, -8398, -8440, -8485, -8525, -8571, -8609, -8658, -8695, -8742, -8782, -8826, -8869, -8910, -8954, -8998, -9036, -9084, -9122, -9168, -9209, -9252, -9293, -9338, -9378, -9422, -9463, -9507, -9548, -9591, -9634, -9673, -9720, -9758, -9803, -9844, -9886, -9929, -9971, -10011, -10058, -10093, -10142, -10179, -10223, -10266, -10306, -10347, -10394, -10428, -10478, -10513, -10560, -10597, -10644, -10681, -10725, -10767, -10805, -10854, -10886, -10937, -10971, -11017, -11057, -11098, -11140, -11181, -11225, -11260, -11310, -11343, -11390, -11428, -11472, -11509, -11556, -11591, -11637, -11675, -11718, -11757, -11800, -11840, -11880, -11923, -11963, -12002, -12047, -12082, -12129, -12165, -12209, -12246, -12291, -12328, -12371, -12411, -12449, -12495, -12528, -12577, -12609, -12657, -12691, -12735, -12775, -12813, -12858, -12892, -12937, -12975, -13015, -13057, -13095, -13135, -13178, -13212, -13260, -13291, -13341, -13370, -13420, -13450, -13499, -13531, -13577, -13612, -13654, -13693, -13732, -13772, -13813, -13848, -13893, -13930, -13966, -14013, -14043, -14091, -14124, -14167, -14203, -14246, -14281, -14324, -14359, -14402, -14437, -14480, -14516, -14556, -14593, -14636, -14669, -14713, -14749, -14786, -14831, -14860, -14908, -14941, -14980, -15021, -15056, -15098, -15134, -15171, -15214, -15246, -15291, -15323, -15365, -15402, -15440, -15476, -15519, -15551, -15595, -15627, -15669, -15704, -15745, -15779, -15820, -15855, -15894, -15932, -15968, -16007, -16043, -16082, -16118, -16157, -16192, -16232, -16267, -16305, -16343, -16378, -16418, -16452, -16492, -16526, -16565, -16601, -16639, -16675, -16710, -16750, -16785, -16822, -16859, -16894, -16931, -16970, -17002, -17044, -17075, -17115, -17150, -17184, -17226, -17255, -17299, -17327, -17369, -17403, -17438, -17475, -17512, -17544, -17586, -17615, -17656, -17688, -7805, -7837, -7877, -7909, -7945, -7982, -8015, -8053, -8087, -8122, -8157, -8193, -8228, -8263, -8298, -8334, -8366, -8405, -8437, -8472, -8509, -8541, -8578, -8610, -8648, -8678, -8720, -8745, -8788, -8816, -8854, -8888, -8921, -8956, -8990, -9025, -9057, -9094, -9124, -9163, -9192, -9230, -9261, -9296, -9329, -9365, -9394, -9434, -9460, -9501, -9529, -9565, -9598, -9631, -9663, -9700, -9729, -9765, -9797, -9828, -9866, -9894, -9931, -9959, -9997, -10026, -10061, -10093, -10124, -10161, -10187, -10226, -10254, -10288, -10322, -10350, -10387, -10416, -10450, -10480, -10515, -10544, -10579, -10608, -10642, -15075, -26212, -27891, -27866, -27828, -27800, -27769, -27735, -27705, -27675, -27638, -27616, -27575, -27553, -27513, -27489, -27453, -27425, -27394, -27361, -27332, -27301, -27268, -27242, -27206, -27180, -27146, -27117, -27087, -27056, -27025, -26998, -26961, -26940, -26900, -26878, -26845, -26812, -26790, -26748, -26732, -26690, -26670, -26634, -26605, -26580, -26543, -26523, -26484, -26461, -26429, -26400, -26373, -26340, -26314, -26283, -26256, -26225, -26198, -26167, -26140, -26111, -26081, -26054, -26025, -25995, -25969, -25938, -25912, -25882, -25854, -25827, -25797, -25771, -25740, -25716, -25683, -25661, -25628, -25603, -25575, -25546, -25520, -25492, -25464, -25436, -27232, -13246, -13279, -13301, -13331, -13358, -13383, -13413, -13438, -13465, -13493, -13519, -13545, -13574, -13598, -13626, -13653, -13677, -13708, -13729, -13760, -13783, -13810, -13838, -13860, -13891, -13913, -13942, -13965, -13993, -14016, -14046, -14067, -14096, -14120, -14145, -14173, -14194, -14224, -14246, -14272, -14298, -14322, -14348, -14372, -14398, -14421, -14448, -14471, -14497, -14520, -14547, -14569, -14594, -14621, -14640, -14671, -14688, -14719, -14737, -14767, -14785, -14814, -14834, -14861, -14882, -14907, -14931, -14953, -14980, -14998, -15027, -15046, -15072, -15094, -15117, -15142, -15162, -15189, -15206, -15236, -15252, -15281, -15298, -15325, -15345, -23934, -23241, -23216, -23197, -23171, -23152, -23128, -23106, -23087, -23058, -23045, -23014, -23001, -22973, -22955, -22930, -22912, -22886, -22871, -22843, -22827, -22801, -22785, -22757, -22745, -22714, -22702, -22675, -22656, -22638, -22611, -22599, -22569, -22557, -22529, -22516, -22489, -22473, -22451, -22431, -22412, -22390, -22372, -22351, -22330, -22314, -22289, -22275, -22251, -22233, -22214, -22194, -22174, -22156, -22137, -22116, -22099, -22078, -22060, -22042, -22021, -22004, -21984, -21968, -21945, -21930, -21909, -21893, -21874, -21854, -21838, -21817, -21803, -21781, -21766, -21746, -21728, -21714, -21689, -21681, -21653, -21645, -21620, -21607, -21588, -21570, -18156, -17090, -17115, -17125, -17147, -17161, -17179, -17196, -17212, -17229, -17247, -17260, -17280, -17294, -17312, -17328, -17343, -17361, -17374, -17394, -17407, -17424, -17440, -17455, -17472, -17485, -17504, -17516, -17536, -17546, -17565, -17579, -17594, -17611, -17623, -17640, -17654, -17670, -17683, -17700, -17713, -17728, -17742, -17758, -17771, -17785, -17802, -17812, -17831, -17840, -17858, -17869, -17886, -17897, -17912, -17926, -17938, -17954, -17965, -17982, -17989, -18010, -18017, -18034, -18046, -18057, -18074, -18083, -18098, -18111, -18121, -18138, -18146, -18162, -18172, -18186, -18197, -18212, -18220, -18235, -18247, -18256, -18274, -18278, -18297, -25233, -20316, -20300, -20291, -20279, -20268, -20256, -20245, -20234, -20222, -20213, -20200, -20190, -20180, -20166, -20160, -20145, -20138, -20124, -20117, -20104, -20096, -20082, -20076, -20063, -20055, -20044, -20033, -20025, -20015, -20004, -19996, -19985, -28577, -28585, -28595, -28605, -28613, -28624, -28631, -28641, -28650, -28658, -28670, -28674, -28688, -28690, -28706, -28707, -28724, -28724, -28738, -28743, -28752, -28762, -28767, -28778, -28782, -28794, -28799, -28807, -28817, -28820, -28833, -28835, -28847, -28850, -28862, -28863, -28878, -28878, -28887, -28897, -28898, -28911, -28913, -28922, -28927, -28936, -28938, -28950, -28951, -28961, -28965, -28971, -28978, -28985, -28987, -28998, -28998, -29009, -29010, -29019, -29023, -29029, -29032, -29042, -29040, -29054, -29051, -29062, -29062, -29070, -29075, -29076, -29087, -29083, -29096, -29095, -29100, -29108, -29107, -29115, -29118, -29119, -29129, -29127, -29135, -29137, -29139, -29148, -29144, -29154, -29153, -29159, -29162, -29164, -29167, -29172, -29171, -29180, -29177, -29183, -29186, -29185, -29194, -29188, -29200, -29193, -29203, -29201, -29203, -29209, -29205, -29212, -29212, -29214, -29215, -29218, -29218, -29222, -29221, -29224, -29224, -29226, -29228, -29228, -29229, -29231, -29231, -29232, -29235, -29231, -29236, -29234, -29236, -29236, -29236, -29237, -29236, -29238, -29236, -29239, -29234, -29241, -29233, -29240, -29233, -29239, -29234, -29235, -29235, -29232, -29235, -29232, -29230, -29232, -29227, -29232, -29224, -29229, -29221, -29227, -29219, -29224, -29216, -29219, -29215, -29215, -29211, -29212, -29206, -29208, -29204, -29201, -29201, -29196, -29197, -29191, -29191, -29187, -29185, -29183, -29179, -29177, -29173, -29171, -29168, -29165, -29160, -29159, -29154, -29153, -29146, -29146, -29139, -29139, -29132, -29129, -29128, -29119, -29121, -29110, -29112, -29104, -29102, -29096, -29092, -29088, -29083, -29079, -29074, -29068, -29065, -29059, -29055, -29048, -29047, -29036, -29035, -29029, -29022, -29019, -29012, -29005, -29003, -28993, -28992, -28982, -28978, -28972, -28965, -28960, -28953, -28947, -28940, -28936, -28926, -28923, -28913, -28909, -28900, -28896, -28886, -28883, -28872, -28866, -28861, -28850, -28848, -28836, -28830, -28823, -28815, -28807, -28802, -28789, -28787, -28775, -28768, -28762, -28750, -28746, -28735, -28728, -28720, -28709, -28705, -28690, -28689, -28674, -28669, -28658, -28651, -28640, -28633, -28622, -28613, -28606, -28594, -28587, -28574, -28570, -28553, -28551, -28536, -28529, -28518, -28509, -28496, -28491, -28477, -28468, -28459, -28445, -28439, -28427, -28415, -28406, -28395, -28383, -28376, -28361, -28351, -28343, -28326, -28323, -28304, -28298, -28284, -28273, -28264, -28249, -28239, -28228, -28215, -28205, -28191, -28180, -28168, -28157, -28143, -28132, -28119, -28108, -28095, -28082, -28070, -28058, -28044, -28033, -28018, -28007, -27994, -27980, -27968, -27955, -27939, -27931, -27911, -27906, -27884, -27877, -27859, -27849, -27832, -27822, -27803, -27795, -27777, -27765, -27750, -27736, -27721, -27709, -27693, -27678, -27666, -27648, -27637, -27620, -27604, -27595, -27572, -27566, -27543, -27532, -27517, -27499, -27488, -27469, -27455, -27441, -27422, -27411, -27390, -27381, -27358, -27348, -27329, -27314, -27297, -27284, -27263, -27251, -27233, -27215, -27203, -27182, -27168, -27151, -27134, -27118, -27100, -27085, -27065, -27052, -27031, -27017, -26999, -26980, -26966, -26944, -26932, -26911, -26894, -26878, -26856, -26846, -26820, -26807, -26788, -26769, -26752, -26735, -26713, -26700, -26677, -26661, -26642, -26625, -26603, -26589, -26565, -26552, -26528, -26513, -26491, -26474, -26456, -26433, -26419, -26394, -26380, -26357, -26339, -26321, -26298, -26282, -26259, -26242, -26220, -26203, -26180, -26161, -26143, -26119, -26103, -26079, -26062, -26040, -26019, -26000, -25979, -25957, -25941, -25912, -25901, -25871, -25859, -25829, -25816, -25789, -25771, -25751, -25724, -25710, -25682, -25667, -25640, -25622, -25597, -25579, -25555, -25534, -25512, -25490, -25469, -25444, -25425, -25402, -25380, -25356, -25337, -25310, -25293, -25266, -25244, -25226, -25196, -25180, -25153, -25130, -25110, -25085, -25063, -25038, -25017, -24991, -24972, -24944, -24926, -24896, -24878, -24851, -24830, -24804, -24782, -24757, -24733, -24711, -24685, -24661, -24640, -24610, -24592, -24564, -24540, -24518, -24489, -24471, -24439, -24422, -24389, -24373, -24340, -24323, -24291, -24272, -24243, -24218, -24197, -24165, -24148, -24115, -24095, -24066, -24044, -24015, -23992, -23965, -23939, -23916, -23886, -23864, -23835, -23811, -23785, -23757, -23733, -23706, -23679, -23654, -23627, -23600, -23575, -23546, -23523, -23492, -23471, -23438, -23416, -23386, -23360, -23335, -23304, -23283, -23248, -23228, -23196, -23171, -23143, -23116, -23088, -23061, -23033, -23005, -22979, -22949, -22923, -22895, -22865, -22841, -22808, -22785, -22753, -22727, -22697, -22672, -22639, -22615, -22583, -22558, -22526, -22501, -22468, -22444, -22412, -22385, -22355, -22327, -22296, -22271, -22238, -22211, -22182, -22150, -22125, -22092, -22066, -22032, -22008, -21973, -21949, -21914, -21889, -21855, -21829, -21796, -21769, -21736, -21711, -21674, -21650, -21616, -21587, -21559, -21525, -21497, -21466, -21435, -21405, -21376, -21341, -21316, -21280, -21254, -21220, -21190, -21160, -21127, -21099, -21065, -21036, -21003, -20975, -20939, -20914, -20875, -20851, -20813, -20788, -20751, -20723, -20688, -20660, -20626, -20595, -20563, -20530, -20501, -20465, -20438, -20401, -20373, -20337, -20308, -20273, -20244, -24295, -24222, -24153, -24075, -24012, -23929, -23867, -23787, -23718, -23645, -23572, -23501, -23427, -23355, -23281, -23210, -23137, -23063, -22993, -22916, -22846, -22772, -22698, -22628, -22552, -22479, -22407, -22334, -22258, -22188, -22113, -22039, -21967, -21892, -21819, -21745, -21674, -21595, -21527, -21449, -21376, -21304, -21228, -21156, -21079, -21009, -20930, -20861, -20782, -20711, -20635, -20562, -20488, -20409, -20343, -20258, -20194, -20111, -20042, -19964, -19891, -19815, -19742, -19664, -19594, -19513, -19443, -19367, -19288, -19220, -19137, -19068, -18990, -18915, -18840, -18764, -18690, -18613, -18539, -18462, -18387, -18312, -18236, -18160, -18085, -18007, -17935, -17856, -17782, -17705, -17629, -17553, -17479, -17399, -17327, -17248, -17172, -17099, -17016, -16948, -16864, -16794, -16713, -16638, -16562, -16485, -16409, -16331, -16256, -16178, -16102, -16024, -15949, -15871, -15794, -15719, -15638, -15566, -15483, -15413, -15329, -15257, -15177, -15100, -15024, -14945, -14869, -14792, -14711, -14640, -14555, -14483, -14405, -14322, -14254, -14165, -14097, -14013, -13938, -13861, -13779, -13707, -13623, -13550, -13469, -13392, -13315, -13234, -13159, -13078, -13002, -12923, -12844, -12767, -12686, -12612, -12528, -12456, -12371, -12298, -12215, -12140, -12058, -11983, -11901, -11825, -11743, -11668, -11585, -11511, -11427, -11353, -11269, -11195, -11112, -11036, -10954, -10877, -10798, -10717, -10639, -10560, -10479, -10403, -10319, -10244, -10162, -10084, -10003, -9925, -9844, -9767, -9683, -9608, -9525, -9448, -9366, -9288, -9205, -9131, -9045, -8969, -8888, -8807, -8729, -8648, -8567, -8569, -8564, -8569, -8561, -8568, -8559, -8566, -8559, -8562, -8558, -8559, -8557, -8557, -8555, -8553, -8554, -8550, -8553, -8547, -8550, -8544, -8547, -8542, -8545, -8540, -8539, -8540, -8534, -8538, -8532, -8533, -8530, -8529, -8528, -8524, -8525, -8521, -8522, -8517, -8518, -8513, -8515, -8509, -8511, -8506, -8507, -8501, -8504, -8497, -8499, -8493, -8496, -8488, -8491, -8486, -8483, -8484, -8478, -8480, -8473, -8474, -8470, -8468, -8468, -8460, -8464, -8456, -8457, -8454, -8450, -8448, -8448, -8439, -8445, -8435, -8436, -8433, -8429, -8427, -8426, -8419, -8420, -8416, -8412, -8412, -8406, -8404, -8402, -8398, -8395, -8394, -8388, -8387, -8383, -8380, -8377, -8374, -8371, -8368, -8365, -8359, -8362, -8349, -8359, -8342, -8349, -8339, -8341, -8333, -8333, -8327, -8324, -8324, -8316, -8315, -8311, -8307, -8303, -8303, -8295, -8294, -8289, -8285, -8285, -8277, -8277, -8269, -8270, -8261, -8265, -8251, -8258, -8245, -8247, -8241, -8238, -8233, -8230, -8226, -8222, -8218, -8216, -8207, -8209, -8201, -8199, -8194, -8190, -8187, -8182, -8179, -8172, -8171, -8167, -8160, -8161, -8149, -8153, -8142, -8144, -8134, -8135, -8126, -8126, -8117, -8119, -8107, -8112, -8098, -8102, -8091, -8091, -8085, -8082, -8075, -8073, -8067, -8063, -8060, -8053, -8051, -8045, -8040, -8038, -8031, -8027, -8025, -8015, -8018, -8005, -8008, -7998, -7997, -7990, -7986, -7983, -7976, -7973, -7968, -7962, -7960, -7952, -7952, -7941, -7943, -3847, -3806, -3762, -3714, -3675, -3624, -3586, -3536, -3497, -3447, -3407, -3360, -3316, -3273, -3226, -3184, -3138, -3093, -3050, -3005, -2960, -2916, -2870, -2827, -2782, -2739, -2690, -2650, -2603, -2558, -2517, -2468, -2426, -2380, -2336, -2291, -2248, -2201, -2157, -2115, -2064, -2028, -1976, -1935, -1889, -1846, -1798, -1758, -1709, -1666, -1623, -1574, -1535, -1484, -1446, -1395, -1354, -1309, -1263, -1219, -1174, -1129, -1085, -1040, -995, -951, -905, -861, -816, -772, -727, -681, -638, -592, -548, -502, -460, -410, -374, -318, -284, -230, -194, -141, -104};
