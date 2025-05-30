/*!
 * @file where-clause-data-set.class-member.00.pattern_by_construction.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX

#include <iterator>
#include <optional>
#include <vector>

#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/integer-literal.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>

#include "../where-clause-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * ---------------------------------------
     * |    | WhereClause                    |
     * |    |--------------------------------|
     * |    | condition_expression           |
     * |====|================================|
     * | _0 | -                              |
     * ---------------------------------------
     *
     * ---------------------------------------
     * |    | WhereClause                    |
     * |    |--------------------------------|
     * |    | condition_expression           |
     * |    |--------------------------------|
     * |    | BinaryOperation                |
     * |    |--------------------------------|
     * |    | operator | left     | right    |
     * |====|==========|==========|==========|
     * | _1 | -        | -        | -        |
     * |----|----------|----------|----------|
     * | _2 | o        | o        | o        |
     * |----|          |          |----------|
     * | _3 |          |          | -        |
     * |----|          |----------|----------|
     * | __ |          | -        | o        | ※コンパイル不可
     * |----|          |          |----------|
     * | _4 |          |          | -        |
     * |----|----------|----------|----------|
     * | _5 | x        | o        | o        |
     * |----|          |          |----------|
     * | _6 |          |          | -        |
     * |----|          |----------|----------|
     * | __ |          | -        | o        | ※コンパイル不可
     * |----|          |          |----------|
     * | _7 |          |          | -        |
     * ---------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li - : 未指定
     * @li o : 有効値
     * @li x : 無効値（ @c operator : @c BinaryOperationKind::None ）
     *
     * [ 構成 ] @n
     * @li      _0 : @link pattern_by_default_construction()   @endlink
     * @li _1 ~ _7 : @link pattern_by_undefault_construction() @endlink
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     *
     * @see sqlxx::clause::WhereClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::WhereClause::to_string() テスト対象メンバ関数
     */
    auto WhereClauseDataSet::pattern_by_construction()
        -> std::vector<WhereClauseDataSetElement>
    {
        std::vector<std::vector<WhereClauseDataSetElement>> data_set_parts = {
            // clang-format off
            WhereClauseDataSet::pattern_by_default_construction(),
            WhereClauseDataSet::pattern_by_undefault_construction(),
            // clang-format on
        };

        auto data_set = std::vector<WhereClauseDataSetElement>();
        for (auto && data_set_part : data_set_parts) {
            data_set.insert(
                std::end(data_set),
                std::begin(data_set_part),
                std::end(data_set_part));
        }
        return data_set;
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause : デフォルトコンストラクタにより構築したオブジェクト
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_default_construction()
        -> std::vector<WhereClauseDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {},

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : @c BinaryOperation （下記参照）
     *
     * @c BinaryOperation @n
     * @li @c operator : 有効値 or 無効値（ @c BinaryOperationKind::None ）
     * @li @c left     : 有効値 or 無効値（ @c nullptr ）
     * @li @c right    : 有効値 or 無効値（ @c nullptr ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_undefault_construction()
        -> std::vector<WhereClauseDataSetElement>
    {
        // clang-format off
        return {
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : 未指定
            //         + left     : 未指定
            //         + right    : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {
                    BinaryOperation {},
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : 有効値
            //         + left     : 有効値
            //         + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        IdentifierExpression { "p.id" },
                        IntegerLiteral { 1234 },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.id = 1234",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : 有効値
            //         + left     : 有効値
            //         + right    : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        IdentifierExpression { "p.id" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : 有効値
            //         + left     : 未指定
            //         + right    : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::EqualTo,
                    },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : 無効値
            //         + left     : 有効値
            //         + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::None,
                        IdentifierExpression { "p.id" },
                        IntegerLiteral { 1234 },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _6
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : 無効値
            //         + left     : 有効値
            //         + right    : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::None,
                        IdentifierExpression { "p.id" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _7
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : 無効値
            //         + left     : 無効値
            //         + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::None,
                    },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },
        };
        // clang-format on
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX */
