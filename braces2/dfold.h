

// dfold.h
int dfold_SIZE = 4096;
const int16_t dfold_DATA[4096] =
{-9453, -9309, -9170, -9026, -8886, -8744, -8602, -8460, -8321, -8175, -8038, -7891, -7756, -7608, -7471, -7327, -7186, -7046, -6901, -6763, -6617, -6481, -6335, -6195, -6055, -5909, -5772, -5628, -5488, -5345, -5204, -5063, -4920, -4782, -4635, -4499, -4354, -4214, -4073, -3929, -3790, -3648, -3506, -3366, -3222, -3083, -2940, -2801, -2656, -2518, -2374, -2236, -2091, -1953, -1807, -1673, -1524, -1389, -1243, -1105, -962, -823, -678, -541, -397, -257, -116, 27, 165, 309, 447, 591, 731, 872, 1012, 1155, 1293, 1438, 1574, 1720, 1856, 2002, 2138, 2282, 2421, 2563, 2703, 2845, 2983, 3127, 3266, 3406, 3548, 3688, 3828, 3971, 4108, 4251, 4390, 4533, 4671, 4811, 4955, 5091, 5234, 5375, 5512, 5656, 5794, 5934, 6077, 6214, 6356, 6495, 6636, 6776, 6916, 7056, 7195, 7337, 7474, 7619, 7753, 7897, 8034, 8176, 8316, 8453, 8596, 8733, 8874, 9014, 9152, 9294, 9430, 9575, 9706, 9856, 9985, 10133, 10266, 10410, 10545, 10688, 10825, 10964, 11106, 11240, 11385, 11519, 11661, 11799, 11938, 12077, 12216, 12354, 12494, 12632, 12771, 12909, 13050, 13183, 13331, 13458, 13607, 13737, 13882, 14016, 14157, 14293, 14434, 14569, 14709, 14849, 14982, 15127, 15257, 15402, 15535, 15677, 15811, 15952, 16087, 16227, 16363, 16502, 16639, 16776, 16914, 17052, 17189, 17326, 17464, 17600, 17739, 17874, 18015, 18146, 18290, 18421, 18561, 18699, 18832, 18973, 19106, 19247, 19379, 19520, 19654, 19790, 19930, 20061, 20203, 20335, 20475, 20607, 20747, 20881, 21018, 21154, 21289, 21426, 21562, 21697, 21834, 21968, 22106, 22238, 22379, 22507, 22652, 22778, 22920, 23052, 23188, 23323, 23460, 23592, 23730, 23863, 23998, 24135, 24267, 24404, 24536, 24675, 24804, 24945, 25072, 25213, 25344, 25479, 25614, 25745, 25884, 26015, 26149, 26285, 26416, 26552, 26685, 26819, 26953, 27086, 27218, 27355, 27485, 27622, 27752, 27886, 28019, 28154, 28284, 28421, 28549, 28687, 28814, 28953, 29081, 29215, 29173, 29034, 28909, 28771, 28641, 28510, 28375, 28246, 28111, 27982, 27846, 27720, 27582, 27455, 27321, 27191, 27057, 26929, 26794, 26667, 26531, 26404, 26269, 26143, 26007, 25880, 25746, 25618, 25486, 25356, 25223, 25098, 24961, 24837, 24702, 24574, 24443, 24315, 24180, 24058, 23920, 23797, 23663, 23534, 23407, 23274, 23148, 23017, 22886, 22762, 22627, 22502, 22373, 22241, 22115, 21986, 21856, 21730, 21599, 21471, 21345, 21213, 21090, 20955, 20968, 21009, 21058, 21100, 21150, 21189, 21242, 21279, 21331, 21371, 21419, 21463, 21508, 21552, 21596, 21643, 21683, 21735, 21770, 21821, 21863, 21904, 21955, 21991, 22040, 22082, 22126, 22169, 22214, 22253, 22303, 22340, 22387, 22429, 22471, 22515, 22559, 22596, 22648, 22680, 22733, 22766, 22814, 22855, 22896, 22938, 22982, 23021, 23065, 23106, 23146, 23190, 23231, 23270, 23314, 23354, 23394, 23438, 23475, 23519, 23558, 23598, 23641, 23679, 23722, 23758, 23802, 23841, 23880, 23922, 23959, 24000, 24041, 24079, 24117, 24161, 24193, 24241, 24272, 24316, 24353, 24391, 24432, 24468, 24510, 24543, 24588, 24619, 24664, 24698, 24736, 24776, 24810, 24853, 24885, 24927, 24960, 25002, 25034, 25078, 25106, 25151, 25183, 25222, 25257, 25295, 25328, 25371, 25399, 25442, 25473, 25512, 25547, 25581, 25620, 25652, 25690, 25724, 25759, 25795, 25830, 25863, 25901, 25932, 25970, 26002, 26037, 26074, 26103, 26141, 26174, 26207, 26243, 26274, 26310, 26340, 26378, 26407, 26443, 26475, 26507, 26542, 26573, 26606, 26639, 26671, 26703, 26737, 26766, 26801, 26832, 26862, 26896, 26927, 26957, 26991, 27019, 27053, 27082, 27115, 27144, 27176, 27206, 27235, 27269, 27296, 27328, 27357, 27388, 27499, 27613, 27721, 27837, 27947, 28058, 28172, 28280, 28393, 28505, 28613, 28728, 28836, 28947, 29059, 29167, 29241, 29127, 29021, 28906, 28801, 28688, 28579, 28470, 28360, 28251, 28142, 28031, 27925, 27813, 27707, 27596, 27488, 27381, 27272, 27162, 27056, 26947, 26839, 26732, 26625, 26514, 26412, 26298, 26198, 26085, 25982, 25873, 25766, 25663, 25551, 25449, 25340, 25235, 25131, 25021, 24919, 24810, 24707, 24600, 24496, 24390, 24285, 24181, 24074, 23971, 23867, 23760, 23658, 23553, 23449, 23344, 23242, 23137, 23033, 22932, 22823, 22727, 22618, 22519, 22413, 22312, 22209, 22106, 22004, 21901, 21801, 21695, 21598, 21491, 21394, 21290, 21188, 21089, 20985, 20887, 20783, 20685, 20582, 20483, 20382, 20280, 20184, 20079, 19984, 19879, 19784, 19680, 19584, 19484, 19383, 19288, 19182, 19091, 18986, 18893, 18789, 18696, 18593, 18500, 18397, 18302, 18204, 18107, 18008, 17912, 17814, 17718, 17620, 17524, 17426, 17332, 17232, 17141, 17038, 16949, 16848, 16754, 16659, 16563, 16467, 16373, 16277, 16182, 16088, 15992, 15899, 15802, 15712, 15613, 15522, 15428, 15331, 15243, 15143, 15055, 14959, 14866, 14774, 14680, 14588, 14496, 14401, 14312, 14217, 14126, 14035, 13942, 13849, 13763, 13662, 13582, 13481, 13396, 13304, 13211, 13123, 13032, 12939, 12854, 12758, 12673, 12581, 12490, 12405, 12309, 12227, 12131, 12047, 11956, 11868, 11780, 11688, 11604, 11514, 11426, 11339, 11249, 11163, 11077, 10985, 10905, 10808, 10732, 10636, 10555, 10467, 10379, 10295, 10208, 10121, 10037, 9951, 9863, 9781, 9693, 9610, 9524, 9438, 9355, 9269, 9186, 9101, 9017, 8931, 8851, 8763, 8684, 8595, 8517, 8430, 8349, 8266, 8181, 8101, 8018, 7935, 7853, 7770, 7690, 7606, 7527, 7443, 7363, 7281, 7200, 7120, 7038, 6958, 6878, 6795, 6719, 6635, 6557, 6478, 6395, 6320, 6236, 6160, 6080, 6001, 5921, 5846, 5762, 5689, 5605, 5534, 5449, 5378, 5293, 5221, 5142, 5064, 4988, 4910, 4833, 4759, 4679, 4605, 4527, 4453, 4374, 4303, 4221, 4152, 4072, 3999, 3922, 3851, 3770, 3703, 3621, 3551, 3478, 3399, 3330, 3253, 3180, 3109, 3032, 2962, 2886, 2816, 2741, 2670, 2596, 2526, 2451, 2382, 2307, 2238, 2165, 2094, 2022, 1952, 1881, 1808, 1741, 1667, 1598, 1529, 1456, 1389, 1318, 1248, 1179, 1109, 1040, 972, 902, 833, 766, 695, 630, 558, 493, 424, 355, 291, 219, 157, 84, 21, -47, -114, -179, -248, -311, -381, -442, -514, -572, -646, -704, -773, -838, -899, -971, -1028, -1098, -1159, -1224, -1289, -1352, -1415, -1481, -1541, -1608, -1667, -1734, -1792, -1862, -1915, -1987, -2039, -2111, -2166, -2231, -2292, -2352, -2415, -2476, -2536, -2597, -2659, -2718, -2779, -2840, -2897, -2962, -3016, -3082, -3134, -3200, -3255, -3316, -3375, -3431, -3493, -3550, -3606, -3670, -3720, -3786, -3836, -3901, -3951, -4015, -4065, -4129, -4180, -4241, -4294, -4351, -4410, -4461, -4521, -4575, -4630, -4688, -4740, -4795, -4853, -4906, -4960, -5016, -5068, -5123, -5180, -5228, -5288, -5336, -5393, -5445, -5498, -5550, -5606, -5653, -5712, -5759, -5815, -5863, -5920, -5965, -6023, -6072, -6121, -6176, -6223, -6277, -6326, -6376, -6428, -6476, -6528, -6577, -6627, -6675, -6727, -6774, -6824, -6874, -6920, -6971, -7020, -7064, -7119, -7159, -7214, -7258, -7305, -7356, -7398, -7450, -7495, -7539, -7592, -7631, -7685, -7724, -7775, -7818, -7865, -7911, -7955, -8002, -8044, -8094, -8132, -8184, -8222, -8270, -8313, -8358, -8401, -8444, -8488, -8532, -8575, -8619, -8659, -8704, -8747, -8788, -8832, -8872, -8915, -8958, -8998, -9040, -9083, -9121, -9083, -9039, -9000, -8957, -8915, -8873, -8831, -8789, -8746, -8705, -8659, -8620, -8573, -8533, -8487, -8446, -8400, -8358, -8313, -8268, -8226, -8179, -8137, -8090, -8046, -8002, -7954, -7912, -7863, -7821, -7772, -7728, -7680, -7635, -7590, -7539, -7497, -7446, -7402, -7354, -7305, -7260, -7209, -7165, -7115, -7066, -7021, -6967, -6924, -6872, -6824, -6777, -6722, -6679, -6626, -6576, -6529, -6475, -6429, -6376, -6327, -6274, -6226, -6174, -6123, -6072, -6019, -5970, -5917, -5865, -5814, -5759, -5712, -5653, -5607, -5548, -5500, -5444, -5393, -5337, -5286, -5230, -5178, -5124, -5068, -5016, -4960, -4906, -4852, -4795, -4742, -4686, -4630, -4576, -4520, -4462, -4409, -4352, -4293, -4243, -4179, -4127, -4069, -4011, -3955, -3898, -3838, -3783, -3723, -3669, -3605, -3553, -3489, -3434, -3375, -3314, -3258, -3196, -3139, -3077, -3021, -2958, -2899, -2840, -2778, -2719, -2659, -2596, -2538, -2475, -2413, -2356, -2289, -2232, -2168, -2105, -2046, -1982, -1920, -1858, -1793, -1733, -1670, -1605, -1544, -1477, -1418, -1352, -1288, -1224, -1160, -1097, -1030, -969, -900, -838, -773, -706, -642, -576, -510, -446, -378, -313, -247, -178, -117, -43, 16, 90, 152, 223, 287, 358, 423, 492, 561, 627, 697, 766, 831, 905, 969, 1041, 1111, 1176, 1252, 1314, 1390, 1457, 1528, 1598, 1669, 1738, 1809, 1882, 1950, 2025, 2091, 2168, 2234, 2311, 2379, 2454, 2523, 2598, 2668, 2743, 2815, 2886, 2962, 3033, 3107, 3182, 3252, 3331, 3399, 3477, 3550, 3625, 3699, 3773, 3848, 3924, 3998, 4075, 4146, 4227, 4299, 4376, 4453, 4525, 4608, 4676, 4763, 4828, 4915, 4984, 5067, 5140, 5221, 5296, 5374, 5453, 5530, 5607, 5690, 5760, 5848, 5919, 6003, 6079, 6158, 6240, 6315, 6401, 6473, 6558, 6637, 6715, 6800, 6875, 6958, 7039, 7118, 7203, 7278, 7367, 7438, 7531, 7603, 7692, 7769, 7854, 7934, 8019, 8099, 8183, 8266, 8348, 8431, 8515, 8598, 8682, 8765, 8847, 8935, 9015, 9103, 9184, 9269, 9357, 9435, 9528, 9606, 9696, 9779, 9864, 9951, 10036, 10122, 10208, 10294, 10381, 10466, 10553, 10640, 10727, 10814, 10901, 10987, 11075, 11164, 11249, 11340, 11425, 11514, 11603, 11690, 11780, 11867, 11956, 12047, 12132, 12225, 12312, 12401, 12494, 12579, 12672, 12761, 12849, 12944, 13030, 13123, 13211, 13305, 13393, 13487, 13574, 13670, 13757, 13853, 13940, 14036, 14124, 14220, 14309, 14403, 14496, 14587, 14681, 14773, 14866, 14961, 15051, 15148, 15239, 15333, 15427, 15522, 15614, 15711, 15802, 15899, 15993, 16086, 16184, 16276, 16373, 16468, 16562, 16659, 16754, 16850, 16945, 17043, 17136, 17236, 17329, 17429, 17521, 17623, 17715, 17816, 17912, 18006, 18110, 18200, 18305, 18397, 18498, 18595, 18694, 18790, 18893, 18986, 19090, 19185, 19285, 19385, 19484, 19581, 19685, 19779, 19884, 19980, 20082, 20181, 20282, 20381, 20483, 20583, 20684, 20783, 20888, 20983, 21091, 21186, 21293, 21390, 21495, 21594, 21698, 21800, 21901, 22003, 22109, 22205, 22316, 22410, 22520, 22619, 22724, 22826, 22932, 23031, 23139, 23240, 23345, 23450, 23551, 23659, 23760, 23867, 23971, 24074, 24182, 24283, 24391, 24497, 24598, 24710, 24808, 24919, 25023, 25129, 25235, 25341, 25448, 25553, 25662, 25765, 25875, 25979, 26089, 26194, 26301, 26411, 26514, 26626, 26730, 26840, 26947, 27056, 27162, 27274, 27376, 27493, 27592, 27711, 27810, 27926, 28031, 28141, 28254, 28356, 28473, 28577, 28689, 28801, 28906, 29020, 29129, 29238, 29170, 29058, 28946, 28839, 28724, 28617, 28502, 28394, 28281, 28171, 28058, 27948, 27833, 27727, 27608, 27503, 27384, 27361, 27325, 27298, 27268, 27234, 27209, 27173, 27146, 27114, 27083, 27051, 27022, 26987, 26962, 26923, 26898, 26861, 26833, 26799, 26769, 26734, 26705, 26670, 26639, 26607, 26573, 26540, 26510, 26473, 26444, 26407, 26377, 26341, 26310, 26274, 26243, 26206, 26176, 26137, 26108, 26072, 26035, 26006, 25965, 25937, 25897, 25866, 25827, 25798, 25756, 25728, 25684, 25658, 25616, 25584, 25546, 25510, 25476, 25439, 25404, 25366, 25331, 25293, 25260, 25218, 25187, 25146, 25112, 25074, 25036, 25000, 24962, 24926, 24886, 24852, 24811, 24775, 24737, 24698, 24662, 24622, 24585, 24545, 24509, 24468, 24432, 24391, 24355, 24311, 24279, 24234, 24198, 24158, 24119, 24078, 24042, 23998, 23961, 23922, 23878, 23844, 23798, 23762, 23720, 23680, 23639, 23600, 23557, 23519, 23476, 23436, 23396, 23353, 23314, 23270, 23232, 23188, 23148, 23106, 23063, 23024, 22979, 22940, 22896, 22855, 22812, 22770, 22727, 22686, 22643, 22600, 22557, 22515, 22471, 22430, 22385, 22343, 22299, 22257, 22211, 22172, 22123, 22085, 22035, 21997, 21950, 21907, 21864, 21816, 21777, 21729, 21686, 21642, 21596, 21553, 21507, 21463, 21418, 21373, 21328, 21284, 21235, 21196, 21145, 21103, 21056, 21011, 20965, 20960, 21085, 21217, 21341, 21474, 21599, 21728, 21858, 21984, 22116, 22242, 22372, 22502, 22627, 22762, 22885, 23019, 23147, 23274, 23407, 23534, 23664, 23796, 23921, 24056, 24183, 24312, 24446, 24571, 24706, 24832, 24966, 25093, 25226, 25356, 25485, 25618, 25747, 25878, 26010, 26139, 26272, 26403, 26532, 26666, 26794, 26929, 27058, 27190, 27322, 27452, 27588, 27713, 27852, 27977, 28115, 28242, 28379, 28507, 28642, 28773, 28904, 29039, 29171, 29215, 29083, 28949, 28817, 28686, 28550, 28421, 28283, 28155, 28017, 27889, 27751, 27622, 27484, 27356, 27217, 27088, 26952, 26817, 26688, 26548, 26422, 26280, 26152, 26013, 25884, 25746, 25615, 25477, 25346, 25210, 25076, 24942, 24806, 24673, 24538, 24402, 24269, 24133, 23999, 23864, 23728, 23593, 23459, 23323, 23190, 23051, 22918, 22782, 22648, 22510, 22377, 22239, 22105, 21970, 21832, 21699, 21560, 21426, 21291, 21152, 21020, 20879, 20749, 20606, 20476, 20334, 20203, 20062, 19930, 19789, 19656, 19518, 19380, 19246, 19108, 18970, 18836, 18697, 18560, 18424, 18286, 18151, 18010, 17879, 17733, 17606, 17460, 17328, 17189, 17050, 16916, 16775, 16640, 16501, 16364, 16226, 16088, 15951, 15813, 15674, 15538, 15399, 15261, 15124, 14984, 14847, 14710, 14570, 14433, 14293, 14157, 14017, 13880, 13740, 13602, 13465, 13323, 13190, 13045, 12911, 12771, 12631, 12495, 12353, 12216, 12078, 11937, 11800, 11660, 11519, 11386, 11239, 11108, 10962, 10826, 10686, 10549, 10405, 10272, 10126, 9992, 9849, 9712, 9571, 9432, 9293, 9152, 9015, 8872, 8736, 8591, 8458, 8313, 8176, 8036, 7893, 7758, 7615, 7475, 7338, 7193, 7059, 6913, 6778, 6634, 6497, 6354, 6217, 6073, 5937, 5794, 5654, 5515, 5373, 5233, 5095, 4951, 4813, 4672, 4530, 4393, 4248, 4111, 3970, 3827, 3690, 3546, 3408, 3264, 3128, 2983, 2846, 2702, 2562, 2423, 2280, 2141, 1999, 1858, 1718, 1576, 1437, 1293, 1155, 1012, 872, 732, 588, 449, 308, 167, 24, -113, -261, -393, -543, -677, -825, -959, -1107, -1242, -1388, -1528, -1668, -1811, -1951, -2091, -2237, -2373, -2518, -2658, -2798, -2942, -3082, -3223, -3366, -3505, -3649, -3789, -3930, -4073, -4213, -4356, -4496, -4639, -4777, -4924, -5060, -5206, -5345, -5487, -5629, -5770, -5911, -6055, -6194, -6338, -6476, -6621, -6761, -6903, -7045, -7184, -7331, -7465, -7616, -7746, -7901, -8030, -8181, -8317, -8461, -8603, -8743, -8886, -9027, -9169, -9310, -9452, -9512, -9570, -9630, -9691, -9746, -9810, -9867, -9925, -9989, -10043, -10106, -10163, -10225, -10280, -10344, -10400, -10462, -10518, -10581, -10637, -10699, -10756, -10816, -10877, -10933, -10996, -11051, -11115, -11170, -11232, -11289, -11351, -11408, -11468, -11528, -11585, -11647, -11703, -11766, -11821, -11885, -11937, -12005, -12055, -12123, -12174, -12239, -12295, -12355, -12414, -12473, -12532, -12592, -12648, -12712, -12764, -12831, -12883, -12947, -13002, -13064, -13120, -13182, -13238, -13299, -13357, -13415, -13476, -13532, -13593, -13651, -13709, -13769, -13826, -13887, -13944, -14002, -14063, -14119, -14180, -14237, -14295, -14356, -14412, -14473, -14528, -14590, -14646, -14706, -14763, -14822, -14881, -14939, -14996, -15057, -15111, -15174, -15229, -15288, -15348, -15403, -15464, -15518, -15583, -15633, -15698, -15751, -15812, -15868, -15929, -15981, -16047, -16097, -16160, -16216, -16272, -16334, -16388, -16447, -16505, -16561, -16621, -16676, -16737, -16790, -16852, -16906, -16965, -17022, -17080, -17136, -17196, -17249, -17311, -17364, -17424, -17480, -17538, -17594, -17651, -17709, -17765, -17822, -17881, -17933, -17996, -18048, -18107, -18163, -18221, -18275, -18335, -18389, -18447, -18503, -18559, -18616, -18674, -18727, -18787, -18839, -18900, -18953, -19011, -19066, -19121, -19181, -19232, -19293, -19345, -19402, -19460, -19512, -19572, -19623, -19684, -19736, -19793, -19848, -19903, -19960, -20016, -20069, -20126, -20180, -20237, -20293, -20344, -20404, -20456, -20512, -20568, -20622, -20675, -20736, -20783, -20843, -20898, -20947, -21011, -21056, -21117, -21170, -21222, -21280, -21332, -21388, -21441, -21496, -21549, -21605, -21657, -21714, -21764, -21822, -21873, -21928, -21982, -22035, -22090, -22141, -22199, -22247, -22306, -22355, -22411, -22463, -22518, -22568, -22625, -22674, -22732, -22781, -22836, -22887, -22943, -22991, -23051, -23094, -23157, -23201, -23259, -23309, -23362, -23413, -23469, -23516, -23574, -23621, -23676, -23727, -23780, -23830, -23884, -23934, -23986, -24040, -24088, -24141, -24194, -24242, -24298, -24345, -24399, -24449, -24500, -24551, -24603, -24653, -24705, -24754, -24806, -24857, -24906, -24958, -25009, -25057, -25110, -25159, -25209, -25261, -25308, -25362, -25408, -25461, -25508, -25560, -25610, -25658, -25709, -25757, -25807, -25858, -25904, -25959, -26000, -26057, -26101, -26151, -26203, -26247, -26299, -26347, -26396, -26443, -26494, -26539, -26592, -26636, -26687, -26733, -26782, -26831, -26878, -26926, -26974, -27020, -27071, -27116, -27165, -27211, -27259, -27307, -27353, -27401, -27448, -27494, -27542, -27590, -27633, -27684, -27728, -27774, -27824, -27866, -27916, -27960, -28007, -28053, -28098, -28147, -28188, -28239, -28146, -28022, -27890, -27767, -27633, -27512, -27379, -27257, -27124, -27000, -26873, -26742, -26623, -26486, -26367, -26236, -26111, -25983, -25859, -25729, -25605, -25479, -25349, -25229, -25097, -24974, -24848, -24722, -24594, -24474, -24340, -24224, -24090, -23971, -23841, -23720, -23592, -23469, -23343, -23216, -23096, -22968, -22844, -22722, -22592, -22474, -22345, -22224, -22098, -21975, -21852, -21725, -21605, -21479, -21356, -21234, -21109, -20986, -20863, -20740, -20617, -20495, -20371, -20247, -20128, -20001, -19884, -19757, -19635, -19517, -19389, -19273, -19146, -19027, -18905, -18782, -18663, -18538, -18421, -18295, -18178, -18054, -17935, -17813, -17693, -17571, -17451, -17332, -17209, -17092, -16968, -16850, -16729, -16611, -16488, -16373, -16248, -16132, -16011, -15892, -15773, -15655, -15532, -15419, -15293, -15182, -15056, -14944, -14819, -14706, -14585, -14467, -14351, -14229, -14115, -13995, -13878, -13761, -13642, -13526, -13408, -13291, -13174, -13057, -12940, -12824, -12706, -12590, -12474, -12356, -12244, -12121, -12013, -11888, -11781, -11659, -11546, -11430, -11314, -11200, -11084, -10968, -10854, -10739, -10624, -10509, -10395, -10280, -10166, -10051, -9937, -9824, -9709, -9596, -9480, -9369, -9255, -9140, -9029, -8913, -8802, -8688, -8576, -8461, -8352, -8236, -8125, -8012, -7901, -7870, -7841, -7810, -7783, -7750, -7725, -7691, -7667, -7634, -7607, -7577, -7550, -7520, -7493, -7463, -7437, -7406, -7381, -7351, -7324, -7297, -7269, -7240, -7217, -7184, -7162, -7131, -7108, -7078, -7054, -7026, -6998, -6977, -6943, -6926, -6892, -6871, -6845, -6816, -6794, -6768, -6740, -6721, -6688, -6670, -6641, -6618, -6594, -6568, -6545, -6520, -6496, -6473, -6448, -6424, -6402, -6377, -6355, -6330, -6309, -6284, -6263, -6238, -6217, -6194, -6172, -6149, -6127, -6104, -6085, -6059, -6042, -6015, -5999, -5973, -5957, -5930, -5913, -5890, -5871, -5849, -5832, -5804, -5793, -5764, -5753, -5725, -5711, -5688, -5670, -5651, -5629, -5614, -5591, -5575, -5555, -5536, -5518, -5500, -5480, -5465, -5443, -5430, -5406, -5395, -5371, -5360, -5338, -5323, -5306, -5286, -5276, -5249, -5246, -5215, -5211, -5187, -5174, -5159, -5140, -5128, -5110, -5096, -5081, -5063, -5052, -5033, -5024, -5002, -4995, -4973, -4966, -4947, -4935, -4922, -4905, -4896, -4878, -4869, -4851, -4843, -4826, -4816, -4802, -4789, -4777, -4766, -4751, -4742, -4729, -4715, -4709, -4690, -4686, -4669, -4660, -4651, -4637, -4628, -4618, -4604, -4599, -4585, -4575, -4568, -4554, -4549, -4536, -4528, -4519, -4509, -4500, -4493, -4481, -4477, -4463, -4460, -4447, -4443, -4433, -4425, -4419, -4410, -4403, -4396, -4389, -4381, -4376, -4368, -4361, -4356, -4349, -4343, -4337, -4330, -4325, -4321, -4313, -4310, -4302, -4300, -4292, -4291, -4281, -4283, -4272, -4275, -4263, -4266, -4257, -4256, -4253, -4248, -4245, -4243, -4237, -4239, -4231, -4233, -4228, -4224, -4228, -4218, -4223, -4218, -4215, -4217, -4213, -4213, -4213, -4209, -4212, -4207, -4211, -4208, -4208, -4210, -4206, -4211, -4207, -4211, -4209, -4211, -4213, -4211, -4216, -4214, -4217, -4219, -4220, -4222, -4226, -4224, -4230, -4231, -4234, -4238, -4237, -4244, -4246, -4248, -4254, -4255, -4260, -4266, -4265, -4274, -4276, -4281, -4286, -4291, -4293, -4303, -4304, -4312, -4315, -4324, -4325, -4337, -4337, -4348, -4351, -4360, -4365, -4372, -4379, -4386, -4394, -4402, -4407, -4416, -4423, -4433, -4440, -4448, -4457, -4462, -4478, -4478, -4496, -4498, -4510, -4519, -4530, -4537, -4550, -4557, -4569, -4579, -4589, -4599, -4613, -4619, -4633, -4645, -4651, -4672, -4673, -4692, -4701, -4714, -4725, -4740, -4748, -4765, -4776, -4789, -4802, -4816, -4828, -4843, -4856, -4869, -4886, -4894, -4917, -4921, -4947, -4952, -4973, -4984, -5002, -5016, -5032, -5048, -5061, -5081, -5094, -5113, -5125, -5147, -5158, -5179, -5195, -5211, -5229, -5248, -5261, -5284, -5298, -5319, -5334, -5356, -5369, -5395, -5406, -5432, -5445, -5467, -5488, -5504, -5527, -5544, -5565, -5586, -5605, -5627, -5644, -5671, -5684, -5712, -5728, -5753, -5772, -5797, -5813, -5841, -5859, -5883, -5906, -5926, -5951, -5973, -5996, -6020, -6041, -6067, -6089, -6113, -6138, -6161, -6184, -6212, -6231, -6262, -6282, -6309, -6334, -6358, -6385, -6410, -6436, -6461, -6488, -6513, -6541, -6566, -6594, -6619, -6647, -6674, -6702, -6728, -6757, -6783, -6812, -6840, -6867, -6898, -6923, -6954, -6982, -7011, -7039, -7071, -7097, -7129, -7159, -7185, -7220, -7246, -7280, -7308, -7339, -7371, -7399, -7433, -7464, -7492, -7530, -7554, -7593, -7618, -7656, -7685, -7719, -7751, -7783, -7818, -7848, -7886, -7912, -7955, -7978, -8023, -8047, -8088, -8120, -8153, -8190, -8223, -8259, -8293, -8330, -8363, -8401, -8435, -8470, -8509, -8543, -8579, -8617, -8652, -8690, -8726, -8763, -8801, -8838, -8876, -8913, -8949, -8993, -9023, -9069, -9102, -9143, -9182, -9219, -9261, -9297, -9338, -9379, -9414, -9461, -9493, -9540, -9575, -9620, -9657, -9699, -9741, -9780, -9741, -9700, -9656, -9620, -9576, -9538, -9497, -9456, -9418, -9376, -9340, -9297, -9259, -9222, -9179, -9144, -9104, -9064, -9029, -8988, -8951, -8914, -8875, -8838, -8801, -8763, -8727, -8688, -8654, -8616, -8580, -8543, -8507, -8471, -8436, -8400, -8364, -8329, -8293, -8260, -8222, -8190, -8154, -8120, -8086, -8051, -8017, -7984, -7950, -7916, -7884, -7849, -7817, -7783, -7752, -7719, -7685, -7654, -7622, -7589, -7559, -7525, -7494, -7465, -7430, -7403, -7368, -7341, -7307, -7279, -7247, -7220, -7185, -7160, -7126, -7100, -7070, -7038, -7014, -6978, -6957, -6923, -6896, -6870, -6837, -6813, -6784, -6756, -6729, -6700, -6675, -6646, -6621, -6593, -6565, -6541, -6514, -6487, -6463, -6433, -6413, -6381, -6363, -6330, -6311, -6282, -6260, -6234, -6209, -6186, -6161, -6136, -6116, -6085, -6070, -6039, -6023, -5993, -5975, -5948, -5929, -5906, -5880, -5863, -5836, -5819, -5793, -5774, -5750, -5732, -5708, -5688, -5668, -5645, -5628, -5604, -5585, -5566, -5544, -5527, -5505, -5485, -5469, -5445, -5432, -5407, -5393, -5370, -5356, -5334, -5319, -5299, -5281, -5265, -5245, -5230, -5211, -5195, -5178, -5160, -5145, -5127, -5111, -5097, -5077, -5063, -5050, -5028, -5020, -4998, -4987, -4971, -4955, -4942, -4926, -4913, -4897, -4884, -4869, -4857, -4843, -4827, -4817, -4801, -4790, -4776, -4763, -4751, -4739, -4724, -4716, -4700, -4691, -4677, -4667, -4654, -4645, -4631, -4623, -4609, -4602, -4585, -4584, -4563, -4564, -4544, -4541, -4526, -4522, -4508, -4502, -4491, -4482, -4474, -4465, -4457, -4447, -4442, -4429, -4425, -4416, -4408, -4402, -4391, -4389, -4376, -4376, -4362, -4361, -4351, -4347, -4339, -4335, -4326, -4323, -4316, -4311, -4306, -4299, -4296, -4290, -4286, -4281, -4276, -4272, -4268, -4264, -4260, -4257, -4252, -4249, -4246, -4242, -4241, -4235, -4235, -4230, -4231, -4224, -4226, -4221, -4221, -4218, -4217, -4215, -4216, -4210, -4215, -4207, -4214, -4207, -4210, -4208, -4209, -4208, -4209, -4207, -4211, -4207, -4212, -4210, -4212, -4213, -4213, -4216, -4216, -4220, -4219, -4223, -4223, -4226, -4230, -4229, -4237, -4232, -4242, -4241, -4245, -4249, -4252, -4254, -4262, -4260, -4269, -4269, -4277, -4278, -4286, -4287, -4295, -4298, -4304, -4308, -4314, -4320, -4326, -4330, -4338, -4341, -4350, -4356, -4360, -4370, -4374, -4381, -4391, -4393, -4406, -4408, -4420, -4424, -4435, -4440, -4450, -4458, -4465, -4475, -4482, -4492, -4501, -4509, -4518, -4529, -4536, -4548, -4555, -4567, -4576, -4586, -4597, -4606, -4617, -4627, -4640, -4647, -4663, -4668, -4685, -4693, -4706, -4716, -4729, -4741, -4752, -4767, -4775, -4790, -4803, -4813, -4830, -4838, -4855, -4866, -4881, -4893, -4908, -4919, -4937, -4947, -4963, -4978, -4990, -5007, -5020, -5035, -5050, -5065, -5080, -5096, -5111, -5126, -5142, -5158, -5173, -5191, -5205, -5223, -5238, -5254, -5274, -5286, -5308, -5320, -5341, -5356, -5375, -5391, -5410, -5426, -5446, -5464, -5480, -5500, -5517, -5537, -5555, -5575, -5592, -5612, -5630, -5651, -5669, -5690, -5708, -5730, -5745, -5773, -5784, -5812, -5827, -5851, -5869, -5893, -5909, -5936, -5950, -5980, -5991, -6023, -6036, -6063, -6083, -6104, -6128, -6149, -6172, -6193, -6217, -6239, -6262, -6285, -6308, -6330, -6355, -6377, -6402, -6424, -6449, -6471, -6497, -6521, -6544, -6569, -6593, -6618, -6642, -6669, -6690, -6719, -6740, -6769, -6792, -6820, -6842, -6870, -6896, -6920, -6950, -6971, -7001, -7026, -7053, -7080, -7105, -7134, -7159, -7188, -7214, -7241, -7269, -7297, -7323, -7353, -7378, -7410, -7434, -7464, -7493, -7519, -7552, -7576, -7607, -7636, -7663, -7696, -7720, -7755, -7779, -7812, -7841, -7869, -7902, -8011, -8126, -8236, -8351, -8461, -8577, -8687, -8802, -8915, -9025, -9145, -9250, -9372, -9478, -9598, -9708, -9824, -9937, -10051, -10167, -10278, -10397, -10508, -10625, -10738, -10853, -10970, -11083, -11200, -11314, -11430, -11545, -11662, -11776, -11893, -12010, -12122, -12244, -12354, -12477, -12587, -12709, -12822, -12940, -13058, -13173, -13292, -13407, -13527, -13642, -13760, -13880, -13992, -14117, -14228, -14353, -14464, -14589, -14700, -14826, -14937, -15063, -15176, -15296, -15418, -15532, -15655, -15773, -15890, -16014, -16129, -16252, -16369, -16490, -16610, -16729, -16851, -16969, -17090, -17210, -17332, -17450, -17573, -17691, -17814, -17935, -18054, -18177, -18297, -18418, -18541, -18662, -18781, -18907, -19023, -19151, -19269, -19392, -19515, -19635, -19759, -19882, -20001, -20129, -20246, -20372, -20495, -20616, -20740, -20864, -20984, -21112, -21231, -21357, -21480, -21603, -21727, -21851, -21975, -22098, -22225, -22344, -22474, -22592, -22723, -22843, -22969, -23094, -23217, -23345, -23466, -23595, -23717, -23843, -23969, -24094, -24218, -24347, -24469, -24595, -24725, -24843, -24977, -25098, -25227, -25350, -25480, -25601, -25735, -25854, -25986, -26109, -26238, -26363, -26493, -26616, -26746, -26872, -26998, -27128, -27254, -27380, -27511, -27634, -27766, -27892, -28019, -28148, -28237, -28190, -28146, -28098, -28053, -28007, -27961, -27915, -27866, -27825, -27771, -27733, -27679, -27636, -27590, -27539, -27498, -27445, -27402, -27353, -27308, -27257, -27213, -27163, -27118, -27069, -27022, -26972, -26928, -26876, -26833, -26779, -26737, -26684, -26638, -26591, -26539, -26494, -26443, -26396, -26347, -26299, -26247, -26203, -26150, -26103, -26054, -26004, -25956, -25906, -25856, -25808, -25757, -25709, -25659, -25608, -25561, -25508, -25460, -25410, -25360, -25309, -25261, -25208, -25160, -25109, -25058, -25009, -24957, -24906, -24859, -24804, -24756, -24704, -24652, -24605, -24548, -24504, -24446, -24401, -24344, -24297, -24243, -24194, -24140, -24091, -24037, -23987, -23935, -23882, -23832, -23780, -23724, -23680, -23619, -23573, -23520, -23463, -23419, -23358, -23312, -23256, -23205, -23152, -23099, -23048, -22992, -22943, -22886, -22837, -22783, -22728, -22678, -22620, -22574, -22513, -22468, -22406, -22360, -22300, -22253, -22195, -22143, -22090, -22033, -21983, -21929, -21872, -21822, -21765, -21712, -21659, -21604, -21548, -21498, -21441, -21386, -21335, -21276, -21226, -21168, -21117, -21058, -21008, -20950, -20896, -20843, -20786, -20732, -20677, -20623, -20565, -20515, -20454, -20405, -20344, -20293, -20236, -20181, -20125, -20071, -20015, -19959, -19905, -19846, -19794, -19737, -19682, -19625, -19570, -19514, -19459, -19400, -19350, -19288, -19236, -19177, -19124, -19065, -19012, -18952, -18898, -18842, -18785, -18729, -18672, -18617, -18558, -18504, -18445, -18392, -18332, -18278, -18219, -18163, -18108, -18048, -17994, -17936, -17879, -17823, -17765, -17708, -17652, -17594, -17537, -17482, -17420, -17369, -17306, -17253, -17195, -17134, -17083, -17018, -16969, -16905, -16850, -16794, -16732, -16681, -16617, -16563, -16505, -16446, -16391, -16330, -16274, -16217, -16156, -16103, -16041, -15985, -15928, -15866, -15814, -15750, -15697, -15636, -15579, -15522, -15461, -15406, -15345, -15289, -15230, -15173, -15112, -15057, -14995, -14940, -14881, -14821, -14764, -14705, -14648, -14586, -14534, -14467, -14416, -14354, -14295, -14239, -14177, -14121, -14062, -14002, -13946, -13884, -13828, -13768, -13710, -13650, -13593, -13533, -13475, -13416, -13357, -13297, -13242, -13177, -13125, -13059, -13008, -12941, -12889, -12825, -12768, -12710, -12649, -12592, -12532, -12472, -12415, -12354, -12297, -12236, -12178, -12118, -12061, -11999, -11942, -11882, -11823, -11764, -11705, -11644, -11588, -11526, -11470, -11406, -11351, -11290, -11231, -11172, -11113, -11052, -10996, -10933, -10877, -10815, -10759, -10695, -10641, -10577, -10522, -10459, -10401, -10343, -10281, -10226, -10161, -10106, -10046, -9984, -9929, -9865, -9810, -9748, -9689, -9630, -9571, -9511};
