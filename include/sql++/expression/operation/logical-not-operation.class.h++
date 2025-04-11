/*!
 * @file logical-not-operation.class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__LOGICAL_NOT_OPERATION_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__LOGICAL_NOT_OPERATION_CLASS_HXX

#include <stdexcept>
#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/unary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/unary-operation.class.h++>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪論理否定演算式≫を表現するクラス
     */
    class LogicalNotOperation : public virtual UnaryOperation
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        LogicalNotOperation();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operand 演算される≪式≫
         */
        LogicalNotOperation(Expression const & operand);

        /*!
         * @brief このオブジェクトが空か判定する
         *
         * @return このオブジェクトが空の場合は @c true を、
         *         そうではない場合は @c false を返却する
         */
        auto empty() const -> bool;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

        /*!
         * @brief このオブジェクトを複製する
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> LogicalNotOperation * override;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪論理否定演算式≫を生成する
     *
     * @param[in] operand 演算される≪式≫のオブジェクト
     *
     * @return ≪論理否定演算式≫
     */
    auto logical_not(Expression const & operand) -> LogicalNotOperation;

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out                    出力ストリーム
     * @param[in] logical_not_expression ≪論理否定演算式≫のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream & out, LogicalNotOperation const logical_not_expression)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    LogicalNotOperation::LogicalNotOperation()
        : UnaryOperation(UnaryOperationKind::LogicalNot)
    {}

    LogicalNotOperation::LogicalNotOperation(Expression const & operand)
        : UnaryOperation(UnaryOperationKind::LogicalNot, operand)
    {}

    auto LogicalNotOperation::empty() const -> bool
    {
        auto operand = this->operand();
        if (operand == nullptr) {
            return true;
        }
        try {
            // TODO [要検討] このオブジェクトが空であるか否かの判定について、
            //      演算される≪式≫の evaluate メンバ関数の戻り値で判定せず、
            //      直接、演算される≪式≫が空であるか否かを判定すべき。
            //      従って、 Expression::empty メンバ関数等を実装すべき。
            return operand->evaluate().empty();
        } catch (std::runtime_error &) {
            // NOTE SQLの文法エラーが発生した場合、このオブジェクトが空であるとみなす
            return true;
        }
    }

    auto LogicalNotOperation::to_string() const -> std::string
    {
        if (this->empty()) {
            return {};
        }
        return this->evaluate();
    }

    auto LogicalNotOperation::clone() const -> LogicalNotOperation *
    {
        return new LogicalNotOperation { *this };
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto logical_not(Expression const & operand) -> LogicalNotOperation
    {
        return LogicalNotOperation { operand };
    }

    auto operator<<(
        std::ostream & out, LogicalNotOperation const logical_not_expression)
        -> std::ostream &
    {
        out << logical_not_expression.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__LOGICAL_NOT_OPERATION_CLASS_HXX
