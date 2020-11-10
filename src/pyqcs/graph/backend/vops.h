#ifndef VOPS_H_
#define VOPS_H_
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarraytypes.h>

static npy_uint8 vop_lookup_table[24][24] = 
{
	{2, 4, 0, 12, 1, 7, 15, 5, 10, 19, 8, 22, 3, 14, 13, 6, 23, 18, 17, 9, 21, 20, 11, 16}
	, {3, 5, 1, 13, 6, 8, 17, 9, 2, 20, 11, 23, 10, 15, 16, 0, 21, 19, 14, 4, 22, 18, 7, 12}
	, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}
	, {1, 6, 3, 10, 5, 9, 0, 8, 11, 4, 2, 7, 13, 16, 15, 17, 12, 14, 19, 20, 18, 22, 23, 21}
	, {12, 7, 4, 14, 15, 10, 18, 19, 0, 21, 22, 16, 8, 6, 23, 2, 20, 9, 13, 1, 11, 17, 5, 3}
	, {13, 8, 5, 15, 17, 2, 19, 20, 1, 22, 23, 12, 11, 0, 21, 3, 18, 4, 16, 6, 7, 14, 9, 10}
	, {10, 9, 6, 16, 0, 11, 14, 4, 3, 18, 7, 21, 2, 17, 12, 1, 22, 20, 15, 5, 23, 19, 8, 13}
	, {14, 10, 7, 6, 18, 0, 9, 21, 4, 11, 16, 3, 22, 2, 20, 12, 17, 1, 23, 15, 5, 13, 19, 8}
	, {15, 2, 8, 0, 19, 1, 4, 22, 5, 7, 12, 10, 23, 3, 18, 13, 14, 6, 21, 17, 9, 16, 20, 11}
	, {16, 11, 9, 17, 14, 3, 20, 18, 6, 23, 21, 13, 7, 1, 22, 10, 19, 5, 12, 0, 8, 15, 4, 2}
	, {6, 0, 10, 2, 9, 4, 1, 11, 7, 5, 3, 8, 16, 12, 17, 14, 13, 15, 20, 18, 19, 23, 21, 22}
	, {17, 3, 11, 1, 20, 6, 5, 23, 9, 8, 13, 2, 21, 10, 19, 16, 15, 0, 22, 14, 4, 12, 18, 7}
	, {4, 15, 12, 8, 7, 19, 2, 10, 22, 1, 0, 5, 14, 23, 6, 18, 3, 13, 9, 21, 17, 11, 16, 20}
	, {5, 17, 13, 11, 8, 20, 3, 2, 23, 6, 1, 9, 15, 21, 0, 19, 10, 16, 4, 22, 14, 7, 12, 18}
	, {7, 18, 14, 22, 10, 21, 12, 0, 16, 15, 4, 19, 6, 20, 2, 9, 8, 23, 1, 11, 13, 5, 3, 17}
	, {8, 19, 15, 23, 2, 22, 13, 1, 12, 17, 5, 20, 0, 18, 3, 4, 11, 21, 6, 7, 16, 9, 10, 14}
	, {9, 14, 16, 7, 11, 18, 10, 3, 21, 0, 6, 4, 17, 22, 1, 20, 2, 12, 5, 23, 15, 8, 13, 19}
	, {11, 20, 17, 21, 3, 23, 16, 6, 13, 14, 9, 18, 1, 19, 10, 5, 7, 22, 0, 8, 12, 4, 2, 15}
	, {22, 21, 18, 20, 12, 16, 23, 15, 14, 13, 19, 17, 4, 9, 8, 7, 5, 11, 2, 10, 3, 1, 0, 6}
	, {23, 22, 19, 18, 13, 12, 21, 17, 15, 16, 20, 14, 5, 4, 11, 8, 9, 7, 3, 2, 10, 6, 1, 0}
	, {21, 23, 20, 19, 16, 13, 22, 14, 17, 12, 18, 15, 9, 5, 7, 11, 4, 8, 10, 3, 2, 0, 6, 1}
	, {20, 16, 21, 9, 23, 14, 11, 13, 18, 3, 17, 6, 19, 7, 5, 22, 1, 10, 8, 12, 0, 2, 15, 4}
	, {18, 12, 22, 4, 21, 15, 7, 16, 19, 10, 14, 0, 20, 8, 9, 23, 6, 2, 11, 13, 1, 3, 17, 5}
    , {19, 13, 23, 5, 22, 17, 8, 12, 20, 2, 15, 1, 18, 11, 4, 21, 0, 3, 7, 16, 6, 10, 14, 9}
};

#define VOP_H 0
#define VOP_S 1
#define VOP_I 2
#define VOP_Z 5
#define VOP_X 14

#define VOP_siZ 8
#define VOP_smiZ 1
#define VOP_smiX 12
#define VOP_siX 6
#define VOP_siY 7
#define VOP_smiY 13


// S, I, Z, S^\dagger
#define vop_commutes_with_CZ(v) (v == 1 || v == 2 || v == 5 || v == 8)

// FIXME: this is suboptimal.
static npy_uint8 C_L_as_products_lengths[24] =
{
    5, 3, 4, 4, 4, 2, 5, 5, 1, 4, 4, 3, 5, 5, 4, 4, 5, 4, 5, 5, 3, 4, 2, 2
};


static npy_uint8 C_L_as_products_daggered[24][5] =
{
    {1, 6, 6, 6, 1}
    , {1, 1, 1, 0, 0}
    , {1, 1, 1, 1, 0}
    , {6, 6, 6, 1, 0}
    , {1, 6, 6, 6, 0}
    , {1, 1, 0, 0, 0}
    , {1, 1, 6, 1, 1}
    , {1, 1, 1, 6, 1}
    , {1, 0, 0, 0, 0}
    , {1, 1, 6, 1, 0}
    , {1, 1, 1, 6, 0}
    , {1, 1, 6, 0, 0}
    , {1, 1, 1, 1, 6}
    , {1, 6, 1, 1, 1}
    , {1, 6, 6, 1, 0}
    , {6, 1, 1, 1, 0}
    , {1, 1, 1, 6, 6}
    , {1, 6, 1, 1, 0}
    , {1, 1, 6, 6, 1}
    , {1, 1, 6, 6, 6}
    , {1, 6, 1, 0, 0}
    , {1, 1, 6, 6, 0}
    , {6, 1, 0, 0, 0}
    , {1, 6, 0, 0, 0}
};


// This is just the readable version of the lookup table above.
/*
static char C_L_as_products[24][5] = 
{
	"sxxxs"
	, "sss"
	, "ssss"
	, "xxxs"
	, "sxxx"
	, "ss"
	, "ssxss"
	, "sssxs"
	, "s"
	, "ssxs"
	, "sssx"
	, "ssx"
	, "ssssx"
	, "sxsss"
	, "sxxs"
	, "xsss"
	, "sssxx"
	, "sxss"
	, "ssxxs"
	, "ssxxx"
	, "sxs"
	, "ssxx"
	, "xs"
	, "sx"
};
*/



