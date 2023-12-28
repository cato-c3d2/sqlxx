/*!
 * @file as-clause-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__AS_CLAUSE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__AS_CLAUSE_DATA_SET_HXX

#include <vector>

#include <sql++/clause/as-clause.class.h++>

#include "./as-clause-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief @c AsClause クラスのテストケースで使用するデータセット
     */
    class AsClauseDataSet
    {
    public:
        /*!
        * @brief  データセットを返却する
        *
        * [ データパターン表 ] @n
        * <pre>
        * ---------------------
        * |     | alias_name  |
        * =====================
        * |  _0 |      -      |
        * |  _1 |      e      |
        * |  _2 |      x      |
        * |  _3 |      o      |
        * ---------------------
        * </pre>
        *
        * [[ 凡例 ]] @n
        * @li o ... 指定(適格)
        * @li e ... 指定(不適格(空文字列))
        * @li x ... 指定(不適格(半角スペース))
        * @li - ... 未指定
        *
        * @return データセット
        *
        * @see sqlxx::clause::AsClause              テスト対象クラス
        * @see sqlxx::clause::AsClause::empty()     テスト対象メンバ関数
        * @see sqlxx::clause::AsClause::to_string() テスト対象メンバ関数
        */
        static auto for_some_test_case() -> std::vector<AsClauseDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    using sqlxx::AsClause;

    auto AsClauseDataSet::for_some_test_case()
        -> std::vector<AsClauseDataSetElement>
    {
        // clang-format off
        return {
            // _0
            {
                // [条件]
                // + alias_name : 未指定
                AsClause {},
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _1
            {
                // [条件]
                // + alias_name : 空文字列
                AsClause { "" },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _2
            {
                // [条件]
                // + alias_name : 不適格(半角スペース)
                AsClause { " " },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _3
            {
                // [条件]
                // + alias_name : 適格(カラム指定)
                AsClause { "p.id" },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "AS p.id"
            },
            // _4
            {
                // [条件]
                // + alias_name : 適格(テーブル指定)
                AsClause { "p" },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "AS p"
            }
        };
        // clang-format on
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__AS_CLAUSE_DATA_SET_HXX */
