﻿# Задание 11. Демонстрационное тестирование 2024, никаких гарантий, всё как есть! :)
# Автор: Alexander BitsCode. Лицензия: Creative Commons.
# Архив: https://www.youtube.com/@BitsCode/. Исходный код: https://github.com/dreamy-cat/Academic.

print('    Задание 11. Вычисление объема и количества информации или данных\n')
print('    Решается устно если размерности небольшие, или всегда можно помочь себе калькулятором интерпретатора. '
      'Быть внимательней при чтения условия задания, часто конкретное слово определяет правило вычисления. '
      'Дополнительный материал: бит, байт, двоичная система счисления и двоичный код. Ну и помнить о приставках '
      'кило-мега-гига по степеням 2. Если структура сложная, то учитывать что элементы располагаются последовательно.')
print('\nТаблица степеней двойки, количества бит и пределы объема информации соответственно.')
print('Bits:\tBytes:\tKilobytes:\tMegabytes:')
bits = 1; volume = 1; kilo = 0x01 << 10; mega = 0x01 << 20
while (bits <= 20):
    # Арифметичесеий сдвиг влево на один бит равен умножению на два.
    volume = volume << 0x01
    print('%d\t%d\t%8.4f\t%5.4f' % (bits, volume, volume / kilo, volume / mega))
    bits += 1

#   Далее задания, просто решенные теоретически, обсуждения на вещаниях не было, в целом не сложно.
print('\n\n    Задание демонстрационного варианта 2024.')
print('    При регистрации в компьютерной системе каждому объекту присваивается идентификатор, состоящий из '
      '60 символов и содержащий только десятичные цифры и символы из 250-символьного специального алфавита. '
      'В базе данных для хранения каждого идентификатора отведено одинаковое и минимально возможное целое '
      'число байт. При этом используется посимвольное кодирование идентификаторов, все символы кодируются '
      'одинаковым и минимально возможным количеством бит.'
      '\n    Определите объем памяти в килобайтах, необходимый для хранения 65536 идентификаторов. В ответе '
      'запишите только целое число - количество Кбайт.')
print('\n    Решение карандашом. Сначала желательно определить мощность алфавита или ответить на вопрос: '
      'сколько бит и целых байт потребуется для хранения одного идентификатора? По условию имеем 10 цифр и '
      '250 символов, суммарно это 260 символов. Для определения объема одного символа вспоминаем что 8 бит, это '
      '2 в 8-ой степени или 256 различных комбинаций(вариаций). Недостаточно для хранения 260-ти, берем следующий '
      'размер 2 в 9-ой степени или 9 бит. Это уже 512 комбинаций и достаточно для сохранения всего алфавита.')
print('    Дальше вычисляем объемы хранения записи и общие. 60 символов умножаем на 9 бит, это равняется 540 бит. '
      'Т.к. биты следуют плотно по условию, т.е. без разделения на отдельные байты, то целое количество байт '
      'можно вычислять уже по общей длине слова или идентификатора. 540 бит делим на 8 и получаем 67.5, ближайщее '
      'целое будет 68 байт, т.к. сохранить 0.5 байта отдельно невозможно, следовательно округление всегда идет '
      'до ближайшего целого вверх.')
print('    Вычисляем общий объем, 65536 идентификаторов умножаем на 68 байт - 4456448 байт. Делим на 1024, т.к. '
      'ответ требуется в килобайтах, 4352 килобайта.')

print('\n\n    Задание  №11114.')
print('    При регистрации в компьютерной системе каждому пользователю выдается пароль, '
      'состоящий из 9 символов и содержащий только символы из 26-символьного набора прописных латинских букв. '
      'В базе данных для хранения сведений о каждом пользователе отведено одинаковое и минимально возможное '
      'целое число байт. При этом используют посимвольное кодирование паролей, все символы кодируют одинаковым и '
      'минимально возможным количеством бит. Кроме собственно пароля, для каждого пользователя в системе хранятся '
      'дополнительные сведения, для чего выделено целое число байт; это число одно и то же для всех пользователей.')
print('    Для хранения сведений о 20 пользователях, потребовалось 400 байт. Сколько байт выделено для хранения '
      'дополнительных сведений об одном пользователе? В ответе запишите только целое число - количество байт.')
print('\n    Краткое решение карандашом. Мощность алфавита из 26 символов, 5 бит на символ. 2 в 4-ой степени '
      'слишком мало, а 2 в 5-ой степени уже достатачно для символа. Пароль занимает 9 символов, это 5 * 9 = 45 бит, '
      'ближайшее целое число байт это 6 байт(48 бит / 8 бит). На 1 пользователя отводится 400 байт / 20 пользователей '
      'равно 20 байт или 160 бит. Остается 20 байт - 6 байт = 14 байт остается на каждого пользователя доп. сведений.')

print('\n\n    Задание №18715.')
print('    При регистрации в компьютерной системе каждому пользователю выдаётся пароль, состоящий из 15 символов. '
      'Для построения идентификатора используют только прописные латинские буквы (11 букв). В базе данных для '
      'хранения каждого пароля отведено одинаковое минимально возможное целое число байт. При этом используют '
      'посимвольное кодирование паролей, все символы кодируют одинаковым минимально возможным количеством бит. '
      'Кроме пароля для каждого пользователя в системе хранятся дополнительные сведения, для чего выделено 12 байт '
      'на каждого пользователя. Сколько байт нужно выделить для хранения сведений о 200 пользователях?')
print('\n    Краткое решение карандашом. Мощность алфавита для хранения 11 букв потребуется 4 бита, т.к. 2 в 3-ей '
      'степени 8 и недостаточно. 2 в 4-ой достаточно для 16-ти вариаций. 15 символов по 4 бита это 60 бит или '
      '8 байт в целых единицах. 12 байт дополнительных сведений плюс 8 байт пароля и всё это умножаем на '
      '200 пользователей и получается 4000 байт.')

print('\n\n    Задание №55598.')
print('    В информационной системе хранится информация об объектах определенной структуры. Описание каждого '
      'объекта включает в себя идентификатор объекта, описание струкутуры объекта и дополнительную информацию. '
      'Идентификатор объекта состоит из 9 заглавных латинских букв. Каждая буква идентификатора кодируется '
      'минимально возможным числом битов, а для хранения всего идентификатора отводится минимально возможное '
      'целое число байтов. Структура объекта описывается как последовательность, простых элементов.')
print('    Всего существует 1984 различных простых элемента. Каждый простой элемент кодируется одинаковым для '
      'всех элементов минимально возможным количеством битов. Для описания структуры объекта выделяется одинаковое '
      'для всех объектов минимально возможное количество байтов, достаточное для записи 50 простых элементов. '
      'Для хранения дополнительной информации выделяется одинаковое для всех объектов целое число байтов.')
print('    Известно, что для хранения данных 32768 объектах потребовалось, 4 мегабайта. Сколько байтов выделено для '
      'хранения дополнительной информации об объекте? В ответ запишите целое число байтов. ')
print('\n    Решение карандашом. Формулировка задания напоминает нарезку с повторениями, но как есть. Мощность алфавита '
      'заглавных латинских 26 букв - 5 бит, 4 бита не достотаточно, т.к. 2 в 4-ой степени 16, а 2 в 5-ой подходит. '
      'Всего 9 символов, т.е. 45 бит и с округлением до ближайшего целого это 6 байт. 1984 простых элемента кодируются '
      '11 битами, т.к. 2 в 10-ой степени это 1024, а 2 в 11-ой степени 2048 и этого достаточно, а в байтах это 2 байта '
      'на каждый элемент. Всего используется 4 мбайта памяти, это 4 * (2 в 10) * (2 в 10 степени) или 4194304 байта делим '
      'на 32768 объектов и равняются 128 байт на объект. Структура занимает 50 элементов * 11 бит = 550 бит или 69 байт. '
      ' Плюс идентификатор в 6 байт и получаем 75 байт на объект. Вычитаем из 128 байт - 75 = 53 байт доп. информации.')

print('\n\n    Задание №6258.')
print('    Для регистрации на сайте некоторой страны пользователю требуется придумать пароль. Длина пароля - ровно 11 '
      'символов. В качестве символов могут быть использованы десятичные цифры и 32 различные буквы местного алфавита, '
      'причем все буквы используются в двух начертаниях: как строчные, так и прописные (регистр буквы имеет значение!). '
      'Под хранение каждого пароля на компьютере отводится одинаковое и минимально возможное количество байтов. При этом '
      'используется посимвольное кодирование, и все символы кодируются одинаковым и минимально возможным количеством битов. '
      'Определите объем памяти, который используется для хранения 50 паролей. Ответ дайте в байтах.')
print('\n    Решение карандашом. Определим мощность алфавита в 32 символа умножаем на 2 из-за регистра, это 64 символа '
      'для представления потребуется ровно 6 бит и на 11 символов это 66 бит. Для представления 66 комбинация потребуется '
      '7 бит, т.к. 2 в 6-ой степени недостаточно, а 2 в 7-ой это 128 максимум. 7 бит умножить на 11 это 77 бит, или '
      '10 байт, с округлением в большую сторону. Для 50 паролей общий объем будет 50 умножить на 10 байт равно 500 байт.')
# 69, 9463.