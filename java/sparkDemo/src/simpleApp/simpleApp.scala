package simpleApp

import org.apache.spark.SparkContext;
import org.apache.spark.SparkContext._;
import org.apache.spark.SparkConf;
import java.util.Calendar
import java.text.SimpleDateFormat

object simpleApp {
  
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf().setMaster("local").set("spark.worker.memory", "4g").setAppName("Simple Application");
    val sc = new SparkContext(conf);
    
    val start = Calendar.getInstance().getTime();
    val logFile = "./a"; 
    val logData = sc.textFile(logFile).cache();
    
    val logFile2 = "./b";
    val logData2 = sc.textFile(logFile2).cache();
    
    val res = logData.intersection(logData2);
//    val res = logData.sortBy(line => line.toLong, true, 2);
    res.coalesce(1, true).saveAsTextFile("res");
//    for(i <- 0 until res.length){
//      println(res(i));
//    }
    val end = Calendar.getInstance().getTime();
    println(start);
    println(end);
//    val numAs = logData.filter(line => line.contains("a")).count();
//    val numBs = logData.filter(line => line.contains("b")).count();
//    println("Line with a:%s,Line with b:".format(numAs,numBs));
  }

}