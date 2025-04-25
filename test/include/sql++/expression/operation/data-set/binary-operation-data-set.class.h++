/*!
 * @file binary-operation-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__DATA_SET__BINARY_OPERATION_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__DATA_SET__BINARY_OPERATION_DATA_SET_HXX

#include <iterator>
#include <vector>

#include "./binary-operation-data-set-element.class.h++"

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
     * @brief ≪二項演算式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::BinaryOperation              テスト対象クラス
     * @see sqlxx::test::expression::BinaryOperationDataSet データセット要素
     */
    class BinaryOperationDataSet
    {
    public:
        /*! @brief ≪二項演算式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<BinaryOperationDataSetElement>;

    protected:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪比較演算≫を指定する */
        static auto pattern_by_comparison_operation()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪論理演算≫を指定する */
        static auto pattern_by_logical_operation()
            -> std::vector<BinaryOperationDataSetElement>;

    private:
        /*! @brief データパターン : デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_default_construction()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : 非デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_undefault_construction()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪等値比較演算≫を指定する */
        static auto pattern_by_equal_to()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪非等値比較演算≫を指定する */
        static auto pattern_by_not_equal_to()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪比較演算（小なり）≫を指定する */
        static auto pattern_by_less()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪比較演算（以下）≫を指定する */
        static auto pattern_by_less_equal()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪比較演算（大なり）≫を指定する */
        static auto pattern_by_greater()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪比較演算（以上）≫を指定する */
        static auto pattern_by_greater_equal()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪IS演算≫を指定する */
        static auto pattern_by_is()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪論理積演算≫を指定する */
        static auto pattern_by_logical_and()
            -> std::vector<BinaryOperationDataSetElement>;

        /*! @brief データパターン : ≪論理和演算≫を指定する */
        static auto pattern_by_logical_or()
            -> std::vector<BinaryOperationDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターンと構成 ] @n
     * @li @link pattern_by_construction()         @endlink : 任意の引数によりオブジェクトを構築する
     * @li @link pattern_by_comparison_operation() @endlink : ≪比較演算≫を指定する
     * @li @link pattern_by_logical_operation()    @endlink : ≪論理演算≫を指定する
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::BinaryOperation::empty()     テスト対象メンバ関数
     * @see sqlxx::expression::BinaryOperation::to_string() テスト対象メンバ関数
     */
    auto BinaryOperationDataSet::for_some_test_case()
        -> std::vector<BinaryOperationDataSetElement>
    {
        std::vector<std::vector<BinaryOperationDataSetElement>>
            data_set_parts = {
                // clang-format off
                BinaryOperationDataSet::pattern_by_construction(),
                BinaryOperationDataSet::pattern_by_comparison_operation(),
                BinaryOperationDataSet::pattern_by_logical_operation(),
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
} // namespace expression
} // namespace sqlxx::test

#include "./definition/binary-operation-data-set.class-member.00.pattern_by_construction.h++"
#include "./definition/binary-operation-data-set.class-member.01.pattern_by_comparison_operation.h++"
#include "./definition/binary-operation-data-set.class-member.02.pattern_by_logical_operation.h++"

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__DATA_SET__BINARY_OPERATION_DATA_SET_HXX */
