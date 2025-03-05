#!/bin/bash

count_text_stats(){
	input_text="$1"
	char_count=$(echo -n "$input_text" | wc -m )
	word_count=$(echo "$input_text" | wc -w )
	space_count=$(echo "$input_text" | tr -cd ' ' | wc -c )
	special_count=$(echo "$input_text" | tr -cd '[:punct:]' | wc -c )


echo "Text analysis report :"
echo " "
echo "Character count : $char_count"
echo "word count : $word_count"
echo "space count : $space_count"
echo "spl count : $special_count"
echo " "
}

text_to_analyze="This is an examle text xontaining 1special character @"
count_text_stats "$text_to_analyze"
echo "Ho gya"
