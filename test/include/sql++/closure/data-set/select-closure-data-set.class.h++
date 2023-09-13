/*!
 * @file select-closure-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_HXX

#include <iterator>
#include <vector>

#include <sql++/closure/select-closure.class.h++>

#include "./select-closure-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace
{
    /*!
     * @brief @c SelectClosure クラスのテストケースで使用するデータセット
     */
    class SelectClosureDataSet
    {
    public:
        static auto for_some_test_case()
            -> std::vector<SelectClosureDataSetElement>;

    private:
        static auto for_some_test_case_00_a()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_00_b()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_01()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_02()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_03()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_04()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_05()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_06()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_07()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_08()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_09()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_10()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_11()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_12()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_13()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_14()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_15()
            -> std::vector<SelectClosureDataSetElement>;
        static auto for_some_test_case_16()
            -> std::vector<SelectClosureDataSetElement>;
    };

    /*!
     * @brief  データセットを返却する
     *
     * [ データパターン表 ] @n
     * <pre>
     * ------------------------
     * |      |   column[0]   |
     * ========================
     * |   _0 |       -       |
     * ------------------------
     *
     * ------------------------
     * |      |   column[0]   |
     * |      | name  |  as   |
     * ========================
     * |   _1 |   -   |   -   |
     * |   _2 |   -   |   e   |
     * |   _3 |   -   |   x   |
     * |   _4 |   -   |   o   |
     * |   _5 |   e   |   -   |
     * |   _6 |   e   |   e   |
     * |   _7 |   e   |   x   |
     * |   _8 |   e   |   o   |
     * |   _9 |   x   |   -   |
     * |  _10 |   x   |   e   |
     * |  _11 |   x   |   x   |
     * |  _12 |   x   |   o   |
     * |  _13 |   o   |   -   |
     * |  _14 |   o   |   e   |
     * |  _15 |   o   |   x   |
     * |  _16 |   o   |   o   |
     * ------------------------
     *
     * ----------------------------------------
     * |      |   column[0]   |   column[1]   |
     * |      | name  |  as   | name  |  as   |
     * ========================================
     * |  _17 |   -   |   -   |   -   |   -   |
     * |  _18 |   -   |   -   |   -   |   e   |
     * |  _19 |   -   |   -   |   -   |   x   |
     * |  _20 |   -   |   -   |   -   |   o   |
     * |  _21 |   -   |   -   |   e   |   -   |
     * |  _22 |   -   |   -   |   e   |   e   |
     * |  _23 |   -   |   -   |   e   |   x   |
     * |  _24 |   -   |   -   |   e   |   o   |
     * |  _25 |   -   |   -   |   x   |   -   |
     * |  _26 |   -   |   -   |   x   |   e   |
     * |  _27 |   -   |   -   |   x   |   x   |
     * |  _28 |   -   |   -   |   x   |   o   |
     * |  _29 |   -   |   -   |   o   |   -   |
     * |  _30 |   -   |   -   |   o   |   e   |
     * |  _31 |   -   |   -   |   o   |   x   |
     * |  _32 |   -   |   -   |   o   |   o   |
     * ----------------------------------------
     * |  _33 |   -   |   e   |   -   |   -   |
     * |  _34 |   -   |   e   |   -   |   e   |
     * |  _35 |   -   |   e   |   -   |   x   |
     * |  _36 |   -   |   e   |   -   |   o   |
     * |  _37 |   -   |   e   |   e   |   -   |
     * |  _38 |   -   |   e   |   e   |   e   |
     * |  _39 |   -   |   e   |   e   |   x   |
     * |  _40 |   -   |   e   |   e   |   o   |
     * |  _41 |   -   |   e   |   x   |   -   |
     * |  _42 |   -   |   e   |   x   |   e   |
     * |  _43 |   -   |   e   |   x   |   x   |
     * |  _44 |   -   |   e   |   x   |   o   |
     * |  _45 |   -   |   e   |   o   |   -   |
     * |  _46 |   -   |   e   |   o   |   e   |
     * |  _47 |   -   |   e   |   o   |   x   |
     * |  _48 |   -   |   e   |   o   |   o   |
     * ----------------------------------------
     * |  _49 |   -   |   x   |   -   |   -   |
     * |  _50 |   -   |   x   |   -   |   e   |
     * |  _51 |   -   |   x   |   -   |   x   |
     * |  _52 |   -   |   x   |   -   |   o   |
     * |  _53 |   -   |   x   |   e   |   -   |
     * |  _54 |   -   |   x   |   e   |   e   |
     * |  _55 |   -   |   x   |   e   |   x   |
     * |  _56 |   -   |   x   |   e   |   o   |
     * |  _57 |   -   |   x   |   x   |   -   |
     * |  _58 |   -   |   x   |   x   |   e   |
     * |  _59 |   -   |   x   |   x   |   x   |
     * |  _60 |   -   |   x   |   x   |   o   |
     * |  _61 |   -   |   x   |   o   |   -   |
     * |  _62 |   -   |   x   |   o   |   e   |
     * |  _63 |   -   |   x   |   o   |   x   |
     * |  _64 |   -   |   x   |   o   |   o   |
     * ----------------------------------------
     * |  _65 |   -   |   o   |   -   |   -   |
     * |  _66 |   -   |   o   |   -   |   e   |
     * |  _67 |   -   |   o   |   -   |   x   |
     * |  _68 |   -   |   o   |   -   |   o   |
     * |  _69 |   -   |   o   |   e   |   -   |
     * |  _70 |   -   |   o   |   e   |   e   |
     * |  _71 |   -   |   o   |   e   |   x   |
     * |  _72 |   -   |   o   |   e   |   o   |
     * |  _73 |   -   |   o   |   x   |   -   |
     * |  _74 |   -   |   o   |   x   |   e   |
     * |  _75 |   -   |   o   |   x   |   x   |
     * |  _76 |   -   |   o   |   x   |   o   |
     * |  _77 |   -   |   o   |   o   |   -   |
     * |  _78 |   -   |   o   |   o   |   e   |
     * |  _79 |   -   |   o   |   o   |   x   |
     * |  _80 |   -   |   o   |   o   |   o   |
     * ----------------------------------------
     * |  _81 |   e   |   -   |   -   |   -   |
     * |  _82 |   e   |   -   |   -   |   e   |
     * |  _83 |   e   |   -   |   -   |   x   |
     * |  _84 |   e   |   -   |   -   |   o   |
     * |  _85 |   e   |   -   |   e   |   -   |
     * |  _86 |   e   |   -   |   e   |   e   |
     * |  _87 |   e   |   -   |   e   |   x   |
     * |  _88 |   e   |   -   |   e   |   o   |
     * |  _89 |   e   |   -   |   x   |   -   |
     * |  _90 |   e   |   -   |   x   |   e   |
     * |  _91 |   e   |   -   |   x   |   x   |
     * |  _92 |   e   |   -   |   x   |   o   |
     * |  _93 |   e   |   -   |   o   |   -   |
     * |  _94 |   e   |   -   |   o   |   e   |
     * |  _95 |   e   |   -   |   o   |   x   |
     * |  _96 |   e   |   -   |   o   |   o   |
     * ----------------------------------------
     * |  _97 |   e   |   e   |   -   |   -   |
     * |  _98 |   e   |   e   |   -   |   e   |
     * |  _99 |   e   |   e   |   -   |   x   |
     * | _100 |   e   |   e   |   -   |   o   |
     * | _101 |   e   |   e   |   e   |   -   |
     * | _102 |   e   |   e   |   e   |   e   |
     * | _103 |   e   |   e   |   e   |   x   |
     * | _104 |   e   |   e   |   e   |   o   |
     * | _105 |   e   |   e   |   x   |   -   |
     * | _106 |   e   |   e   |   x   |   e   |
     * | _107 |   e   |   e   |   x   |   x   |
     * | _108 |   e   |   e   |   x   |   o   |
     * | _109 |   e   |   e   |   o   |   -   |
     * | _110 |   e   |   e   |   o   |   e   |
     * | _111 |   e   |   e   |   o   |   x   |
     * | _112 |   e   |   e   |   o   |   o   |
     * ----------------------------------------
     * | _113 |   e   |   x   |   -   |   -   |
     * | _114 |   e   |   x   |   -   |   e   |
     * | _115 |   e   |   x   |   -   |   x   |
     * | _116 |   e   |   x   |   -   |   o   |
     * | _117 |   e   |   x   |   e   |   -   |
     * | _118 |   e   |   x   |   e   |   e   |
     * | _119 |   e   |   x   |   e   |   x   |
     * | _120 |   e   |   x   |   e   |   o   |
     * | _121 |   e   |   x   |   x   |   -   |
     * | _122 |   e   |   x   |   x   |   e   |
     * | _123 |   e   |   x   |   x   |   x   |
     * | _124 |   e   |   x   |   x   |   o   |
     * | _125 |   e   |   x   |   o   |   -   |
     * | _126 |   e   |   x   |   o   |   e   |
     * | _127 |   e   |   x   |   o   |   x   |
     * | _128 |   e   |   x   |   o   |   o   |
     * ----------------------------------------
     * | _129 |   e   |   o   |   -   |   -   |
     * | _130 |   e   |   o   |   -   |   e   |
     * | _131 |   e   |   o   |   -   |   x   |
     * | _132 |   e   |   o   |   -   |   o   |
     * | _133 |   e   |   o   |   e   |   -   |
     * | _134 |   e   |   o   |   e   |   e   |
     * | _135 |   e   |   o   |   e   |   x   |
     * | _136 |   e   |   o   |   e   |   o   |
     * | _137 |   e   |   o   |   x   |   -   |
     * | _138 |   e   |   o   |   x   |   e   |
     * | _139 |   e   |   o   |   x   |   x   |
     * | _140 |   e   |   o   |   x   |   o   |
     * | _141 |   e   |   o   |   o   |   -   |
     * | _142 |   e   |   o   |   o   |   e   |
     * | _143 |   e   |   o   |   o   |   x   |
     * | _144 |   e   |   o   |   o   |   o   |
     * ----------------------------------------
     * | _145 |   x   |   -   |   -   |   -   |
     * | _146 |   x   |   -   |   -   |   e   |
     * | _147 |   x   |   -   |   -   |   x   |
     * | _148 |   x   |   -   |   -   |   o   |
     * | _149 |   x   |   -   |   e   |   -   |
     * | _150 |   x   |   -   |   e   |   e   |
     * | _151 |   x   |   -   |   e   |   x   |
     * | _152 |   x   |   -   |   e   |   o   |
     * | _153 |   x   |   -   |   x   |   -   |
     * | _154 |   x   |   -   |   x   |   e   |
     * | _155 |   x   |   -   |   x   |   x   |
     * | _156 |   x   |   -   |   x   |   o   |
     * | _157 |   x   |   -   |   o   |   -   |
     * | _158 |   x   |   -   |   o   |   e   |
     * | _159 |   x   |   -   |   o   |   x   |
     * | _160 |   x   |   -   |   o   |   o   |
     * ----------------------------------------
     * | _161 |   x   |   e   |   -   |   -   |
     * | _162 |   x   |   e   |   -   |   e   |
     * | _163 |   x   |   e   |   -   |   x   |
     * | _164 |   x   |   e   |   -   |   o   |
     * | _165 |   x   |   e   |   e   |   -   |
     * | _166 |   x   |   e   |   e   |   e   |
     * | _167 |   x   |   e   |   e   |   x   |
     * | _168 |   x   |   e   |   e   |   o   |
     * | _169 |   x   |   e   |   x   |   -   |
     * | _170 |   x   |   e   |   x   |   e   |
     * | _171 |   x   |   e   |   x   |   x   |
     * | _172 |   x   |   e   |   x   |   o   |
     * | _173 |   x   |   e   |   o   |   -   |
     * | _174 |   x   |   e   |   o   |   e   |
     * | _175 |   x   |   e   |   o   |   x   |
     * | _176 |   x   |   e   |   o   |   o   |
     * ----------------------------------------
     * | _177 |   x   |   x   |   -   |   -   |
     * | _178 |   x   |   x   |   -   |   e   |
     * | _179 |   x   |   x   |   -   |   x   |
     * | _180 |   x   |   x   |   -   |   o   |
     * | _181 |   x   |   x   |   e   |   -   |
     * | _182 |   x   |   x   |   e   |   e   |
     * | _183 |   x   |   x   |   e   |   x   |
     * | _184 |   x   |   x   |   e   |   o   |
     * | _185 |   x   |   x   |   x   |   -   |
     * | _186 |   x   |   x   |   x   |   e   |
     * | _187 |   x   |   x   |   x   |   x   |
     * | _188 |   x   |   x   |   x   |   o   |
     * | _189 |   x   |   x   |   o   |   -   |
     * | _190 |   x   |   x   |   o   |   e   |
     * | _191 |   x   |   x   |   o   |   x   |
     * | _192 |   x   |   x   |   o   |   o   |
     * ----------------------------------------
     * | _193 |   x   |   o   |   -   |   -   |
     * | _194 |   x   |   o   |   -   |   e   |
     * | _195 |   x   |   o   |   -   |   x   |
     * | _196 |   x   |   o   |   -   |   o   |
     * | _197 |   x   |   o   |   e   |   -   |
     * | _198 |   x   |   o   |   e   |   e   |
     * | _199 |   x   |   o   |   e   |   x   |
     * | _200 |   x   |   o   |   e   |   o   |
     * | _201 |   x   |   o   |   x   |   -   |
     * | _202 |   x   |   o   |   x   |   e   |
     * | _203 |   x   |   o   |   x   |   x   |
     * | _204 |   x   |   o   |   x   |   o   |
     * | _205 |   x   |   o   |   o   |   -   |
     * | _206 |   x   |   o   |   o   |   e   |
     * | _207 |   x   |   o   |   o   |   x   |
     * | _208 |   x   |   o   |   o   |   o   |
     * ----------------------------------------
     * | _209 |   o   |   -   |   -   |   -   |
     * | _210 |   o   |   -   |   -   |   e   |
     * | _211 |   o   |   -   |   -   |   x   |
     * | _212 |   o   |   -   |   -   |   o   |
     * | _213 |   o   |   -   |   e   |   -   |
     * | _214 |   o   |   -   |   e   |   e   |
     * | _215 |   o   |   -   |   e   |   x   |
     * | _216 |   o   |   -   |   e   |   o   |
     * | _217 |   o   |   -   |   x   |   -   |
     * | _218 |   o   |   -   |   x   |   e   |
     * | _219 |   o   |   -   |   x   |   x   |
     * | _220 |   o   |   -   |   x   |   o   |
     * | _221 |   o   |   -   |   o   |   -   |
     * | _222 |   o   |   -   |   o   |   e   |
     * | _223 |   o   |   -   |   o   |   x   |
     * | _224 |   o   |   -   |   o   |   o   |
     * ----------------------------------------
     * | _225 |   o   |   e   |   -   |   -   |
     * | _226 |   o   |   e   |   -   |   e   |
     * | _227 |   o   |   e   |   -   |   x   |
     * | _228 |   o   |   e   |   -   |   o   |
     * | _229 |   o   |   e   |   e   |   -   |
     * | _230 |   o   |   e   |   e   |   e   |
     * | _231 |   o   |   e   |   e   |   x   |
     * | _232 |   o   |   e   |   e   |   o   |
     * | _233 |   o   |   e   |   x   |   -   |
     * | _234 |   o   |   e   |   x   |   e   |
     * | _235 |   o   |   e   |   x   |   x   |
     * | _236 |   o   |   e   |   x   |   o   |
     * | _237 |   o   |   e   |   o   |   -   |
     * | _238 |   o   |   e   |   o   |   e   |
     * | _239 |   o   |   e   |   o   |   x   |
     * | _240 |   o   |   e   |   o   |   o   |
     * ----------------------------------------
     * | _241 |   o   |   x   |   -   |   -   |
     * | _242 |   o   |   x   |   -   |   e   |
     * | _243 |   o   |   x   |   -   |   x   |
     * | _244 |   o   |   x   |   -   |   o   |
     * | _245 |   o   |   x   |   e   |   -   |
     * | _246 |   o   |   x   |   e   |   e   |
     * | _247 |   o   |   x   |   e   |   x   |
     * | _248 |   o   |   x   |   e   |   o   |
     * | _249 |   o   |   x   |   x   |   -   |
     * | _250 |   o   |   x   |   x   |   e   |
     * | _251 |   o   |   x   |   x   |   x   |
     * | _252 |   o   |   x   |   x   |   o   |
     * | _253 |   o   |   x   |   o   |   -   |
     * | _254 |   o   |   x   |   o   |   e   |
     * | _255 |   o   |   x   |   o   |   x   |
     * | _256 |   o   |   x   |   o   |   o   |
     * ----------------------------------------
     * | _257 |   o   |   o   |   -   |   -   |
     * | _258 |   o   |   o   |   -   |   e   |
     * | _259 |   o   |   o   |   -   |   x   |
     * | _260 |   o   |   o   |   -   |   o   |
     * | _261 |   o   |   o   |   e   |   -   |
     * | _262 |   o   |   o   |   e   |   e   |
     * | _263 |   o   |   o   |   e   |   x   |
     * | _264 |   o   |   o   |   e   |   o   |
     * | _265 |   o   |   o   |   x   |   -   |
     * | _266 |   o   |   o   |   x   |   e   |
     * | _267 |   o   |   o   |   x   |   x   |
     * | _268 |   o   |   o   |   x   |   o   |
     * | _269 |   o   |   o   |   o   |   -   |
     * | _270 |   o   |   o   |   o   |   e   |
     * | _271 |   o   |   o   |   o   |   x   |
     * | _272 |   o   |   o   |   o   |   o   |
     * ----------------------------------------
     * </pre>
     *
     * [[ 凡例 ]] @n
     * @li o ... 指定(適格)
     * @li e ... 指定(不適格(空文字列))
     * @li x ... 指定(不適格(半角スペース))
     * @li - ... 未指定
     *
     * [[ 構成 ]] @n
     * @li          _0 : @link for_some_test_case_00_a() @endlink @link select-closure-data-set.class-member.00.h++ @endlink
     * @li   _1 ~  _16 : @link for_some_test_case_00_b() @endlink @link select-closure-data-set.class-member.00.h++ @endlink
     * @li  _16 ~  _32 : @link for_some_test_case_01()   @endlink @link select-closure-data-set.class-member.01.h++ @endlink
     * @li  _33 ~  _48 : @link for_some_test_case_02()   @endlink @link select-closure-data-set.class-member.02.h++ @endlink
     * @li  _49 ~  _64 : @link for_some_test_case_03()   @endlink @link select-closure-data-set.class-member.03.h++ @endlink
     * @li  _65 ~  _80 : @link for_some_test_case_04()   @endlink @link select-closure-data-set.class-member.04.h++ @endlink
     * @li  _81 ~  _96 : @link for_some_test_case_05()   @endlink @link select-closure-data-set.class-member.05.h++ @endlink
     * @li  _97 ~ _112 : @link for_some_test_case_06()   @endlink @link select-closure-data-set.class-member.06.h++ @endlink
     * @li _113 ~ _128 : @link for_some_test_case_07()   @endlink @link select-closure-data-set.class-member.07.h++ @endlink
     * @li _129 ~ _144 : @link for_some_test_case_08()   @endlink @link select-closure-data-set.class-member.08.h++ @endlink
     * @li _145 ~ _160 : @link for_some_test_case_09()   @endlink @link select-closure-data-set.class-member.09.h++ @endlink
     * @li _161 ~ _176 : @link for_some_test_case_10()   @endlink @link select-closure-data-set.class-member.10.h++ @endlink
     * @li _177 ~ _192 : @link for_some_test_case_11()   @endlink @link select-closure-data-set.class-member.11.h++ @endlink
     * @li _193 ~ _208 : @link for_some_test_case_12()   @endlink @link select-closure-data-set.class-member.12.h++ @endlink
     * @li _209 ~ _224 : @link for_some_test_case_13()   @endlink @link select-closure-data-set.class-member.13.h++ @endlink
     * @li _225 ~ _240 : @link for_some_test_case_14()   @endlink @link select-closure-data-set.class-member.14.h++ @endlink
     * @li _241 ~ _256 : @link for_some_test_case_15()   @endlink @link select-closure-data-set.class-member.15.h++ @endlink
     * @li _257 ~ _272 : @link for_some_test_case_16()   @endlink @link select-closure-data-set.class-member.16.h++ @endlink
     *
     * @return データセット
     *
     * @see sqlxx::closure::SelectClosure              テスト対象クラス
     * @see sqlxx::closure::SelectClosure::empty()     テスト対象メンバ関数
     * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
     */
    auto SelectClosureDataSet::for_some_test_case()
        -> std::vector<SelectClosureDataSetElement>
    {
        std::vector<std::vector<SelectClosureDataSetElement>> data_set_parts = {
            // clang-format off
            SelectClosureDataSet::for_some_test_case_00_a(),
            SelectClosureDataSet::for_some_test_case_00_b(),
            SelectClosureDataSet::for_some_test_case_01(),
            SelectClosureDataSet::for_some_test_case_02(),
            SelectClosureDataSet::for_some_test_case_03(),
            SelectClosureDataSet::for_some_test_case_04(),
            SelectClosureDataSet::for_some_test_case_05(),
            SelectClosureDataSet::for_some_test_case_06(),
            SelectClosureDataSet::for_some_test_case_07(),
            SelectClosureDataSet::for_some_test_case_08(),
            SelectClosureDataSet::for_some_test_case_09(),
            SelectClosureDataSet::for_some_test_case_10(),
            SelectClosureDataSet::for_some_test_case_11(),
            SelectClosureDataSet::for_some_test_case_12(),
            SelectClosureDataSet::for_some_test_case_13(),
            SelectClosureDataSet::for_some_test_case_14(),
            SelectClosureDataSet::for_some_test_case_15(),
            SelectClosureDataSet::for_some_test_case_16()
            // clang-format on
        };

        auto data_set = std::vector<SelectClosureDataSetElement>();
        for (auto && data_set_part : data_set_parts) {
            data_set.insert(
                std::end(data_set),
                std::begin(data_set_part),
                std::end(data_set_part));
        }
        return data_set;
    }
} // namespace
} // namespace sqlxx::test

#include "./detail/select-closure-data-set.class-member.00.h++"
#include "./detail/select-closure-data-set.class-member.01.h++"
#include "./detail/select-closure-data-set.class-member.02.h++"
#include "./detail/select-closure-data-set.class-member.03.h++"
#include "./detail/select-closure-data-set.class-member.04.h++"
#include "./detail/select-closure-data-set.class-member.05.h++"
#include "./detail/select-closure-data-set.class-member.06.h++"
#include "./detail/select-closure-data-set.class-member.07.h++"
#include "./detail/select-closure-data-set.class-member.08.h++"
#include "./detail/select-closure-data-set.class-member.09.h++"
#include "./detail/select-closure-data-set.class-member.10.h++"
#include "./detail/select-closure-data-set.class-member.11.h++"
#include "./detail/select-closure-data-set.class-member.12.h++"
#include "./detail/select-closure-data-set.class-member.13.h++"
#include "./detail/select-closure-data-set.class-member.14.h++"
#include "./detail/select-closure-data-set.class-member.15.h++"
#include "./detail/select-closure-data-set.class-member.16.h++"

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_HXX */