// this is vop0, vop1, edge
static npy_intp two_qbit_config_to_number[24][24][2] = 
{
    { {0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}, {10, 11}, {12, 13}, {14, 15}, {16, 17}, {18, 19}, {20, 21}, {22, 23}, {24, 25}, {26, 27}, {28, 29}, {30, 31}, {32, 33}, {34, 35}, {36, 37}, {38, 39}, {40, 41}, {42, 43}, {44, 45}, {46, 47} }
    , { {48, 49}, {50, 51}, {52, 53}, {54, 55}, {56, 57}, {58, 59}, {60, 61}, {62, 63}, {64, 65}, {66, 67}, {68, 69}, {70, 71}, {72, 73}, {74, 75}, {76, 77}, {78, 79}, {80, 81}, {82, 83}, {84, 85}, {86, 87}, {88, 89}, {90, 91}, {92, 93}, {94, 95} }
    , { {96, 97}, {98, 99}, {100, 101}, {102, 103}, {104, 105}, {106, 107}, {108, 109}, {110, 111}, {112, 113}, {114, 115}, {116, 117}, {118, 119}, {120, 121}, {122, 123}, {124, 125}, {126, 127}, {128, 129}, {130, 131}, {132, 133}, {134, 135}, {136, 137}, {138, 139}, {140, 141}, {142, 143} }
    , { {144, 145}, {146, 147}, {148, 149}, {150, 151}, {152, 153}, {154, 155}, {156, 157}, {158, 159}, {160, 161}, {162, 163}, {164, 165}, {166, 167}, {168, 169}, {170, 171}, {172, 173}, {174, 175}, {176, 177}, {178, 179}, {180, 181}, {182, 183}, {184, 185}, {186, 187}, {188, 189}, {190, 191} }
    , { {192, 193}, {194, 195}, {196, 197}, {198, 199}, {200, 201}, {202, 203}, {204, 205}, {206, 207}, {208, 209}, {210, 211}, {212, 213}, {214, 215}, {216, 217}, {218, 219}, {220, 221}, {222, 223}, {224, 225}, {226, 227}, {228, 229}, {230, 231}, {232, 233}, {234, 235}, {236, 237}, {238, 239} }
    , { {240, 241}, {242, 243}, {244, 245}, {246, 247}, {248, 249}, {250, 251}, {252, 253}, {254, 255}, {256, 257}, {258, 259}, {260, 261}, {262, 263}, {264, 265}, {266, 267}, {268, 269}, {270, 271}, {272, 273}, {274, 275}, {276, 277}, {278, 279}, {280, 281}, {282, 283}, {284, 285}, {286, 287} }
    , { {288, 289}, {290, 291}, {292, 293}, {294, 295}, {296, 297}, {298, 299}, {300, 301}, {302, 303}, {304, 305}, {306, 307}, {308, 309}, {310, 311}, {312, 313}, {314, 315}, {316, 317}, {318, 319}, {320, 321}, {322, 323}, {324, 325}, {326, 327}, {328, 329}, {330, 331}, {332, 333}, {334, 335} }
    , { {336, 337}, {338, 339}, {340, 341}, {342, 343}, {344, 345}, {346, 347}, {348, 349}, {350, 351}, {352, 353}, {354, 355}, {356, 357}, {358, 359}, {360, 361}, {362, 363}, {364, 365}, {366, 367}, {368, 369}, {370, 371}, {372, 373}, {374, 375}, {376, 377}, {378, 379}, {380, 381}, {382, 383} }
    , { {384, 385}, {386, 387}, {388, 389}, {390, 391}, {392, 393}, {394, 395}, {396, 397}, {398, 399}, {400, 401}, {402, 403}, {404, 405}, {406, 407}, {408, 409}, {410, 411}, {412, 413}, {414, 415}, {416, 417}, {418, 419}, {420, 421}, {422, 423}, {424, 425}, {426, 427}, {428, 429}, {430, 431} }
    , { {432, 433}, {434, 435}, {436, 437}, {438, 439}, {440, 441}, {442, 443}, {444, 445}, {446, 447}, {448, 449}, {450, 451}, {452, 453}, {454, 455}, {456, 457}, {458, 459}, {460, 461}, {462, 463}, {464, 465}, {466, 467}, {468, 469}, {470, 471}, {472, 473}, {474, 475}, {476, 477}, {478, 479} }
    , { {480, 481}, {482, 483}, {484, 485}, {486, 487}, {488, 489}, {490, 491}, {492, 493}, {494, 495}, {496, 497}, {498, 499}, {500, 501}, {502, 503}, {504, 505}, {506, 507}, {508, 509}, {510, 511}, {512, 513}, {514, 515}, {516, 517}, {518, 519}, {520, 521}, {522, 523}, {524, 525}, {526, 527} }
    , { {528, 529}, {530, 531}, {532, 533}, {534, 535}, {536, 537}, {538, 539}, {540, 541}, {542, 543}, {544, 545}, {546, 547}, {548, 549}, {550, 551}, {552, 553}, {554, 555}, {556, 557}, {558, 559}, {560, 561}, {562, 563}, {564, 565}, {566, 567}, {568, 569}, {570, 571}, {572, 573}, {574, 575} }
    , { {576, 577}, {578, 579}, {580, 581}, {582, 583}, {584, 585}, {586, 587}, {588, 589}, {590, 591}, {592, 593}, {594, 595}, {596, 597}, {598, 599}, {600, 601}, {602, 603}, {604, 605}, {606, 607}, {608, 609}, {610, 611}, {612, 613}, {614, 615}, {616, 617}, {618, 619}, {620, 621}, {622, 623} }
    , { {624, 625}, {626, 627}, {628, 629}, {630, 631}, {632, 633}, {634, 635}, {636, 637}, {638, 639}, {640, 641}, {642, 643}, {644, 645}, {646, 647}, {648, 649}, {650, 651}, {652, 653}, {654, 655}, {656, 657}, {658, 659}, {660, 661}, {662, 663}, {664, 665}, {666, 667}, {668, 669}, {670, 671} }
    , { {672, 673}, {674, 675}, {676, 677}, {678, 679}, {680, 681}, {682, 683}, {684, 685}, {686, 687}, {688, 689}, {690, 691}, {692, 693}, {694, 695}, {696, 697}, {698, 699}, {700, 701}, {702, 703}, {704, 705}, {706, 707}, {708, 709}, {710, 711}, {712, 713}, {714, 715}, {716, 717}, {718, 719} }
    , { {720, 721}, {722, 723}, {724, 725}, {726, 727}, {728, 729}, {730, 731}, {732, 733}, {734, 735}, {736, 737}, {738, 739}, {740, 741}, {742, 743}, {744, 745}, {746, 747}, {748, 749}, {750, 751}, {752, 753}, {754, 755}, {756, 757}, {758, 759}, {760, 761}, {762, 763}, {764, 765}, {766, 767} }
    , { {768, 769}, {770, 771}, {772, 773}, {774, 775}, {776, 777}, {778, 779}, {780, 781}, {782, 783}, {784, 785}, {786, 787}, {788, 789}, {790, 791}, {792, 793}, {794, 795}, {796, 797}, {798, 799}, {800, 801}, {802, 803}, {804, 805}, {806, 807}, {808, 809}, {810, 811}, {812, 813}, {814, 815} }
    , { {816, 817}, {818, 819}, {820, 821}, {822, 823}, {824, 825}, {826, 827}, {828, 829}, {830, 831}, {832, 833}, {834, 835}, {836, 837}, {838, 839}, {840, 841}, {842, 843}, {844, 845}, {846, 847}, {848, 849}, {850, 851}, {852, 853}, {854, 855}, {856, 857}, {858, 859}, {860, 861}, {862, 863} }
    , { {864, 865}, {866, 867}, {868, 869}, {870, 871}, {872, 873}, {874, 875}, {876, 877}, {878, 879}, {880, 881}, {882, 883}, {884, 885}, {886, 887}, {888, 889}, {890, 891}, {892, 893}, {894, 895}, {896, 897}, {898, 899}, {900, 901}, {902, 903}, {904, 905}, {906, 907}, {908, 909}, {910, 911} }
    , { {912, 913}, {914, 915}, {916, 917}, {918, 919}, {920, 921}, {922, 923}, {924, 925}, {926, 927}, {928, 929}, {930, 931}, {932, 933}, {934, 935}, {936, 937}, {938, 939}, {940, 941}, {942, 943}, {944, 945}, {946, 947}, {948, 949}, {950, 951}, {952, 953}, {954, 955}, {956, 957}, {958, 959} }
    , { {960, 961}, {962, 963}, {964, 965}, {966, 967}, {968, 969}, {970, 971}, {972, 973}, {974, 975}, {976, 977}, {978, 979}, {980, 981}, {982, 983}, {984, 985}, {986, 987}, {988, 989}, {990, 991}, {992, 993}, {994, 995}, {996, 997}, {998, 999}, {1000, 1001}, {1002, 1003}, {1004, 1005}, {1006, 1007} }
    , { {1008, 1009}, {1010, 1011}, {1012, 1013}, {1014, 1015}, {1016, 1017}, {1018, 1019}, {1020, 1021}, {1022, 1023}, {1024, 1025}, {1026, 1027}, {1028, 1029}, {1030, 1031}, {1032, 1033}, {1034, 1035}, {1036, 1037}, {1038, 1039}, {1040, 1041}, {1042, 1043}, {1044, 1045}, {1046, 1047}, {1048, 1049}, {1050, 1051}, {1052, 1053}, {1054, 1055} }
    , { {1056, 1057}, {1058, 1059}, {1060, 1061}, {1062, 1063}, {1064, 1065}, {1066, 1067}, {1068, 1069}, {1070, 1071}, {1072, 1073}, {1074, 1075}, {1076, 1077}, {1078, 1079}, {1080, 1081}, {1082, 1083}, {1084, 1085}, {1086, 1087}, {1088, 1089}, {1090, 1091}, {1092, 1093}, {1094, 1095}, {1096, 1097}, {1098, 1099}, {1100, 1101}, {1102, 1103} }
    , { {1104, 1105}, {1106, 1107}, {1108, 1109}, {1110, 1111}, {1112, 1113}, {1114, 1115}, {1116, 1117}, {1118, 1119}, {1120, 1121}, {1122, 1123}, {1124, 1125}, {1126, 1127}, {1128, 1129}, {1130, 1131}, {1132, 1133}, {1134, 1135}, {1136, 1137}, {1138, 1139}, {1140, 1141}, {1142, 1143}, {1144, 1145}, {1146, 1147}, {1148, 1149}, {1150, 1151} }
};


