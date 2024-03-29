/*!
 * @file from-clause-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__FROM_CLAUSE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__FROM_CLAUSE_DATA_SET_HXX

#include <vector>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/identifier/table-identifier.class.h++>

#include "./from-clause-data-set-element.class.h++"

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
     * @brief @c FromClause クラスのテストケースで使用するデータセット
     */
    class FromClauseDataSet
    {
    public:
        /*!
        * @brief  データセットを返却する
        *
        * [ データパターン表 ] @n
        * <pre>
        * -----------------------
        * |     |     table     |
        * =======================
        * |  _0 |       -       |
        * -----------------------
        *
        * -----------------------
        * |     |     table     |
        * |     | name  |  as   |
        * =======================
        * |  _1 |   -   |   -   |
        * |  _2 |   -   |   e   |
        * |  _3 |   -   |   x   |
        * |  _4 |   -   |   o   |
        * -----------------------
        * |  _5 |   e   |   -   |
        * |  _6 |   e   |   e   |
        * |  _7 |   e   |   x   |
        * |  _8 |   e   |   o   |
        * -----------------------
        * |  _9 |   x   |   -   |
        * | _10 |   x   |   e   |
        * | _11 |   x   |   x   |
        * | _12 |   x   |   o   |
        * -----------------------
        * | _13 |   o   |   -   |
        * | _14 |   o   |   e   |
        * | _15 |   o   |   x   |
        * | _16 |   o   |   o   |
        * -----------------------
        * </pre>
        *
        * [[ 凡例 ]] @n
        * @li o ... 指定(適格)
        * @li e ... 指定(不適格(空文字列))
        * @li x ... 指定(不適格(半角スペース))
        * @li - ... 未指定
        *
        * [[ 構成 ]] @n
        * @li        _0 : @link for_some_test_case_a() @endlink
        * @li  _1 ~  _4 : @link for_some_test_case_b() @endlink
        * @li  _5 ~  _8 : @link for_some_test_case_c() @endlink
        * @li  _9 ~ _12 : @link for_some_test_case_d() @endlink
        * @li _13 ~ _16 : @link for_some_test_case_e() @endlink
        *
        * @return データセット
        *
        * @see sqlxx::clause::FromClause              テスト対象クラス
        * @see sqlxx::clause::FromClause::empty()     テスト対象メンバ関数
        * @see sqlxx::clause::FromClause::to_string() テスト対象メンバ関数
        */
        static auto for_some_test_case()
            -> std::vector<FromClauseDataSetElement>;

    private:
        static auto for_some_test_case_a()
            -> std::vector<FromClauseDataSetElement>;
        static auto for_some_test_case_b()
            -> std::vector<FromClauseDataSetElement>;
        static auto for_some_test_case_c()
            -> std::vector<FromClauseDataSetElement>;
        static auto for_some_test_case_d()
            -> std::vector<FromClauseDataSetElement>;
        static auto for_some_test_case_e()
            -> std::vector<FromClauseDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    using sqlxx::FromClause;
    using sqlxx::TableIdentifier;

    auto FromClauseDataSet::for_some_test_case()
        -> std::vector<FromClauseDataSetElement>
    {
        std::vector<std::vector<FromClauseDataSetElement>> data_set_parts = {
            // clang-format off
            FromClauseDataSet::for_some_test_case_a(),
            FromClauseDataSet::for_some_test_case_b(),
            FromClauseDataSet::for_some_test_case_c(),
            FromClauseDataSet::for_some_test_case_d(),
            FromClauseDataSet::for_some_test_case_e()
            // clang-format on
        };

        auto data_set = std::vector<FromClauseDataSetElement>();
        for (auto && data_set_part : data_set_parts) {
            data_set.insert(
                std::end(data_set),
                std::begin(data_set_part),
                std::end(data_set_part));
        }
        return data_set;
    }

    /*!
     * @brief データセットを返却する
     *
     * データパターン :
     *
     * @c table : 未指定
     *
     * @return データセット
     *
     * @see sqlxx::clause::FromClause              テスト対象クラス
     * @see sqlxx::clause::FromClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::FromClause::to_string() テスト対象メンバ関数
     */
    auto FromClauseDataSet::for_some_test_case_a()
        -> std::vector<FromClauseDataSetElement>
    {
        // clang-format off
        return {
            // _0
            {
                // [条件]
                // + table : 未指定
                FromClause {},
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }

    /*!
     * @brief データセットを返却する
     *
     * データパターン :
     *
     * @c table : @n
     * @li @c name      : 未指定
     * @li @c as_clause : 未指定, 空文字列, 不適格(半角スペース) or 適格
     *
     * @return データセット
     *
     * @see sqlxx::clause::FromClause              テスト対象クラス
     * @see sqlxx::clause::FromClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::FromClause::to_string() テスト対象メンバ関数
     */
    auto FromClauseDataSet::for_some_test_case_b()
        -> std::vector<FromClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 未指定
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            // _1
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 未指定
                    TableIdentifier {}
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _2
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 空文字列
                    TableIdentifier {}.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _3
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 不適格(半角スペース)
                    TableIdentifier {}.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _4
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 適格
                    TableIdentifier {}.as({ "p" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }

    /*!
     * @brief データセットを返却する
     *
     * データパターン :
     *
     * @c table : @n
     * @li @c name      : 空文字列
     * @li @c as_clause : 未指定, 空文字列, 不適格(半角スペース) or 適格
     *
     * @return データセット
     *
     * @see sqlxx::clause::FromClause              テスト対象クラス
     * @see sqlxx::clause::FromClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::FromClause::to_string() テスト対象メンバ関数
     */
    auto FromClauseDataSet::for_some_test_case_c()
        -> std::vector<FromClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 空文字列
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            // _5
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 未指定
                    TableIdentifier { "" }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _6
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 空文字列
                    TableIdentifier { "" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _7
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 不適格(半角スペース)
                    TableIdentifier { "" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _8
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 適格
                    TableIdentifier { "" }.as({ "p" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
        };
        // clang-format on
    }

    /*!
     * @brief データセットを返却する
     *
     * データパターン :
     *
     * @c table : @n
     * @li @c name      : 不適格(半角スペース)
     * @li @c as_clause : 未指定, 空文字列, 不適格(半角スペース) or 適格
     *
     * @return データセット
     *
     * @see sqlxx::clause::FromClause              テスト対象クラス
     * @see sqlxx::clause::FromClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::FromClause::to_string() テスト対象メンバ関数
     */
    auto FromClauseDataSet::for_some_test_case_d()
        -> std::vector<FromClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            // _9
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 未指定
                    TableIdentifier { " " }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _10
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 空文字列
                    TableIdentifier { " " }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _11
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 不適格(半角スペース)
                    TableIdentifier { " " }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _12
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 適格
                    TableIdentifier { " " }.as({ "p" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }

    /*!
     * @brief データセットを返却する
     *
     * データパターン :
     *
     * @c table : @n
     * @li @c name      : 適格
     * @li @c as_clause : 未指定, 空文字列, 不適格(半角スペース) or 適格
     *
     * @return データセット
     *
     * @see sqlxx::clause::FromClause              テスト対象クラス
     * @see sqlxx::clause::FromClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::FromClause::to_string() テスト対象メンバ関数
     */
    auto FromClauseDataSet::for_some_test_case_e()
        -> std::vector<FromClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 適格
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            // _13
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 未指定
                    TableIdentifier { "people" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "FROM people"
            },
            // _14
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 空文字列
                    TableIdentifier { "people" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "FROM people"
            },
            // _15
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 不適格(半角スペース)
                    TableIdentifier { "people" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "FROM people"
            },
            // _16
            {
                FromClause {
                    // [条件(1)]
                    // + table :
                    //     + as_clause : 適格
                    TableIdentifier { "people" }.as({ "p" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "FROM people AS p"
            }
        };
        // clang-format on
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__FROM_CLAUSE_DATA_SET_HXX */
