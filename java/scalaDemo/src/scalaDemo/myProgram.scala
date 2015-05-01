package myProgram

import scala.io.Source;
import scala.collection.immutable.List;
import java.io.FileWriter;
import java.util.Calendar

object myProgram {

  def find(A:Array[Long], B:Long) : Boolean = {
    var start = 0;
    var end = A.length;
    while(start<=end){
      var mid = (start+end)/2;
      if(A(mid) == B){
        return true;
      }
      else if(A(mid) < B){
        start = mid+1;
      }
      else end = mid-1;
    }
    return false;
  }
  
  def main(args: Array[String]): Unit = {
    
    val start = Calendar.getInstance().getTime();
    println(start);
    
    val A = "./a"; 
    var Alines = new Array[Long](40000000);
    var i = 0;
    for(line <- Source.fromFile(A).getLines){
      //Alines(i) = line.toLong;
      Alines(i) = line.toLong;
      i = i+1;
    }
        
    var end = Calendar.getInstance().getTime();
    println(end);
    
    Alines = Alines.sorted;
    
    end = Calendar.getInstance().getTime();
    println(end); 
    
    var B = "./b";
    var Blines = new Array[Long](40000000);
    i = 0;
    for(line <- Source.fromFile(B).getLines){
      Blines(i) = line.toLong;
      i = i+1;
    }
   
    end = Calendar.getInstance().getTime();
    println(end); 
    
    var interSection = List[Long]();
    i = 0;
    for(i <- 0 until Blines.length){
      if(find(Alines,Blines(i))){
        interSection +:=Blines(i);
      }
    }
    
    //var res = List[Long](30000);
//    for(line <- Source.fromFile(file).getLines){
//      //read file
//      lines = lines ::: List(line.toLong);
//    }
    
    end = Calendar.getInstance().getTime();
    println(end);   
    
    var res = interSection.toArray;
    var fw = new FileWriter("test.txt",true);
    for(i <- 0 until res.length){
      fw.write(res(i).toString+"\n")
    }
    fw.close();
    
    end = Calendar.getInstance().getTime();
    println(end); 
  }

}