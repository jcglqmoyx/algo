cmake_minimum_required(VERSION 3.25)
project(algo)

set(CMAKE_CXX_STANDARD 23)

add_executable(algo template.cpp oj/leetcode/algorithms/301-400/371-380/373/373.cpp oj/leetcode/algorithms/1501-1600/1511-1520/1514/1514.cpp oj/leetcode/algorithms/1601-1700/1681-1690/1681/1681.cpp oj/leetcode/algorithms/1601-1700/1621-1630/1627/1627.cpp oj/leetcode/algorithms/801-900/861-870/864/864.cpp oj/leetcode/algorithms/1201-1300/1251-1260/1253/1253.cpp oj/leetcode/algorithms/1901-2000/1991-2000/1998/1998.cpp oj/leetcode/algorithms/2401-2500/2481-2490/2490/2490.cpp oj/leetcode/algorithms/1901-2000/1961-1970/1970/1970.cpp oj/leetcode/algorithms/2701-2800/2701-2710/2709/2709.cpp oj/leetcode/algorithms/1-100/1-10/1/1.cpp oj/leetcode/algorithms/2301-2400/2301-2310/2305/2305_1.cpp oj/leetcode/algorithms/2301-2400/2301-2310/2305/2305_2.cpp oj/leetcode/algorithms/201-300/201-210/204/204.cpp oj/leetcode/algorithms/1-100/1-10/2/2.cpp oj/leetcode/algorithms/1601-1700/1601-1610/1601/1601_1.cpp oj/leetcode/algorithms/1601-1700/1601-1610/1601/1601_2.cpp oj/leetcode/algorithms/2201-2300/2271-2280/2280/2280.cpp oj/leetcode/algorithms/2701-2800/2751-2760/2760/2760.cpp oj/leetcode/algorithms/2701-2800/2761-2770/2761/2761.cpp oj/leetcode/algorithms/2701-2800/2761-2770/2762/2762.cpp  oj/leetcode/algorithms/401-500/441-450/445/445_1.cpp oj/leetcode/algorithms/401-500/441-450/445/445_2.cpp oj/leetcode/algorithms/801-900/851-860/859/859.cpp oj/leetcode/algorithms/2501-2600/2511-2520/2514/2514.cpp oj/leetcode/algorithms/2601-2700/2671-2680/2679/2679.cpp oj/leetcode/algorithms/101-200/131-140/137/137_1.cpp oj/leetcode/algorithms/101-200/131-140/137/137_1.cpp oj/leetcode/algorithms/101-200/131-140/137/137_1.cpp oj/leetcode/algorithms/101-200/131-140/137/137_2.cpp oj/leetcode/algorithms/2501-2600/2591-2600/2600/2600.cpp oj/leetcode/algorithms/1401-1500/1491-1500/1493/1493.cpp oj/leetcode/algorithms/201-300/201-210/209/209.cpp oj/leetcode/algorithms/2101-2200/2171-2180/2178/2178.cpp oj/leetcode/algorithms/2601-2700/2601-2610/2607/2607.cpp oj/leetcode/algorithms/2001-2100/2021-2030/2024/2024.cpp oj/leetcode/algorithms/301-400/351-360/357/357_1.cpp "oj/leetcode/algorithms/301-400/351-360/357/357_2.cpp" oj/leetcode/algorithms/101-200/161-170/167/167.cpp oj/leetcode/algorithms/2301-2400/2371-2380/2376/2376_1.cpp oj/leetcode/algorithms/2301-2400/2371-2380/2376/2376_2.cpp oj/leetcode/algorithms/101-200/111-120/111/111.cpp oj/leetcode/algorithms/1-100/11-20/16/16.cpp oj/leetcode/algorithms/201-300/231-240/233/233.cpp oj/leetcode/algorithms/1901-2000/1911-1920/1911/1911.cpp oj/leetcode/algorithms/801-900/861-870/863/863.cpp oj/leetcode/algorithms/2501-2600/2541-2550/2544/2544_1.cpp oj/leetcode/algorithms/2501-2600/2541-2550/2544/2544_2.cpp oj/leetcode/algorithms/801-900/801-810/802/802_1.cpp oj/leetcode/algorithms/801-900/801-810/802/802_2.cpp oj/leetcode/algorithms/901-1000/901-910/902/902.cpp oj/leetcode/algorithms/901-1000/931-940/931/931.cpp oj/leetcode/algorithms/201-300/201-210/207/207.cpp oj/leetcode/algorithms/1-100/51-60/60/60.cpp oj/leetcode/algorithms/901-1000/971-980/979/979.cpp oj/leetcode/algorithms/1201-1300/1211-1220/1218/1218.cpp oj/leetcode/algorithms/2701-2800/2711-2720/2719/2719.cpp oj/leetcode/algorithms/1-100/11-20/18/18.cpp oj/leetcode/algorithms/1701-1800/1751-1760/1751/1751.cpp oj/leetcode/algorithms/901-1000/991-1000/992/992.cpp
        oj/leetcode/algorithms/401-500/411-420/415/415.cpp
        oj/leetcode/algorithms/2501-2600/2531-2540/2537/2537.cpp
        oj/leetcode/algorithms/101-200/141-150/146/146.cpp
        oj/leetcode/algorithms/801-900/871-880/874/874.cpp
        oj/leetcode/algorithms/401-500/431-440/435/435.cpp
        oj/leetcode/algorithms/2701-2800/2721-2730/2730/2730.cpp
        oj/leetcode/algorithms/901-1000/911-920/918/918.cpp
        oj/leetcode/algorithms/701-800/731-740/735/735.cpp
        oj/leetcode/algorithms/601-700/671-680/673/673_1.cpp
        oj/leetcode/algorithms/1401-1500/1491-1500/1499/1499.cpp
        oj/leetcode/algorithms/2701-2800/2741-2750/2747/2747.cpp
        oj/leetcode/algorithms/801-900/851-860/860/860.cpp
        oj/leetcode/algorithms/601-700/681-690/688/688.cpp
        oj/leetcode/algorithms/1501-1600/1501-1510/1503/1503.cpp
        oj/leetcode/algorithms/1-100/41-50/42/42.cpp
        oj/leetcode/algorithms/801-900/891-900/894/894.cpp
        oj/leetcode/algorithms/2701-2800/2731-2740/2731/2731.cpp
        oj/leetcode/algorithms/1-100/41-50/50/50.cpp oj/leetcode/algorithms/701-800/771-780/771/771.cpp oj/leetcode/algorithms/2201-2300/2211-2220/2211/2211_1.cpp oj/leetcode/algorithms/2201-2300/2211-2220/2211/2211_2.cpp oj/leetcode/algorithms/801-900/851-860/852/852.cpp oj/leetcode/algorithms/2201-2300/2201-2210/2208/2208.cpp oj/leetcode/algorithms/2201-2300/2261-2270/2269/2569.cpp oj/leetcode/algorithms/1801-1900/1861-1870/1870/1870.cpp oj/leetcode/algorithms/2701-2800/2751-2760/2751/2751.cpp)

