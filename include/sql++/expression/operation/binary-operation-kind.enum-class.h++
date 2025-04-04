/*!
 * @file binary-operation-kind.enum-class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_KIND_ENUM_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_KIND_ENUM_CLASS_HXX

#include <string>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /**
     * @brief ≪二項演算種別≫を定義する列挙型
     */
    enum class BinaryOperationKind
    {
        /**
         * @brief ≪演算種別未定≫
         *
         * 演算の種類が未定である場合等に使用する。 @n
         */
        None = 0,

        /**
         * @brief ≪等値比較演算≫
         */
        EqualTo,

        /**
         * @brief ≪非等値比較演算≫
         */
        NotEqualTo,

        /**
         * @brief ≪比較演算（小なり）≫
         */
        Less,

        /**
         * @brief ≪比較演算（以下）≫
         */
        LessEqual,

        /**
         * @brief ≪比較演算（大なり）≫
         */
        Greater,

        /**
         * @brief ≪比較演算（以上）≫
         */
        GreaterEqual,

        /**
         * @brief ≪論理積演算≫
         */
        LogicalAnd,

        /**
         * @brief ≪論理和演算≫
         */
        LogicalOr,

        /**
         * @brief ≪IS演算≫
         */
        Is,
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /**
     * @brief ≪二項演算種別≫の文字列表現を返却する
     *
     * @param[in] operation_kind 文字列に変換する≪二項演算種別≫
     *
     * @return @c operation_kind の文字列表現
     */
    auto to_string(BinaryOperationKind operation_kind) -> std::string;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    inline namespace
    {
        /*!
         * @brief 各種≪二項演算種別≫の演算子の記号又はキーワードを定義するクラス
         *
         * 各種≪二項演算種別≫の文字列表現は
         * @c sqlxx::expression::to_string(BinaryOperationKind)
         * を使用して取得する想定のため、このクラスは外部に公開しない。 @n
         * （そのために無名名前空間内に定義している。） @n
         */
        class BinaryOperatorSymbol
        {
        public:
            /**
             * @brief 演算子の記号 : ≪等値比較演算≫
             */
            static constexpr auto EQUAL_TO = "=";

            /**
             * @brief 演算子の記号 : ≪非等値比較演算≫
             */
            static constexpr auto NOT_EQUAL_TO = "<>";

            /**
             * @brief 演算子の記号 : ≪比較演算（小なり）≫
             */
            static constexpr auto LESS = "<";

            /**
             * @brief 演算子の記号 : ≪比較演算（以下）≫
             */
            static constexpr auto LESS_EQUAL = "<=";

            /**
             * @brief 演算子の記号 : ≪比較演算（大なり）≫
             */
            static constexpr auto GREATER = ">";

            /**
             * @brief 演算子の記号 : ≪比較演算（以上）≫
             */
            static constexpr auto GREATER_EQUAL = ">=";

            /**
             * @brief 演算子のキーワード : ≪論理積演算≫
             */
            static constexpr auto LOGICAL_AND = "AND";

            /**
             * @brief 演算子のキーワード : ≪論理和演算≫
             */
            static constexpr auto LOGICAL_OR = "OR";

            /**
             * @brief 演算子のキーワード : ≪IS演算≫
             */
            static constexpr auto IS = "IS";
        };
    } // namespace

    auto to_string(BinaryOperationKind operation_kind) -> std::string
    {
        switch (operation_kind) {
        case BinaryOperationKind::EqualTo:
            return BinaryOperatorSymbol::EQUAL_TO;
        case BinaryOperationKind::NotEqualTo:
            return BinaryOperatorSymbol::NOT_EQUAL_TO;
        case BinaryOperationKind::Less:
            return BinaryOperatorSymbol::LESS;
        case BinaryOperationKind::LessEqual:
            return BinaryOperatorSymbol::LESS_EQUAL;
        case BinaryOperationKind::Greater:
            return BinaryOperatorSymbol::GREATER;
        case BinaryOperationKind::GreaterEqual:
            return BinaryOperatorSymbol::GREATER_EQUAL;
        case BinaryOperationKind::LogicalAnd:
            return BinaryOperatorSymbol::LOGICAL_AND;
        case BinaryOperationKind::LogicalOr:
            return BinaryOperatorSymbol::LOGICAL_OR;
        case BinaryOperationKind::Is:
            return BinaryOperatorSymbol::IS;
        case BinaryOperationKind::None:
        default:
            return "";
        }
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_KIND_ENUM_CLASS_HXX
