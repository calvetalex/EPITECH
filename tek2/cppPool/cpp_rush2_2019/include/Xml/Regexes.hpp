/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** Regexes
*/

#ifndef REGEXES_HPP
    #define REGEXES_HPP

    #include <string>

    static const std::string r_overallSyntax("^<\\?xml\\sversion=\"1\\.0\"\\?>.|\\s*?<gift>.|\\s*?<toy>.|\\s*?<type>.|\\s*?<\\/type>.|\\s*?<title>.|\\s*?<\\/title>.|\\s*?<\\/toy>.|\\s*?<package>.|\\s*?<packed>.|\\s*?<\\/packed>.|\\s*?<wrapped>.|\\s*?<\\/wrapped>.|\\s*?<\\/package>.|\\s*?<\\/gift>.|\\s*?");
    static const std::string r_header("^<\\?xml\\sversion=\"1\\.0\"\\?>");
    static const std::string r_type("<type>(.*)<\\/type>");
    static const std::string r_title("<title>(.*)<\\/title>");
    static const std::string r_packed("<packed>(.*)<\\/packed>");
    static const std::string r_wrapped("<wrapped>(.*)<\\/wrapped");

    static const std::string r_typeTemplate("P1");
    static const std::string r_titleTemplate("P2");
    static const std::string r_packedTemplate("P3");
    static const std::string r_wrappedTemplate("P4");

#endif /* !REGEXES_HPP */
