/*!
 * @file logical-not-operation.class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__LOGICAL_NOT_OPERATION_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__LOGICAL_NOT_OPERATION_CLASS_HXX

#include <stdexcept>
#include <string>

#include <sql++/expression/expression.class.h++>

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
     * @brief 論理否定演算式を表現するクラス
     */
    class LogicalNotOperation : public virtual Expression
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        LogicalNotOperation();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operand 内部の式
         */
        LogicalNotOperation(Expression const & operand);

        /*!
         * @brief デストラクタ
         */
        virtual ~LogicalNotOperation() override;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        LogicalNotOperation(LogicalNotOperation const & origin);

        /*!
         * @brief コピー代入演算子
         *
         * @param[in] origin コピー元のオブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto operator=(LogicalNotOperation const & origin)
            -> LogicalNotOperation &;

        /*!
         * @brief このオブジェクトが空か判定する
         *
         * @return このオブジェクトが空の場合は @c true を,
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
        virtual auto clone() const -> LogicalNotOperation * override;

    private:
        /*!
         * @brief このオブジェクトにコピー元のオブジェクトを割り当てる
         *
         * このオブジェクトの各データメンバに、
         * @c origin の各データメンバを代入する。 @n
         *
         * NOTE コピーコンストラクタとコピー代入演算子の実装を共通化するために実装した。
         *
         * @param[in] origin コピー元のオブジェクト
         */
        auto assignment(LogicalNotOperation const & origin) -> void;

    private:
        /*!
         * @brief 内部の式
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        Expression const * _operand;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief 論理否定演算式を生成する
     *
     * @param[in] operand 非演算子となる式のオブジェクト
     *
     * @return 論理否定演算式
     */
    auto logical_not(Expression const & operand) -> LogicalNotOperation;

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out                    出力ストリーム
     * @param[in] logical_not_expression 条件式のオブジェクト
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

    LogicalNotOperation::LogicalNotOperation() : _operand(nullptr)
    {}

    LogicalNotOperation::LogicalNotOperation(Expression const & operand)
        : _operand(operand.clone())
    {}

    LogicalNotOperation::~LogicalNotOperation()
    {
        if (this->_operand != nullptr) {
            delete this->_operand;
        }
    }

    LogicalNotOperation::LogicalNotOperation(LogicalNotOperation const & origin)
    {
        this->assignment(origin);
    }

    auto LogicalNotOperation::operator=(LogicalNotOperation const & origin)
        -> LogicalNotOperation &
    {
        this->assignment(origin);
        return *this;
    }

    auto LogicalNotOperation::empty() const -> bool
    {
        if (this->_operand == nullptr) {
            return true;
        }
        try {
            // TODO [要検討] このオブジェクトが空であるか否かの判定について、
            //      ≪内部の式≫の evaluate メンバ関数の戻り値で判定せず、
            //      直接、≪内部の式≫が空であるか否かを判定すべき。
            //      従って、 Expression::empty メンバ関数等を実装すべき。
            return this->_operand->evaluate().empty();
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

    auto LogicalNotOperation::evaluate() const -> std::string
    {
        using namespace std::literals::string_literals;

        if (this->_operand == nullptr) {
            throw std::runtime_error("'_operand' is null-pointer!");
        }

        std::string const operand_as_string = this->_operand->evaluate();

        return sqlxx::expression::to_string(OperationKind::LogicalNot) + " "s
               + operand_as_string;
    }

    auto LogicalNotOperation::clone() const -> LogicalNotOperation *
    {
        return new LogicalNotOperation(*this);
    }

    auto LogicalNotOperation::assignment(LogicalNotOperation const & origin)
        -> void
    {
        this->_operand =
            (origin._operand != nullptr) ? origin._operand->clone() : nullptr;
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
