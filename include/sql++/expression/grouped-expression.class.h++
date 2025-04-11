/*!
 * @file grouped-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__GROUPED_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__GROUPED_EXPRESSION_CLASS_HXX

#include <stdexcept>
#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>
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
     * @brief ≪グループ化された式≫を表現するクラス
     *
     * ≪グループ化された式≫とは、丸括弧（ @c '(' @c ')' ）で囲まれた式のことである。 @n
     * GROUP 句とは何の関係もない点に注意されたし。 @n
     */
    class GroupedExpression :
        public virtual Expression,
        public virtual LogicalOperatable<BinaryOperation>
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        GroupedExpression();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] inner_expression 内包される≪式≫
         */
        GroupedExpression(Expression const & inner_expression);

        /*!
         * @brief デストラクタ
         */
        virtual ~GroupedExpression() override;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        GroupedExpression(GroupedExpression const & origin);

        /*!
         * @brief コピー代入演算子
         *
         * @param[in] origin コピー元のオブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto operator=(GroupedExpression const & origin) -> GroupedExpression &;

        /*!
         * @brief 内包される≪式≫を取得する
         *
         * このオブジェクトが保持する内包される≪式≫を複製し、そのポインタを返却する。 @n
         *
         * @return 複製した内包される≪式≫のポインタ
         */
        auto inner_expression() const -> Expression *;

        /*!
         * @brief 内包される≪式≫を設定する
         *
         * 引数として指定した≪式≫を複製し、そのポインタをこのオブジェクトの内包される≪式≫として保持する。 @n
         *
         * @param[in] inner_expression 内包される≪式≫
         *
         * @return このオブジェクトの参照
         */
        auto inner_expression(Expression const & inner_expression)
            -> GroupedExpression &;

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
        virtual auto clone() const -> GroupedExpression * override;

    private:
        /*!
         * @brief このオブジェクトにコピー元のオブジェクトを割り当てる
         *
         * このオブジェクトの各データメンバに、
         * @c origin の各データメンバを代入する。 @n
         * @n
         * NOTE コピーコンストラクタとコピー代入演算子の実装を共通化するために実装した。 @n
         *
         * @param[in] origin コピー元のオブジェクト
         */
        auto assignment(GroupedExpression const & origin) -> void;

    private:
        /*!
         * @brief 内包される≪式≫
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        Expression const * _inner_expression;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪グループ化された式≫を生成する
     *
     * @param[in] expression グループ化する式のオブジェクト
     *
     * @return ≪グループ化された式≫
     */
    auto parentheses(Expression const & expression) -> GroupedExpression;

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out                出力ストリーム
     * @param[in] grouped_expression ≪グループ化された式≫のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto
    operator<<(std::ostream & out, GroupedExpression const grouped_expression)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    GroupedExpression::GroupedExpression() : _inner_expression(nullptr)
    {}

    GroupedExpression::GroupedExpression(Expression const & inner_expression)
        : _inner_expression(inner_expression.clone())
    {}

    GroupedExpression::~GroupedExpression()
    {
        if (this->_inner_expression != nullptr) {
            delete this->_inner_expression;
        }
    }

    GroupedExpression::GroupedExpression(GroupedExpression const & origin)
    {
        this->assignment(origin);
    }

    auto GroupedExpression::operator=(GroupedExpression const & origin)
        -> GroupedExpression &
    {
        this->assignment(origin);
        return *this;
    }

    auto GroupedExpression::inner_expression() const -> Expression *
    {
        return this->_inner_expression != nullptr
                   ? this->_inner_expression->clone()
                   : nullptr;
    }

    auto
    GroupedExpression::inner_expression(Expression const & inner_expression)
        -> GroupedExpression &
    {
        this->_inner_expression = inner_expression.clone();
        return *this;
    }

    auto GroupedExpression::empty() const -> bool
    {
        if (this->_inner_expression == nullptr) {
            return true;
        }
        try {
            // TODO [要検討] このオブジェクトが空であるか否かの判定について、
            //      内包される≪式≫の evaluate メンバ関数の戻り値で判定せず、
            //      直接、内包される≪式≫が空であるか否かを判定すべき。
            //      従って、 Expression::empty メンバ関数等を実装すべき。
            return this->_inner_expression->evaluate().empty();
        } catch (std::runtime_error &) {
            // NOTE SQLの文法エラーが発生した場合、このオブジェクトが空であるとみなす
            return true;
        }
    }

    auto GroupedExpression::to_string() const -> std::string
    {
        if (this->empty()) {
            return {};
        }
        return this->evaluate();
    }

    auto GroupedExpression::evaluate() const -> std::string
    {
        using namespace std::literals::string_literals;

        if (this->_inner_expression == nullptr) {
            throw std::runtime_error("'_inner_expression' is null-pointer!");
        }

        std::string const inner_expression_as_string =
            this->_inner_expression->evaluate();

        return "("s + inner_expression_as_string + ")"s;
    }

    auto GroupedExpression::clone() const -> GroupedExpression *
    {
        return new GroupedExpression { *this };
    }

    auto GroupedExpression::assignment(GroupedExpression const & origin) -> void
    {
        this->_inner_expression = (origin._inner_expression != nullptr)
                                      ? origin._inner_expression->clone()
                                      : nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto parentheses(Expression const & expression) -> GroupedExpression
    {
        return GroupedExpression { expression };
    }

    auto
    operator<<(std::ostream & out, GroupedExpression const grouped_expression)
        -> std::ostream &
    {
        out << grouped_expression.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__GROUPED_EXPRESSION_CLASS_HXX
