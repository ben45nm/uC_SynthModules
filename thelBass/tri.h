

// tri.h
int tri_SIZE = 4096;
const int16_t tri_DATA[4096] =
{-29237, -29209, -29179, -29153, -29122, -29094, -29067, -29035, -29012, -28977, -28954, -28921, -28896, -28865, -28838, -28809, -28779, -28755, -28719, -28698, -28664, -28638, -28610, -28579, -28553, -28522, -28497, -28464, -28439, -28409, -28380, -28353, -28322, -28297, -28263, -28243, -28203, -28186, -28148, -28127, -28092, -28069, -28036, -28010, -27982, -27950, -27926, -27893, -27869, -27835, -27813, -27778, -27755, -27722, -27696, -27666, -27640, -27607, -27584, -27550, -27526, -27494, -27468, -27437, -27411, -27381, -27353, -27323, -27296, -27267, -27239, -27210, -27180, -27154, -27123, -27097, -27067, -27037, -27013, -26978, -26956, -26923, -26895, -26869, -26837, -26812, -26780, -26755, -26722, -26698, -26666, -26640, -26610, -26582, -26553, -26524, -26497, -26467, -26439, -26411, -26381, -26353, -26326, -26294, -26271, -26236, -26212, -26182, -26153, -26125, -26097, -26067, -26040, -26010, -25983, -25951, -25929, -25892, -25872, -25836, -25813, -25780, -25756, -25724, -25697, -25668, -25639, -25612, -25581, -25556, -25523, -25498, -25468, -25439, -25413, -25380, -25355, -25326, -25296, -25270, -25237, -25214, -25181, -25156, -25123, -25099, -25067, -25042, -25009, -24985, -24953, -24926, -24897, -24868, -24841, -24812, -24781, -24756, -24724, -24699, -24668, -24640, -24612, -24583, -24554, -24527, -24496, -24469, -24442, -24410, -24384, -24354, -24326, -24298, -24269, -24240, -24212, -24184, -24154, -24126, -24098, -24070, -24038, -24016, -23979, -23959, -23923, -23899, -23869, -23841, -23812, -23784, -23754, -23727, -23698, -23669, -23642, -23610, -23587, -23551, -23531, -23495, -23471, -23440, -23413, -23383, -23357, -23325, -23299, -23270, -23239, -23215, -23183, -23155, -23127, -23099, -23068, -23044, -23010, -22986, -22954, -22928, -22898, -22869, -22844, -22809, -22788, -22753, -22728, -22699, -22669, -22642, -22614, -22582, -22559, -22523, -22503, -22466, -22446, -22409, -22388, -22352, -22331, -22296, -22272, -22242, -22211, -22188, -22152, -22130, -22099, -22069, -22043, -22012, -21986, -21956, -21927, -21900, -21869, -21844, -21811, -21787, -21755, -21729, -21698, -21671, -21642, -21614, -21584, -21558, -21526, -21501, -21470, -21443, -21412, -21388, -21353, -21331, -21298, -21270, -21246, -21208, -21192, -21150, -21134, -21096, -21072, -21043, -21014, -20985, -20957, -20929, -20897, -20876, -20838, -20817, -20784, -20757, -20730, -20698, -20673, -20641, -20615, -20585, -20559, -20527, -20501, -20470, -20443, -20416, -20384, -20359, -20327, -20300, -20273, -20241, -20216, -20186, -20156, -20130, -20099, -20072, -20044, -20014, -19986, -19958, -19928, -19901, -19872, -19842, -19817, -19783, -19761, -19727, -19701, -19671, -19645, -19612, -19590, -19554, -19533, -19497, -19475, -19441, -19416, -19387, -19357, -19330, -19300, -19273, -19243, -19215, -19187, -19158, -19128, -19104, -19068, -19048, -19012, -18988, -18959, -18927, -18905, -18868, -18848, -18812, -18789, -18758, -18728, -18703, -18672, -18644, -18616, -18586, -18558, -18532, -18499, -18475, -18442, -18417, -18387, -18357, -18333, -18297, -18278, -18240, -18218, -18186, -18159, -18131, -18100, -18074, -18044, -18016, -17987, -17959, -17931, -17901, -17872, -17847, -17813, -17791, -17757, -17729, -17705, -17669, -17650, -17612, -17589, -17559, -17530, -17503, -17473, -17444, -17418, -17385, -17362, -17328, -17305, -17272, -17244, -17218, -17187, -17160, -17130, -17103, -17072, -17047, -17015, -16989, -16959, -16931, -16902, -16874, -16845, -16818, -16785, -16763, -16729, -16702, -16676, -16642, -16620, -16586, -16561, -16530, -16503, -16474, -16446, -16416, -16389, -16359, -16332, -16303, -16273, -16247, -16216, -16189, -16160, -16131, -16104, -16072, -16050, -16011, -15994, -15956, -15934, -15902, -15875, -15845, -15817, -15791, -15757, -15735, -15701, -15675, -15647, -15617, -15588, -15562, -15530, -15504, -15475, -15445, -15419, -15388, -15360, -15333, -15302, -15276, -15246, -15218, -15188, -15162, -15130, -15106, -15074, -15046, -15018, -14989, -14961, -14932, -14904, -14875, -14846, -14818, -14789, -14762, -14731, -14705, -14673, -14649, -14616, -14591, -14561, -14530, -14507, -14473, -14448, -14419, -14387, -14364, -14330, -14306, -14274, -14248, -14218, -14190, -14160, -14134, -14104, -14074, -14050, -14015, -13993, -13959, -13934, -13904, -13876, -13846, -13821, -13786, -13767, -13728, -13707, -13675, -13648, -13617, -13593, -13558, -13537, -13501, -13479, -13444, -13423, -13386, -13366, -13330, -13306, -13276, -13247, -13221, -13188, -13164, -13131, -13107, -13075, -13049, -13018, -12991, -12962, -12933, -12905, -12876, -12849, -12818, -12791, -12762, -12733, -12706, -12676, -12648, -12620, -12590, -12563, -12533, -12506, -12476, -12448, -12419, -12393, -12359, -12338, -12302, -12278, -12248, -12220, -12190, -12165, -12131, -12109, -12073, -12051, -12018, -11992, -11964, -11931, -11909, -11873, -11852, -11818, -11791, -11766, -11729, -11710, -11675, -11649, -11621, -11590, -11563, -11536, -11504, -11479, -11447, -11421, -11391, -11365, -11332, -11307, -11278, -11247, -11223, -11189, -11165, -11134, -11106, -11078, -11048, -11022, -10990, -10965, -10933, -10908, -10876, -10851, -10818, -10794, -10762, -10737, -10704, -10679, -10649, -10621, -10592, -10564, -10533, -10510, -10474, -10453, -10419, -10393, -10363, -10335, -10307, -10279, -10248, -10222, -10191, -10166, -10133, -10108, -10077, -10051, -10021, -9991, -9966, -9933, -9909, -9877, -9850, -9821, -9794, -9762, -9737, -9707, -9676, -9654, -9617, -9597, -9561, -9538, -9504, -9482, -9447, -9424, -9391, -9366, -9333, -9311, -9275, -9253, -9220, -9194, -9163, -9138, -9106, -9080, -9049, -9023, -8991, -8968, -8933, -8910, -8876, -8854, -8818, -8797, -8761, -8739, -8706, -8681, -8649, -8622, -8595, -8562, -8540, -8504, -8482, -8450, -8421, -8395, -8364, -8337, -8308, -8279, -8250, -8224, -8192, -8166, -8136, -8109, -8077, -8054, -8020, -7994, -7967, -7934, -7911, -7878, -7851, -7823, -7793, -7767, -7735, -7710, -7679, -7651, -7623, -7593, -7567, -7536, -7509, -7479, -7452, -7422, -7396, -7363, -7339, -7307, -7281, -7252, -7221, -7196, -7165, -7138, -7108, -7080, -7053, -7020, -6999, -6961, -6941, -6907, -6880, -6852, -6824, -6793, -6768, -6735, -6711, -6679, -6653, -6622, -6596, -6565, -6539, -6508, -6481, -6452, -6423, -6395, -6366, -6338, -6309, -6282, -6250, -6225, -6193, -6169, -6136, -6111, -6078, -6056, -6019, -6001, -5960, -5944, -5905, -5884, -5850, -5825, -5795, -5766, -5740, -5707, -5683, -5651, -5626, -5593, -5569, -5537, -5510, -5481, -5453, -5423, -5397, -5365, -5341, -5307, -5283, -5252, -5224, -5196, -5167, -5139, -5109, -5083, -5050, -5027, -4994, -4968, -4938, -4910, -4883, -4851, -4826, -4795, -4767, -4741, -4707, -4685, -4650, -4627, -4595, -4568, -4538, -4511, -4481, -4455, -4423, -4397, -4367, -4340, -4309, -4285, -4249, -4229, -4193, -4169, -4141, -4107, -4086, -4050, -4028, -3994, -3969, -3939, -3911, -3883, -3851, -3829, -3792, -3772, -3737, -3711, -3684, -3651, -3628, -3594, -3570, -3539, -3511, -3483, -3452, -3428, -3394, -3371, -3338, -3312, -3282, -3254, -3226, -3196, -3170, -3138, -3113, -3081, -3055, -3025, -2999, -2966, -2942, -2910, -2883, -2855, -2825, -2797, -2769, -2740, -2711, -2684, -2653, -2626, -2599, -2566, -2543, -2510, -2482, -2458, -2422, -2401, -2367, -2340, -2313, -2282, -2256, -2225, -2198, -2169, -2140, -2113, -2083, -2054, -2027, -1998, -1968, -1942, -1911, -1884, -1856, -1824, -1800, -1767, -1743, -1711, -1684, -1654, -1629, -1595, -1571, -1541, -1511, -1485, -1455, -1427, -1397, -1371, -1339, -1315, -1282, -1256, -1226, -1199, -1169, -1143, -1109, -1087, -1053, -1029, -998, -969, -942, -912, -884, -858, -824, -801, -768, -742, -714, -683, -656, -627, -599, -569, -544, -509, -489, -452, -429, -399, -369, -343, -313, -283, -258, -227, -198, -171, -141, -114, -85, -55, -28, 2, 28, 59, 87, 114, 147, 167, 207, 223, 264, 282, 317, 344, 371, 402, 428, 459, 485, 518, 539, 577, 596, 633, 656, 686, 716, 742, 772, 802, 827, 860, 883, 918, 940, 975, 998, 1030, 1058, 1084, 1118, 1140, 1173, 1200, 1229, 1257, 1287, 1313, 1343, 1373, 1398, 1431, 1456, 1485, 1515, 1543, 1571, 1601, 1628, 1656, 1688, 1711, 1746, 1769, 1801, 1828, 1858, 1884, 1914, 1943, 1972, 1999, 2029, 2055, 2086, 2116, 2140, 2173, 2198, 2228, 2258, 2284, 2315, 2341, 2371, 2399, 2430, 2454, 2488, 2510, 2545, 2569, 2601, 2627, 2657, 2684, 2714, 2743, 2768, 2803, 2824, 2860, 2882, 2914, 2943, 2969, 3000, 3029, 3053, 3088, 3111, 3143, 3170, 3199, 3227, 3258, 3282, 3316, 3338, 3374, 3396, 3430, 3454, 3485, 3513, 3541, 3572, 3596, 3630, 3653, 3687, 3711, 3742, 3770, 3798, 3828, 3856, 3882, 3915, 3940, 3971, 3997, 4029, 4053, 4086, 4113, 4138, 4174, 4194, 4230, 4254, 4285, 4310, 4344, 4367, 4401, 4424, 4457, 4482, 4515, 4538, 4572, 4596, 4628, 4654, 4684, 4713, 4740, 4771, 4795, 4829, 4853, 4885, 4912, 4940, 4970, 4997, 5027, 5053, 5086, 5110, 5142, 5168, 5197, 5227, 5255, 5282, 5313, 5339, 5370, 5398, 5424, 5457, 5481, 5514, 5538, 5570, 5597, 5627, 5653, 5684, 5710, 5742, 5768, 5797, 5826, 5854, 5883, 5912, 5939, 5970, 5996, 6026, 6054, 6083, 6112, 6138, 6171, 6194, 6228, 6253, 6282, 6312, 6339, 6369, 6397, 6425, 6454, 6482, 6512, 6539, 6569, 6596, 6626, 6653, 6683, 6711, 6739, 6769, 6795, 6827, 6852, 6884, 6909, 6941, 6966, 6999, 7022, 7057, 7078, 7115, 7135, 7172, 7192, 7229, 7250, 7284, 7309, 7342, 7364, 7399, 7422, 7456, 7481, 7510, 7539, 7567, 7597, 7624, 7653, 7683, 7708, 7741, 7765, 7799, 7822, 7854, 7882, 7908, 7942, 7965, 7996, 8025, 8053, 8080, 8113, 8135, 8170, 8194, 8226, 8251, 8283, 8308, 8340, 8367, 8394, 8427, 8449, 8484, 8509, 8537, 8570, 8592, 8627, 8649, 8686, 8704, 8744, 8762, 8798, 8823, 8853, 8879, 8913, 8934, 8971, 8991, 9027, 9049, 9085, 9105, 9141, 9166, 9194, 9225, 9251, 9281, 9310, 9337, 9366, 9396, 9423, 9452, 9480, 9509, 9539, 9564, 9598, 9620, 9654, 9680, 9708, 9739, 9765, 9795, 9824, 9850, 9882, 9907, 9939, 9965, 9995, 10023, 10052, 10079, 10111, 10134, 10169, 10193, 10223, 10252, 10279, 10309, 10338, 10365, 10393, 10425, 10449, 10482, 10507, 10537, 10566, 10594, 10623, 10650, 10681, 10708, 10737, 10765, 10795, 10822, 10851, 10881, 10905, 10941, 10962, 10996, 11021, 11051, 11081, 11106, 11138, 11165, 11192, 11226, 11246, 11283, 11307, 11336, 11366, 11392, 11423, 11451, 11479, 11508, 11536, 11565, 11594, 11620, 11653, 11677, 11710, 11734, 11766, 11793, 11821, 11853, 11876, 11910, 11935, 11964, 11994, 12022, 12050, 12080, 12105, 12138, 12163, 12195, 12220, 12252, 12277, 12309, 12334, 12366, 12392, 12422, 12451, 12477, 12508, 12536, 12563, 12595, 12618, 12654, 12675, 12710, 12733, 12765, 12792, 12823, 12848, 12880, 12906, 12934, 12966, 12992, 13021, 13050, 13077, 13109, 13133, 13166, 13191, 13221, 13251, 13276, 13309, 13333, 13366, 13390, 13423, 13448, 13478, 13508, 13533, 13565, 13591, 13622, 13649, 13677, 13707, 13735, 13763, 13793, 13819, 13851, 13876, 13908, 13933, 13965, 13991, 14021, 14048, 14079, 14105, 14136, 14162, 14193, 14218, 14253, 14273, 14310, 14331, 14366, 14390, 14421, 14449, 14476, 14507, 14534, 14563, 14592, 14619, 14650, 14675, 14708, 14732, 14765, 14790, 14820, 14849, 14876, 14908, 14931, 14965, 14991, 15018, 15052, 15073, 15109, 15131, 15165, 15189, 15222, 15246, 15279, 15302, 15338, 15359, 15394, 15417, 15449, 15477, 15505, 15534, 15563, 15589, 15622, 15646, 15677, 15706, 15733, 15762, 15791, 15819, 15848, 15876, 15905, 15934, 15962, 15990, 16020, 16045, 16081, 16101, 16136, 16160, 16191, 16220, 16246, 16278, 16303, 16335, 16360, 16391, 16419, 16447, 16478, 16501, 16536, 16559, 16593, 16618, 16647, 16676, 16703, 16735, 16760, 16793, 16814, 16853, 16869, 16910, 16930, 16962, 16991, 17016, 17050, 17073, 17106, 17132, 17161, 17191, 17216, 17250, 17273, 17306, 17331, 17362, 17389, 17420, 17444, 17479, 17501, 17534, 17561, 17588, 17621, 17644, 17678, 17701, 17735, 17758, 17792, 17816, 17848, 17875, 17902, 17934, 17960, 17989, 18019, 18046, 18074, 18106, 18130, 18161, 18190, 18217, 18247, 18274, 18305, 18329, 18364, 18385, 18421, 18445, 18475, 18503, 18531, 18561, 18589, 18617, 18648, 18671, 18708, 18727, 18763, 18788, 18817, 18847, 18873, 18905, 18929, 18962, 18988, 19016, 19049, 19071, 19105, 19130, 19161, 19188, 19218, 19245, 19274, 19304, 19329, 19363, 19385, 19420, 19443, 19476, 19502, 19530, 19562, 19585, 19620, 19643, 19675, 19703, 19730, 19760, 19788, 19816, 19847, 19872, 19904, 19929, 19962, 19985, 20019, 20045, 20072, 20105, 20128, 20161, 20188, 20216, 20245, 20274, 20301, 20332, 20359, 20387, 20418, 20442, 20476, 20500, 20533, 20556, 20591, 20613, 20647, 20672, 20702, 20731, 20759, 20787, 20816, 20844, 20875, 20900, 20931, 20958, 20988, 21017, 21042, 21076, 21098, 21133, 21158, 21186, 21218, 21242, 21274, 21302, 21329, 21359, 21387, 21415, 21445, 21473, 21500, 21532, 21556, 21588, 21616, 21642, 21676, 21698, 21732, 21758, 21785, 21818, 21841, 21876, 21899, 21930, 21959, 21985, 22017, 22043, 22072, 22102, 22128, 22159, 22187, 22214, 22245, 22270, 22303, 22328, 22359, 22385, 22417, 22441, 22475, 22498, 22531, 22558, 22585, 22617, 22640, 22676, 22697, 22733, 22754, 22789, 22812, 22845, 22872, 22899, 22932, 22954, 22989, 23012, 23045, 23071, 23101, 23128, 23158, 23186, 23214, 23244, 23270, 23301, 23329, 23357, 23386, 23413, 23445, 23469, 23503, 23527, 23557, 23586, 23614, 23644, 23670, 23701, 23728, 23757, 23786, 23813, 23844, 23870, 23901, 23928, 23956, 23987, 24012, 24045, 24069, 24101, 24128, 24155, 24189, 24210, 24245, 24269, 24302, 24326, 24358, 24384, 24413, 24445, 24468, 24502, 24526, 24557, 24586, 24612, 24644, 24669, 24700, 24728, 24757, 24783, 24816, 24838, 24876, 24894, 24932, 24953, 24986, 25014, 25041, 25071, 25099, 25126, 25159, 25182, 25215, 25240, 25272, 25297, 25330, 25354, 25385, 25413, 25441, 25472, 25497, 25528, 25555, 25586, 25611, 25644, 25666, 25702, 25725, 25757, 25784, 25812, 25842, 25870, 25898, 25928, 25954, 25985, 26013, 26041, 26070, 26098, 26127, 26155, 26185, 26211, 26243, 26268, 26299, 26326, 26356, 26383, 26414, 26439, 26471, 26497, 26527, 26556, 26582, 26614, 26640, 26670, 26698, 26725, 26757, 26782, 26814, 26839, 26871, 26896, 26928, 26954, 26983, 27013, 27039, 27072, 27095, 27128, 27153, 27184, 27213, 27239, 27271, 27295, 27329, 27352, 27385, 27410, 27442, 27468, 27498, 27525, 27555, 27583, 27612, 27640, 27668, 27698, 27726, 27753, 27786, 27807, 27845, 27864, 27900, 27925, 27953, 27985, 28010, 28041, 28067, 28098, 28125, 28155, 28183, 28210, 28241, 28266, 28300, 28323, 28355, 28383, 28409, 28443, 28464, 28501, 28522, 28557, 28580, 28612, 28639, 28669, 28696, 28725, 28755, 28780, 28814, 28836, 28871, 28894, 28927, 28952, 28983, 29012, 29037, 29070, 29094, 29127, 29153, 29181, 29213, 29236, 29213, 29181, 29153, 29127, 29094, 29069, 29040, 29009, 28984, 28952, 28926, 28897, 28868, 28838, 28812, 28782, 28754, 28725, 28698, 28666, 28641, 28611, 28582, 28555, 28524, 28498, 28468, 28439, 28412, 28381, 28356, 28324, 28298, 28267, 28241, 28210, 28184, 28153, 28127, 28096, 28069, 28039, 28012, 27984, 27952, 27928, 27895, 27870, 27840, 27811, 27784, 27752, 27730, 27692, 27675, 27634, 27617, 27579, 27558, 27523, 27500, 27466, 27444, 27408, 27386, 27353, 27327, 27297, 27270, 27238, 27215, 27180, 27158, 27124, 27099, 27069, 27039, 27014, 26982, 26956, 26926, 26898, 26869, 26841, 26811, 26785, 26755, 26725, 26701, 26666, 26644, 26610, 26585, 26555, 26526, 26499, 26469, 26442, 26410, 26387, 26352, 26329, 26298, 26268, 26243, 26212, 26183, 26156, 26127, 26098, 26071, 26039, 26014, 25984, 25955, 25928, 25897, 25872, 25839, 25815, 25782, 25758, 25725, 25701, 25667, 25645, 25610, 25586, 25556, 25525, 25502, 25466, 25446, 25409, 25388, 25353, 25329, 25298, 25271, 25241, 25214, 25184, 25157, 25126, 25101, 25068, 25044, 25013, 24983, 24958, 24927, 24899, 24872, 24839, 24817, 24781, 24761, 24723, 24703, 24668, 24645, 24610, 24589, 24552, 24533, 24495, 24474, 24440, 24415, 24384, 24359, 24325, 24303, 24267, 24246, 24211, 24188, 24155, 24129, 24099, 24072, 24041, 24016, 23983, 23960, 23926, 23900, 23872, 23841, 23817, 23784, 23757, 23728, 23700, 23672, 23643, 23613, 23587, 23556, 23529, 23500, 23471, 23444, 23414, 23386, 23356, 23331, 23298, 23274, 23241, 23215, 23187, 23156, 23130, 23100, 23071, 23044, 23014, 22987, 22956, 22931, 22898, 22874, 22842, 22815, 22787, 22755, 22733, 22697, 22675, 22640, 22618, 22584, 22560, 22528, 22500, 22473, 22444, 22414, 22388, 22356, 22331, 22299, 22275, 22241, 22217, 22185, 22159, 22130, 22099, 22075, 22041, 22017, 21987, 21957, 21931, 21899, 21874, 21843, 21817, 21785, 21760, 21728, 21702, 21672, 21644, 21617, 21585, 21560, 21529, 21501, 21474, 21443, 21417, 21386, 21359, 21330, 21302, 21272, 21245, 21215, 21188, 21158, 21131, 21101, 21073, 21044, 21018, 20984, 20963, 20926, 20905, 20871, 20846, 20816, 20786, 20762, 20725, 20708, 20668, 20649, 20614, 20588, 20559, 20531, 20502, 20473, 20445, 20417, 20387, 20359, 20332, 20300, 20276, 20242, 20219, 20186, 20161, 20130, 20102, 20074, 20045, 20017, 19988, 19959, 19931, 19903, 19873, 19846, 19816, 19788, 19762, 19727, 19706, 19671, 19648, 19615, 19590, 19558, 19532, 19503, 19473, 19447, 19415, 19391, 19357, 19334, 19301, 19274, 19247, 19216, 19188, 19162, 19129, 19104, 19075, 19044, 19019, 18988, 18959, 18934, 18901, 18876, 18844, 18819, 18788, 18761, 18731, 18703, 18676, 18644, 18620, 18586, 18564, 18529, 18504, 18476, 18444, 18420, 18387, 18361, 18333, 18302, 18275, 18247, 18217, 18190, 18160, 18132, 18104, 18075, 18046, 18018, 17990, 17959, 17934, 17903, 17875, 17847, 17817, 17791, 17759, 17735, 17701, 17677, 17647, 17617, 17591, 17559, 17535, 17501, 17479, 17444, 17420, 17388, 17362, 17333, 17303, 17278, 17243, 17222, 17187, 17163, 17132, 17104, 17077, 17044, 17022, 16987, 16963, 16933, 16903, 16877, 16847, 16818, 16791, 16761, 16733, 16705, 16675, 16648, 16618, 16591, 16561, 16533, 16506, 16474, 16449, 16417, 16393, 16359, 16337, 16301, 16278, 16248, 16217, 16194, 16158, 16136, 16104, 16075, 16051, 16015, 15994, 15960, 15934, 15905, 15877, 15847, 15820, 15790, 15762, 15735, 15704, 15676, 15650, 15616, 15595, 15559, 15536, 15503, 15479, 15447, 15419, 15393, 15360, 15335, 15306, 15276, 15249, 15219, 15191, 15163, 15135, 15104, 15077, 15049, 15019, 14992, 14962, 14935, 14904, 14879, 14846, 14822, 14791, 14762, 14735, 14705, 14679, 14646, 14623, 14588, 14566, 14533, 14506, 14478, 14448, 14421, 14391, 14363, 14336, 14304, 14279, 14248, 14221, 14192, 14161, 14138, 14102, 14082, 14046, 14021, 13993, 13962, 13935, 13908, 13874, 13854, 13816, 13796, 13760, 13737, 13705, 13679, 13649, 13620, 13594, 13560, 13539, 13504, 13480, 13448, 13422, 13391, 13366, 13333, 13308, 13277, 13252, 13218, 13194, 13164, 13133, 13112, 13071, 13057, 13014, 12999, 12959, 12939, 12904, 12881, 12848, 12822, 12792, 12764, 12737, 12706, 12679, 12649, 12622, 12592, 12566, 12534, 12508, 12479, 12449, 12423, 12391, 12366, 12334, 12310, 12276, 12252, 12221, 12192, 12167, 12133, 12110, 12077, 12051, 12023, 11991, 11967, 11933, 11911, 11876, 11853, 11821, 11793, 11765, 11736, 11708, 11680, 11649, 11623, 11593, 11565, 11537, 11506, 11481, 11450, 11422, 11394, 11365, 11336, 11310, 11276, 11254, 11219, 11198, 11161, 11140, 11105, 11082, 11049, 11024, 10993, 10965, 10938, 10907, 10880, 10852, 10821, 10796, 10763, 10739, 10707, 10681, 10650, 10623, 10594, 10565, 10539, 10506, 10481, 10451, 10422, 10396, 10365, 10336, 10311, 10277, 10255, 10219, 10198, 10163, 10140, 10107, 10080, 10052, 10023, 9994, 9967, 9936, 9910, 9879, 9853, 9822, 9796, 9765, 9738, 9709, 9680, 9653, 9622, 9596, 9565, 9539, 9508, 9482, 9450, 9425, 9395, 9365, 9340, 9307, 9282, 9252, 9224, 9194, 9168, 9136, 9111, 9080, 9053, 9023, 8996, 8965, 8940, 8908, 8882, 8851, 8826, 8792, 8771, 8734, 8712, 8681, 8651, 8625, 8595, 8567, 8539, 8509, 8480, 8455, 8422, 8397, 8366, 8339, 8309, 8283, 8251, 8225, 8196, 8166, 8140, 8109, 8083, 8051, 8025, 7996, 7966, 7942, 7907, 7883, 7852, 7825, 7796, 7768, 7737, 7712, 7680, 7656, 7621, 7600, 7563, 7544, 7506, 7485, 7452, 7424, 7399, 7364, 7341, 7311, 7279, 7258, 7221, 7198, 7167, 7140, 7110, 7083, 7053, 7025, 6997, 6967, 6940, 6911, 6881, 6856, 6823, 6797, 6770, 6735, 6716, 6679, 6655, 6626, 6595, 6569, 6539, 6512, 6482, 6454, 6425, 6397, 6369, 6339, 6311, 6284, 6252, 6228, 6195, 6169, 6141, 6110, 6083, 6055, 6024, 5999, 5967, 5941, 5911, 5883, 5854, 5826, 5798, 5767, 5741, 5712, 5683, 5654, 5626, 5596, 5572, 5537, 5515, 5480, 5457, 5424, 5399, 5368, 5341, 5312, 5282, 5256, 5225, 5198, 5170, 5138, 5115, 5080, 5058, 5024, 4999, 4969, 4940, 4913, 4883, 4855, 4826, 4799, 4768, 4742, 4712, 4683, 4656, 4626, 4597, 4572, 4539, 4514, 4482, 4455, 4428, 4398, 4370, 4340, 4313, 4283, 4257, 4225, 4200, 4168, 4143, 4111, 4085, 4055, 4026, 4001, 3968, 3942, 3913, 3883, 3857, 3827, 3798, 3771, 3740, 3714, 3684, 3656, 3627, 3599, 3569, 3544, 3510, 3488, 3453, 3429, 3398, 3371, 3341, 3315, 3281, 3260, 3224, 3201, 3170, 3141, 3115, 3083, 3057, 3027, 2999, 2971, 2942, 2913, 2885, 2857, 2826, 2801, 2769, 2743, 2713, 2686, 2655, 2628, 2601, 2568, 2545, 2512, 2484, 2461, 2422, 2405, 2366, 2346, 2312, 2286, 2256, 2228, 2200, 2172, 2141, 2115, 2084, 2058, 2028, 2000, 1971, 1943, 1913, 1886, 1857, 1828, 1801, 1770, 1744, 1712, 1688, 1654, 1633, 1596, 1573, 1543, 1513, 1488, 1455, 1430, 1399, 1374, 1339, 1319, 1282, 1260, 1228, 1200, 1172, 1143, 1115, 1085, 1059, 1028, 1000, 973, 942, 915, 887, 856, 831, 799, 772, 744, 714, 688, 655, 632, 597, 577, 538, 520, 482, 461, 427, 402, 372, 343, 317, 283, 261, 228, 201, 173, 144, 114, 88, 57, 30, 1, -27, -57, -83, -116, -139, -173, -196, -230, -253, -288, -310, -344, -369, -399, -427, -456, -485, -513, -541, -571, -596, -631, -652, -688, -710, -743, -768, -801, -825, -857, -884, -912, -942, -970, -997, -1029, -1054, -1084, -1114, -1139, -1171, -1198, -1226, -1257, -1282, -1313, -1341, -1370, -1397, -1428, -1454, -1483, -1516, -1536, -1573, -1596, -1626, -1658, -1680, -1715, -1739, -1769, -1800, -1824, -1856, -1884, -1910, -1943, -1968, -1997, -2028, -2053, -2085, -2111, -2141, -2168, -2199, -2224, -2258, -2280, -2315, -2337, -2372, -2394, -2430, -2450, -2487, -2509, -2542, -2568, -2597, -2626, -2654, -2684, -2711, -2740, -2769, -2797, -2826, -2853, -2885, -2908, -2944, -2965, -2999, -3025, -3054, -3083, -3110, -3142, -3166, -3200, -3221, -3259, -3277, -3317, -3335, -3371, -3396, -3425, -3455, -3481, -3512, -3540, -3567, -3598, -3624, -3655, -3681, -3711, -3741, -3765, -3801, -3820, -3858, -3879, -3912, -3939, -3969, -3995, -4027, -4050, -4085, -4109, -4141, -4166, -4197, -4225, -4252, -4284, -4308, -4342, -4365, -4398, -4423, -4455, -4480, -4512, -4538, -4568, -4596, -4624, -4654, -4681, -4712, -4736, -4771, -4792, -4828, -4850, -4884, -4908, -4941, -4965, -4997, -5024, -5053, -5080, -5113, -5134, -5173, -5190, -5229, -5248, -5285, -5307, -5342, -5363, -5399, -5421, -5454, -5482, -5508, -5540, -5565, -5597, -5622, -5655, -5678, -5712, -5738, -5765, -5797, -5822, -5854, -5880, -5910, -5937, -5968, -5994, -6024, -6052, -6082, -6108, -6139, -6164, -6199, -6219, -6257, -6276, -6312, -6337, -6365, -6397, -6422, -6452, -6481, -6508, -6539, -6566, -6594, -6623, -6653, -6680, -6708, -6740, -6762, -6799, -6819, -6856, -6876, -6912, -6935, -6966, -6997, -7020, -7054, -7078, -7109, -7138, -7166, -7193, -7225, -7249, -7282, -7306, -7340, -7363, -7397, -7420, -7453, -7479, -7509, -7536, -7567, -7592, -7625, -7649, -7681, -7707, -7739, -7763, -7796, -7821, -7851, -7881, -7907, -7937, -7966, -7992, -8024, -8050, -8080, -8107, -8138, -8164, -8194, -8222, -8251, -8279, -8308, -8337, -8363, -8397, -8419, -8452, -8480, -8506, -8538, -8565, -8592, -8623, -8651, -8677, -8711, -8732, -8769, -8789, -8826, -8847, -8881, -8906, -8937, -8965, -8992, -9023, -9048, -9081, -9107, -9135, -9166, -9191, -9223, -9250, -9278, -9308, -9336, -9363, -9396, -9417, -9454, -9476, -9508, -9537, -9562, -9594, -9622, -9647, -9683, -9703, -9738, -9763, -9792, -9823, -9848, -9880, -9905, -9937, -9962, -9995, -10018, -10053, -10075, -10109, -10134, -10164, -10193, -10220, -10250, -10278, -10307, -10334, -10365, -10390, -10424, -10446, -10481, -10504, -10536, -10564, -10591, -10622, -10648, -10679, -10706, -10734, -10766, -10788, -10825, -10844, -10883, -10902, -10938, -10960, -10994, -11020, -11049, -11078, -11105, -11136, -11162, -11193, -11219, -11250, -11276, -11308, -11332, -11365, -11390, -11422, -11447, -11479, -11503, -11537, -11562, -11592, -11619, -11649, -11678, -11703, -11739, -11758, -11795, -11818, -11848, -11878, -11905, -11935, -11962, -11992, -12018, -12050, -12075, -12108, -12133, -12161, -12194, -12217, -12250, -12276, -12305, -12334, -12364, -12388, -12423, -12444, -12480, -12504, -12533, -12565, -12587, -12622, -12647, -12677, -12705, -12734, -12760, -12793, -12819, -12847, -12877, -12904, -12934, -12962, -12991, -13018, -13049, -13075, -13106, -13133, -13161, -13192, -13217, -13249, -13276, -13305, -13333, -13361, -13390, -13420, -13447, -13477, -13503, -13533, -13562, -13591, -13617, -13650, -13673, -13706, -13733, -13760, -13792, -13817, -13849, -13874, -13905, -13933, -13960, -13991, -14018, -14047, -14077, -14101, -14136, -14158, -14192, -14218, -14246, -14277, -14303, -14332, -14362, -14389, -14419, -14447, -14474, -14505, -14532, -14561, -14590, -14617, -14648, -14674, -14705, -14731, -14762, -14788, -14819, -14846, -14875, -14905, -14930, -14962, -14989, -15017, -15048, -15073, -15105, -15131, -15161, -15189, -15218, -15246, -15275, -15303, -15332, -15361, -15388, -15419, -15445, -15475, -15504, -15530, -15562, -15587, -15620, -15644, -15676, -15701, -15734, -15758, -15790, -15818, -15843, -15878, -15900, -15933, -15960, -15988, -16018, -16045, -16075, -16102, -16132, -16159, -16191, -16214, -16247, -16274, -16302, -16334, -16356, -16392, -16414, -16448, -16472, -16503, -16532, -16559, -16589, -16615, -16647, -16673, -16703, -16730, -16761, -16787, -16818, -16844, -16874, -16902, -16932, -16959, -16987, -17018, -17044, -17075, -17100, -17133, -17157, -17191, -17213, -17248, -17270, -17306, -17327, -17362, -17386, -17417, -17445, -17472, -17503, -17531, -17558, -17589, -17615, -17645, -17673, -17702, -17730, -17760, -17786, -17818, -17842, -17875, -17900, -17931, -17960, -17986, -18016, -18045, -18071, -18104, -18129, -18158, -18189, -18214, -18245, -18274, -18298, -18334, -18355, -18390, -18414, -18444, -18473, -18501, -18531, -18557, -18588, -18614, -18645, -18673, -18701, -18729, -18759, -18786, -18816, -18844, -18872, -18901, -18930, -18958, -18986, -19016, -19044, -19070, -19105, -19125, -19162, -19183, -19217, -19243, -19273, -19300, -19329, -19358, -19386, -19417, -19441, -19474, -19498, -19532, -19557, -19585, -19617, -19641, -19673, -19701, -19728, -19759, -19785, -19814, -19845, -19870, -19902, -19928, -19957, -19987, -20014, -20043, -20072, -20100, -20129, -20157, -20187, -20213, -20244, -20271, -20300, -20329, -20357, -20387, -20413, -20443, -20472, -20499, -20530, -20556, -20585, -20615, -20643, -20671, -20700, -20728, -20757, -20786, -20813, -20845, -20869, -20900, -20929, -20956, -20987, -21012, -21044, -21069, -21103, -21124, -21161, -21181, -21218, -21239, -21273, -21297, -21331, -21355, -21385, -21414, -21442, -21471, -21500, -21526, -21558, -21585, -21613, -21643, -21669, -21701, -21726, -21758, -21784, -21813, -21843, -21869, -21900, -21928, -21955, -21986, -22012, -22042, -22071, -22099, -22127, -22157, -22182, -22216, -22241, -22269, -22302, -22323, -22359, -22384, -22412, -22442, -22471, -22497, -22530, -22553, -22585, -22613, -22642, -22670, -22697, -22729, -22754, -22786, -22811, -22842, -22869, -22901, -22923, -22960, -22979, -23017, -23039, -23070, -23099, -23126, -23155, -23186, -23210, -23243, -23269, -23297, -23329, -23353, -23386, -23410, -23443, -23468, -23499, -23526, -23555, -23584, -23612, -23641, -23668, -23700, -23725, -23756, -23783, -23812, -23841, -23869, -23898, -23927, -23954, -23984, -24012, -24040, -24070, -24096, -24128, -24153, -24186, -24209, -24242, -24268, -24298, -24326, -24355, -24383, -24411, -24442, -24467, -24498, -24527, -24552, -24586, -24609, -24642, -24667, -24699, -24724, -24756, -24782, -24811, -24841, -24869, -24895, -24928, -24952, -24984, -25012, -25039, -25067, -25100, -25122, -25157, -25181, -25212, -25239, -25269, -25297, -25324, -25356, -25381, -25411, -25441, -25466, -25500, -25522, -25557, -25579, -25614, -25637, -25670, -25696, -25725, -25754, -25781, -25812, -25839, -25869, -25895, -25926, -25952, -25984, -26010, -26040, -26067, -26096, -26126, -26152, -26184, -26208, -26242, -26265, -26298, -26324, -26352, -26385, -26408, -26439, -26469, -26494, -26526, -26554, -26579, -26612, -26639, -26666, -26698, -26722, -26755, -26781, -26810, -26838, -26869, -26894, -26926, -26952, -26981, -27011, -27037, -27070, -27093, -27126, -27152, -27181, -27211, -27238, -27267, -27295, -27326, -27350, -27384, -27407, -27441, -27464, -27499, -27521, -27554, -27581, -27609, -27639, -27666, -27696, -27723, -27754, -27779, -27811, -27837, -27868, -27893, -27927, -27949, -27983, -28009, -28037, -28067, -28095, -28123, -28154, -28179, -28209, -28239, -28264, -28298, -28321, -28354, -28379, -28410, -28437, -28467, -28494, -28525, -28550, -28582, -28608, -28638, -28666, -28695, -28722, -28753, -28780, -28809, -28837, -28866, -28895, -28923, -28952, -28978, -29012, -29034, -29070, -29090, -29125, -29151, -29181, -29207};