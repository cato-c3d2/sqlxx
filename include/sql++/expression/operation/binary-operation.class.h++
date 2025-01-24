/*!
 * @file binary-operation.class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_HXX

#include <stdexcept>
#include <string>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/logical-operatable.class.h++>

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
     * @brief ≪二項演算式≫を表現するクラス
     */
    class BinaryOperation :
        public virtual ConditionExpression,
        public virtual LogicalOperatable<BinaryOperation>
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        BinaryOperation();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operater         ≪二項演算種別≫
         * @param[in] left_expression  左辺の≪式≫
         * @param[in] right_expression 右辺の≪式≫
         */
        BinaryOperation(
            BinaryOperationKind operater,
            Expression const &  left_expression,
            Expression const &  right_expression);

        /*!
         * @brief コンストラクタ
         *
         * ≪二項演算種別≫のみを設定し、左辺の≪式≫及び右辺の≪式≫を後から設定する場合に使用する。
         *
         * @param[in] operater ≪二項演算種別≫
         */
        BinaryOperation(BinaryOperationKind operater);

        /*!
         * @brief コンストラクタ
         *
         * ≪二項演算種別≫と左辺の≪式≫を設定し、右辺の≪式≫を後から設定する場合に使用する。
         *
         * @param[in] operater        ≪二項演算種別≫
         * @param[in] left_expression 左辺の≪式≫
         */
        BinaryOperation(
            BinaryOperationKind operater, Expression const & left_expression);

        /*!
         * @brief デストラクタ
         */
        virtual ~BinaryOperation() override;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        BinaryOperation(BinaryOperation const & origin);

        /*!
         * @brief コピー代入演算子
         *
         * @param[in] origin コピー元のオブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto operator=(BinaryOperation const & origin) -> BinaryOperation &;

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
        virtual auto clone() const -> BinaryOperation * override;

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
        auto assignment(BinaryOperation const & origin) -> void;

    private:
        /*!
         * @brief ≪二項演算種別≫
         */
        BinaryOperationKind _operater;

        /*!
         * @brief 左辺の≪式≫
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        Expression const * _left_expression;

        /*!
         * @brief 右辺の≪式≫
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        Expression const * _right_expression;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] binary_operation ≪二項演算式≫のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, BinaryOperation const binary_operation)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    BinaryOperation::BinaryOperation()
        : BinaryOperation(BinaryOperationKind::None)
    {}

    BinaryOperation::BinaryOperation(
        BinaryOperationKind operater,
        Expression const &  left_expression,
        Expression const &  right_expression)
        : _operater(operater)
        , _left_expression(left_expression.clone())
        , _right_expression(right_expression.clone())
    {}

    BinaryOperation::BinaryOperation(BinaryOperationKind operater)
        : _operater(operater)
        , _left_expression(nullptr)
        , _right_expression(nullptr)
    {}

    BinaryOperation::BinaryOperation(
        BinaryOperationKind operater, Expression const & left_expression)
        : _operater(operater)
        , _left_expression(left_expression.clone())
        , _right_expression(nullptr)
    {}

    BinaryOperation::~BinaryOperation()
    {
        if (this->_left_expression != nullptr) {
            delete this->_left_expression;
        }
        if (this->_right_expression != nullptr) {
            delete this->_right_expression;
        }
    }

    BinaryOperation::BinaryOperation(BinaryOperation const & origin)
    {
        this->assignment(origin);
    }

    auto BinaryOperation::operator=(BinaryOperation const & origin)
        -> BinaryOperation &
    {
        this->assignment(origin);
        return *this;
    }

    auto BinaryOperation::empty() const -> bool
    {
        return this->_operater == BinaryOperationKind::None
               || this->_left_expression == nullptr
               || this->_right_expression == nullptr;
    }

    auto BinaryOperation::to_string() const -> std::string
    {
        if (this->empty()) {
            return {};
        }
        return this->evaluate();
    }

    auto BinaryOperation::evaluate() const -> std::string
    {
        if (this->_operater == BinaryOperationKind::None) {
            throw std::runtime_error("'_operater' is empty!");
        }
        if (this->_left_expression == nullptr) {
            throw std::runtime_error("'_left_expression' is null-pointer!");
        }
        if (this->_right_expression == nullptr) {
            throw std::runtime_error("'_right_expression' is null-pointer!");
        }

        return this->_left_expression->evaluate() + " "
               + sqlxx::expression::to_string(this->_operater) + " "
               + this->_right_expression->evaluate();
    }

    auto BinaryOperation::clone() const -> BinaryOperation *
    {
        return new BinaryOperation { *this };
    }

    auto BinaryOperation::assignment(BinaryOperation const & origin) -> void
    {
        this->_operater        = origin._operater;
        this->_left_expression = (origin._left_expression != nullptr)
                                     ? origin._left_expression->clone()
                                     : nullptr;
        this->_right_expression = (origin._right_expression != nullptr)
                                      ? origin._right_expression->clone()
                                      : nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, BinaryOperation const binary_operation)
        -> std::ostream &
    {
        out << binary_operation.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_HXX
