package de.fosd.typechef.linux

import java.io._
import xml.XML

/** internal data collection, comparing allyes performance vs va performance */
object CollectTimes extends App {

  val files = scala.io.Source.fromFile("linux_files.lst").getLines.toList

  for (file <- files) {
    try {
    val vastats=scala.io.Source.fromFile("l/"+file+".dbg").getLines.toList.last
    val istats=scala.io.Source.fromFile("l/"+file+".i.dbg").getLines.toList.last
    val errors =(XML.load(new FileReader("l/"+file+".c.xml")) \ "_").size
    val ierrors =(XML.load(new FileReader("l/"+file+".i.xml")) \ "_").size
    val out= file+";"+vastats+";"+istats+";"+errors+";"+ierrors
    println(out) 
  } catch {
    case e:Exception => println("error "+file+";"+e.getMessage)
  }
  }


}
