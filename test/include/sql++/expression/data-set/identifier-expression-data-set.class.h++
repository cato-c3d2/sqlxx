/*!
 * @file identifier-expression-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__IDENTIFIER_EXPRESSION_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__IDENTIFIER_EXPRESSION_DATA_SET_HXX

#include <iterator>
#include <vector>

#include <sql++/expression/identifier-expression.class.h++>

#include "./identifier-expression-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪識別子式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::IdentifierExpression              テスト対象クラス
     * @see sqlxx::test::expression::IdentifierExpressionDataSet データセット要素
     */
    class IdentifierExpressionDataSet
    {
    public:
        /*! @brief ≪識別子式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<IdentifierExpressionDataSetElement>;

    private:
        /*! @brief データパターン : デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_default_construction()
            -> std::vector<IdentifierExpressionDataSetElement>;

        /*! @brief データパターン : 非デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_undefault_construction()
            -> std::vector<IdentifierExpressionDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * -----------------------------
     * |    | IdentifierExpression |
     * |    |----------------------|
     * |    | name                 |
     * |====|======================|
     * | _0 | -                    |
     * |----|----------------------|
     * | _1 | o (empty-string)     |
     * |----|----------------------|
     * | _2 | o (white-space)      |
     * |----|----------------------|
     * | _3 | o (any-string)       |
     * -----------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li -            ... 未指定
     * @li o            ... 指定
     * @li empty-string ... 空文字列
     * @li white-space  ... 半角スペース
     * @li any-string   ... 任意の文字列
     *
     * [ 構成 ] @n
     * @li      _0 : @link pattern_by_default_construction()   @endlink
     * @li _2 ~ _9 : @link pattern_by_undefault_construction() @endlink
     *
     * @return ≪識別子式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::IdentifierExpression::name()      テスト対象メンバ関数
     * @see sqlxx::expression::IdentifierExpression::to_string() テスト対象メンバ関数
     */
    auto IdentifierExpressionDataSet::for_some_test_case()
        -> std::vector<IdentifierExpressionDataSetElement>
    {
        std::vector<std::vector<IdentifierExpressionDataSetElement>>
            data_set_parts = {
                // clang-format off
                IdentifierExpressionDataSet::pattern_by_default_construction(),
                IdentifierExpressionDataSet::pattern_by_undefault_construction(),
                // clang-format on
            };

        auto data_set = std::vector<IdentifierExpressionDataSetElement>();
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
     * @c IdentifierExpression : デフォルトコンストラクタにより構築したオブジェクト
     *
     * @return ≪識別子式≫のテストケースで使用するデータセット
     */
    auto IdentifierExpressionDataSet::pattern_by_default_construction()
        -> std::vector<IdentifierExpressionDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IdentifierExpression : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IdentifierExpression {},

                // 期待結果 - name メンバ関数 & to_string メンバ関数
                "",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c IdentifierExpression : 非デフォルトコンストラクタにより構築したオブジェクト
     *
     * @return ≪識別子式≫のテストケースで使用するデータセット
     */
    auto IdentifierExpressionDataSet::pattern_by_undefault_construction()
        -> std::vector<IdentifierExpressionDataSetElement>
    {
        // clang-format off
        return {
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IdentifierExpression
            //     + name : 空文字列
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IdentifierExpression { "" },

                // 期待結果 - name メンバ関数 & to_string メンバ関数
                "",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IdentifierExpression
            //     + name : 半角スペース
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IdentifierExpression { " " },

                // 期待結果 - name メンバ関数 & to_string メンバ関数
                " ",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IdentifierExpression
            //     + name : テーブル名
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IdentifierExpression { "people" },

                // 期待結果 - name メンバ関数 & to_string メンバ関数
                "people",
            },

            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IdentifierExpression
            //     + name : カラム名
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IdentifierExpression { "id" },

                // 期待結果 - name メンバ関数 & to_string メンバ関数
                "id",
            },

            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IdentifierExpression
            //     + name : テーブル名 + カラム名
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IdentifierExpression { "people.id" },

                // 期待結果 - name メンバ関数 & to_string メンバ関数
                "people.id",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__IDENTIFIER_EXPRESSION_DATA_SET_HXX */
