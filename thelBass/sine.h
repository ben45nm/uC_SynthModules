

// sine.h
int sine_SIZE = 4096;
const int16_t sine_DATA[4096] =
{1, 45, 92, 135, 180, 227, 267, 318, 358, 405, 450, 494, 539, 585, 627, 676, 717, 764, 808, 853, 898, 944, 985, 1035, 1074, 1125, 1164, 1214, 1254, 1303, 1344, 1394, 1432, 1483, 1524, 1570, 1616, 1658, 1705, 1750, 1792, 1840, 1883, 1927, 1974, 2016, 2064, 2106, 2152, 2197, 2240, 2287, 2330, 2377, 2418, 2468, 2506, 2557, 2597, 2645, 2687, 2733, 2777, 2823, 2866, 2912, 2955, 3001, 3045, 3091, 3132, 3183, 3219, 3273, 3309, 3359, 3402, 3445, 3493, 3533, 3582, 3622, 3671, 3712, 3759, 3802, 3846, 3892, 3936, 3979, 4027, 4068, 4114, 4158, 4201, 4248, 4290, 4337, 4377, 4426, 4467, 4513, 4557, 4601, 4645, 4691, 4734, 4777, 4826, 4862, 4916, 4952, 5002, 5043, 5086, 5134, 5174, 5222, 5262, 5311, 5349, 5400, 5438, 5486, 5528, 5574, 5616, 5662, 5705, 5748, 5795, 5834, 5884, 5921, 5971, 6012, 6055, 6102, 6141, 6190, 6232, 6274, 6321, 6362, 6408, 6450, 6496, 6538, 6581, 6627, 6668, 6713, 6757, 6799, 6844, 6888, 6928, 6978, 7014, 7065, 7104, 7147, 7195, 7233, 7282, 7321, 7367, 7408, 7454, 7495, 7539, 7583, 7624, 7670, 7713, 7754, 7801, 7838, 7889, 7927, 7972, 8016, 8057, 8103, 8143, 8188, 8230, 8273, 8317, 8358, 8402, 8446, 8486, 8533, 8572, 8617, 8661, 8699, 8750, 8784, 8835, 8871, 8919, 8957, 9003, 9044, 9086, 9131, 9170, 9216, 9256, 9300, 9342, 9385, 9427, 9470, 9512, 9555, 9597, 9641, 9680, 9727, 9763, 9811, 9848, 9895, 9933, 9978, 10019, 10060, 10106, 10142, 10191, 10228, 10272, 10315, 10355, 10400, 10438, 10484, 10521, 10567, 10606, 10647, 10693, 10728, 10778, 10812, 10858, 10899, 10939, 10983, 11025, 11062, 11112, 11144, 11193, 11230, 11273, 11313, 11357, 11393, 11440, 11477, 11520, 11563, 11599, 11647, 11682, 11727, 11768, 11806, 11853, 11888, 11933, 11972, 12013, 12054, 12095, 12134, 12176, 12218, 12255, 12301, 12336, 12381, 12420, 12460, 12503, 12541, 12583, 12625, 12662, 12706, 12744, 12784, 12825, 12865, 12904, 12948, 12982, 13029, 13063, 13107, 13147, 13185, 13228, 13265, 13308, 13346, 13388, 13426, 13465, 13508, 13542, 13588, 13622, 13666, 13702, 13745, 13781, 13824, 13862, 13900, 13944, 13978, 14023, 14059, 14099, 14140, 14176, 14217, 14256, 14294, 14333, 14374, 14410, 14452, 14488, 14529, 14568, 14606, 14646, 14684, 14723, 14764, 14800, 14841, 14877, 14917, 14955, 14992, 15033, 15068, 15111, 15145, 15186, 15222, 15262, 15301, 15337, 15379, 15413, 15456, 15489, 15533, 15563, 15610, 15638, 15685, 15715, 15757, 15794, 15830, 15870, 15906, 15944, 15984, 16018, 16059, 16093, 16135, 16168, 16211, 16242, 16284, 16317, 16356, 16394, 16428, 16469, 16502, 16542, 16577, 16616, 16650, 16691, 16724, 16764, 16799, 16838, 16872, 16912, 16943, 16985, 17017, 17056, 17092, 17125, 17166, 17199, 17237, 17272, 17309, 17346, 17381, 17419, 17452, 17492, 17526, 17562, 17597, 17635, 17666, 17707, 17737, 17776, 17811, 17846, 17883, 17916, 17954, 17987, 18025, 18060, 18094, 18131, 18166, 18200, 18237, 18269, 18306, 18338, 18376, 18408, 18446, 18477, 18514, 18548, 18584, 18617, 18653, 18687, 18721, 18760, 18788, 18829, 18857, 18895, 18927, 18961, 18997, 19027, 19066, 19095, 19132, 19166, 19198, 19234, 19266, 19302, 19334, 19370, 19402, 19436, 19470, 19502, 19536, 19568, 19603, 19633, 19670, 19700, 19735, 19767, 19801, 19833, 19868, 19898, 19935, 19965, 19999, 20034, 20061, 20100, 20126, 20162, 20193, 20226, 20258, 20290, 20321, 20357, 20384, 20422, 20449, 20485, 20515, 20549, 20580, 20612, 20645, 20674, 20707, 20738, 20769, 20802, 20831, 20864, 20894, 20927, 20958, 20988, 21021, 21052, 21083, 21115, 21145, 21178, 21207, 21240, 21267, 21301, 21327, 21363, 21388, 21423, 21450, 21483, 21512, 21543, 21573, 21604, 21635, 21663, 21698, 21723, 21757, 21785, 21814, 21844, 21874, 21903, 21933, 21962, 21992, 22020, 22053, 22079, 22110, 22140, 22168, 22200, 22228, 22256, 22289, 22313, 22346, 22370, 22403, 22428, 22459, 22487, 22514, 22546, 22570, 22603, 22628, 22660, 22685, 22717, 22743, 22773, 22801, 22827, 22857, 22883, 22912, 22938, 22967, 22993, 23023, 23048, 23078, 23103, 23134, 23159, 23187, 23215, 23242, 23272, 23296, 23325, 23350, 23378, 23404, 23430, 23458, 23483, 23512, 23536, 23564, 23589, 23619, 23642, 23672, 23695, 23724, 23750, 23776, 23803, 23827, 23854, 23879, 23904, 23930, 23956, 23981, 24008, 24031, 24059, 24083, 24110, 24134, 24161, 24186, 24212, 24237, 24262, 24286, 24312, 24336, 24359, 24386, 24408, 24435, 24458, 24483, 24508, 24531, 24558, 24581, 24605, 24631, 24655, 24679, 24705, 24725, 24752, 24772, 24799, 24820, 24845, 24867, 24893, 24912, 24941, 24961, 24984, 25012, 25028, 25061, 25075, 25106, 25124, 25149, 25171, 25193, 25216, 25237, 25262, 25281, 25308, 25325, 25352, 25372, 25394, 25420, 25437, 25464, 25484, 25507, 25530, 25550, 25572, 25594, 25613, 25638, 25656, 25679, 25701, 25719, 25744, 25765, 25783, 25809, 25826, 25850, 25872, 25889, 25917, 25929, 25959, 25968, 26000, 26010, 26037, 26054, 26074, 26097, 26115, 26135, 26157, 26176, 26195, 26218, 26236, 26258, 26278, 26294, 26318, 26333, 26355, 26373, 26391, 26413, 26428, 26451, 26468, 26486, 26510, 26522, 26548, 26562, 26583, 26604, 26619, 26641, 26657, 26675, 26694, 26712, 26728, 26748, 26765, 26783, 26802, 26819, 26836, 26856, 26873, 26890, 26911, 26924, 26949, 26958, 26983, 26992, 27017, 27027, 27047, 27063, 27079, 27099, 27112, 27131, 27146, 27166, 27177, 27202, 27210, 27235, 27246, 27264, 27282, 27293, 27314, 27326, 27343, 27358, 27375, 27388, 27406, 27421, 27436, 27453, 27467, 27484, 27498, 27516, 27528, 27549, 27557, 27579, 27585, 27607, 27616, 27633, 27649, 27659, 27678, 27689, 27705, 27721, 27732, 27749, 27762, 27778, 27791, 27807, 27819, 27832, 27848, 27857, 27875, 27884, 27901, 27910, 27929, 27935, 27956, 27963, 27980, 27991, 28006, 28018, 28033, 28043, 28060, 28067, 28084, 28093, 28105, 28119, 28130, 28140, 28158, 28162, 28181, 28189, 28202, 28216, 28225, 28240, 28248, 28265, 28273, 28285, 28297, 28305, 28319, 28328, 28339, 28351, 28359, 28376, 28377, 28400, 28399, 28418, 28426, 28436, 28448, 28460, 28467, 28481, 28487, 28499, 28508, 28516, 28530, 28532, 28552, 28551, 28569, 28574, 28583, 28599, 28599, 28618, 28621, 28633, 28644, 28650, 28659, 28670, 28674, 28687, 28691, 28702, 28711, 28717, 28728, 28735, 28742, 28754, 28758, 28772, 28775, 28786, 28794, 28800, 28812, 28812, 28826, 28828, 28839, 28843, 28852, 28859, 28866, 28874, 28878, 28891, 28889, 28909, 28903, 28920, 28922, 28928, 28938, 28941, 28948, 28953, 28960, 28964, 28973, 28975, 28986, 28986, 28999, 28997, 29009, 29012, 29019, 29025, 29031, 29035, 29042, 29044, 29051, 29055, 29059, 29066, 29065, 29079, 29072, 29089, 29084, 29093, 29099, 29098, 29110, 29109, 29117, 29119, 29125, 29125, 29133, 29133, 29137, 29142, 29143, 29149, 29150, 29156, 29157, 29162, 29165, 29168, 29172, 29175, 29180, 29180, 29187, 29184, 29191, 29189, 29195, 29194, 29198, 29201, 29200, 29205, 29206, 29209, 29211, 29213, 29214, 29218, 29219, 29223, 29221, 29225, 29224, 29227, 29225, 29230, 29226, 29231, 29230, 29231, 29233, 29234, 29232, 29238, 29232, 29242, 29233, 29243, 29236, 29241, 29237, 29239, 29238, 29236, 29240, 29234, 29239, 29235, 29237, 29235, 29236, 29235, 29234, 29237, 29230, 29239, 29227, 29238, 29224, 29233, 29224, 29227, 29223, 29222, 29220, 29221, 29216, 29216, 29216, 29209, 29215, 29207, 29209, 29207, 29204, 29202, 29199, 29196, 29194, 29191, 29186, 29187, 29181, 29180, 29176, 29175, 29169, 29170, 29164, 29163, 29160, 29156, 29156, 29147, 29149, 29140, 29139, 29133, 29130, 29125, 29123, 29117, 29113, 29110, 29105, 29101, 29098, 29093, 29089, 29085, 29081, 29075, 29072, 29064, 29062, 29052, 29052, 29041, 29042, 29031, 29030, 29022, 29018, 29011, 29009, 28999, 28999, 28989, 28987, 28978, 28976, 28963, 28963, 28951, 28949, 28940, 28933, 28928, 28920, 28915, 28908, 28900, 28896, 28886, 28884, 28872, 28871, 28859, 28856, 28843, 28842, 28825, 28827, 28811, 28810, 28798, 28791, 28784, 28776, 28766, 28764, 28748, 28749, 28733, 28731, 28719, 28715, 28701, 28694, 28686, 28673, 28671, 28655, 28651, 28638, 28632, 28621, 28614, 28603, 28595, 28586, 28576, 28568, 28559, 28549, 28537, 28531, 28513, 28513, 28493, 28490, 28475, 28469, 28453, 28450, 28433, 28427, 28416, 28404, 28396, 28383, 28377, 28361, 28355, 28337, 28331, 28317, 28306, 28295, 28283, 28271, 28262, 28247, 28239, 28224, 28217, 28200, 28194, 28178, 28171, 28154, 28147, 28127, 28123, 28101, 28098, 28077, 28070, 28055, 28040, 28034, 28013, 28009, 27988, 27982, 27965, 27954, 27942, 27928, 27915, 27899, 27889, 27869, 27863, 27843, 27832, 27817, 27803, 27790, 27776, 27762, 27747, 27735, 27719, 27709, 27689, 27683, 27659, 27652, 27632, 27618, 27605, 27587, 27573, 27560, 27541, 27530, 27513, 27496, 27486, 27465, 27456, 27436, 27424, 27407, 27392, 27376, 27359, 27343, 27327, 27311, 27294, 27278, 27262, 27246, 27230, 27213, 27196, 27182, 27164, 27148, 27134, 27113, 27102, 27080, 27064, 27048, 27027, 27016, 26991, 26980, 26959, 26942, 26926, 26908, 26889, 26876, 26853, 26839, 26822, 26802, 26786, 26768, 26748, 26729, 26713, 26691, 26677, 26655, 26636, 26620, 26600, 26583, 26562, 26545, 26527, 26506, 26491, 26470, 26451, 26434, 26410, 26395, 26371, 26355, 26333, 26315, 26294, 26274, 26256, 26235, 26217, 26194, 26179, 26154, 26141, 26114, 26099, 26077, 26057, 26034, 26016, 25992, 25975, 25952, 25931, 25911, 25890, 25869, 25849, 25827, 25808, 25785, 25766, 25743, 25725, 25702, 25680, 25658, 25636, 25615, 25592, 25572, 25547, 25529, 25503, 25486, 25458, 25443, 25415, 25397, 25374, 25350, 25333, 25305, 25287, 25258, 25242, 25213, 25195, 25168, 25147, 25124, 25100, 25079, 25054, 25032, 25009, 24986, 24962, 24941, 24917, 24893, 24870, 24845, 24822, 24797, 24775, 24746, 24730, 24697, 24680, 24652, 24630, 24604, 24583, 24555, 24534, 24509, 24485, 24460, 24437, 24409, 24387, 24359, 24336, 24310, 24285, 24261, 24234, 24210, 24186, 24158, 24137, 24107, 24087, 24057, 24036, 24010, 23980, 23961, 23927, 23907, 23879, 23850, 23830, 23798, 23775, 23748, 23721, 23698, 23668, 23645, 23616, 23593, 23564, 23541, 23511, 23486, 23457, 23432, 23404, 23376, 23351, 23320, 23299, 23264, 23246, 23209, 23191, 23158, 23132, 23108, 23075, 23054, 23022, 22997, 22966, 22940, 22910, 22884, 22856, 22824, 22803, 22766, 22746, 22712, 22688, 22657, 22632, 22599, 22577, 22543, 22520, 22487, 22459, 22430, 22401, 22372, 22343, 22314, 22284, 22257, 22225, 22198, 22169, 22138, 22113, 22078, 22055, 22022, 21993, 21966, 21931, 21907, 21872, 21844, 21814, 21784, 21753, 21725, 21692, 21665, 21634, 21603, 21573, 21546, 21509, 21490, 21448, 21426, 21390, 21362, 21329, 21300, 21267, 21237, 21206, 21177, 21142, 21116, 21080, 21052, 21021, 20989, 20960, 20927, 20897, 20865, 20833, 20802, 20770, 20738, 20706, 20673, 20644, 20609, 20581, 20546, 20513, 20487, 20447, 20424, 20384, 20359, 20321, 20295, 20257, 20227, 20195, 20158, 20131, 20095, 20063, 20031, 19996, 19966, 19932, 19899, 19868, 19832, 19803, 19769, 19735, 19703, 19670, 19635, 19603, 19569, 19534, 19504, 19466, 19436, 19399, 19371, 19330, 19304, 19264, 19236, 19197, 19169, 19130, 19101, 19065, 19029, 18997, 18961, 18927, 18895, 18855, 18828, 18786, 18759, 18719, 18687, 18653, 18617, 18584, 18550, 18514, 18482, 18444, 18411, 18375, 18340, 18306, 18267, 18239, 18194, 18169, 18125, 18099, 18053, 18029, 17984, 17957, 17916, 17885, 17845, 17816, 17772, 17745, 17700, 17672, 17630, 17598, 17561, 17524, 17490, 17451, 17419, 17380, 17347, 17308, 17274, 17236, 17204, 17163, 17132, 17088, 17059, 17015, 16985, 16944, 16910, 16871, 16836, 16798, 16763, 16725, 16689, 16652, 16616, 16578, 16544, 16503, 16469, 16430, 16395, 16354, 16321, 16278, 16246, 16206, 16168, 16134, 16093, 16057, 16020, 15982, 15944, 15911, 15866, 15836, 15792, 15759, 15717, 15682, 15642, 15604, 15567, 15528, 15491, 15452, 15415, 15375, 15340, 15299, 15263, 15223, 15188, 15146, 15112, 15069, 15032, 14995, 14953, 14917, 14877, 14838, 14802, 14759, 14724, 14683, 14645, 14607, 14569, 14527, 14493, 14449, 14414, 14375, 14332, 14296, 14254, 14218, 14175, 14140, 14096, 14059, 14021, 13979, 13942, 13901, 13863, 13822, 13786, 13742, 13706, 13665, 13625, 13585, 13547, 13501, 13471, 13421, 13389, 13345, 13305, 13267, 13225, 13187, 13146, 13107, 13066, 13027, 12986, 12947, 12905, 12866, 12823, 12788, 12740, 12707, 12660, 12625, 12581, 12542, 12501, 12461, 12420, 12380, 12339, 12300, 12258, 12217, 12177, 12134, 12097, 12052, 12014, 11970, 11932, 11888, 11852, 11804, 11771, 11721, 11689, 11641, 11604, 11563, 11519, 11481, 11436, 11399, 11354, 11314, 11272, 11230, 11190, 11148, 11105, 11066, 11023, 10982, 10940, 10899, 10857, 10817, 10774, 10733, 10691, 10648, 10608, 10564, 10524, 10482, 10436, 10402, 10351, 10316, 10271, 10228, 10191, 10142, 10107, 10059, 10022, 9977, 9936, 9892, 9852, 9807, 9767, 9724, 9680, 9640, 9597, 9552, 9515, 9467, 9429, 9384, 9342, 9301, 9257, 9216, 9173, 9128, 9089, 9042, 9004, 8957, 8918, 8871, 8832, 8787, 8745, 8704, 8657, 8619, 8572, 8533, 8487, 8448, 8400, 8361, 8317, 8271, 8233, 8185, 8144, 8103, 8054, 8018, 7969, 7929, 7886, 7840, 7802, 7753, 7714, 7670, 7625, 7585, 7537, 7498, 7450, 7412, 7363, 7324, 7278, 7234, 7195, 7145, 7108, 7059, 7019, 6974, 6933, 6886, 6845, 6800, 6755, 6716, 6667, 6626, 6582, 6536, 6497, 6448, 6409, 6361, 6320, 6275, 6232, 6188, 6145, 6099, 6058, 6012, 5969, 5925, 5879, 5839, 5791, 5751, 5702, 5663, 5615, 5574, 5528, 5485, 5441, 5396, 5354, 5307, 5267, 5218, 5179, 5129, 5090, 5042, 5000, 4956, 4909, 4868, 4821, 4780, 4732, 4692, 4643, 4603, 4556, 4514, 4468, 4424, 4381, 4333, 4294, 4243, 4206, 4154, 4117, 4066, 4026, 3979, 3937, 3889, 3849, 3801, 3759, 3714, 3667, 3627, 3577, 3539, 3488, 3449, 3399, 3360, 3309, 3272, 3220, 3182, 3132, 3091, 3044, 3003, 2953, 2915, 2863, 2825, 2776, 2734, 2688, 2643, 2598, 2556, 2508, 2466, 2419, 2375, 2332, 2284, 2244, 2193, 2155, 2105, 2064, 2017, 1973, 1928, 1883, 1841, 1790, 1754, 1699, 1664, 1612, 1571, 1526, 1478, 1437, 1391, 1345, 1303, 1254, 1213, 1167, 1121, 1079, 1030, 990, 941, 899, 852, 809, 763, 719, 672, 631, 582, 540, 494, 450, 404, 360, 315, 269, 228, 178, 136, 91, 45, 3, -46, -87, -136, -176, -224, -268, -313, -358, -403, -446, -494, -536, -583, -626, -672, -717, -760, -808, -849, -897, -941, -985, -1030, -1076, -1118, -1168, -1207, -1256, -1298, -1344, -1390, -1432, -1480, -1521, -1570, -1611, -1659, -1701, -1748, -1792, -1836, -1882, -1926, -1970, -2018, -2058, -2107, -2148, -2197, -2236, -2288, -2324, -2376, -2418, -2461, -2511, -2547, -2601, -2638, -2689, -2730, -2775, -2821, -2865, -2908, -2957, -2995, -3046, -3087, -3132, -3177, -3222, -3265, -3311, -3356, -3398, -3446, -3489, -3531, -3581, -3620, -3669, -3711, -3756, -3800, -3846, -3888, -3934, -3979, -4021, -4069, -4108, -4159, -4198, -4246, -4289, -4331, -4381, -4419, -4471, -4506, -4559, -4596, -4646, -4687, -4732, -4775, -4823, -4861, -4913, -4949, -5001, -5039, -5087, -5130, -5173, -5221, -5259, -5310, -5349, -5395, -5440, -5480, -5530, -5568, -5617, -5657, -5704, -5745, -5793, -5833, -5880, -5921, -5969, -6007, -6060, -6093, -6147, -6182, -6233, -6271, -6320, -6358, -6408, -6445, -6495, -6534, -6581, -6623, -6667, -6711, -6755, -6797, -6844, -6884, -6930, -6973, -7015, -7061, -7101, -7149, -7186, -7237, -7275, -7319, -7366, -7405, -7451, -7495, -7536, -7581, -7625, -7666, -7714, -7750, -7800, -7838, -7885, -7925, -7970, -8012, -8056, -8099, -8142, -8184, -8229, -8271, -8314, -8358, -8400, -8444, -8486, -8531, -8569, -8618, -8655, -8702, -8742, -8786, -8829, -8870, -8916, -8954, -9002, -9041, -9085, -9128, -9171, -9212, -9257, -9297, -9341, -9384, -9423, -9469, -9509, -9553, -9594, -9637, -9679, -9723, -9762, -9809, -9846, -9893, -9932, -9977, -10018, -10059, -10103, -10142, -10188, -10226, -10270, -10312, -10352, -10398, -10434, -10483, -10517, -10567, -10602, -10649, -10688, -10730, -10774, -10813, -10856, -10897, -10937, -10982, -11020, -11063, -11105, -11144, -11189, -11228, -11270, -11312, -11353, -11394, -11437, -11477, -11519, -11560, -11601, -11642, -11683, -11723, -11766, -11804, -11849, -11887, -11927, -11972, -12009, -12052, -12094, -12132, -12175, -12216, -12255, -12299, -12336, -12378, -12419, -12458, -12500, -12539, -12580, -12622, -12659, -12704, -12738, -12787, -12819, -12866, -12902, -12945, -12984, -13026, -13062, -13108, -13141, -13188, -13220, -13268, -13300, -13348, -13380, -13427, -13461, -13504, -13544, -13582, -13625, -13661, -13704, -13742, -13782, -13821, -13861, -13898, -13941, -13976, -14020, -14056, -14096, -14135, -14176, -14213, -14254, -14293, -14330, -14374, -14409, -14450, -14489, -14526, -14566, -14606, -14641, -14685, -14717, -14761, -14799, -14834, -14879, -14910, -14956, -14989, -15032, -15067, -15109, -15144, -15187, -15219, -15263, -15296, -15338, -15373, -15414, -15448, -15491, -15524, -15568, -15599, -15643, -15677, -15718, -15754, -15794, -15828, -15871, -15904, -15944, -15980, -16017, -16056, -16091, -16131, -16167, -16204, -16242, -16280, -16314, -16358, -16387, -16431, -16465, -16504, -16540, -16578, -16610, -16654, -16685, -16724, -16761, -16795, -16834, -16872, -16904, -16946, -16977, -17019, -17053, -17090, -17126, -17164, -17198, -17239, -17267, -17313, -17337, -17385, -17410, -17456, -17482, -17527, -17556, -17596, -17630, -17666, -17703, -17738, -17775, -17809, -17847, -17879, -17920, -17947, -17991, -18017, -18060, -18092, -18125, -18165, -18194, -18236, -18265, -18305, -18336, -18375, -18407, -18444, -18479, -18511, -18551, -18577, -18620, -18648, -18686, -18719, -18752, -18790, -18819, -18861, -18887, -18927, -18960, -18992, -19031, -19060, -19099, -19129, -19167, -19195, -19234, -19262, -19301, -19330, -19368, -19397, -19434, -19465, -19501, -19532, -19567, -19601, -19633, -19669, -19698, -19737, -19763, -19804, -19828, -19867, -19897, -19929, -19965, -19994, -20028, -20063, -20091, -20129, -20157, -20193, -20223, -20259, -20288, -20324, -20353, -20386, -20418, -20449, -20482, -20512, -20547, -20575, -20610, -20638, -20675, -20701, -20740, -20764, -20801, -20831, -20863, -20896, -20924, -20958, -20987, -21018, -21052, -21077, -21114, -21141, -21173, -21206, -21232, -21269, -21294, -21331, -21356, -21392, -21419, -21452, -21482, -21511, -21543, -21570, -21603, -21631, -21662, -21692, -21721, -21752, -21781, -21813, -21841, -21873, -21900, -21933, -21960, -21994, -22020, -22051, -22079, -22108, -22137, -22167, -22195, -22226, -22252, -22284, -22311, -22340, -22373, -22394, -22434, -22452, -22490, -22513, -22544, -22573, -22599, -22628, -22658, -22682, -22714, -22741, -22765, -22802, -22821, -22854, -22882, -22907, -22939, -22965, -22993, -23022, -23049, -23076, -23105, -23129, -23160, -23182, -23215, -23237, -23267, -23293, -23321, -23346, -23378, -23398, -23432, -23453, -23485, -23510, -23538, -23562, -23591, -23613, -23645, -23665, -23696, -23718, -23748, -23771, -23800, -23822, -23852, -23876, -23903, -23930, -23953, -23983, -24006, -24032, -24059, -24081, -24109, -24132, -24157, -24185, -24205, -24236, -24255, -24286, -24305, -24337, -24356, -24384, -24409, -24431, -24462, -24482, -24507, -24531, -24554, -24581, -24602, -24628, -24650, -24677, -24697, -24726, -24745, -24773, -24795, -24820, -24841, -24871, -24889, -24916, -24938, -24960, -24985, -25007, -25029, -25053, -25075, -25100, -25122, -25143, -25171, -25185, -25220, -25231, -25264, -25279, -25307, -25328, -25350, -25372, -25393, -25416, -25437, -25460, -25482, -25501, -25527, -25545, -25570, -25591, -25610, -25638, -25652, -25683, -25696, -25724, -25741, -25764, -25785, -25803, -25828, -25844, -25868, -25888, -25909, -25929, -25952, -25969, -25993, -26012, -26034, -26055, -26074, -26096, -26116, -26134, -26157, -26173, -26194, -26214, -26234, -26253, -26273, -26293, -26309, -26336, -26349, -26372, -26391, -26409, -26432, -26448, -26471, -26484, -26509, -26521, -26546, -26558, -26582, -26597, -26617, -26637, -26652, -26673, -26691, -26709, -26729, -26745, -26767, -26781, -26805, -26815, -26840, -26850, -26874, -26887, -26906, -26924, -26940, -26958, -26975, -26994, -27008, -27030, -27042, -27065, -27078, -27098, -27112, -27133, -27144, -27165, -27177, -27196, -27211, -27227, -27245, -27259, -27277, -27291, -27310, -27324, -27342, -27356, -27374, -27390, -27405, -27423, -27433, -27453, -27465, -27481, -27497, -27511, -27526, -27541, -27556, -27573, -27584, -27604, -27614, -27633, -27646, -27661, -27678, -27689, -27707, -27716, -27733, -27746, -27760, -27774, -27788, -27800, -27818, -27826, -27846, -27855, -27872, -27883, -27900, -27911, -27928, -27938, -27953, -27963, -27979, -27988, -28004, -28014, -28031, -28036, -28057, -28064, -28079, -28092, -28103, -28116, -28131, -28140, -28157, -28164, -28180, -28189, -28200, -28215, -28220, -28239, -28245, -28258, -28271, -28280, -28293, -28305, -28313, -28330, -28337, -28350, -28362, -28371, -28384, -28393, -28402, -28415, -28422, -28435, -28445, -28451, -28469, -28471, -28488, -28494, -28506, -28515, -28528, -28534, -28549, -28555, -28566, -28575, -28585, -28591, -28604, -28608, -28622, -28628, -28639, -28645, -28658, -28662, -28678, -28679, -28695, -28699, -28710, -28720, -28727, -28734, -28744, -28747, -28763, -28760, -28780, -28776, -28793, -28796, -28804, -28815, -28817, -28833, -28831, -28848, -28849, -28860, -28867, -28873, -28879, -28886, -28892, -28899, -28908, -28909, -28922, -28921, -28936, -28936, -28946, -28951, -28958, -28964, -28972, -28978, -28983, -28990, -28993, -29000, -29005, -29011, -29014, -29023, -29024, -29033, -29036, -29043, -29046, -29055, -29055, -29066, -29067, -29075, -29079, -29083, -29087, -29090, -29097, -29098, -29105, -29106, -29112, -29115, -29120, -29123, -29128, -29133, -29134, -29142, -29141, -29150, -29152, -29155, -29158, -29159, -29165, -29164, -29172, -29170, -29174, -29179, -29177, -29188, -29181, -29193, -29187, -29198, -29194, -29203, -29200, -29206, -29206, -29206, -29212, -29208, -29214, -29213, -29216, -29217, -29217, -29223, -29219, -29225, -29224, -29226, -29229, -29228, -29233, -29229, -29236, -29229, -29235, -29232, -29234, -29233, -29235, -29233, -29237, -29232, -29237, -29235, -29236, -29237, -29236, -29236, -29238, -29236, -29237, -29235, -29234, -29232, -29234, -29229, -29233, -29227, -29231, -29224, -29231, -29222, -29226, -29225, -29220, -29225, -29219, -29220, -29218, -29215, -29213, -29211, -29209, -29205, -29208, -29198, -29204, -29193, -29200, -29190, -29194, -29187, -29188, -29183, -29185, -29177, -29180, -29170, -29173, -29164, -29165, -29158, -29157, -29153, -29148, -29148, -29139, -29143, -29132, -29134, -29129, -29123, -29124, -29117, -29114, -29110, -29103, -29101, -29094, -29091, -29085, -29081, -29077, -29071, -29067, -29062, -29057, -29054, -29047, -29044, -29039, -29033, -29030, -29021, -29018, -29011, -29004, -28999, -28994, -28985, -28985, -28971, -28972, -28962, -28959, -28950, -28946, -28939, -28935, -28927, -28922, -28913, -28907, -28901, -28892, -28885, -28880, -28868, -28867, -28855, -28851, -28841, -28836, -28828, -28821, -28815, -28804, -28802, -28790, -28785, -28775, -28765, -28761, -28748, -28742, -28734, -28723, -28718, -28706, -28701, -28690, -28685, -28671, -28668, -28656, -28651, -28640, -28631, -28621, -28611, -28604, -28591, -28584, -28573, -28563, -28555, -28543, -28535, -28526, -28515, -28506, -28496, -28487, -28476, -28469, -28454, -28449, -28432, -28427, -28411, -28403, -28392, -28380, -28370, -28360, -28346, -28340, -28325, -28316, -28305, -28294, -28282, -28274, -28259, -28250, -28235, -28226, -28211, -28201, -28187, -28178, -28162, -28155, -28136, -28132, -28112, -28107, -28090, -28080, -28068, -28055, -28044, -28028, -28019, -28001, -27991, -27978, -27960, -27954, -27934, -27926, -27909, -27897, -27885, -27869, -27859, -27843, -27831, -27818, -27804, -27789, -27777, -27758, -27749, -27730, -27718, -27704, -27686, -27677, -27657, -27647, -27629, -27617, -27601, -27589, -27571, -27559, -27544, -27528, -27513, -27496, -27482, -27466, -27450, -27435, -27417, -27405, -27387, -27372, -27357, -27339, -27326, -27309, -27295, -27277, -27263, -27245, -27231, -27211, -27196, -27178, -27163, -27145, -27128, -27112, -27093, -27081, -27057, -27049, -27024, -27012, -26994, -26976, -26962, -26942, -26925, -26907, -26889, -26871, -26853, -26834, -26820, -26796, -26784, -26762, -26745, -26728, -26709, -26692, -26673, -26657, -26635, -26622, -26598, -26582, -26561, -26545, -26521, -26507, -26484, -26466, -26450, -26425, -26412, -26388, -26372, -26351, -26334, -26312, -26296, -26275, -26254, -26237, -26212, -26196, -26175, -26151, -26138, -26109, -26097, -26071, -26053, -26033, -26012, -25993, -25971, -25952, -25931, -25912, -25889, -25870, -25846, -25827, -25804, -25783, -25762, -25742, -25717, -25701, -25674, -25657, -25633, -25613, -25592, -25569, -25550, -25526, -25507, -25481, -25461, -25438, -25414, -25396, -25368, -25350, -25325, -25303, -25281, -25259, -25235, -25216, -25189, -25170, -25145, -25125, -25101, -25077, -25053, -25033, -25003, -24988, -24956, -24938, -24914, -24886, -24870, -24838, -24823, -24793, -24773, -24747, -24726, -24700, -24680, -24650, -24630, -24604, -24578, -24557, -24527, -24507, -24482, -24456, -24431, -24409, -24380, -24362, -24330, -24312, -24283, -24261, -24235, -24210, -24183, -24159, -24133, -24107, -24084, -24052, -24034, -24002, -23981, -23953, -23928, -23904, -23875, -23853, -23823, -23803, -23774, -23747, -23722, -23694, -23669, -23641, -23615, -23589, -23560, -23537, -23507, -23482, -23457, -23425, -23406, -23373, -23349, -23323, -23294, -23270, -23239, -23213, -23185, -23159, -23130, -23101, -23076, -23046, -23021, -22991, -22965, -22936, -22911, -22879, -22856, -22825, -22799, -22772, -22740, -22715, -22684, -22656, -22629, -22598, -22571, -22541, -22514, -22485, -22456, -22427, -22399, -22370, -22343, -22312, -22285, -22256, -22225, -22198, -22167, -22136, -22110, -22076, -22051, -22019, -21989, -21961, -21930, -21902, -21870, -21844, -21811, -21784, -21753, -21723, -21695, -21662, -21632, -21602, -21571, -21542, -21510, -21481, -21448, -21419, -21390, -21356, -21330, -21297, -21264, -21241, -21200, -21179, -21143, -21112, -21083, -21048, -21019, -20987, -20956, -20923, -20895, -20859, -20833, -20796, -20770, -20733, -20707, -20672, -20642, -20611, -20577, -20548, -20513, -20482, -20449, -20417, -20385, -20353, -20320, -20288, -20256, -20224, -20190, -20160, -20126, -20096, -20061, -20031, -19996, -19965, -19931, -19898, -19865, -19831, -19799, -19765, -19734, -19696, -19670, -19629, -19603, -19565, -19534, -19501, -19467, -19434, -19402, -19365, -19335, -19297, -19267, -19230, -19197, -19164, -19128, -19097, -19059, -19030, -18990, -18964, -18921, -18895, -18855, -18825, -18790, -18753, -18723, -18682, -18654, -18613, -18583, -18545, -18512, -18478, -18440, -18409, -18372, -18337, -18304, -18268, -18233, -18200, -18162, -18131, -18091, -18059, -18021, -17986, -17952, -17915, -17880, -17844, -17809, -17773, -17737, -17705, -17663, -17634, -17594, -17560, -17525, -17489, -17451, -17417, -17378, -17344, -17307, -17271, -17235, -17196, -17164, -17124, -17091, -17051, -17019, -16978, -16946, -16907, -16871, -16836, -16797, -16761, -16724, -16687, -16649, -16615, -16572, -16543, -16499, -16466, -16428, -16390, -16354, -16318, -16278, -16245, -16204, -16170, -16130, -16093, -16057, -16015, -15984, -15939, -15907, -15865, -15831, -15790, -15756, -15714, -15680, -15640, -15603, -15566, -15527, -15490, -15452, -15412, -15376, -15336, -15298, -15260, -15221, -15183, -15145, -15106, -15068, -15029, -14992, -14953, -14913, -14878, -14836, -14801, -14760, -14720, -14685, -14640, -14609, -14561, -14530, -14485, -14449, -14411, -14367, -14336, -14288, -14258, -14210, -14179, -14134, -14099, -14058, -14018, -13979, -13939, -13901, -13859, -13821, -13781, -13739, -13706, -13657, -13628, -13577, -13549, -13498, -13469, -13421, -13388, -13342, -13306, -13265, -13224, -13186, -13142, -13105, -13063, -13025, -12981, -12946, -12901, -12864, -12823, -12780, -12746, -12699, -12665, -12619, -12583, -12538, -12503, -12456, -12419, -12378, -12336, -12297, -12254, -12215, -12174, -12133, -12093, -12051, -12011, -11971, -11929, -11889, -11848, -11805, -11767, -11723, -11683, -11642, -11598, -11562, -11515, -11479, -11434, -11394, -11354, -11311, -11271, -11229, -11188, -11147, -11105, -11064, -11021, -10981, -10938, -10897, -10853, -10816, -10769, -10732, -10687, -10647, -10605, -10562, -10522, -10480, -10437, -10398, -10352, -10314, -10269, -10228, -10186, -10143, -10103, -10056, -10021, -9971, -9937, -9887, -9851, -9805, -9764, -9723, -9679, -9639, -9594, -9554, -9509, -9469, -9425, -9382, -9342, -9295, -9257, -9211, -9171, -9127, -9085, -9042, -8999, -8958, -8914, -8873, -8827, -8789, -8741, -8703, -8656, -8614, -8573, -8528, -8487, -8442, -8400, -8356, -8316, -8269, -8231, -8183, -8142, -8101, -8055, -8015, -7968, -7927, -7884, -7839, -7798, -7753, -7709, -7669, -7622, -7581, -7538, -7492, -7452, -7406, -7365, -7320, -7278, -7233, -7191, -7146, -7103, -7060, -7015, -6974, -6927, -6886, -6842, -6797, -6755, -6710, -6669, -6621, -6583, -6533, -6495, -6448, -6406, -6359, -6321, -6269, -6234, -6182, -6145, -6096, -6055, -6010, -5966, -5924, -5877, -5836, -5790, -5748, -5702, -5661, -5613, -5573, -5525, -5485, -5436, -5397, -5349, -5306, -5264, -5216, -5175, -5129, -5087, -5039, -5002, -4948, -4914, -4862, -4822, -4776, -4733, -4688, -4642, -4600, -4554, -4512, -4466, -4421, -4377, -4334, -4289, -4244, -4201, -4155, -4112, -4068, -4022, -3979, -3932, -3891, -3845, -3799, -3758, -3708, -3669, -3623, -3575, -3537, -3486, -3446, -3399, -3356, -3310, -3268, -3220, -3178, -3132, -3089, -3041, -3001, -2952, -2911, -2863, -2822, -2772, -2736, -2681, -2644, -2597, -2550, -2511, -2459, -2421, -2371, -2331, -2283, -2238, -2197, -2147, -2108, -2057, -2019, -1968, -1928, -1880, -1838, -1790, -1750, -1699, -1660, -1612, -1568, -1524, -1476, -1437, -1386, -1346, -1298, -1254, -1211, -1164, -1120, -1075, -1030, -987, -939, -897, -850, -807, -761, -717, -670, -629, -580, -539, -491, -447, -404, -356, -315, -267, -223, -179, -133, -89, -44};
