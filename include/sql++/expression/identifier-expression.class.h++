/*!
 * @file identifier-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_HXX

#include <string>
#include <type_traits>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/expression.class.h++>
#include <sql++/expression/literal-expression.class.h++>

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
     * @brief 識別子式（式中の識別子）を表現するクラス
     *
     * 本コードベースでは式中の識別子を「識別子式」と呼称する。 @n
     */
    class IdentifierExpression : public virtual Expression
    {
    public:
        /*!
         * @brief 識別子の名称の型
         */
        using NameType = std::string;

    public:
        /*!
         * @brief 識別子の名称の初期値
         */
        static NameType initial_name;

    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        IdentifierExpression();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name 識別子の名称
         */
        IdentifierExpression(NameType name);

        /*!
         * @brief デストラクタ
         */
        virtual ~IdentifierExpression() override = default;

        /*!
         * @brief 識別子の名称を取得する
         *
         * @return 識別子の名称
         */
        auto name() const -> NameType;

        /*!
         * @brief 識別子の名称を設定する
         *
         * @param[in] name 識別子の名称
         *
         * @return このオブジェクトの参照
         */
        auto name(NameType name) -> IdentifierExpression &;

        /*!
         * @brief 等値比較演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、等値比較演算式を生成する。 @n
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::equal_to （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 等値比較演算式
         */
        template<typename Type>
        auto equal_to(Type operand) const -> ConditionExpression const;

        /*!
         * @brief 非等値比較演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、非等値比較演算式を生成する。 @n
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::not_equal_to （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return 非等値比較演算式
         */
        template<typename Type>
        auto not_equal_to(Type operand) const -> ConditionExpression const;

        /*!
         * @brief IS 演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、 IS 演算式を生成する。
         *
         * @param[in] operand 右辺の式のオブジェクトまたはリテラルの内部値
         *
         * @return IS 演算式
         */
        template<typename Type>
        auto is(Type operand) const -> ConditionExpression const;

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
        virtual auto clone() const -> IdentifierExpression const * override;

    private:
        /*!
         * @brief 式のオブジェクトを生成する
         *
         * @param[in] expression_or_literal_inner_value 式のオブジェクトまたはリテラルの内部値
         *
         * @return 式のオブジェクト
         *         @c expression_or_literal_inner_value が式のオブジェクトの場合は、
         *         @c expression_or_literal_inner_value を元に生成した式のオブジェクトを返却する。 @n
         *         @c expression_or_literal_inner_value がリテラルの内部値の場合は、
         *         @c expression_or_literal_inner_value を元に生成したリテラル式のオブジェクトを返却する。 @n
         */
        template<typename Type>
        static auto make_expression(Type expression_or_literal_inner_value)
            -> Expression const *;

    private:
        /*!
         * @brief 識別子の名称
         */
        NameType _name;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out                   出力ストリーム
     * @param[in] identifier_expression 識別子式のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream & out, IdentifierExpression const identifier_expression)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    IdentifierExpression::NameType IdentifierExpression::initial_name = "";

    IdentifierExpression::IdentifierExpression()
        : IdentifierExpression(initial_name)
    {}

    IdentifierExpression::IdentifierExpression(NameType name) : _name(name)
    {}

    auto IdentifierExpression::name() const -> NameType
    {
        return this->_name;
    }

    auto IdentifierExpression::name(NameType name) -> IdentifierExpression &
    {
        this->_name = name;
        return *this;
    }

    template<typename Type>
    auto IdentifierExpression::equal_to(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression { "=",
                                     this->clone(),
                                     make_expression(operand) };
    }

    template<typename Type>
    auto IdentifierExpression::not_equal_to(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression { "<>",
                                     this->clone(),
                                     make_expression(operand) };
    }

    template<typename Type>
    auto IdentifierExpression::is(Type operand) const
        -> ConditionExpression const
    {
        return ConditionExpression { "IS",
                                     this->clone(),
                                     make_expression(operand) };
    }

    auto IdentifierExpression::to_string() const -> std::string
    {
        return this->_name;
    }

    auto IdentifierExpression::evaluate() const -> std::string
    {
        return this->to_string();
    }

    auto IdentifierExpression::clone() const -> IdentifierExpression const *
    {
        return new IdentifierExpression(*this);
    }

    inline namespace
    {
        template<typename Type, bool IS_BASE_OF_EXPRESSION = true>
        struct GetExpressionTypeImplementation
        {
            using ExpressionType = Type;
        };

        template<typename Type>
        struct GetExpressionTypeImplementation<Type, false>
        {
            using ExpressionType = LiteralExpression<Type>;
        };

        template<typename Type>
        struct GetExpressionType :
            public GetExpressionTypeImplementation<
                Type,
                std::is_base_of<Expression, Type>::value>
        {};
    } // namespace

    template<typename Type>
    auto IdentifierExpression::make_expression(
        Type expression_or_literal_inner_value) -> Expression const *
    {
        return new typename GetExpressionType<Type>::ExpressionType {
            expression_or_literal_inner_value
        };
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(
        std::ostream & out, IdentifierExpression const identifier_expression)
        -> std::ostream &
    {
        out << identifier_expression.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_HXX
