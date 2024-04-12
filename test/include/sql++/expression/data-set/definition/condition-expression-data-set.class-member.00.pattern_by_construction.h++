/*!
 * @file condition-expression-data-set.class-member.00.pattern_by_construction.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX

#include <iterator>
#include <optional>
#include <vector>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/integer-literal.class.h++>
#include <sql++/expression/operation/operation-kind.enum-class.h++>

#include "../condition-expression-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * ----------------------------------------
     * |     | ConditionExpression            |
     * |     |--------------------------------|
     * |     | operater | left     | right    |
     * |=====|==========|==========|==========|
     * |  _0 | -        | -        | -        |
     * |-----|----------|----------|----------|
     * |  _1 | o        | o        | o        |
     * |-----|          |          |----------|
     * |  _2 |          |          | x        |
     * |-----|          |----------|----------|
     * |  _3 |          | x        | o        |
     * |-----|          |          |----------|
     * |  _4 |          |          | x        |
     * |-----|----------|----------|----------|
     * |  _5 | x        | o        | o        |
     * |-----|          |          |----------|
     * |  _6 |          |          | x        |
     * |-----|          |----------|----------|
     * |  _7 |          | x        | o        |
     * |-----|          |          |----------|
     * |  _8 |          |          | x        |
     * ----------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li - ... 未指定
     * @li o ... 有効値
     * @li x ... 無効値 (
     *           @c operater : @c OperationKind::None /
     *           @c left & @c right : @c nullptr )
     *
     * [ 構成 ] @n
     * @li      _0 : @link pattern_by_default_construction()   @endlink
     * @li _1 ~ _8 : @link pattern_by_undefault_construction() @endlink
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_construction()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        std::vector<std::vector<ConditionExpressionDataSetElement>>
            data_set_parts = {
                // clang-format off
                ConditionExpressionDataSet::pattern_by_default_construction(),
                ConditionExpressionDataSet::pattern_by_undefault_construction(),
                // clang-format on
            };

        auto data_set = std::vector<ConditionExpressionDataSetElement>();
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
     * @c ConditionExpression : デフォルトコンストラクタにより構築したオブジェクト
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_default_construction()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {},

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
     * @c ConditionExpression @n
     * @li @c operater : 有効値 or 無効値 ( @c OperationKind::None )
     * @li @c left     : 有効値 or 無効値 ( @c nullptr )
     * @li @c right    : 有効値 or 無効値 ( @c nullptr )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_undefault_construction()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        // clang-format off
        return {
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : 有効値
            //     + left     : 有効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    new IdentifierExpression { "p.id" },
                    new IntegerLiteral { 1234 },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.id = 1234",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : 有効値
            //     + left     : 有効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    new IdentifierExpression { "p.id" },
                    nullptr,
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : 有効値
            //     + left     : 無効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    nullptr,
                    new IntegerLiteral { 1234 },
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
            // + ConditionExpression
            //     + operater : 有効値
            //     + left     : 無効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    nullptr,
                    nullptr,
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
            // + ConditionExpression
            //     + operater : 無効値
            //     + left     : 有効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::None,
                    new IdentifierExpression { "p.id" },
                    new IntegerLiteral { 1234 },
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
            // + ConditionExpression
            //     + operater : 無効値
            //     + left     : 有効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::None,
                    new IdentifierExpression { "p.id" },
                    nullptr,
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
            // + ConditionExpression
            //     + operater : 無効値
            //     + left     : 無効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::None,
                    nullptr,
                    new IntegerLiteral { 1234 },
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _8
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : 無効値
            //     + left     : 無効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::None,
                    nullptr,
                    nullptr,
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
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX */
