/*!
 * @file unary-operation-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_HXX

#include <iterator>
#include <vector>

#include "./unary-operation-data-set-element.class.h++"

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
     * @brief ≪単項演算式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::UnaryOperation              テスト対象クラス
     * @see sqlxx::test::expression::UnaryOperationDataSet データセット要素
     */
    class UnaryOperationDataSet
    {
    public:
        /*! @brief ≪単項演算式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<UnaryOperationDataSetElement>;

    protected:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<UnaryOperationDataSetElement>;

        /*! @brief データパターン : ≪論理演算≫を指定する */
        static auto pattern_by_logical_operation()
            -> std::vector<UnaryOperationDataSetElement>;

    private:
        /*! @brief データパターン : デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_default_construction()
            -> std::vector<UnaryOperationDataSetElement>;

        /*! @brief データパターン : 非デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_undefault_construction()
            -> std::vector<UnaryOperationDataSetElement>;

        /*! @brief データパターン : ≪論理否定演算≫を指定する */
        static auto pattern_by_logical_not()
            -> std::vector<UnaryOperationDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターンと構成 ] @n
     * @li @link pattern_by_construction()      @endlink ... 任意の引数によりオブジェクトを構築する
     * @li @link pattern_by_logical_operation() @endlink ... ≪論理演算≫を指定する
     *
     * @return ≪単項演算式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::UnaryOperation::empty()     テスト対象メンバ関数
     * @see sqlxx::expression::UnaryOperation::to_string() テスト対象メンバ関数
     */
    auto UnaryOperationDataSet::for_some_test_case()
        -> std::vector<UnaryOperationDataSetElement>
    {
        std::vector<std::vector<UnaryOperationDataSetElement>>
            data_set_parts = {
                // clang-format off
                UnaryOperationDataSet::pattern_by_construction(),
                UnaryOperationDataSet::pattern_by_logical_operation(),
                // clang-format on
            };

        auto data_set = std::vector<UnaryOperationDataSetElement>();
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

#include "./definition/unary-operation-data-set.class-member.00.pattern_by_construction.h++"
#include "./definition/unary-operation-data-set.class-member.02.pattern_by_logical_operation.h++"

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_HXX */
