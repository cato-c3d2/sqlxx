/*!
 * @file select-statement-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_HXX

#include <iterator>
#include <vector>

#include "./select-statement-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace
{
    /*!
     * @brief @c SelectStatement クラスのテストケースで使用するデータセット
     */
    class SelectStatementDataSet
    {
    public:
        static auto for_some_test_case()
            -> std::vector<SelectStatementDataSetElement>;

    private:
        static auto for_some_test_case_00()
            -> std::vector<SelectStatementDataSetElement>;
        static auto for_some_test_case_01()
            -> std::vector<SelectStatementDataSetElement>;
        static auto for_some_test_case_02()
            -> std::vector<SelectStatementDataSetElement>;
        static auto for_some_test_case_03()
            -> std::vector<SelectStatementDataSetElement>;
        static auto for_some_test_case_04()
            -> std::vector<SelectStatementDataSetElement>;
    };

    /*!
     * @brief  データセットを返却する
     *
     * [ データパターン表 ] @n
     * <pre>
     * -------------------------------------------------------
     * |     |        select_closure         | from_closure  |
     * |     |   column[0]   |   column[1]   |     table     |
     * |     | name  |  as   | name  |  as   | name  |  as   |
     * =======================================================
     * |  _0 |   o   |   o   |   o   |   o   |   o   |   o   |
     * |  _1 |   o   |   o   |   o   |   o   |   o   |   -   |
     * |  _2 |   o   |   o   |   o   |   o   |   -   |   o   |
     * |  _3 |   o   |   o   |   o   |   o   |   -   |   -   |
     * |  _4 |   o   |   o   |   o   |   -   |   o   |   o   |
     * |  _5 |   o   |   o   |   o   |   -   |   o   |   -   |
     * |  _6 |   o   |   o   |   o   |   -   |   -   |   o   |
     * |  _7 |   o   |   o   |   o   |   -   |   -   |   -   |
     * |  _8 |   o   |   o   |   -   |   o   |   o   |   o   |
     * |  _9 |   o   |   o   |   -   |   o   |   o   |   -   |
     * | _10 |   o   |   o   |   -   |   o   |   -   |   o   |
     * | _11 |   o   |   o   |   -   |   o   |   -   |   -   |
     * | _12 |   o   |   o   |   -   |   -   |   o   |   o   |
     * | _13 |   o   |   o   |   -   |   -   |   o   |   -   |
     * | _14 |   o   |   o   |   -   |   -   |   -   |   o   |
     * | _15 |   o   |   o   |   -   |   -   |   -   |   -   |
     * -------------------------------------------------------
     * | _16 |   o   |   -   |   o   |   o   |   o   |   o   |
     * | _17 |   o   |   -   |   o   |   o   |   o   |   -   |
     * | _18 |   o   |   -   |   o   |   o   |   -   |   o   |
     * | _19 |   o   |   -   |   o   |   o   |   -   |   -   |
     * | _20 |   o   |   -   |   o   |   -   |   o   |   o   |
     * | _21 |   o   |   -   |   o   |   -   |   o   |   -   |
     * | _22 |   o   |   -   |   o   |   -   |   -   |   o   |
     * | _23 |   o   |   -   |   o   |   -   |   -   |   -   |
     * | _24 |   o   |   -   |   -   |   o   |   o   |   o   |
     * | _25 |   o   |   -   |   -   |   o   |   o   |   -   |
     * | _26 |   o   |   -   |   -   |   o   |   -   |   o   |
     * | _27 |   o   |   -   |   -   |   o   |   -   |   -   |
     * | _28 |   o   |   -   |   -   |   -   |   o   |   o   |
     * | _29 |   o   |   -   |   -   |   -   |   o   |   -   |
     * | _30 |   o   |   -   |   -   |   -   |   -   |   o   |
     * | _31 |   o   |   -   |   -   |   -   |   -   |   -   |
     * -------------------------------------------------------
     * | _32 |   -   |   o   |   o   |   o   |   o   |   o   |
     * | _33 |   -   |   o   |   o   |   o   |   o   |   -   |
     * | _34 |   -   |   o   |   o   |   o   |   -   |   o   |
     * | _35 |   -   |   o   |   o   |   o   |   -   |   -   |
     * | _36 |   -   |   o   |   o   |   -   |   o   |   o   |
     * | _37 |   -   |   o   |   o   |   -   |   o   |   -   |
     * | _38 |   -   |   o   |   o   |   -   |   -   |   o   |
     * | _39 |   -   |   o   |   o   |   -   |   -   |   -   |
     * | _40 |   -   |   o   |   -   |   o   |   o   |   o   |
     * | _41 |   -   |   o   |   -   |   o   |   o   |   -   |
     * | _42 |   -   |   o   |   -   |   o   |   -   |   o   |
     * | _43 |   -   |   o   |   -   |   o   |   -   |   -   |
     * | _44 |   -   |   o   |   -   |   -   |   o   |   o   |
     * | _45 |   -   |   o   |   -   |   -   |   o   |   -   |
     * | _46 |   -   |   o   |   -   |   -   |   -   |   o   |
     * | _47 |   -   |   o   |   -   |   -   |   -   |   -   |
     * -------------------------------------------------------
     * | _48 |   -   |   -   |   o   |   o   |   o   |   o   |
     * | _49 |   -   |   -   |   o   |   o   |   o   |   -   |
     * | _50 |   -   |   -   |   o   |   o   |   -   |   o   |
     * | _51 |   -   |   -   |   o   |   o   |   -   |   -   |
     * | _52 |   -   |   -   |   o   |   -   |   o   |   o   |
     * | _53 |   -   |   -   |   o   |   -   |   o   |   -   |
     * | _54 |   -   |   -   |   o   |   -   |   -   |   o   |
     * | _55 |   -   |   -   |   o   |   -   |   -   |   -   |
     * | _56 |   -   |   -   |   -   |   o   |   o   |   o   |
     * | _57 |   -   |   -   |   -   |   o   |   o   |   -   |
     * | _58 |   -   |   -   |   -   |   o   |   -   |   o   |
     * | _59 |   -   |   -   |   -   |   o   |   -   |   -   |
     * | _60 |   -   |   -   |   -   |   -   |   o   |   o   |
     * | _61 |   -   |   -   |   -   |   -   |   o   |   -   |
     * | _62 |   -   |   -   |   -   |   -   |   -   |   o   |
     * | _63 |   -   |   -   |   -   |   -   |   -   |   -   |
     * -------------------------------------------------------
     * </pre>
     *
     * [[ 凡例 ]] @n
     * @li o ... 指定
     * @li - ... 未指定
     *
     * [[ 構成 ]] @n
     * @li  _0 ~ _15 : @link select-statement-data-set.class-member.00.h++ @endlink
     * @li _16 ~ _31 : @link select-statement-data-set.class-member.01.h++ @endlink
     * @li _32 ~ _47 : @link select-statement-data-set.class-member.02.h++ @endlink
     * @li _48 ~ _63 : @link select-statement-data-set.class-member.03.h++ @endlink
     * @li _64 ~ _68 : @link select-statement-data-set.class-member.04.h++ @endlink ... 上記データパターン以外のパターン
     *
     * @return データセット
     *
     * @see sqlxx::statement::SelectStatement              テスト対象クラス
     * @see sqlxx::statement::SelectStatement::to_string() テスト対象メンバ関数
     */
    auto SelectStatementDataSet::for_some_test_case()
        -> std::vector<SelectStatementDataSetElement>
    {
        std::vector<std::vector<SelectStatementDataSetElement>>
            data_set_parts = {
                // clang-format off
                SelectStatementDataSet::for_some_test_case_00(),
                SelectStatementDataSet::for_some_test_case_01(),
                SelectStatementDataSet::for_some_test_case_02(),
                SelectStatementDataSet::for_some_test_case_03(),
                SelectStatementDataSet::for_some_test_case_04()
                // clang-format on
            };

        auto data_set = std::vector<SelectStatementDataSetElement>();
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

#include "./detail/select-statement-data-set.class-member.00.h++"
#include "./detail/select-statement-data-set.class-member.01.h++"
#include "./detail/select-statement-data-set.class-member.02.h++"
#include "./detail/select-statement-data-set.class-member.03.h++"
#include "./detail/select-statement-data-set.class-member.04.h++"

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_HXX */
