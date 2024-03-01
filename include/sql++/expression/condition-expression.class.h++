/*!
 * @file condition-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_HXX

#include <stdexcept>
#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/logical-operatable.class.h++>

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
     * @brief 条件式を表現するクラス
     */
    class ConditionExpression :
        public virtual Expression,
        public virtual LogicalOperatable<ConditionExpression>
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        ConditionExpression();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operater         演算子
         * @param[in] left_expression  左辺の式
         * @param[in] right_expression 右辺の式
         */
        ConditionExpression(
            std::string        operater,
            Expression const * left_expression,
            Expression const * right_expression);

        /*!
         * @brief デストラクタ
         */
        virtual ~ConditionExpression() override;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        ConditionExpression(ConditionExpression const & origin);

        /*!
         * @brief コピー代入演算子
         *
         * @param[in] origin コピー元のオブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto operator=(ConditionExpression const & origin)
            -> ConditionExpression &;

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
        virtual auto clone() const -> ConditionExpression const * override;

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
        auto assignment(ConditionExpression const & origin) -> void;

    private:
        /*!
         * @brief 演算子
         */
        std::string _operater;

        /*!
         * @brief 左辺の式
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        Expression const * _left_expression;

        /*!
         * @brief 右辺の式
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
     * @param[in] out                  出力ストリーム
     * @param[in] condition_expression 条件式のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream & out, ConditionExpression const condition_expression)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    ConditionExpression::ConditionExpression()
        : ConditionExpression("", nullptr, nullptr)
    {}

    ConditionExpression::ConditionExpression(
        std::string        operater,
        Expression const * left_expression,
        Expression const * right_expression)
        : _operater(operater)
        , _left_expression(left_expression)
        , _right_expression(right_expression)
    {}

    ConditionExpression::~ConditionExpression()
    {
        if (this->_left_expression != nullptr) {
            delete this->_left_expression;
        }
        if (this->_right_expression != nullptr) {
            delete this->_right_expression;
        }
    }

    ConditionExpression::ConditionExpression(ConditionExpression const & origin)
    {
        this->assignment(origin);
    }

    auto ConditionExpression::operator=(ConditionExpression const & origin)
        -> ConditionExpression &
    {
        this->assignment(origin);
        return *this;
    }

    auto ConditionExpression::empty() const -> bool
    {
        return this->_operater.empty() || this->_left_expression == nullptr
               || this->_right_expression == nullptr;
    }

    auto ConditionExpression::to_string() const -> std::string
    {
        if (this->empty()) {
            return {};
        }
        return this->evaluate();
    }

    auto ConditionExpression::evaluate() const -> std::string
    {
        if (this->_operater.empty()) {
            throw std::runtime_error("'_operater' is empty!");
        }
        if (this->_left_expression == nullptr) {
            throw std::runtime_error("'_left_expression' is null-pointer!");
        }
        if (this->_right_expression == nullptr) {
            throw std::runtime_error("'_right_expression' is null-pointer!");
        }

        return this->_left_expression->evaluate() + " " + this->_operater + " "
               + this->_right_expression->evaluate();
    }

    auto ConditionExpression::clone() const -> ConditionExpression const *
    {
        return new ConditionExpression(*this);
    }

    auto ConditionExpression::assignment(ConditionExpression const & origin)
        -> void
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

    auto operator<<(
        std::ostream & out, ConditionExpression const condition_expression)
        -> std::ostream &
    {
        out << condition_expression.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_HXX