static npy_intp two_qbit_vops_after_CZ[1152][3] = 
{
    {0, 0, 0}
    , {2, 2, 0}
    , {0, 1, 0}
    , {0, 8, 1}
    , {0, 2, 0}
    , {0, 5, 1}
    , {0, 0, 0}
    , {2, 1, 0}
    , {0, 4, 0}
    , {1, 2, 0}
    , {0, 5, 0}
    , {0, 2, 1}
    , {0, 2, 0}
    , {1, 1, 0}
    , {0, 7, 0}
    , {5, 2, 0}
    , {0, 8, 0}
    , {0, 1, 1}
    , {0, 7, 0}
    , {5, 1, 0}
    , {0, 1, 0}
    , {8, 2, 0}
    , {0, 5, 0}
    , {8, 1, 0}
    , {0, 2, 0}
    , {8, 8, 0}
    , {0, 0, 0}
    , {2, 5, 0}
    , {0, 2, 0}
    , {0, 14, 1}
    , {0, 0, 0}
    , {2, 8, 0}
    , {0, 1, 0}
    , {0, 16, 1}
    , {0, 1, 0}
    , {1, 5, 0}
    , {0, 4, 0}
    , {0, 18, 1}
    , {0, 5, 0}
    , {1, 8, 0}
    , {0, 7, 0}
    , {5, 5, 0}
    , {0, 5, 0}
    , {0, 21, 1}
    , {0, 7, 0}
    , {5, 8, 0}
    , {0, 4, 0}
    , {8, 5, 0}
    , {1, 0, 0}
    , {1, 13, 1}
    , {1, 1, 1}
    , {1, 1, 0}
    , {1, 2, 1}
    , {1, 2, 0}
    , {1, 0, 0}
    , {1, 15, 1}
    , {1, 8, 1}
    , {2, 8, 0}
    , {1, 5, 1}
    , {1, 5, 0}
    , {1, 2, 1}
    , {2, 2, 0}
    , {8, 7, 0}
    , {1, 7, 1}
    , {1, 8, 1}
    , {1, 8, 0}
    , {8, 7, 0}
    , {1, 9, 1}
    , {1, 1, 1}
    , {5, 1, 0}
    , {1, 5, 1}
    , {5, 5, 0}
    , {1, 2, 1}
    , {5, 2, 0}
    , {1, 0, 0}
    , {1, 0, 1}
    , {1, 2, 1}
    , {8, 2, 0}
    , {1, 0, 0}
    , {1, 3, 1}
    , {1, 1, 1}
    , {8, 1, 0}
    , {1, 1, 1}
    , {2, 1, 0}
    , {1, 8, 1}
    , {8, 8, 0}
    , {1, 5, 1}
    , {2, 5, 0}
    , {8, 7, 0}
    , {1, 20, 1}
    , {1, 5, 1}
    , {8, 5, 0}
    , {8, 7, 0}
    , {1, 22, 1}
    , {1, 8, 1}
    , {5, 8, 0}
    , {2, 0, 0}
    , {1, 3, 1}
    , {2, 1, 1}
    , {2, 1, 0}
    , {2, 2, 1}
    , {2, 2, 0}
    , {2, 0, 0}
    , {1, 13, 1}
    , {2, 8, 1}
    , {8, 8, 0}
    , {2, 5, 1}
    , {2, 5, 0}
    , {2, 2, 1}
    , {8, 2, 0}
    , {5, 7, 0}
    , {1, 9, 1}
    , {2, 8, 1}
    , {2, 8, 0}
    , {5, 7, 0}
    , {1, 20, 1}
    , {2, 1, 1}
    , {1, 1, 0}
    , {2, 5, 1}
    , {1, 5, 0}
    , {2, 2, 1}
    , {1, 2, 0}
    , {2, 0, 0}
    , {1, 15, 1}
    , {2, 2, 1}
    , {5, 2, 0}
    , {2, 0, 0}
    , {1, 0, 1}
    , {2, 1, 1}
    , {5, 1, 0}
    , {2, 1, 1}
    , {8, 1, 0}
    , {2, 8, 1}
    , {5, 8, 0}
    , {2, 5, 1}
    , {8, 5, 0}
    , {5, 7, 0}
    , {1, 22, 1}
    , {2, 5, 1}
    , {5, 5, 0}
    , {5, 7, 0}
    , {1, 7, 1}
    , {2, 8, 1}
    , {1, 8, 0}
    , {0, 0, 0}
    , {1, 2, 0}
    , {0, 1, 0}
    , {0, 2, 1}
    , {0, 2, 0}
    , {0, 8, 1}
    , {0, 0, 0}
    , {1, 1, 0}
    , {0, 4, 0}
    , {5, 2, 0}
    , {0, 5, 0}
    , {0, 1, 1}
    , {0, 2, 0}
    , {5, 1, 0}
    , {0, 7, 0}
    , {8, 2, 0}
    , {0, 8, 0}
    , {0, 5, 1}
    , {0, 7, 0}
    , {8, 1, 0}
    , {0, 1, 0}
    , {2, 2, 0}
    , {0, 5, 0}
    , {2, 1, 0}
    , {0, 2, 0}
    , {2, 8, 0}
    , {0, 0, 0}
    , {1, 5, 0}
    , {0, 2, 0}
    , {0, 18, 1}
    , {0, 0, 0}
    , {1, 8, 0}
    , {0, 1, 0}
    , {0, 14, 1}
    , {0, 1, 0}
    , {5, 5, 0}
    , {0, 4, 0}
    , {0, 21, 1}
    , {0, 5, 0}
    , {5, 8, 0}
    , {0, 7, 0}
    , {8, 5, 0}
    , {0, 5, 0}
    , {0, 16, 1}
    , {0, 7, 0}
    , {8, 8, 0}
    , {0, 4, 0}
    , {2, 5, 0}
    , {4, 0, 0}
    , {2, 1, 0}
    , {8, 1, 1}
    , {8, 2, 0}
    , {8, 2, 1}
    , {8, 8, 0}
    , {4, 0, 0}
    , {2, 5, 0}
    , {8, 8, 1}
    , {0, 1, 1}
    , {8, 5, 1}
    , {8, 1, 0}
    , {8, 2, 1}
    , {0, 5, 1}
    , {1, 7, 0}
    , {5, 8, 0}
    , {8, 8, 1}
    , {8, 5, 0}
    , {1, 7, 0}
    , {5, 2, 0}
    , {8, 1, 1}
    , {0, 16, 1}
    , {8, 5, 1}
    , {0, 21, 1}
    , {8, 2, 1}
    , {0, 14, 1}
    , {4, 0, 0}
    , {2, 8, 0}
    , {8, 2, 1}
    , {1, 1, 0}
    , {4, 0, 0}
    , {2, 2, 0}
    , {8, 1, 1}
    , {1, 5, 0}
    , {8, 1, 1}
    , {0, 8, 1}
    , {8, 8, 1}
    , {1, 2, 0}
    , {8, 5, 1}
    , {0, 2, 1}
    , {1, 7, 0}
    , {5, 1, 0}
    , {8, 5, 1}
    , {1, 8, 0}
    , {1, 7, 0}
    , {5, 5, 0}
    , {8, 8, 1}
    , {0, 18, 1}
    , {5, 0, 0}
    , {1, 15, 1}
    , {5, 1, 1}
    , {5, 1, 0}
    , {5, 2, 1}
    , {5, 2, 0}
    , {5, 0, 0}
    , {1, 0, 1}
    , {5, 8, 1}
    , {1, 8, 0}
    , {5, 5, 1}
    , {5, 5, 0}
    , {5, 2, 1}
    , {1, 2, 0}
    , {2, 7, 0}
    , {1, 22, 1}
    , {5, 8, 1}
    , {5, 8, 0}
    , {2, 7, 0}
    , {1, 7, 1}
    , {5, 1, 1}
    , {8, 1, 0}
    , {5, 5, 1}
    , {8, 5, 0}
    , {5, 2, 1}
    , {8, 2, 0}
    , {5, 0, 0}
    , {1, 3, 1}
    , {5, 2, 1}
    , {2, 2, 0}
    , {5, 0, 0}
    , {1, 13, 1}
    , {5, 1, 1}
    , {2, 1, 0}
    , {5, 1, 1}
    , {1, 1, 0}
    , {5, 8, 1}
    , {2, 8, 0}
    , {5, 5, 1}
    , {1, 5, 0}
    , {2, 7, 0}
    , {1, 9, 1}
    , {5, 5, 1}
    , {2, 5, 0}
    , {2, 7, 0}
    , {1, 20, 1}
    , {5, 8, 1}
    , {8, 8, 0}
    , {2, 0, 0}
    , {1, 1, 0}
    , {2, 1, 1}
    , {2, 2, 0}
    , {2, 2, 1}
    , {2, 8, 0}
    , {2, 0, 0}
    , {1, 5, 0}
    , {2, 8, 1}
    , {0, 5, 1}
    , {2, 5, 1}
    , {2, 1, 0}
    , {2, 2, 1}
    , {0, 8, 1}
    , {5, 7, 0}
    , {8, 8, 0}
    , {2, 8, 1}
    , {2, 5, 0}
    , {5, 7, 0}
    , {8, 2, 0}
    , {2, 1, 1}
    , {0, 14, 1}
    , {2, 5, 1}
    , {0, 16, 1}
    , {2, 2, 1}
    , {0, 18, 1}
    , {2, 0, 0}
    , {1, 8, 0}
    , {2, 2, 1}
    , {5, 1, 0}
    , {2, 0, 0}
    , {1, 2, 0}
    , {2, 1, 1}
    , {5, 5, 0}
    , {2, 1, 1}
    , {0, 2, 1}
    , {2, 8, 1}
    , {5, 2, 0}
    , {2, 5, 1}
    , {0, 1, 1}
    , {5, 7, 0}
    , {8, 1, 0}
    , {2, 5, 1}
    , {5, 8, 0}
    , {5, 7, 0}
    , {8, 5, 0}
    , {2, 8, 1}
    , {0, 21, 1}
    , {7, 0, 0}
    , {2, 5, 0}
    , {7, 8, 0}
    , {7, 1, 1}
    , {7, 5, 0}
    , {7, 2, 1}
    , {7, 0, 0}
    , {2, 8, 0}
    , {7, 1, 0}
    , {8, 5, 0}
    , {7, 2, 0}
    , {7, 5, 1}
    , {7, 5, 0}
    , {8, 8, 0}
    , {7, 7, 0}
    , {5, 5, 0}
    , {7, 1, 0}
    , {7, 8, 1}
    , {7, 7, 0}
    , {5, 8, 0}
    , {7, 4, 0}
    , {1, 5, 0}
    , {7, 2, 0}
    , {1, 8, 0}
    , {7, 5, 0}
    , {1, 1, 0}
    , {7, 0, 0}
    , {2, 2, 0}
    , {7, 5, 0}
    , {0, 5, 1}
    , {7, 0, 0}
    , {2, 1, 0}
    , {7, 4, 0}
    , {0, 8, 1}
    , {7, 4, 0}
    , {8, 2, 0}
    , {7, 1, 0}
    , {0, 1, 1}
    , {7, 2, 0}
    , {8, 1, 0}
    , {7, 7, 0}
    , {5, 2, 0}
    , {7, 2, 0}
    , {0, 2, 1}
    , {7, 7, 0}
    , {5, 1, 0}
    , {7, 1, 0}
    , {1, 2, 0}
    , {8, 0, 0}
    , {1, 0, 1}
    , {8, 1, 1}
    , {8, 1, 0}
    , {8, 2, 1}
    , {8, 2, 0}
    , {8, 0, 0}
    , {1, 3, 1}
    , {8, 8, 1}
    , {5, 8, 0}
    , {8, 5, 1}
    , {8, 5, 0}
    , {8, 2, 1}
    , {5, 2, 0}
    , {1, 7, 0}
    , {1, 20, 1}
    , {8, 8, 1}
    , {8, 8, 0}
    , {1, 7, 0}
    , {1, 22, 1}
    , {8, 1, 1}
    , {2, 1, 0}
    , {8, 5, 1}
    , {2, 5, 0}
    , {8, 2, 1}
    , {2, 2, 0}
    , {8, 0, 0}
    , {1, 13, 1}
    , {8, 2, 1}
    , {1, 2, 0}
    , {8, 0, 0}
    , {1, 15, 1}
    , {8, 1, 1}
    , {1, 1, 0}
    , {8, 1, 1}
    , {5, 1, 0}
    , {8, 8, 1}
    , {1, 8, 0}
    , {8, 5, 1}
    , {5, 5, 0}
    , {1, 7, 0}
    , {1, 7, 1}
    , {8, 5, 1}
    , {1, 5, 0}
    , {1, 7, 0}
    , {1, 9, 1}
    , {8, 8, 1}
    , {2, 8, 0}
    , {7, 0, 0}
    , {1, 5, 0}
    , {7, 8, 0}
    , {7, 2, 1}
    , {7, 5, 0}
    , {7, 8, 1}
    , {7, 0, 0}
    , {1, 8, 0}
    , {7, 1, 0}
    , {2, 5, 0}
    , {7, 2, 0}
    , {7, 1, 1}
    , {7, 5, 0}
    , {2, 8, 0}
    , {7, 7, 0}
    , {8, 5, 0}
    , {7, 1, 0}
    , {7, 5, 1}
    , {7, 7, 0}
    , {8, 8, 0}
    , {7, 4, 0}
    , {5, 5, 0}
    , {7, 2, 0}
    , {5, 8, 0}
    , {7, 5, 0}
    , {5, 1, 0}
    , {7, 0, 0}
    , {1, 2, 0}
    , {7, 5, 0}
    , {0, 8, 1}
    , {7, 0, 0}
    , {1, 1, 0}
    , {7, 4, 0}
    , {0, 2, 1}
    , {7, 4, 0}
    , {2, 2, 0}
    , {7, 1, 0}
    , {0, 5, 1}
    , {7, 2, 0}
    , {2, 1, 0}
    , {7, 7, 0}
    , {8, 2, 0}
    , {7, 2, 0}
    , {0, 1, 1}
    , {7, 7, 0}
    , {8, 1, 0}
    , {7, 1, 0}
    , {5, 2, 0}
    , {1, 0, 0}
    , {2, 8, 0}
    , {1, 1, 1}
    , {1, 5, 0}
    , {1, 2, 1}
    , {1, 1, 0}
    , {1, 0, 0}
    , {2, 2, 0}
    , {1, 8, 1}
    , {0, 18, 1}
    , {1, 5, 1}
    , {1, 8, 0}
    , {1, 2, 1}
    , {0, 14, 1}
    , {4, 7, 0}
    , {5, 1, 0}
    , {1, 8, 1}
    , {1, 2, 0}
    , {4, 7, 0}
    , {5, 5, 0}
    , {1, 1, 1}
    , {0, 8, 1}
    , {1, 5, 1}
    , {0, 2, 1}
    , {1, 2, 1}
    , {0, 5, 1}
    , {1, 0, 0}
    , {2, 1, 0}
    , {1, 2, 1}
    , {8, 8, 0}
    , {1, 0, 0}
    , {2, 5, 0}
    , {1, 1, 1}
    , {8, 2, 0}
    , {1, 1, 1}
    , {0, 16, 1}
    , {1, 8, 1}
    , {8, 5, 0}
    , {1, 5, 1}
    , {0, 21, 1}
    , {4, 7, 0}
    , {5, 8, 0}
    , {1, 5, 1}
    , {8, 1, 0}
    , {4, 7, 0}
    , {5, 2, 0}
    , {1, 8, 1}
    , {0, 1, 1}
    , {5, 0, 0}
    , {1, 8, 0}
    , {5, 1, 1}
    , {5, 5, 0}
    , {5, 2, 1}
    , {5, 1, 0}
    , {5, 0, 0}
    , {1, 2, 0}
    , {5, 8, 1}
    , {0, 21, 1}
    , {5, 5, 1}
    , {5, 8, 0}
    , {5, 2, 1}
    , {0, 18, 1}
    , {2, 7, 0}
    , {8, 1, 0}
    , {5, 8, 1}
    , {5, 2, 0}
    , {2, 7, 0}
    , {8, 5, 0}
    , {5, 1, 1}
    , {0, 2, 1}
    , {5, 5, 1}
    , {0, 1, 1}
    , {5, 2, 1}
    , {0, 8, 1}
    , {5, 0, 0}
    , {1, 1, 0}
    , {5, 2, 1}
    , {2, 8, 0}
    , {5, 0, 0}
    , {1, 5, 0}
    , {5, 1, 1}
    , {2, 2, 0}
    , {5, 1, 1}
    , {0, 14, 1}
    , {5, 8, 1}
    , {2, 5, 0}
    , {5, 5, 1}
    , {0, 16, 1}
    , {2, 7, 0}
    , {8, 8, 0}
    , {5, 5, 1}
    , {2, 1, 0}
    , {2, 7, 0}
    , {8, 2, 0}
    , {5, 8, 1}
    , {0, 5, 1}
    , {2, 0, 0}
    , {8, 8, 0}
    , {2, 1, 1}
    , {2, 5, 0}
    , {2, 2, 1}
    , {2, 1, 0}
    , {2, 0, 0}
    , {8, 2, 0}
    , {2, 8, 1}
    , {0, 14, 1}
    , {2, 5, 1}
    , {2, 8, 0}
    , {2, 2, 1}
    , {0, 16, 1}
    , {5, 7, 0}
    , {1, 1, 0}
    , {2, 8, 1}
    , {2, 2, 0}
    , {5, 7, 0}
    , {1, 5, 0}
    , {2, 1, 1}
    , {0, 5, 1}
    , {2, 5, 1}
    , {0, 8, 1}
    , {2, 2, 1}
    , {0, 1, 1}
    , {2, 0, 0}
    , {8, 1, 0}
    , {2, 2, 1}
    , {5, 8, 0}
    , {2, 0, 0}
    , {8, 5, 0}
    , {2, 1, 1}
    , {5, 2, 0}
    , {2, 1, 1}
    , {0, 21, 1}
    , {2, 8, 1}
    , {5, 5, 0}
    , {2, 5, 1}
    , {0, 18, 1}
    , {5, 7, 0}
    , {1, 8, 0}
    , {2, 5, 1}
    , {5, 1, 0}
    , {5, 7, 0}
    , {1, 2, 0}
    , {2, 8, 1}
    , {0, 2, 1}
    , {0, 0, 0}
    , {5, 2, 0}
    , {0, 1, 0}
    , {0, 1, 1}
    , {0, 2, 0}
    , {0, 2, 1}
    , {0, 0, 0}
    , {5, 1, 0}
    , {0, 4, 0}
    , {8, 2, 0}
    , {0, 5, 0}
    , {0, 5, 1}
    , {0, 2, 0}
    , {8, 1, 0}
    , {0, 7, 0}
    , {2, 2, 0}
    , {0, 8, 0}
    , {0, 8, 1}
    , {0, 7, 0}
    , {2, 1, 0}
    , {0, 1, 0}
    , {1, 2, 0}
    , {0, 5, 0}
    , {1, 1, 0}
    , {0, 2, 0}
    , {1, 8, 0}
    , {0, 0, 0}
    , {5, 5, 0}
    , {0, 2, 0}
    , {0, 21, 1}
    , {0, 0, 0}
    , {5, 8, 0}
    , {0, 1, 0}
    , {0, 18, 1}
    , {0, 1, 0}
    , {8, 5, 0}
    , {0, 4, 0}
    , {0, 16, 1}
    , {0, 5, 0}
    , {8, 8, 0}
    , {0, 7, 0}
    , {2, 5, 0}
    , {0, 5, 0}
    , {0, 14, 1}
    , {0, 7, 0}
    , {2, 8, 0}
    , {0, 4, 0}
    , {1, 5, 0}
    , {2, 0, 0}
    , {0, 14, 1}
    , {2, 1, 1}
    , {2, 8, 0}
    , {2, 2, 1}
    , {2, 5, 0}
    , {2, 0, 0}
    , {0, 16, 1}
    , {2, 8, 1}
    , {1, 1, 0}
    , {2, 5, 1}
    , {2, 2, 0}
    , {2, 2, 1}
    , {1, 5, 0}
    , {5, 7, 0}
    , {0, 5, 1}
    , {2, 8, 1}
    , {2, 1, 0}
    , {5, 7, 0}
    , {0, 8, 1}
    , {2, 1, 1}
    , {8, 8, 0}
    , {2, 5, 1}
    , {8, 2, 0}
    , {2, 2, 1}
    , {8, 5, 0}
    , {2, 0, 0}
    , {0, 21, 1}
    , {2, 2, 1}
    , {5, 5, 0}
    , {2, 0, 0}
    , {0, 18, 1}
    , {2, 1, 1}
    , {5, 8, 0}
    , {2, 1, 1}
    , {1, 8, 0}
    , {2, 8, 1}
    , {5, 1, 0}
    , {2, 5, 1}
    , {1, 2, 0}
    , {5, 7, 0}
    , {0, 2, 1}
    , {2, 5, 1}
    , {5, 2, 0}
    , {5, 7, 0}
    , {0, 1, 1}
    , {2, 8, 1}
    , {8, 1, 0}
    , {0, 0, 0}
    , {8, 2, 0}
    , {0, 1, 0}
    , {0, 5, 1}
    , {0, 2, 0}
    , {0, 1, 1}
    , {0, 0, 0}
    , {8, 1, 0}
    , {0, 4, 0}
    , {2, 2, 0}
    , {0, 5, 0}
    , {0, 8, 1}
    , {0, 2, 0}
    , {2, 1, 0}
    , {0, 7, 0}
    , {1, 2, 0}
    , {0, 8, 0}
    , {0, 2, 1}
    , {0, 7, 0}
    , {1, 1, 0}
    , {0, 1, 0}
    , {5, 2, 0}
    , {0, 5, 0}
    , {5, 1, 0}
    , {0, 2, 0}
    , {5, 8, 0}
    , {0, 0, 0}
    , {8, 5, 0}
    , {0, 2, 0}
    , {0, 16, 1}
    , {0, 0, 0}
    , {8, 8, 0}
    , {0, 1, 0}
    , {0, 21, 1}
    , {0, 1, 0}
    , {2, 5, 0}
    , {0, 4, 0}
    , {0, 14, 1}
    , {0, 5, 0}
    , {2, 8, 0}
    , {0, 7, 0}
    , {1, 5, 0}
    , {0, 5, 0}
    , {0, 18, 1}
    , {0, 7, 0}
    , {1, 8, 0}
    , {0, 4, 0}
    , {5, 5, 0}
    , {1, 0, 0}
    , {0, 18, 1}
    , {1, 1, 1}
    , {1, 8, 0}
    , {1, 2, 1}
    , {1, 5, 0}
    , {1, 0, 0}
    , {0, 14, 1}
    , {1, 8, 1}
    , {5, 1, 0}
    , {1, 5, 1}
    , {1, 2, 0}
    , {1, 2, 1}
    , {5, 5, 0}
    , {4, 7, 0}
    , {0, 8, 1}
    , {1, 8, 1}
    , {1, 1, 0}
    , {4, 7, 0}
    , {0, 2, 1}
    , {1, 1, 1}
    , {2, 8, 0}
    , {1, 5, 1}
    , {2, 2, 0}
    , {1, 2, 1}
    , {2, 5, 0}
    , {1, 0, 0}
    , {0, 16, 1}
    , {1, 2, 1}
    , {8, 5, 0}
    , {1, 0, 0}
    , {0, 21, 1}
    , {1, 1, 1}
    , {8, 8, 0}
    , {1, 1, 1}
    , {5, 8, 0}
    , {1, 8, 1}
    , {8, 1, 0}
    , {1, 5, 1}
    , {5, 2, 0}
    , {4, 7, 0}
    , {0, 1, 1}
    , {1, 5, 1}
    , {8, 2, 0}
    , {4, 7, 0}
    , {0, 5, 1}
    , {1, 8, 1}
    , {2, 1, 0}
    , {1, 0, 0}
    , {5, 1, 0}
    , {1, 1, 1}
    , {1, 2, 0}
    , {1, 2, 1}
    , {1, 8, 0}
    , {1, 0, 0}
    , {5, 5, 0}
    , {1, 8, 1}
    , {0, 8, 1}
    , {1, 5, 1}
    , {1, 1, 0}
    , {1, 2, 1}
    , {0, 2, 1}
    , {4, 7, 0}
    , {2, 8, 0}
    , {1, 8, 1}
    , {1, 5, 0}
    , {4, 7, 0}
    , {2, 2, 0}
    , {1, 1, 1}
    , {0, 18, 1}
    , {1, 5, 1}
    , {0, 14, 1}
    , {1, 2, 1}
    , {0, 21, 1}
    , {1, 0, 0}
    , {5, 8, 0}
    , {1, 2, 1}
    , {8, 1, 0}
    , {1, 0, 0}
    , {5, 2, 0}
    , {1, 1, 1}
    , {8, 5, 0}
    , {1, 1, 1}
    , {0, 1, 1}
    , {1, 8, 1}
    , {8, 2, 0}
    , {1, 5, 1}
    , {0, 5, 1}
    , {4, 7, 0}
    , {2, 1, 0}
    , {1, 5, 1}
    , {8, 8, 0}
    , {4, 7, 0}
    , {2, 5, 0}
    , {1, 8, 1}
    , {0, 16, 1}
    , {4, 0, 0}
    , {0, 16, 1}
    , {8, 1, 1}
    , {8, 8, 0}
    , {8, 2, 1}
    , {8, 5, 0}
    , {4, 0, 0}
    , {0, 21, 1}
    , {8, 8, 1}
    , {2, 1, 0}
    , {8, 5, 1}
    , {8, 2, 0}
    , {8, 2, 1}
    , {2, 5, 0}
    , {1, 7, 0}
    , {0, 1, 1}
    , {8, 8, 1}
    , {8, 1, 0}
    , {1, 7, 0}
    , {0, 5, 1}
    , {8, 1, 1}
    , {5, 8, 0}
    , {8, 5, 1}
    , {5, 2, 0}
    , {8, 2, 1}
    , {5, 5, 0}
    , {4, 0, 0}
    , {0, 18, 1}
    , {8, 2, 1}
    , {1, 5, 0}
    , {4, 0, 0}
    , {0, 14, 1}
    , {8, 1, 1}
    , {1, 8, 0}
    , {8, 1, 1}
    , {2, 8, 0}
    , {8, 8, 1}
    , {1, 1, 0}
    , {8, 5, 1}
    , {2, 2, 0}
    , {1, 7, 0}
    , {0, 8, 1}
    , {8, 5, 1}
    , {1, 2, 0}
    , {1, 7, 0}
    , {0, 2, 1}
    , {8, 8, 1}
    , {5, 1, 0}
    , {5, 0, 0}
    , {8, 1, 0}
    , {5, 1, 1}
    , {5, 2, 0}
    , {5, 2, 1}
    , {5, 8, 0}
    , {5, 0, 0}
    , {8, 5, 0}
    , {5, 8, 1}
    , {0, 2, 1}
    , {5, 5, 1}
    , {5, 1, 0}
    , {5, 2, 1}
    , {0, 1, 1}
    , {2, 7, 0}
    , {1, 8, 0}
    , {5, 8, 1}
    , {5, 5, 0}
    , {2, 7, 0}
    , {1, 2, 0}
    , {5, 1, 1}
    , {0, 21, 1}
    , {5, 5, 1}
    , {0, 18, 1}
    , {5, 2, 1}
    , {0, 16, 1}
    , {5, 0, 0}
    , {8, 8, 0}
    , {5, 2, 1}
    , {2, 1, 0}
    , {5, 0, 0}
    , {8, 2, 0}
    , {5, 1, 1}
    , {2, 5, 0}
    , {5, 1, 1}
    , {0, 5, 1}
    , {5, 8, 1}
    , {2, 2, 0}
    , {5, 5, 1}
    , {0, 8, 1}
    , {2, 7, 0}
    , {1, 1, 0}
    , {5, 5, 1}
    , {2, 8, 0}
    , {2, 7, 0}
    , {1, 5, 0}
    , {5, 8, 1}
    , {0, 14, 1}
    , {7, 0, 0}
    , {5, 5, 0}
    , {7, 8, 0}
    , {7, 8, 1}
    , {7, 5, 0}
    , {7, 5, 1}
    , {7, 0, 0}
    , {5, 8, 0}
    , {7, 1, 0}
    , {1, 5, 0}
    , {7, 2, 0}
    , {7, 2, 1}
    , {7, 5, 0}
    , {1, 8, 0}
    , {7, 7, 0}
    , {2, 5, 0}
    , {7, 1, 0}
    , {7, 1, 1}
    , {7, 7, 0}
    , {2, 8, 0}
    , {7, 4, 0}
    , {8, 5, 0}
    , {7, 2, 0}
    , {8, 8, 0}
    , {7, 5, 0}
    , {8, 1, 0}
    , {7, 0, 0}
    , {5, 2, 0}
    , {7, 5, 0}
    , {0, 2, 1}
    , {7, 0, 0}
    , {5, 1, 0}
    , {7, 4, 0}
    , {0, 1, 1}
    , {7, 4, 0}
    , {1, 2, 0}
    , {7, 1, 0}
    , {0, 8, 1}
    , {7, 2, 0}
    , {1, 1, 0}
    , {7, 7, 0}
    , {2, 2, 0}
    , {7, 2, 0}
    , {0, 5, 1}
    , {7, 7, 0}
    , {2, 1, 0}
    , {7, 1, 0}
    , {8, 2, 0}
    , {5, 0, 0}
    , {0, 21, 1}
    , {5, 1, 1}
    , {5, 8, 0}
    , {5, 2, 1}
    , {5, 5, 0}
    , {5, 0, 0}
    , {0, 18, 1}
    , {5, 8, 1}
    , {8, 1, 0}
    , {5, 5, 1}
    , {5, 2, 0}
    , {5, 2, 1}
    , {8, 5, 0}
    , {2, 7, 0}
    , {0, 2, 1}
    , {5, 8, 1}
    , {5, 1, 0}
    , {2, 7, 0}
    , {0, 1, 1}
    , {5, 1, 1}
    , {1, 8, 0}
    , {5, 5, 1}
    , {1, 2, 0}
    , {5, 2, 1}
    , {1, 5, 0}
    , {5, 0, 0}
    , {0, 14, 1}
    , {5, 2, 1}
    , {2, 5, 0}
    , {5, 0, 0}
    , {0, 16, 1}
    , {5, 1, 1}
    , {2, 8, 0}
    , {5, 1, 1}
    , {8, 8, 0}
    , {5, 8, 1}
    , {2, 1, 0}
    , {5, 5, 1}
    , {8, 2, 0}
    , {2, 7, 0}
    , {0, 5, 1}
    , {5, 5, 1}
    , {2, 2, 0}
    , {2, 7, 0}
    , {0, 8, 1}
    , {5, 8, 1}
    , {1, 1, 0}
    , {7, 0, 0}
    , {8, 5, 0}
    , {7, 8, 0}
    , {7, 5, 1}
    , {7, 5, 0}
    , {7, 1, 1}
    , {7, 0, 0}
    , {8, 8, 0}
    , {7, 1, 0}
    , {5, 5, 0}
    , {7, 2, 0}
    , {7, 8, 1}
    , {7, 5, 0}
    , {5, 8, 0}
    , {7, 7, 0}
    , {1, 5, 0}
    , {7, 1, 0}
    , {7, 2, 1}
    , {7, 7, 0}
    , {1, 8, 0}
    , {7, 4, 0}
    , {2, 5, 0}
    , {7, 2, 0}
    , {2, 8, 0}
    , {7, 5, 0}
    , {2, 1, 0}
    , {7, 0, 0}
    , {8, 2, 0}
    , {7, 5, 0}
    , {0, 1, 1}
    , {7, 0, 0}
    , {8, 1, 0}
    , {7, 4, 0}
    , {0, 5, 1}
    , {7, 4, 0}
    , {5, 2, 0}
    , {7, 1, 0}
    , {0, 2, 1}
    , {7, 2, 0}
    , {5, 1, 0}
    , {7, 7, 0}
    , {1, 2, 0}
    , {7, 2, 0}
    , {0, 8, 1}
    , {7, 7, 0}
    , {1, 1, 0}
    , {7, 1, 0}
    , {2, 2, 0}
    , {4, 0, 0}
    , {5, 8, 0}
    , {8, 1, 1}
    , {8, 5, 0}
    , {8, 2, 1}
    , {8, 1, 0}
    , {4, 0, 0}
    , {5, 2, 0}
    , {8, 8, 1}
    , {0, 16, 1}
    , {8, 5, 1}
    , {8, 8, 0}
    , {8, 2, 1}
    , {0, 21, 1}
    , {1, 7, 0}
    , {2, 1, 0}
    , {8, 8, 1}
    , {8, 2, 0}
    , {1, 7, 0}
    , {2, 5, 0}
    , {8, 1, 1}
    , {0, 1, 1}
    , {8, 5, 1}
    , {0, 5, 1}
    , {8, 2, 1}
    , {0, 2, 1}
    , {4, 0, 0}
    , {5, 1, 0}
    , {8, 2, 1}
    , {1, 8, 0}
    , {4, 0, 0}
    , {5, 5, 0}
    , {8, 1, 1}
    , {1, 2, 0}
    , {8, 1, 1}
    , {0, 18, 1}
    , {8, 8, 1}
    , {1, 5, 0}
    , {8, 5, 1}
    , {0, 14, 1}
    , {1, 7, 0}
    , {2, 8, 0}
    , {8, 5, 1}
    , {1, 1, 0}
    , {1, 7, 0}
    , {2, 2, 0}
    , {8, 8, 1}
    , {0, 8, 1}
};

