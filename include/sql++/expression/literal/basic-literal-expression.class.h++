/*!
 * @file basic-literal-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__LITERAL__BASIC_LITERAL_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__LITERAL__BASIC_LITERAL_EXPRESSION_CLASS_HXX

#include <string>

#include <sql++/expression/comparison-operable.class.h++>
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
     * @brief リテラル式（式中のリテラル）を表現するクラス
     *
     * 本コードベースでは式中のリテラルを「リテラル式」と呼称する。 @n
     */
    template<typename Type>
    class BasicLiteralExpression :
        public virtual Expression,
        public virtual ComparisonOperable
    {
    public:
        /*!
         * @brief リテラルの内部値の型
         */
        using InnerValueType = Type;

    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        BasicLiteralExpression();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] inner_value リテラルの内部値
         */
        BasicLiteralExpression(Type inner_value);

        /*!
         * @brief デストラクタ
         */
        virtual ~BasicLiteralExpression() override = default;

        /*!
         * @brief リテラルの内部値を取得する
         *
         * @return リテラルの内部値
         */
        auto inner_value() const -> InnerValueType;

        /*!
         * @brief リテラルの内部値を設定する
         *
         * @param[in] inner_value リテラルの内部値
         *
         * @return このオブジェクトの参照
         */
        auto inner_value(InnerValueType inner_value)
            -> BasicLiteralExpression<Type> &;

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
        virtual auto clone() const
            -> BasicLiteralExpression<Type> const * override;

    private:
        /*!
         * @brief リテラルの内部値
         */
        Type _inner_value;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out                      出力ストリーム
     * @param[in] basic_literal_expression リテラル式のオブジェクト
     *
     * @return 出力ストリーム
     */
    template<typename Type>
    auto operator<<(
        std::ostream &                     out,
        BasicLiteralExpression<Type> const basic_literal_expression)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    template<typename Type>
    BasicLiteralExpression<Type>::BasicLiteralExpression()
        : BasicLiteralExpression(Type {})
    {}

    template<typename Type>
    BasicLiteralExpression<Type>::BasicLiteralExpression(Type inner_value)
        : _inner_value(inner_value)
    {}

    template<typename Type>
    auto BasicLiteralExpression<Type>::inner_value() const -> InnerValueType
    {
        return this->_inner_value;
    }

    template<typename Type>
    auto BasicLiteralExpression<Type>::inner_value(InnerValueType inner_value)
        -> BasicLiteralExpression<Type> &
    {
        this->_inner_value = inner_value;
        return *this;
    }

    template<typename Type>
    auto BasicLiteralExpression<Type>::to_string() const -> std::string
    {
        return std::to_string(this->_inner_value);
    }

    /*!
     * @brief このオブジェクトの文字列表現を返却する
     *
     * 【メンバ関数の特殊化について】 @n
     * このリテラルの内部値の型が @c bool の場合、
     * 論理値を示す文字列を返却する。 @n
     *
     * @return このオブジェクトの文字列表現
     */
    template<>
    auto BasicLiteralExpression<bool>::to_string() const -> std::string
    {
        return this->_inner_value ? "true" : "false";
    }

    /*!
     * @brief このオブジェクトの文字列表現を返却する
     *
     * 【メンバ関数の特殊化について】 @n
     * このリテラルの内部値の型が @c std::string の場合、
     * 内部値の両端をシングルクォーテーションで囲んだ文字列を返却する。 @n
     *
     * @return このオブジェクトの文字列表現
     */
    template<>
    auto BasicLiteralExpression<std::string>::to_string() const -> std::string
    {
        using namespace std::literals::string_literals;

        return "'"s + this->_inner_value + "'"s;
    }

    /*!
     * @brief このオブジェクトの文字列表現を返却する
     *
     * 【メンバ関数の特殊化について】 @n
     * このリテラルの内部値の型が <tt>char const *</tt> の場合、
     * 内部値の両端をシングルクォーテーションで囲んだ文字列を返却する。 @n
     *
     * @return このオブジェクトの文字列表現
     */
    template<>
    auto BasicLiteralExpression<char const *>::to_string() const -> std::string
    {
        using namespace std::literals::string_literals;

        return "'"s + this->_inner_value + "'"s;
    }

    /*!
     * @brief このオブジェクトの文字列表現を返却する
     *
     * 【メンバ関数の特殊化について】 @n
     * このリテラルの内部値の型が @c std::nullptr_t の場合、
     * NULL を示す文字列を返却する。 @n
     *
     * @return このオブジェクトの文字列表現
     */
    template<>
    auto BasicLiteralExpression<std::nullptr_t>::to_string() const
        -> std::string
    {
        return "NULL";
    }

    template<typename Type>
    auto BasicLiteralExpression<Type>::evaluate() const -> std::string
    {
        return this->to_string();
    }

    template<typename Type>
    auto BasicLiteralExpression<Type>::clone() const
        -> BasicLiteralExpression<Type> const *
    {
        return new BasicLiteralExpression(*this);
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    template<typename Type>
    auto operator<<(
        std::ostream &                     out,
        BasicLiteralExpression<Type> const basic_literal_expression)
        -> std::ostream &
    {
        out << basic_literal_expression.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__LITERAL__BASIC_LITERAL_EXPRESSION_CLASS_HXX