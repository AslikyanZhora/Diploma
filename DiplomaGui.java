import java.awt.Color;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.jfree.chart.JFreeChart; 
import org.jfree.data.xy.XYDataset; 
import org.jfree.data.xy.XYSeries; 
import org.jfree.ui.ApplicationFrame;
import org.jfree.ui.RefineryUtilities;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartFrame;
import org.jfree.chart.plot.PlotOrientation; 
import org.jfree.data.xy.XYSeriesCollection; 

@SuppressWarnings("serial")
public class DiplomaGui extends ApplicationFrame {

   public DiplomaGui( String applicationTitle, String chartTitle ) {
      super(applicationTitle);
      JFreeChart xylineChart = ChartFactory.createXYLineChart(
         chartTitle ,
         "Nanoseconds" ,
         "",
         createDataset() ,
         PlotOrientation.VERTICAL ,
         true , true , false);
      
      xylineChart.getPlot().setBackgroundPaint( Color.BLACK );    
      
	  ChartFrame chartFrame = new ChartFrame("", xylineChart);
	  chartFrame.setVisible(true);
	  chartFrame.setSize(300, 300);
   }
   
   private XYDataset createDataset( ) {
      Map<String, List<Integer>> map = new HashMap<>();
      final XYSeriesCollection dataset = new XYSeriesCollection( );  
      
      map.put("a", Arrays.asList(new Integer[] {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0}));
      map.put("b", Arrays.asList(new Integer[] {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0}));
      map.put("c", Arrays.asList(new Integer[] {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0}));
      map.put("d", Arrays.asList(new Integer[] {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}));
      map.put("x", Arrays.asList(new Integer[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 15}));
      map.put("y", Arrays.asList(new Integer[] {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 18}));
      map.put("out", Arrays.asList(new Integer[] {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 14}));
      
      int y = 1;

      for (Map.Entry<String, List<Integer>> entry : map.entrySet()) {
    	  XYSeries series = new XYSeries( entry.getKey());

    	  double  x = 1;
    	  for (int i = 0; i < entry.getValue().size() - 1; ++i) {
    		  series.add(x,y + entry.getValue().get(i));
    		  x = x + 1 + entry.getValue().get(16) * 0.01;
    		  series.add(x,y + entry.getValue().get(i));
    	  }
    	  y = y + 2;
          dataset.addSeries(series);
      }      
              
      return dataset;
   }

   public static void main( String[ ] args ) {
	   DiplomaGui chart = new DiplomaGui("Gate level modeling",
         "Gates timing diagramm");
      chart.pack( );          
      RefineryUtilities.centerFrameOnScreen( chart );          
      chart.setVisible( true ); 
   }
   
}