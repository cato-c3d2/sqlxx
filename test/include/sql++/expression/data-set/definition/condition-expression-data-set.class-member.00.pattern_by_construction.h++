/*!
 * @file condition-expression-data-set.class-member.00.pattern_by_construction.h++
 */

// FIXME 【要修正】ファイル名を変更する予定 : condition-expression*.h++ => binary-operation*.h++

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX

#include <iterator>
#include <optional>
#include <vector>

#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/integer-literal.class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>
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
     * |     | BinaryOperation                |
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
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto BinaryOperationDataSet::pattern_by_construction()
        -> std::vector<BinaryOperationDataSetElement>
    {
        std::vector<std::vector<BinaryOperationDataSetElement>>
            data_set_parts = {
                // clang-format off
                BinaryOperationDataSet::pattern_by_default_construction(),
                BinaryOperationDataSet::pattern_by_undefault_construction(),
                // clang-format on
            };

        auto data_set = std::vector<BinaryOperationDataSetElement>();
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
     * @c BinaryOperation : デフォルトコンストラクタにより構築したオブジェクト
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto BinaryOperationDataSet::pattern_by_default_construction()
        -> std::vector<BinaryOperationDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperation : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {},

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
     * @c BinaryOperation @n
     * @li @c operater : 有効値 or 無効値 ( @c OperationKind::None )
     * @li @c left     : 有効値 or 無効値 ( @c nullptr )
     * @li @c right    : 有効値 or 無効値 ( @c nullptr )
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto BinaryOperationDataSet::pattern_by_undefault_construction()
        -> std::vector<BinaryOperationDataSetElement>
    {
        // clang-format off
        return {
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperation
            //     + operater : 有効値
            //     + left     : 有効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
            // + BinaryOperation
            //     + operater : 有効値
            //     + left     : 有効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
            // + BinaryOperation
            //     + operater : 有効値
            //     + left     : 無効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
            // + BinaryOperation
            //     + operater : 有効値
            //     + left     : 無効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
            // + BinaryOperation
            //     + operater : 無効値
            //     + left     : 有効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
            // + BinaryOperation
            //     + operater : 無効値
            //     + left     : 有効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
            // + BinaryOperation
            //     + operater : 無効値
            //     + left     : 無効値
            //     + right    : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
            // + BinaryOperation
            //     + operater : 無効値
            //     + left     : 無効値
            //     + right    : 無効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
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
