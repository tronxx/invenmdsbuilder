object Form_consrelvta: TForm_consrelvta
  Left = 210
  Top = 169
  Width = 796
  Height = 533
  Caption = 'Consulta Relaci�n de Ventas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 780
    Height = 494
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 780
      Height = 81
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object GroupBox1: TGroupBox
        Left = 313
        Top = 0
        Width = 449
        Height = 81
        Align = alLeft
        Caption = 'Reporte Acumulado Ventas'
        TabOrder = 0
        object SpeedButton1: TSpeedButton
          Left = 160
          Top = 21
          Width = 147
          Height = 22
          Action = definir_zonasexclu
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
            0000000000000000000000000000FFFF0000FFFF0000FFFF0000FF00FF00FF00
            FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF000000000000000000FFFF
            FF0000FFFF00FFFFFF0000FFFF0000000000FFFF0000FFFF0000FF00FF00FF00
            FF00FF00FF00FF00FF0000000000FFFFFF000000000000FFFF00FFFFFF0000FF
            FF000000000000FFFF00FFFFFF0000FFFF0000000000FFFF0000FF00FF00FF00
            FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF0000000000000000000000
            000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FF00FF00FF00
            FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF000000000000FF
            FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FF00FF00FF00
            FF00FF00FF00000000000000000000000000000000000000000000FFFF00FFFF
            FF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
            000000000000FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFFFF000000
            0000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF00000000
            0000FFFFFF0000FFFF0000000000000000000000000000000000000000000000
            0000000000000000000000FFFF00FFFFFF000000000000000000FFFF00000000
            000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
            FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FFFF00000000
            0000FFFFFF0000FFFF00FFFFFF0000FFFF000000000000000000000000000000
            0000000000000000000000000000FFFFFF00FFFFFF0000000000FFFF00000000
            000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
            FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
            0000FFFFFF0000FFFF00FFFFFF0000FFFF000000000000000000000000000000
            000000000000FFFFFF0000000000000000000000000000000000FFFF00000000
            000000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000
            0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000000000000000
            0000FF00FF00000000000000000000000000000000000000000000000000FFFF
            FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
            0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
        end
        object BitBtn3: TBitBtn
          Left = 6
          Top = 19
          Width = 147
          Height = 25
          Action = reporte_acumulados
          Caption = 'Reporte Acumulados'
          TabOrder = 0
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF000000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000000000000FF00FF0000000000BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000000000000000000000000000000000000000FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD000000000000000000BDBD
            BD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBD
            BD00FFFFFF00BDBDBD00FFFFFF000000FF00FFFFFF000000000000000000FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD0000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
            FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
            0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
            FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF0000000000BDBDBD00FFFFFF0000000000FFFF
            FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00000000000000000000000000000000000000000000000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
        object mmo_zonasexclu: TMemo
          Left = 336
          Top = 15
          Width = 111
          Height = 64
          Align = alRight
          Lines.Strings = (
            'mmo_zonasexclu')
          TabOrder = 1
        end
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 313
        Height = 81
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 1
        object Label8: TLabel
          Left = 16
          Top = 16
          Width = 60
          Height = 13
          Caption = 'Fecha Inicial'
        end
        object Label9: TLabel
          Left = 16
          Top = 38
          Width = 55
          Height = 13
          Caption = 'Fecha Final'
        end
        object date_fecini: TDateTimePicker
          Left = 87
          Top = 12
          Width = 90
          Height = 21
          CalAlignment = dtaLeft
          Date = 37548.4553024306
          Time = 37548.4553024306
          DateFormat = dfShort
          DateMode = dmComboBox
          Kind = dtkDate
          ParseInput = False
          TabOrder = 0
        end
        object date_fecfin: TDateTimePicker
          Left = 87
          Top = 34
          Width = 90
          Height = 21
          CalAlignment = dtaLeft
          Date = 37548.4553024306
          Time = 37548.4553024306
          DateFormat = dfShort
          DateMode = dmComboBox
          Kind = dtkDate
          ParseInput = False
          TabOrder = 1
        end
        object BitBtn1: TBitBtn
          Left = 184
          Top = 8
          Width = 75
          Height = 25
          TabOrder = 2
          OnClick = BitBtn1Click
          Kind = bkOK
        end
        object BitBtn2: TBitBtn
          Left = 184
          Top = 40
          Width = 75
          Height = 25
          Action = impritext
          Caption = 'Imprimir'
          TabOrder = 3
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF000000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000000000000FF00FF0000000000BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
            BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000000000000000000000000000000000000000FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD000000000000000000BDBD
            BD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBD
            BD00FFFFFF00BDBDBD00FFFFFF000000FF00FFFFFF000000000000000000FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
            FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD0000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
            FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
            0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
            FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF0000000000BDBDBD00FFFFFF0000000000FFFF
            FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00000000000000000000000000000000000000000000000000FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
      end
    end
    object GroupBox2: TGroupBox
      Left = 0
      Top = 81
      Width = 780
      Height = 413
      Align = alClient
      Caption = 'Ventas'
      TabOrder = 1
      object dbgrd_ventas: TdxDBGrid
        Left = 2
        Top = 15
        Width = 776
        Height = 396
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDRELVTAS'
        ShowGroupPanel = True
        ShowSummaryFooter = True
        SummaryGroups = <
          item
            DefaultGroup = False
            SummaryItems = <
              item
                ColumnName = 'dbgrd_ventasPRECIOLISTA'
                SummaryField = 'PRECIOLISTA'
                SummaryFormat = '$,0.00;-$,0.00'
                SummaryType = cstSum
              end>
            Name = 'dbgrd_ventasSummaryGroup1'
          end>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        DataSource = dts_relvtas
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        ShowRowFooter = True
        object dbgrd_ventasREMATE: TdxDBGridMaskColumn
          Caption = 'Remate'
          Sorted = csUp
          Visible = False
          BandIndex = 0
          RowIndex = 0
          FieldName = 'REMATE'
          GroupIndex = 0
          SummaryGroupName = 'dbgrd_ventasSummaryGroup1'
        end
        object dbgrd_ventasUBICA: TdxDBGridMaskColumn
          Caption = 'Ubicaci�n'
          Sorted = csUp
          Visible = False
          BandIndex = 0
          RowIndex = 0
          FieldName = 'UBICA'
          GroupIndex = 1
          SummaryGroupName = 'dbgrd_ventasSummaryGroup1'
        end
        object dbgrd_ventasZona: TdxDBGridMaskColumn
          Caption = 'Zona'
          Sorted = csUp
          Visible = False
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ZONAPTVTA'
          GroupIndex = 2
          SummaryGroupName = 'dbgrd_ventasSummaryGroup1'
        end
        object dbgrd_ventasPTOVTA: TdxDBGridMaskColumn
          Caption = 'Pto.Vta'
          Sorted = csUp
          Visible = False
          BandIndex = 0
          RowIndex = 0
          FieldName = 'PTOVTA'
          GroupIndex = 3
          SummaryGroupName = 'dbgrd_ventasSummaryGroup1'
        end
        object dbgrd_ventasFecha: TdxDBGridDateColumn
          Caption = 'Fecha'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHA'
        end
        object dbgrd_ventasHORA: TdxDBGridMaskColumn
          BandIndex = 0
          RowIndex = 0
          FieldName = 'HORA'
        end
        object dbgrd_ventasNombre: TdxDBGridMaskColumn
          Caption = 'Nombre'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'NOMBRE'
        end
        object dbgrd_ventasPOBLAC: TdxDBGridMaskColumn
          Caption = 'Poblacion'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'POBLAC'
        end
        object dbgrd_ventasCODIGO: TdxDBGridMaskColumn
          Caption = 'Codigo'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'CODIGO'
        end
        object dbgrd_ventasDESCRI: TdxDBGridMaskColumn
          Caption = 'Descripci�n'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DESCRI'
        end
        object dbgrd_ventasTIPOCTE: TdxDBGridMaskColumn
          Caption = 'TC'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TIPOCTE'
        end
        object dbgrd_ventasVENDEDOR: TdxDBGridMaskColumn
          Caption = 'Vnd'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'VENDEDOR'
        end
        object dbgrd_ventasSALEDE: TdxDBGridMaskColumn
          Caption = 'Almacen'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SALEDE'
        end
        object dbgrd_ventasPRECIOLISTA: TdxDBGridCurrencyColumn
          Caption = 'Precio Lista'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'PRECIOLISTA'
          SummaryFooterType = cstSum
          SummaryFooterField = 'PRECIOLISTA'
          SummaryFooterFormat = '$,0.00;-$,0.00'
          SummaryType = cstSum
          SummaryField = 'PRECIOLISTA'
          SummaryFormat = '$,0.00;-$,0.00'
          SummaryGroupName = 'dbgrd_ventasSummaryGroup2'
        end
      end
    end
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 280
    Top = 256
    object nuevo: TAction
      Caption = '&Nuevo'
      ImageIndex = 0
      ShortCut = 16462
    end
    object modifica: TAction
      Caption = '&Modifica'
      Hint = 'Modifica'
      ImageIndex = 1
      ShortCut = 16461
    end
    object borra: TAction
      Caption = 'Borra'
      Hint = 'Borra'
      ImageIndex = 2
      ShortCut = 16450
    end
    object grabar: TAction
      Caption = 'Grabar'
      Enabled = False
      ImageIndex = 9
      ShortCut = 16455
      OnExecute = grabarExecute
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      Enabled = False
      ImageIndex = 11
      ShortCut = 16460
      OnExecute = cancelarExecute
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = 'C&lose'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'primero'
      Hint = 'Selecciona la Primer Marca'
      ImageIndex = 5
      ShortCut = 49232
    end
    object anterior: TAction
      Caption = 'Anterior'
      Hint = 'Selecciona la Anterior Marca'
      ImageIndex = 6
      ShortCut = 49217
    end
    object siguiente: TAction
      Caption = 'Siguiente'
      Hint = 'Selecciona la Siguiente Marca'
      ImageIndex = 8
      ShortCut = 49235
    end
    object ultimo: TAction
      Caption = 'Ultimo'
      Hint = 'Selecciona la Ultima Marca'
      ImageIndex = 7
      ShortCut = 49237
    end
    object agreren: TAction
      Caption = 'A&grega.Reng'
      ImageIndex = 13
    end
    object cierraren: TAction
      Caption = 'Afectar Rengl�n'
      ImageIndex = 15
      ShortCut = 16454
    end
    object borraren: TAction
      Caption = 'Eliminar Rengl�n'
      ImageIndex = 17
      ShortCut = 16453
    end
    object exportdbgrid: TAction
      Caption = 'Exportar a ...'
      ImageIndex = 19
      OnExecute = exportdbgridExecute
    end
    object cierra_entrada: TAction
      Caption = 'Cerrar'
      ImageIndex = 15
    end
    object impritext: TAction
      Caption = 'Imprimir'
      Hint = 'Impresi�n'
      ImageIndex = 21
      ShortCut = 16464
      Visible = False
      OnExecute = impritextExecute
    end
    object reporte_acumulados: TAction
      Caption = 'Reporte Acumulados'
      OnExecute = reporte_acumuladosExecute
    end
    object definir_zonasexclu: TAction
      Caption = 'Zonas a Excluir'
      ImageIndex = 25
      OnExecute = definir_zonasexcluExecute
    end
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select  clave, nombre from almacen where cia = :CIA order by cla' +
        've')
    Left = 312
    Top = 288
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_almacen: TDataSource
    DataSet = qry_almacen
    Left = 312
    Top = 317
  end
  object qry_renentra: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select idrelvtaart, idrelvtas, a.idart, salede, conse, a.idcodig' +
        'o, a.iddescri,'
      'cast(b.concepto as varchar(13) ) as codigo,'
      'c.concepto as descri, preciolista'
      'from'
      'inv_relvtaart a '
      'join conceps b on a.idcodigo = b.ncon'
      'join conceps c on a.iddescri = c.ncon'
      'where idrelvtas = :IDRELVTAS'
      'order by conse')
    UpdateObject = uqry_renentra
    Left = 375
    Top = 289
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDRELVTAS'
        ParamType = ptUnknown
      end>
  end
  object dts_renentra: TDataSource
    AutoEdit = False
    DataSet = qry_renentra
    Left = 375
    Top = 318
  end
  object qry_sigent: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select max (folio) as sigent from inv_relvtas where cia = :CIA')
    Left = 407
    Top = 289
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_entradas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select idrelvtas, folio, fecha, idnombre, tipocte,'
      'idtipoentrega, ptovta, fechaent, entrega, vendedor,'
      'idpoblac, idusuario, feccap, cia'
      'from inv_relvtas'
      'where folio = :NUMERO and cia = :CIA')
    UpdateObject = uqry_entradas
    Left = 439
    Top = 289
    ParamData = <
      item
        DataType = ftInteger
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_entradas: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_relvtas'
      'set'
      '  FECHA = :FECHA,'
      '  IDNOMBRE = :IDNOMBRE,'
      '  TIPOCTE = :TIPOCTE,'
      '  IDTIPOENTREGA = :IDTIPOENTREGA,'
      '  PTOVTA = :PTOVTA,'
      '  FECHAENT = :FECHAENT,'
      '  ENTREGA = :ENTREGA,'
      '  VENDEDOR = :VENDEDOR,'
      '  IDPOBLAC = :IDPOBLAC,'
      '  IDUSUARIO = :IDUSUARIO,'
      '  FECCAP = :FECCAP'
      'where'
      '  IDRELVTAS = :OLD_IDRELVTAS')
    InsertSQL.Strings = (
      'insert into inv_relvtas'
      
        '  (IDRELVTAS, FOLIO, FECHA, IDNOMBRE, TIPOCTE, IDTIPOENTREGA, PT' +
        'OVTA, '
      'FECHAENT, '
      '   ENTREGA, VENDEDOR, IDPOBLAC, IDUSUARIO, FECCAP, CIA)'
      'values'
      
        '  (:IDRELVTAS, :FOLIO, :FECHA, :IDNOMBRE, :TIPOCTE, :IDTIPOENTRE' +
        'GA, '
      ':PTOVTA, '
      
        '   :FECHAENT, :ENTREGA, :VENDEDOR, :IDPOBLAC, :IDUSUARIO, :FECCA' +
        'P, :CIA)')
    DeleteSQL.Strings = (
      'delete from inv_relvtas'
      'where'
      '  IDRELVTAS = :OLD_IDRELVTAS')
    Left = 438
    Top = 319
  end
  object qry_ultfol: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select IFNULL(min(folio), 0) as ultfol, count(*) as exist'
      'from movart'
      'where idart = :IDART and  idalm = :IDALM and salio = '#39'N'#39' '
      'and fecha <= :FECHA and cia = :CIA')
    Left = 407
    Top = 320
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDART'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IDALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_conse: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select IFNULL(max(conse),0) as ultren'
      ' from renentra where identrada = :IDENTRADA')
    Left = 503
    Top = 290
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDENTRADA'
        ParamType = ptUnknown
      end>
  end
  object uqry_renentra: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_relvtaart'
      'set'
      '  IDART = :IDART,'
      '  SALEDE = :SALEDE,'
      '  CONSE = :CONSE'
      'where'
      '  IDRELVTAART = :OLD_IDRELVTAART')
    InsertSQL.Strings = (
      'insert into inv_relvtaart'
      '  (IDRELVTAART, IDRELVTAS, IDART, SALEDE, CONSE)'
      'values'
      '  (:IDRELVTAART, :IDRELVTAS, :IDART, :SALEDE, :CONSE)')
    DeleteSQL.Strings = (
      'delete from inv_relvtaart'
      'where'
      '  IDRELVTAART = :OLD_IDRELVTAART')
    Left = 376
    Top = 261
  end
  object dts_entradas: TDataSource
    AutoEdit = False
    DataSet = qry_entradas
    Left = 436
    Top = 259
  end
  object qry_exist: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select alm, EXISTES, EXISTEN, ULTFOL, (existes + existen) as tot' +
        'exi, CIA'
      'from exist where codigo = :CODIGO'
      'and cia = :CIA and (existes + existen) > 0'
      'order by alm')
    Left = 221
    Top = 290
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_vendr: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, nombre'
      ' from vendedor '
      'order by codigo')
    Left = 161
    Top = 292
  end
  object dts_vendr: TDataSource
    DataSet = qry_vendr
    Left = 161
    Top = 320
  end
  object qry_folsale: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select a.codigo, a.idart, b.idmovart, b.idalm, b.costo, b.modent' +
        ', '
      'b.folio, b.idserie, b.fecha, c.serie, '
      'b.entcan, b.fecentori, facpro, b.idprove'
      'from inven a join movart b on a.idart = b.idart'
      'left outer join series c on b.idserie = c.idserie'
      'where a.idart = :IDART and b.idalm = :IDALM'
      'and salio = '#39'N'#39' and folio = :FOLIO')
    Left = 161
    Top = 352
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDART'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IDALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FOLIO'
        ParamType = ptUnknown
      end>
  end
  object qry_ciudad: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from poblacs order by nombre')
    Left = 129
    Top = 291
  end
  object dts_ciudad: TDataSource
    DataSet = qry_ciudad
    Left = 129
    Top = 320
  end
  object qry_ptovta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre from ptovta where cia = :CIA order by clave')
    Left = 533
    Top = 291
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_ptovta: TDataSource
    DataSet = qry_ptovta
    Left = 533
    Top = 320
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.codigo, a.descri, tipo, costos, coston, piva, b.idart'
      
        'from inven a join inv_invhist b on a.codigo = b.codigo and a.cia' +
        ' = b.cia'
      'where a.codigo = :CODIGO and a.cia = :CIA order by a.codigo')
    Left = 343
    Top = 369
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 343
    Top = 398
  end
  object qry_tiposctes: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select  idticte, ticte, descri from car_tiposctes where cia = :C' +
        'IA order by ticte')
    Left = 344
    Top = 288
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_tiposctes: TDataSource
    DataSet = qry_tiposctes
    Left = 344
    Top = 317
  end
  object qry_tipoentrega: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select  idtipoentrega, codigo, descri '
      'from inv_tipoentrega '
      'where cia = :CIA'
      'order by codigo'
      '')
    Left = 272
    Top = 288
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_tipoentrega: TDataSource
    DataSet = qry_tipoentrega
    Left = 272
    Top = 317
  end
  object qry_chofer: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre'
      ' from promotor '
      'order by clave')
    Left = 193
    Top = 292
  end
  object dts_chofer: TDataSource
    DataSet = qry_chofer
    Left = 193
    Top = 320
  end
  object qry_buscod: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, tipo, costos, coston, piva'
      
        'from inven where codigo like :CODIGO and cia = :CIA order by cod' +
        'igo')
    Left = 373
    Top = 369
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_buscod: TDataSource
    DataSet = qry_buscod
    Left = 373
    Top = 398
  end
  object qry_direcs: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select iddirvta, idrelvtas, idconcep, conse, b.concepto as direc'
      ' from inv_dirvta a join conceps b on a.idconcep = b.ncon'
      'where idrelvtas = :IDRELVTA order by conse'
      '')
    UpdateObject = uqry_direcs
    Left = 471
    Top = 290
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDRELVTA'
        ParamType = ptUnknown
      end>
  end
  object uqry_direcs: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_dirvta'
      'set'
      '  IDRELVTAS = :IDRELVTAS,'
      '  IDCONCEP = :IDCONCEP,'
      '  CONSE = :CONSE'
      'where'
      '  IDDIRVTA = :OLD_IDDIRVTA')
    InsertSQL.Strings = (
      'insert into inv_dirvta'
      '  (IDDIRVTA, IDRELVTAS, IDCONCEP, CONSE)'
      'values'
      '  (:IDDIRVTA, :IDRELVTAS, :IDCONCEP, :CONSE)')
    DeleteSQL.Strings = (
      'delete from inv_dirvta'
      'where'
      '  IDDIRVTA = :OLD_IDDIRVTA')
    Left = 471
    Top = 319
  end
  object dts_exist: TDataSource
    DataSet = qry_exist
    Left = 225
    Top = 320
  end
  object qry_relvtas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select j.remate, g.ubica, i.zonaptvta, d.ptovta, d.entrega,'
      'g.descri as descriubi, d.hora, e.concepto as nombre,'
      'f.nombre as poblac, d.tipocte, d.vendedor,'
      
        'idrelvtaart, a.idrelvtas, a.idart, salede, conse, a.idcodigo, a.' +
        'iddescri,'
      'a.idreltransf, a.idpolrelvta,'
      'cast(b.concepto as varchar(13) ) as codigo,'
      'c.concepto as descri, preciolista, d.fecha'
      'from'
      'inv_relvtas d'
      'join inv_relvtaart a  on d.idrelvtas = a.idrelvtas'
      'join conceps b on a.idcodigo = b.ncon'
      'join conceps c on a.iddescri = c.ncon'
      'join conceps e on d.idnombre = e.ncon'
      'join poblacs f on d.idpoblac = f.numero'
      'join inv_relubiptovta h on d.ptovta = h.ptovta'
      'join inv_ubiptovta g on h.idubiptovta = g.idubiptovta'
      'join ubivtainv i on d.ptovta = i.pvta and i.alm = '#39#39
      'join car_tiposctes j on d.tipocte = j.ticte'
      'where '
      'd.fecha between :FECINI and :FECFIN and d.cia = :CIA'
      
        'order by j.remate, g.ubica, i.zonaptvta, d.ptovta, a.idrelvtas, ' +
        'conse'
      ' '
      ' ')
    Left = 97
    Top = 291
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_relvtas: TDataSource
    AutoEdit = False
    DataSet = qry_relvtas
    Left = 97
    Top = 320
  end
  object PopupMenu1: TPopupMenu
    Left = 200
    Top = 165
    object AgregaReng1: TMenuItem
      Action = exportdbgrid
    end
    object ReporteAcumulados1: TMenuItem
      Action = reporte_acumulados
    end
  end
end
