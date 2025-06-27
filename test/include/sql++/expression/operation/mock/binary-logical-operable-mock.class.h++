/*!
 * @file binary-logical-operable-mock.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__BINARY_LOGICAL_OPERABLE_MOCK_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__BINARY_LOGICAL_OPERABLE_MOCK_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/binary-logical-operable.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>

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
     * @brief @c BinaryLogicalOperable クラスを継承したモッククラス
     */
    class BinaryLogicalOperableMock :
        public virtual BinaryLogicalOperable<BinaryLogicalOperableMock>
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        BinaryLogicalOperableMock() : _operation_kind(BinaryOperationKind::None)
        {}

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operation_kind ≪二項演算種別≫
         * @param[in] left_operand   左辺の≪式≫（使用しない）
         * @param[in] right_operand  右辺の≪式≫（使用しない）
         */
        BinaryLogicalOperableMock(
            BinaryOperationKind operation_kind,
            Expression const &  left_operand,
            Expression const &  right_operand)
            : _operation_kind(operation_kind)
        {}

        /*!
         * @brief 仮想デストラクタ
         */
        virtual ~BinaryLogicalOperableMock() override = default;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        BinaryLogicalOperableMock(BinaryLogicalOperableMock const & origin)
        {
            this->_operation_kind = origin._operation_kind;
        };

        /*!
         * @brief この式の文字列表現を返却する
         *
         * @return この式の文字列表現
         */
        virtual auto evaluate() const -> std::string override;

        /*!
         * @brief このオブジェクトを複製する
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> BinaryLogicalOperableMock * override;

    private:
        /*!
         * @brief ≪二項演算種別≫
         */
        BinaryOperationKind _operation_kind;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out     出力ストリーム
     * @param[in] operand モッククラスその一のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto
    operator<<(std::ostream & out, BinaryLogicalOperableMock const & operand)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto BinaryLogicalOperableMock::evaluate() const -> std::string
    {
        using namespace std::literals::string_literals;

        std::string operation_kind;
        if (this->_operation_kind != BinaryOperationKind::None) {
            operation_kind =
                sqlxx::expression::to_string(this->_operation_kind);
        } else {
            operation_kind = "(operation_kind-none)";
        }

        return "L "s + operation_kind + " R"s;
    }

    auto BinaryLogicalOperableMock::clone() const -> BinaryLogicalOperableMock *
    {
        return new BinaryLogicalOperableMock { *this };
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto
    operator<<(std::ostream & out, BinaryLogicalOperableMock const & operand)
        -> std::ostream &
    {
        return out << operand.evaluate();
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__BINARY_LOGICAL_OPERABLE_MOCK_CLASS_HXX */
