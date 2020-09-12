from os import write

lineOneNames = [
    "罗湖", "国贸", "老街", "大剧院", "科学馆", "华强路", "岗厦", "会展中心", "购物公园", "香蜜湖", "车公庙",
    "竹子林", "侨城东", "华侨城", "世界之窗", "白石洲", "高新园", "深大", "桃园", "大新", "鲤鱼门", "前海湾",
    "新安", "宝安中心", "宝体", "坪洲", "西乡", "固戍", "后瑞", "机场东"
]
lineFiveNames = [
    "赤湾", "荔湾", "铁路公园", "妈湾", "前湾公园", "前湾", "桂湾", "前海湾", "临海", "宝华", "宝安中心",
    "翻身", "灵芝", "洪浪北", "兴东", "留仙洞", "西丽", "大学城", "塘朗", "长岭陂", "深圳北", "民治",
    "五和", "坂田", "杨美", "上水径", "下水径", "长龙", "布吉", "百鸽笼", "布心", "太安", "怡景", "黄贝岭"
]
lineElevenNames = [
    "福田", "车公庙", "红树湾南", "后海", "南山", "前海湾", "宝安", "碧海湾", "机场", "机场北", "福永",
    "桥头", "塘尾", "马安山", "沙井", "后亭", "松岗", "碧头"
]
with open("sample.html", 'r') as sampleHtml:
    lines = sampleHtml.readlines()
with open("lineFive.md", 'r') as lineOne:
    lineOnes = lineOne.readlines()

k = -1
for i in range(0, len(lineOnes)):
    if (lineOnes[i][0:2] == '##'):
        k = k + 1
        with open(lineFiveNames[k] + '.html', 'w') as htmlFile:
            htmlFile.writelines(lines[:14])
            htmlFile.write("<h1>" + lineFiveNames[k] + "</h1>\n")
            htmlFile.write("<h2>站点信息</h2>\n<p>")
            for j in range(i + 1, len(lineOnes)):
                if lineOnes[j][0:2] != '##':
                    htmlFile.write(lineOnes[j])
                else:
                    break
            htmlFile.write("</p>")
            htmlFile.write("<h2>线路图</h2>\n")
            htmlFile.write("<p\n")
            htmlFile.write(
                "style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\n"
            )
            htmlFile.write("<img src=:/images/line5_.png />\n")
            htmlFile.write("</p>\n")
            htmlFile.write("</body>\n")
            htmlFile.write("</html>")