// C^\dagger Z C is one of the following matrices.
// Index is the index of [Z, Y, X, -Z, -Y, -X].
static npy_uint8 observable_after_vop_commute[6][24] =
{
    {2, 0, 0, 2, 4, 0, 4, 5, 0, 5, 1, 1, 1, 2, 3, 2, 3, 4, 3, 4, 5, 3, 5, 1}
    , {4, 2, 1, 0, 5, 4, 0, 1, 5, 0, 2, 0, 3, 1, 4, 3, 2, 2, 5, 3, 4, 1, 3, 5}
    , {0, 4, 2, 1, 0, 5, 2, 0, 1, 4, 0, 5, 2, 3, 2, 4, 1, 3, 4, 5, 3, 5, 1, 3}
    , {5, 3, 3, 5, 1, 3, 1, 2, 3, 2, 4, 4, 4, 5, 0, 5, 0, 1, 0, 1, 2, 0, 2, 4}
    , {1, 5, 4, 3, 2, 1, 3, 4, 2, 3, 5, 3, 0, 4, 1, 0, 5, 5, 2, 0, 1, 4, 0, 2}
    , {3, 1, 5, 4, 3, 2, 5, 3, 4, 1, 3, 2, 5, 0, 5, 1, 4, 0, 1, 2, 0, 2, 4, 0}
};

static npy_uint8 projected_vop[6] =
{0, 1, 2, 7, 18, 5};

static npy_uint8 daggered_vops[24] =
{ 0, 8, 2, 10, 15, 5, 12, 13, 1, 23, 3, 11, 6, 7, 14, 4, 16, 22, 18, 19, 20, 21, 17, 9};
#endif
