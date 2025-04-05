/***************************************************************************
 * Copyright (c) Wolf Vollprecht, Johan Mabille and Sylvain Corlay          *
 * Copyright (c) QuantStack                                                 *
 *                                                                          *
 * Distributed under the terms of the BSD 3-Clause License.                 *
 *                                                                          *
 * The full license is in the file LICENSE, distributed with this software. *
 ****************************************************************************/

// This file is generated from test/files/cppy_source/test_qr.cppy by
// preprocess.py!

#include <algorithm>

#include "xtensor/containers/xarray.hpp"
#include "xtensor/containers/xfixed.hpp"
#include "xtensor/containers/xtensor.hpp"
#include "xtensor/core/xnoalias.hpp"
#include "xtensor/views/xstrided_view.hpp"
#include "xtensor/views/xview.hpp"

#include "gtest/gtest.h"
#include "xtensor-blas/xlinalg.hpp"

namespace xt
{
    using namespace xt::placeholders;

    /*py
    a = np.random.random((6, 3))
    res_q1 = np.linalg.qr(a, 'raw')
    res_q2 = np.linalg.qr(a, 'complete')
    res_q3 = np.linalg.qr(a, 'reduced')
    res_q4 = np.linalg.qr(a, 'r')
    */
    TEST(xtest_extended, qr1)
    {
        // py_a
        xarray<double> py_a = {
            {0.3745401188473625, 0.9507143064099162, 0.7319939418114051},
            {0.5986584841970366, 0.1560186404424365, 0.1559945203362026},
            {0.0580836121681995, 0.8661761457749352, 0.6011150117432088},
            {0.7080725777960455, 0.0205844942958024, 0.9699098521619943},
            {0.8324426408004217, 0.2123391106782762, 0.1818249672071006},
            {0.1834045098534338, 0.3042422429595377, 0.5247564316322378}
        };
        // py_resq1_h = res_q1[0]
        xarray<double> py_resq1_h = {
            {-1.3152987216651169,
             0.3542695728401418,
             0.0343722790456067,
             0.4190178144924799,
             0.4926165861757361,
             0.1085337284576868},
            {-0.567877094797874,
             1.2223138676385652,
             -0.5073775633545011,
             0.3838046167052855,
             0.3339455785740943,
             -0.0869071101793681},
            {-1.0163710885529547,
             0.7215655008695085,
             0.7854784971183756,
             -0.8184018010449023,
             0.3355103841692941,
             -0.2743559826773574}
        };
        // py_resq1_tau = res_q1[1]
        xarray<double> py_resq1_tau = {1.2847566964660388, 1.3124991842889797, 1.0766465015522177};

        auto res1 = linalg::qr(py_a, linalg::qrmode::raw);
        EXPECT_TRUE(allclose(std::get<0>(res1), py_resq1_h));
        EXPECT_TRUE(allclose(std::get<1>(res1), py_resq1_tau));

        // py_resq2_q_cmpl = res_q2[0]
        xarray<double> py_resq2_q_cmpl = {
            {-0.2847566964660388,
             0.6455031901264903,
             -0.0295327810119745,
             -0.5849049416686276,
             -0.0730618203174815,
             -0.3923203408230155},
            {-0.4551502060605353,
             -0.0838170448559192,
             -0.3133472182914374,
             0.0819245453270295,
             -0.7892351407115685,
             0.2408791714587237},
            {-0.0441600156766425,
             0.6881200538051699,
             0.0760152664601146,
             0.7143224973945711,
             0.0235700722943727,
             0.0891638112668338},
            {-0.538335943107778,
             -0.2332659103773061,
             0.7525061466150679,
             0.1447692100263401,
             -0.0279639819291248,
             -0.2603378924852557},
            {-0.6328924578795164,
             -0.1203177215897514,
             -0.4769214096589269,
             0.1040507467269481,
             0.5878955555305321,
             0.0326957112268427},
            {-0.1394394344284399,
             0.1841243791750922,
             0.31850193596774,
             -0.3303532438685529,
             0.1575155429538277,
             0.8433664457979998}
        };
        // py_resq2_r_cmpl = res_q2[1]
        xarray<double> py_resq2_r_cmpl = {
            {-1.3152987216651169, -0.567877094797874, -1.0163710885529547},
            {0., 1.2223138676385652, 0.7215655008695085},
            {0., 0., 0.7854784971183756},
            {0., 0., 0.},
            {0., 0., 0.},
            {0., 0., 0.}
        };

        auto res2 = linalg::qr(py_a, linalg::qrmode::complete);
        EXPECT_TRUE(allclose(std::get<0>(res2), py_resq2_q_cmpl));
        EXPECT_TRUE(allclose(std::get<1>(res2), py_resq2_r_cmpl));

        // py_resq3_q_cmpl = res_q3[0]
        xarray<double> py_resq3_q_cmpl = {
            {-0.2847566964660388, 0.6455031901264903, -0.0295327810119745},
            {-0.4551502060605353, -0.0838170448559192, -0.3133472182914374},
            {-0.0441600156766425, 0.6881200538051699, 0.0760152664601146},
            {-0.538335943107778, -0.2332659103773061, 0.7525061466150679},
            {-0.6328924578795164, -0.1203177215897514, -0.4769214096589269},
            {-0.1394394344284399, 0.1841243791750922, 0.31850193596774}
        };
        // py_resq3_r_cmpl = res_q3[1]
        xarray<double> py_resq3_r_cmpl = {
            {-1.3152987216651169, -0.567877094797874, -1.0163710885529547},
            {0., 1.2223138676385652, 0.7215655008695085},
            {0., 0., 0.7854784971183756}
        };

        auto res3 = linalg::qr(py_a, linalg::qrmode::reduced);
        EXPECT_TRUE(allclose(std::get<0>(res3), py_resq3_q_cmpl));
        EXPECT_TRUE(allclose(std::get<1>(res3), py_resq3_r_cmpl));

        // py_resq4_r_r = res_q4
        xarray<double> py_resq4_r_r = {
            {-1.3152987216651169, -0.567877094797874, -1.0163710885529547},
            {0., 1.2223138676385652, 0.7215655008695085},
            {0., 0., 0.7854784971183756}
        };

        auto res4 = linalg::qr(py_a, linalg::qrmode::r);
        EXPECT_TRUE(allclose(std::get<1>(res4), py_resq4_r_r));
    }

