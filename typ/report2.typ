#set text(font : "Latin Modern Math") 
#align(center)[コンピュータ実験レポート２]
#align(right)[24cb062h 菅原明]

すべてのファイルを https://github.com/meowwowcat/report2.git に置きました．
作成時にCHATGPTをところどころ使用してあります．


= 課題17

==　方法　(17.c)
課題16で作成下u.datを読み込む．ここでの誤差は0.5．

funcは自由落下の運動の式，calc_chi2はχ２乗．


==　結果(~/17/./a.out)

== 考察
χ二乗の値が大きいので間違っている．


= 課題18

== 方法（18.C)

誤差付きのデータを用いて，ｖとｘ０を最小二乗法で求める．

ndatはデータポイントの数，データの誤差は0.1

para_v,para_x0は傾きと切片を収納．



== 結果(output.txt)


#image("18-p.png")
== 考察

妥当な値がえられた．他の人も同じような値である．

= 課題19

== 方法(re19.c)
funcは速度$v$と初期位置$x_0$を用いて$v_x t+x_0$のあたい．

calc_chi2は最小二乗法のχ二乗計算を行う関数．

dcdvはχ二乗の微分．


$v_x$を2~8まで0.01の間隔で変化，$v_x$に対するχ二乗を計算．

datファイルに書き出し，gnuplotでグラフを表示させる．

== 結果
#image("wwwwwwwwwwww.png")

== 考察

妥当である．