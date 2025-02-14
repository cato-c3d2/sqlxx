/*!
 * @file unary-operation.class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_CLASS_HXX

#include <string>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/unary-operation-kind.enum-class.h++>

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
     * @brief ≪単項演算式≫を表現する抽象クラス
     */
    class UnaryOperation : public virtual ConditionExpression
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        UnaryOperation();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operater ≪単項演算種別≫
         * @param[in] operand  演算される≪式≫
         */
        UnaryOperation(UnaryOperationKind operater, Expression const & operand);

        /*!
         * @brief コンストラクタ
         *
         * ≪単項演算種別≫のみを設定し、演算される≪式≫を後から設定する場合に使用する。
         *
         * @param[in] operater ≪単項演算種別≫
         */
        UnaryOperation(UnaryOperationKind operater);

        /*!
         * @brief デストラクタ
         */
        virtual ~UnaryOperation() override;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        UnaryOperation(UnaryOperation const & origin);

        /*!
         * @brief コピー代入演算子
         *
         * @param[in] origin コピー元のオブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto operator=(UnaryOperation const & origin) -> UnaryOperation &;

        /*!
         * @brief ≪単項演算種別≫を取得する
         *
         * @return ≪単項演算種別≫
         */
        auto operater() const -> UnaryOperationKind;

        /*!
         * @brief ≪単項演算種別≫を設定する
         *
         * @param[in] operater ≪単項演算種別≫
         *
         * @return このオブジェクトの参照
         */
        auto operater(UnaryOperationKind operater) -> UnaryOperation &;

        /*!
         * @brief 演算される≪式≫を取得する
         *
         * このオブジェクトが保持する演算される≪式≫を複製し、そのポインタを返却する。
         *
         * @return 複製した演算される≪式≫のポインタ
         */
        auto operand() const -> Expression *;

        /*!
         * @brief 演算される≪式≫を設定する
         *
         * 引数として指定した≪式≫を複製し、そのポインタをこのオブジェクトの演算される≪式≫として保持する。
         *
         * @param[in] operand 演算される≪式≫
         *
         * @return このオブジェクトの参照
         */
        auto operand(Expression const & operand) -> UnaryOperation &;

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
         * @brief 純粋仮想コピーコンストラクタ
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> UnaryOperation * override;

    private:
        /*!
         * @brief このオブジェクトにコピー元のオブジェクトを割り当てる
         *
         * このオブジェクトの各データメンバに、
         * @c origin の各データメンバを代入する。 @n
         *
         * NOTE コピーコンストラクタとコピー代入演算子の実装を共通化するために実装した。 @n
         *
         * @param[in] origin コピー元のオブジェクト
         */
        auto assignment(UnaryOperation const & origin) -> void;

    private:
        /*!
         * @brief ≪単項演算種別≫
         */
        UnaryOperationKind _operater;

        /*!
         * @brief 演算される≪式≫
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
     * @brief ストリーム出力演算
     *
     * @param[in] out             出力ストリーム
     * @param[in] unary_operation ≪単項演算式≫のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, UnaryOperation const unary_operation)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    UnaryOperation::UnaryOperation() : UnaryOperation(UnaryOperationKind::None)
    {}

    UnaryOperation::UnaryOperation(
        UnaryOperationKind operater, Expression const & operand)
        : _operater(operater), _operand(operand.clone())
    {}

    UnaryOperation::UnaryOperation(UnaryOperationKind operater)
        : _operater(operater), _operand(nullptr)
    {}

    UnaryOperation::~UnaryOperation()
    {
        if (this->_operand != nullptr) {
            delete this->_operand;
        }
    }

    UnaryOperation::UnaryOperation(UnaryOperation const & origin)
    {
        this->assignment(origin);
    }

    auto UnaryOperation::operator=(UnaryOperation const & origin)
        -> UnaryOperation &
    {
        this->assignment(origin);
        return *this;
    }

    auto UnaryOperation::operater() const -> UnaryOperationKind
    {
        return this->_operater;
    }

    auto UnaryOperation::operater(UnaryOperationKind operater)
        -> UnaryOperation &
    {
        this->_operater = operater;
        return *this;
    }

    auto UnaryOperation::operand() const -> Expression *
    {
        return this->_operand != nullptr ? this->_operand->clone() : nullptr;
    }

    auto UnaryOperation::operand(Expression const & operand) -> UnaryOperation &
    {
        this->_operand = operand.clone();
        return *this;
    }

    auto UnaryOperation::empty() const -> bool
    {
        return this->_operater == UnaryOperationKind::None
               || this->_operand == nullptr;
    }

    auto UnaryOperation::to_string() const -> std::string
    {
        if (this->empty()) {
            return {};
        }
        return this->evaluate();
    }

    auto UnaryOperation::evaluate() const -> std::string
    {
        if (this->_operater == UnaryOperationKind::None) {
            throw std::runtime_error("'_operater' is empty!");
        }
        if (this->_operand == nullptr) {
            throw std::runtime_error("'_operand' is null-pointer!");
        }

        return sqlxx::expression::to_string(this->_operater) + " "
               + this->_operand->evaluate();
    }

    auto UnaryOperation::clone() const -> UnaryOperation *
    {
        return new UnaryOperation { *this };
    }

    auto UnaryOperation::assignment(UnaryOperation const & origin) -> void
    {
        this->_operater = origin._operater;
        this->_operand =
            (origin._operand != nullptr) ? origin._operand->clone() : nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, UnaryOperation const unary_operation)
        -> std::ostream &
    {
        out << unary_operation.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_CLASS_HXX