    /*py
    a = np.random.random((5, 10))
    res_q1 = np.linalg.qr(a, 'raw')
    res_q2 = np.linalg.qr(a, 'complete')
    res_q3 = np.linalg.qr(a, 'reduced')
    res_q4 = np.linalg.qr(a, 'r')
    */
    TEST(xtest_extended, qr2)
    {
        // py_a
        xarray<double> py_a = {
            {0.4319450186421158,
             0.2912291401980419,
             0.6118528947223795,
             0.1394938606520418,
             0.2921446485352182,
             0.3663618432936917,
             0.4560699842170359,
             0.7851759613930136,
             0.1996737821583597,
             0.5142344384136116},
            {0.5924145688620425,
             0.0464504127199977,
             0.6075448519014384,
             0.1705241236872915,
             0.0650515929852795,
             0.9488855372533332,
             0.9656320330745594,
             0.8083973481164611,
             0.3046137691733707,
             0.0976721140063839},
            {0.6842330265121569,
             0.4401524937396013,
             0.1220382348447788,
             0.4951769101112702,
             0.0343885211152184,
             0.9093204020787821,
             0.2587799816000169,
             0.662522284353982,
             0.311711076089411,
             0.5200680211778108},
            {0.5467102793432796,
             0.184854455525527,
             0.9695846277645586,
             0.7751328233611146,
             0.9394989415641891,
             0.8948273504276488,
             0.5978999788110851,
             0.9218742350231168,
             0.0884925020519195,
             0.1959828624191452},
            {0.0452272889105381,
             0.3253303307632643,
             0.388677289689482,
             0.2713490317738959,
             0.8287375091519293,
             0.3567533266935893,
             0.2809345096873808,
             0.5426960831582485,
             0.1409242249747626,
             0.8021969807540397}
        };
        // py_resq1_h = res_q1[0]
        xarray<double> py_resq1_h = {
            {-1.1430852952870696, 0.3761289948662397, 0.4344253062693247, 0.3471109568548026, 0.0287151863113738},
            {-0.4988738747365853, 0.4145384440977922, -0.1456730968857621, 0.1343802288038163, -0.4549175132696516},
            {-1.0982282164248067, 0.0432498341745755, 0.8009723247566577, -0.2697221220857602, -0.2118640849148783},
            {-0.8189559577243967, 0.2159221672678357, 0.2467828455102148, -0.4358731022610104, 0.0126894274012747},
            {-0.6468222288756241, 0.5399745339753013, 0.9011434603476536, -0.3516828694145329, 0.1205612964483228},
            {-1.6166030169206462, 0.0627336303098124, 0.1745159258713335, -0.1676233275811677, 0.3369911999240203},
            {-1.1247642047094615, -0.1631138338388988, 0.4469666475320985, 0.229673631977487, 0.3155802843315489},
            {-1.5746170823854417, 0.2876936477590398, 0.5186696050660637, 0.0972324032495854, 0.1124970816045023},
            {-0.4678059691956431, 0.0924634343088705, -0.0398310260167535, 0.1199094213119632, 0.1189824829973467},
            {-0.6817147826175952, 0.8209704648352938, 0.1936105292921998, 0.1556371881989978, 0.1610633542281174}
        };
        // py_resq1_tau = res_q1[1]
        xarray<double> py_resq1_tau =
            {1.3778764545594464, 1.6048419481909388, 1.7894907284949315, 1.9996780087119976, 0.};

        auto res1 = linalg::qr(py_a, linalg::qrmode::raw);
        EXPECT_TRUE(allclose(std::get<0>(res1), py_resq1_h));
        EXPECT_TRUE(allclose(std::get<1>(res1), py_resq1_tau));
        // py_resq2_q_cmpl = res_q2[0]
        xarray<double> py_resq2_q_cmpl = {
            {-0.3778764545594464, 0.2477850983490842, 0.2323946032026168, 0.6442783657634198, -0.5715855718413764},
            {-0.5182592859033026, -0.5116427882060655, 0.0755411199296714, 0.3718390470559857, 0.5706647283090043},
            {-0.5985844007732788, 0.3414264138444295, -0.6868036045376356, -0.2311050279755064, 0.0039992397751236},
            {-0.4782760145698324, -0.1296501056095487, 0.5617369601749853, -0.6259003290333343, -0.217125009365484},
            {-0.0395659791067296, 0.737185903526121, 0.3912015899373974, 0.0384753772446496, 0.5481536630508244}
        };
        // py_resq2_r_cmpl = res_q2[1]
        xarray<double> py_resq2_r_cmpl = {
            {-1.1430852952870696,
             -0.4988738747365853,
             -1.0982282164248067,
             -0.8189559577243967,
             -0.6468222288756241,
             -1.6166030169206462,
             -1.1247642047094615,
             -1.5746170823854417,
             -0.4678059691956431,
             -0.6817147826175952},
            {0.,
             0.4145384440977922,
             0.0432498341745755,
             0.2159221672678357,
             0.5399745339753013,
             0.0627336303098124,
             -0.1631138338388988,
             0.2876936477590398,
             0.0924634343088705,
             0.8209704648352938},
            {0.,
             0.,
             0.8009723247566577,
             0.2467828455102148,
             0.9011434603476536,
             0.1745159258713335,
             0.4469666475320985,
             0.5186696050660637,
             -0.0398310260167535,
             0.1936105292921998},
            {0.,
             0.,
             0.,
             -0.4358731022610104,
             -0.3516828694145329,
             -0.1676233275811677,
             0.229673631977487,
             0.0972324032495854,
             0.1199094213119632,
             0.1556371881989978},
            {0.,
             0.,
             0.,
             0.,
             0.1205612964483228,
             0.3369911999240203,
             0.3155802843315489,
             0.1124970816045023,
             0.1189824829973467,
             0.1610633542281174}
        };

        auto res2 = linalg::qr(py_a, linalg::qrmode::complete);
        EXPECT_TRUE(allclose(std::get<0>(res2), py_resq2_q_cmpl));
        EXPECT_TRUE(allclose(std::get<1>(res2), py_resq2_r_cmpl));

        // py_resq3_q_cmpl = res_q3[0]
        xarray<double> py_resq3_q_cmpl = {
            {-0.3778764545594464, 0.2477850983490842, 0.2323946032026168, 0.6442783657634198, -0.5715855718413764},
            {-0.5182592859033026, -0.5116427882060655, 0.0755411199296714, 0.3718390470559857, 0.5706647283090043},
            {-0.5985844007732788, 0.3414264138444295, -0.6868036045376356, -0.2311050279755064, 0.0039992397751236},
            {-0.4782760145698324, -0.1296501056095487, 0.5617369601749853, -0.6259003290333343, -0.217125009365484},
            {-0.0395659791067296, 0.737185903526121, 0.3912015899373974, 0.0384753772446496, 0.5481536630508244}
        };
        // py_resq3_r_cmpl = res_q3[1]
        xarray<double> py_resq3_r_cmpl = {
            {-1.1430852952870696,
             -0.4988738747365853,
             -1.0982282164248067,
             -0.8189559577243967,
             -0.6468222288756241,
             -1.6166030169206462,
             -1.1247642047094615,
             -1.5746170823854417,
             -0.4678059691956431,
             -0.6817147826175952},
            {0.,
             0.4145384440977922,
             0.0432498341745755,
             0.2159221672678357,
             0.5399745339753013,
             0.0627336303098124,
             -0.1631138338388988,
             0.2876936477590398,
             0.0924634343088705,
             0.8209704648352938},
            {0.,
             0.,
             0.8009723247566577,
             0.2467828455102148,
             0.9011434603476536,
             0.1745159258713335,
             0.4469666475320985,
             0.5186696050660637,
             -0.0398310260167535,
             0.1936105292921998},
            {0.,
             0.,
             0.,
             -0.4358731022610104,
             -0.3516828694145329,
             -0.1676233275811677,
             0.229673631977487,
             0.0972324032495854,
             0.1199094213119632,
             0.1556371881989978},
            {0.,
             0.,
             0.,
             0.,
             0.1205612964483228,
             0.3369911999240203,
             0.3155802843315489,
             0.1124970816045023,
             0.1189824829973467,
             0.1610633542281174}
        };

        auto res3 = linalg::qr(py_a, linalg::qrmode::reduced);
        EXPECT_TRUE(allclose(std::get<0>(res3), py_resq3_q_cmpl));
        EXPECT_TRUE(allclose(std::get<1>(res3), py_resq3_r_cmpl));

        // py_resq4_r_r = res_q4
        xarray<double> py_resq4_r_r = {
            {-1.1430852952870696,
             -0.4988738747365853,
             -1.0982282164248067,
             -0.8189559577243967,
             -0.6468222288756241,
             -1.6166030169206462,
             -1.1247642047094615,
             -1.5746170823854417,
             -0.4678059691956431,
             -0.6817147826175952},
            {0.,
             0.4145384440977922,
             0.0432498341745755,
             0.2159221672678357,
             0.5399745339753013,
             0.0627336303098124,
             -0.1631138338388988,
             0.2876936477590398,
             0.0924634343088705,
             0.8209704648352938},
            {0.,
             0.,
             0.8009723247566577,
             0.2467828455102148,
             0.9011434603476536,
             0.1745159258713335,
             0.4469666475320985,
             0.5186696050660637,
             -0.0398310260167535,
             0.1936105292921998},
            {0.,
             0.,
             0.,
             -0.4358731022610104,
             -0.3516828694145329,
             -0.1676233275811677,
             0.229673631977487,
             0.0972324032495854,
             0.1199094213119632,
             0.1556371881989978},
            {0.,
             0.,
             0.,
             0.,
             0.1205612964483228,
             0.3369911999240203,
             0.3155802843315489,
             0.1124970816045023,
             0.1189824829973467,
             0.1610633542281174}
        };

        auto res4 = linalg::qr(py_a, linalg::qrmode::r);
        EXPECT_TRUE(allclose(std::get<1>(res4), py_resq4_r_r));
    }
}  // namespace xt
